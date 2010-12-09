#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "link_operation.h"
#include "block.h"

#define MAXSIZE 10000
#define HASH_FREE 50
#define HASH_USED 50

void * large_block = NULL;
struct gdlist hash_free[HASH_FREE];
struct gdlist hash_used[HASH_USED];
struct block  head;

/*-----------------------------init_hash_tab()---------------------------------
* Function: init_hash_tab() 
* Purpose: init hash table 
*         
* Parameters:
*		tab (IN) -- address of table
*       size (IN) -- table size  
* Return: void
*-----------------------------------------------------------------------------*/
void init_hash_tab(struct gdlist *tab, int size)
{
	int i=0;
	for(i=0; i<size; i++){
		init_dlist(&tab[i]);
	}
}

/*------------------------------key_hash_free()--------------------------------
* Function: key_hash_free()
* Purpose: generate key for free hash table
*         
* Parameters:
*         size(IN) -- the size you want to allocate
* Return: int
*-----------------------------------------------------------------------------*/
int key_hash_free(size_t size)
{
	int key = size/HASH_FREE;
	if(key > HASH_FREE-1){
		key = HASH_FREE-1;	
	}
	return key ;
}

/*-----------------------------key_hash_used()---------------------------------
* Function: key_hash_used()
* Purpose: generate key for used hash table
*         
* Parameters:
*         addr(IN) -- address of the memory you want to free
* Return: int
*-----------------------------------------------------------------------------*/
int key_hash_used(size_t addr)
{
	return addr%HASH_USED;	
}

/*-----------------------------ins_hash_free()---------------------------------
* Function: ins_hash_free()
* Purpose: insert the free block to the free hash table for quick search
*         
* Parameters:
*         pblock(IN) -- the pointer of a free block
* Return: void
*-----------------------------------------------------------------------------*/
void ins_hash_free(struct block *pblock)
{
	int key = 0;
	key = key_hash_free(pblock->size);
	if(key > HASH_FREE-1){
		key = HASH_FREE-1;	
	}
	ins_gdlist_tail(&(hash_free[key]), &(pblock->list_free));
}


/*------------------------------handle_block_free()----------------------------
* Function: handle_block_free()
* Purpose: when allocate a free block,need handle the near by block,if its to 
*         small, merge the left small block to current allocate free block,else 
*		  it big enough for one more block, then create one block more, and do 
*		  corresponding list operation.
* Parameters:
*         pblock (IN) -- avail block searched from free hash table
*		  size (IN) -- size you want to allocate
* Return: void
*-----------------------------------------------------------------------------*/
void handle_block_free(struct block *pblock, size_t size)
{
	struct block *pblock1 = NULL;
	int key_free = 0;
	int key_used = 0;

	if(pblock->size > size+size_block){/*create one more*/
		/*init pblock1*/
		pblock1 = (struct block *)((size_t)pblock + size_block + size);
		pblock1->flag = FREE;
		pblock1->size = pblock->size - size-size_block;
		/*resize the pblock*/
		pblock->size = size;
		pblock->flag = USED;
		
		/*pblock, pblock1*/
		ins_dlist_after(pblock,pblock1);/*insert the new pblock*/

		/*pblock*/
		del_gdlist(&(pblock->list_free)); /*del from free list*/
		key_used = key_hash_used((size_t)pblock);
		ins_gdlist_tail(&hash_used[key_used],&(pblock->list_used));

		/*pblock1*/
		key_free = key_hash_free(pblock1->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(pblock1->list_free));
		
	}else{/*only one pblock*/
		/*del from free hash, set USED*/
		pblock->flag = USED;	
		del_gdlist(&(pblock->list_free));
		key_used = key_hash_used((size_t)pblock);
		ins_gdlist_tail(&hash_used[key_used],&(pblock->list_used));
	}
}

/*------------------------------search_hash_free()-----------------------------
* Function: search_hash_free()
* Purpose: search an available free block from free hash table
*         
* Parameters:
*         size(IN) -- size you want to allocate
* Return: void point
*-----------------------------------------------------------------------------*/
void *search_hash_free(size_t size)
{
	int key = key_hash_free(size);
	struct gdlist *pgdlist = get_glist_next(&(hash_free[key]));
	struct block *pblock = NULL;
	size_t size_tmp = 0;
	if(pgdlist != &hash_free[key]){
		pblock = (struct block *)container_of(struct block, list_free, (size_t)pgdlist);
	    size_tmp = pblock->size;
	}

	while(key < HASH_FREE){
		while(pgdlist != &hash_free[key] && size_tmp < size ){
			pgdlist = get_glist_next(pgdlist);
			pblock = (struct block *)container_of(struct block, list_free, (size_t)pgdlist);
			size_tmp = pblock->size;
		}
		if(pgdlist == &hash_free[key]){/*current key size not available,next key*/
			key++;
			pgdlist = get_glist_next(&(hash_free[key]));
			if(pgdlist != &hash_free[key]){
				pblock = (struct block *)container_of(struct block, list_free, (size_t)pgdlist);
				size_tmp = pblock->size;
			}
			continue;
		}else{
			/*handle near by block, and hash table, link list.it has variety stitution*/
			handle_block_free(pblock,size);
			return (void *)((size_t)pblock + size_block);			
		}

	}
	if(key == HASH_FREE){
		printf("search the all hash table.no block available\n");
		return NULL;
	}
}

