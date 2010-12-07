#include <stdio.h>
#include <stdlib.h>
#include "link_operation.h"
#include "block.h"

#define MAXSIZE 10000
#define HASH_FREE 50
#define HASH_MALLOC 50

void * large_block = NULL;
struct gdlist hash_free[HASH_FREE];
struct gdlist hash_malloc[HASH_MALLOC];
struct block head;

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
void ins_hash_free(struct block *blk)
{
	int key = 0;
	key = (blk->size)/HASH_FREE;
	if(key > HASH_FREE-1){
		key = HASH_FREE-1;	
	}
	ins_gdlist_tail(&(hash_free[key], &(blk->list_free)));
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
	void *key = NULL;
	key = (size_t)blk/HASH_MALLOC;		
	
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void init_divblock(void *blk, size_t size, size_t maxsize)
{
	size_t i = 0;	
	struct block *pblock1 = NULL;
	struct block *pblock2 = NULL;
	void *pmem = NULL;

	init_dlist(&head);
	pmem =  (void *)((size_t)large_block + size_block);
	pblock1 = (struct block *)large_block;
	pblock1->size = size;
	pblock1->flag = USED;
	ins_dlist_tail(&head, pblock1);
	ins_hash_malloc(pblock1);	

	if((size+2*size_block) >= maxsize){
		printf("it can only allocate one\n");
		pblock->size = maxsize-size_block;
	}else{
		printf("it can allocate one more\n");
		pblock2 = (struct block *)((size_t)blk+size_block+size);
		pblock2->flag = FREE;
		pblock2->size = maxsize-2*size_block-size;
		ins_dlist_tail(&head, pblock2);
		ins_hash_free(pblock2);
	}
	return pmem;
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
			printf("it's first alloc, use system malloc()\n");	
			large_block = malloc(MAXSIZE);
			if(large_block == NULL){
				printf("system malloc error\n");
				return NULL;	
			}else{
				init_divblock(large_block, size, MAXSIZE);
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
	void *pblock = NULL;
	void *pmem;

	if(large_block == NULL){
		return init_malloc(size);
	}else{
		
	}
}

