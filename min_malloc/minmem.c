#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "link_operation.h"
#include "block.h"

#define MAXSIZE 10000
#define HASH_FREE 50
#define HASH_MALLOC 50

void * large_block = NULL;
struct gdlist hash_free[HASH_FREE];
struct gdlist hash_malloc[HASH_MALLOC];
struct block  head;

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void init_hash_tab(struct gdlist *tab, int size)
{
	int i=0;
	for(i=0; i<size; i++){
		init_dlist(&tab[i]);
	}
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
int key_hash_free(size_t size)
{
	int key = size/HASH_FREE;
	if(key > HASH_FREE-1){
		key = HASH_FREE-1;	
	}
	return key ;
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
int key_hash_malloc(size_t addr)
{
	return addr%HASH_MALLOC;	
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void ins_hash_free(struct block *blk)
{
	int key = 0;
	key = key_hash_free(blk->size);
	if(key > HASH_FREE-1){
		key = HASH_FREE-1;	
	}
	ins_gdlist_tail(&(hash_free[key]), &(blk->list_free));
}


/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void handle_block_free(struct block *block1, size_t size)
{
	struct block *block2 = NULL;
	int key_free = 0;
	int key_malloc = 0;

	if(block1->size > size+size_block){/*create one more*/
		/*init block2*/
		block2 = (struct block *)((size_t)block1 + size_block + size);
		block2->flag = FREE;
		block2->size = block1->size - size-size_block;
		/*resize the block1*/
		block1->size = size;
		block1->flag = USED;
		
		/*block1, block2*/
		ins_dlist_after(block1,block2);/*insert the new block*/

		/*block1*/
		del_gdlist(&(block1->list_free)); /*del from free list*/
		key_malloc = key_hash_malloc((size_t)block1);
		ins_gdlist_tail(&hash_malloc[key_malloc],&(block1->list_malloc));

		/*block2*/
		key_free = key_hash_free(block2->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(block2->list_free));
		
	}else{/*only one block*/
		/*del from free hash, set USED*/
		block1->flag = USED;	
		del_gdlist(&(block1->list_free));
		key_malloc = key_hash_malloc((size_t)block1);
		ins_gdlist_tail(&hash_malloc[key_malloc],&(block1->list_malloc));
	}
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void *search_hash_free(size_t size)
{
	int key = key_hash_free(size);
	struct gdlist *pgdlist = get_glist_next(&(hash_free[key]));
	struct block *pblk = NULL;
	size_t size_tmp = 0;
	if(pgdlist != &hash_free[key]){
		pblk = (struct block *)container_of(struct block, list_free, (size_t)pgdlist);
	    size_tmp = pblk->size;
	}

	while(key < HASH_FREE){
		while(pgdlist != &hash_free[key] && size_tmp < size ){
			pgdlist = get_glist_next(pgdlist);
			pblk = (struct block *)container_of(struct block, list_free, (size_t)pgdlist);
			size_tmp = pblk->size;
		}
		if(pgdlist == &hash_free[key]){/*current key size not available,next key*/
			key++;
			pgdlist = get_glist_next(&(hash_free[key]));
			if(pgdlist != &hash_free[key]){
				pblk = (struct block *)container_of(struct block, list_free, (size_t)pgdlist);
				size_tmp = pblk->size;
			}
			continue;
		}else{
			/*handle near by block, and hash table, link list.it has variety stitution*/
			handle_block_free(pblk,size);
			return (void *)((size_t)pblk + size_block);			
		}

	}
	if(key == HASH_FREE){
		printf("search the all hash table.no block available\n");
		return NULL;
	}
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void ins_hash_malloc(struct block *blk)
{
	int key = 0;
	key = key_hash_malloc((size_t)blk);
	ins_gdlist_tail(&(hash_malloc[key]),&(blk->list_malloc));	
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void * init_divblock(void *blk, size_t size, size_t maxsize)
{
	struct block *pblock1 = NULL;
	struct block *pblock2 = NULL;
	void *pmem = NULL;

	/*init head*/
	init_dlist(&head);

	pmem =  (void *)((size_t)blk+ size_block);
	pblock1 = (struct block *)blk;
	pblock1->size = size;
	pblock1->flag = USED;
	init_new_block(pblock1);
	ins_dlist_tail(&head, pblock1);

	if((size+2*size_block) >= maxsize){ /*only one block*/
		printf("it can only allocate one\n");
		pblock1->size = maxsize-size_block;
		ins_hash_malloc(pblock1);

		return pmem;
	}else{ /*now two block*/
		printf("it can allocate one more\n");
		pblock2 = (struct block *)((size_t)blk+size_block+size);
		pblock2->flag = FREE;
		pblock2->size = maxsize-2*size_block-size;
		init_new_block(pblock2);
		ins_dlist_after(pblock1, pblock2); /*to head list*/	
		ins_hash_malloc(pblock1); /*to malloc list*/
		ins_hash_free(pblock2); /*to free list*/

		return pmem;
	}
}

/*-----------------------------init_malloc()-----------------------------------
* Function: init_malloc()
* Purpose: initial allocate a large memory block,then the blocks will be 
*         insert to the 2 hash table, for later use.
* Parameters:
*         size (IN) --the size will be allocated 
* Return: an void pointer that point to the allocate memory.  
*-----------------------------------------------------------------------------*/
void * init_malloc(size_t size)
{
		if(size+size_block > MAXSIZE){
			printf("the size is larger than MAXSIZE, implement in next phase.\n");
			return NULL;
		}else{
			printf("init hash table.\n");
			init_hash_tab(hash_free, HASH_FREE);
			init_hash_tab(hash_malloc, HASH_MALLOC);
			printf("it's first alloc, use system malloc()\n");	
			large_block = malloc(MAXSIZE);
			if(large_block == NULL){
				printf("system malloc error\n");
				return NULL;	
			}else{
				return init_divblock(large_block, size, MAXSIZE);
			}
		}
}

/*-----------------------------min_malloc()------------------------------------
* Function: min_malloc()
* Purpose: implement allocate a memory block from ourself memory manage unit.
*         such as link list,hash table, etc.
* Parameters:
*         size (IN) --the size will be allocated 
* Return: an void pointer that point to the allocate memory.  
*-----------------------------------------------------------------------------*/
void *min_malloc(size_t size)
{	
	if(large_block == NULL){
		return init_malloc(size);
	}else{/*ourself mmu*/
		return search_hash_free(size);
	}
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void min_free(void *ptr)
{
	struct block *block1 = (struct block *)(size_t)(ptr-size_block);
	struct block *pprev = block1->prev;
	struct block *pnext = block1->next;
	int key_free = 0;
	unsigned char cases = 0;
	if(pprev->flag == FREE && pnext->flag == FREE){
		cases = 0;
		pprev->size += block1->size + pnext->size + 2*size_block;
		/*del from head list*/
		del_dlist(block1);
		del_dlist(pnext);
		/*del hash list*/
		del_gdlist(&(block1->list_malloc));
		del_gdlist(&(pprev->list_free));
		del_dlist(&(pnext->list_free));
		/*ins hash list*/
		key_free = key_hash_free(pprev->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(pprev->list_free));

	}else if(pprev->flag == FREE && pnext->flag == USED){
		cases = 1;
		pprev->size += block1->size + size_block;
		/*del from head list*/
		del_dlist(block1);
		/*del hash */
		del_gdlist(&(block1->list_malloc));
		del_gdlist(&(pprev->list_free));
		/*ins hash*/
		key_free = key_hash_free(pprev->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(pprev->list_free));
	}else if(pprev->flag == USED && pnext->flag == FREE){
		cases = 2;
		block1->size += pnext->size + size_block;
		/*del from head list*/
		del_dlist(pnext);
		/*del from hash list*/
		del_gdlist(&(block1->list_malloc));
		del_gdlist(&(pnext->list_free));
		/*ins hash list*/
		key_free = key_hash_free(pprev->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(block1->list_free));
	}else{
		cases = 3;	
		block1->flag = FREE;
		/*del hash list*/
		del_gdlist(&(block1->list_malloc));
		/*ins hash list*/
		key_free = key_hash_free(block1->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(block1->list_free));
	}
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void debug(void *chr)
{
	struct block *pnext = head.next;
	struct block *pprev = head.prev;
	int i = 0;
	struct gdlist *phash_malloc = get_glist_next(&(hash_malloc[0]));
	struct gdlist *phash_free = get_glist_next(&(hash_free[0]));
	struct block *pblock = NULL;
//	printf("DEBUG: the char is %c\n", *(char *)chr);
//	while(pnext != &head){
	while(pprev != &head){
		printf("block.flag, block.size,\n");	
//		printf("      %d,         %d   \n\n", pnext->flag, pnext->size);
		printf("      %d,         %d   \n\n", pprev->flag, pprev->size);
//		pnext = pnext->next;
		pprev = pprev->prev;
	}
/*output the hash table*/
	i = 0;
	while(i < HASH_MALLOC){
		while(phash_malloc != &(hash_malloc[i])){
			pblock = (struct block *)container_of(struct block, list_malloc, (size_t)phash_malloc);
			printf("hash_malloc i=%d,flag=%d,size=%d\n",i, pblock->flag, pblock->size);
			phash_malloc = get_glist_next(phash_malloc);
		}
		i++;
		phash_malloc = get_glist_next(&(hash_malloc[i]));
	}
	i = 0;
	while(i < HASH_FREE){
		while(phash_free != &(hash_free[i])){
			pblock = (struct block *)container_of(struct block, list_free, (size_t)phash_free);
			printf("hash_free i=%d,flag=%d,size=%d\n",i, pblock->flag, pblock->size);
			phash_free = get_glist_next(phash_free);
		}
		i++;
		phash_free = get_glist_next(&(hash_free[i]));
	}
}


int main()
{
	printf("test mmu\n");
	void *ptr = min_malloc(5);
	char *chr = NULL;
	void *p2 = (void *)((size_t)ptr - size_block);
	int i = 0;
	int size=0;
	void *pf0 = NULL;
	void *pf1 = NULL;
	void *pf2 = NULL;
	void *pf3 = NULL;
	void *pf4 = NULL;
	void *pf5 = NULL;
	void *pf6 = NULL;

	for(i=0; i<7; i++){
		printf("allocate %d\n", i+1);
		chr =(char *)min_malloc(10+pow(i,3));
		if(chr == NULL){
			printf("min_malloc error\n");
			goto free;
		}
		if(i == 0){
			pf0 = (void *)chr;	
		}
		if(i == 1){
			pf1 = (void *)chr;	
		}
		if(i == 2){
			pf2 = (void *)chr;	
		}
		if(i == 3){
			pf3 = (void *)chr;	
		}
		if(i == 4){
			pf4 = (void *)chr;	
		}
		if(i == 5){
			pf5 = (void *)chr;	
		}
		if(i == 6){
			pf6 = (void *)chr;	
		}
		*chr = 'A'+i;
	}

	min_free(pf2);
	min_free(pf3);
	debug((void *)chr);

	printf("after allocate .\n");
free:
	free(p2);	
	printf("after free\n");
	return 0;
}