/*-------------------------------ins_hash_used()-------------------------------
* Function: ins_hash_used()
* Purpose: insert the used block to used hash table
*         
* Parameters:
*         pblock(IN) -- pointer of used block
* Return: void
*-----------------------------------------------------------------------------*/
void ins_hash_used(struct block *pblock)
{
	int key = 0;
	key = key_hash_used((size_t)pblock);
	ins_gdlist_tail(&(hash_used[key]),&(pblock->list_used));	
}

/*-------------------------------init_divblock()-------------------------------
* Function: init_divblock()
* Purpose: when first allocate from system malloc(),need handle the large block
*          do some list operation
* Parameters:
*         pblock(IN) -- large block from system malloc()
*		  size(IN) -- size you first time you want to allocate
*		  maxsize(IN) -- large block size you will allocate from system malloc()
* Return: void point
*-----------------------------------------------------------------------------*/
void * init_divblock(void *pblock, size_t size, size_t maxsize)
{
	struct block *pblock1 = NULL;
	struct block *pblock2 = NULL;
	void *pmem = NULL;

	/*init head*/
	init_dlist(&head);

	pmem =  (void *)((size_t)pblock+ size_block);
	pblock1 = (struct block *)pblock;
	pblock1->size = size;
	pblock1->flag = USED;
	init_new_block(pblock1);
	ins_dlist_tail(&head, pblock1);

	if((size+2*size_block) >= maxsize){ /*only one block*/
		printf("it can only allocate one\n");
		pblock1->size = maxsize-size_block;
		ins_hash_used(pblock1);

		return pmem;
	}else{ /*now two block*/
		printf("it can allocate one more\n");
		pblock2 = (struct block *)((size_t)pblock+size_block+size);
		pblock2->flag = FREE;
		pblock2->size = maxsize-2*size_block-size;
		init_new_block(pblock2);
		ins_dlist_after(pblock1, pblock2); /*to head list*/	
		ins_hash_used(pblock1); /*to malloc list*/
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
			init_hash_tab(hash_used, HASH_USED);
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

/*--------------------------------min_free()-----------------------------------
* Function: min_free()
* Purpose: free the small block,merge near by clock, and do list operation, 
*         
* Parameters:
*         ptr(IN) -- small memory address,it locate after the control struct, 
*			     not block point address
* Return: void
*-----------------------------------------------------------------------------*/
void min_free(void *ptr)
{
	struct block *pblock = (struct block *)(size_t)(ptr-size_block);
	struct block *pprev = pblock->prev;
	struct block *pnext = pblock->next;
	int key_free = 0;
	unsigned char cases = 0;
	if(pprev->flag == FREE && pnext->flag == FREE){
		cases = 0;
		pprev->size += pblock->size + pnext->size + 2*size_block;
		/*del from head list*/
		del_dlist(pblock);
		del_dlist(pnext);
		/*del hash list*/
		del_gdlist(&(pblock->list_used));
		del_gdlist(&(pprev->list_free));
		del_dlist(&(pnext->list_free));
		/*ins hash list*/
		key_free = key_hash_free(pprev->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(pprev->list_free));

	}else if(pprev->flag == FREE && pnext->flag == USED){
		cases = 1;
		pprev->size += pblock->size + size_block;
		/*del from head list*/
		del_dlist(pblock);
		/*del hash */
		del_gdlist(&(pblock->list_used));
		del_gdlist(&(pprev->list_free));
		/*ins hash*/
		key_free = key_hash_free(pprev->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(pprev->list_free));
	}else if(pprev->flag == USED && pnext->flag == FREE){
		cases = 2;
		pblock->size += pnext->size + size_block;
		/*del from head list*/
		del_dlist(pnext);
		/*del from hash list*/
		del_gdlist(&(pblock->list_used));
		del_gdlist(&(pnext->list_free));
		/*ins hash list*/
		key_free = key_hash_free(pprev->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(pblock->list_free));
	}else{
		cases = 3;	
		pblock->flag = FREE;
		/*del hash list*/
		del_gdlist(&(pblock->list_used));
		/*ins hash list*/
		key_free = key_hash_free(pblock->size);
		ins_gdlist_tail(&(hash_free[key_free]),&(pblock->list_free));
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
	struct gdlist *phash_used = get_glist_next(&(hash_used[0]));
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
	while(i < HASH_USED){
		while(phash_used != &(hash_used[i])){
			pblock = (struct block *)container_of(struct block, list_used, (size_t)phash_used);
			printf("hash_used i=%d,flag=%d,size=%d\n",i, pblock->flag, pblock->size);
			phash_used = get_glist_next(phash_used);
		}
		i++;
		phash_used = get_glist_next(&(hash_used[i]));
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

