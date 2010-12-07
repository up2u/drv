#include <stdio.h>
#include <stdlib.h>
#include "link_operation.h"
#include "block.h"

#define MAX_SIZE 10000
#define HASH_FREE 50
#define HASH_MALLOC 50

void * large_block = NULL;
struct gdlist hash_free[HASH_FREE];
struct gdlist hash_malloc[HASH_MALLOC];
struct block head;

void init_hash_tab(struct gdlist *tab, int size)
{
	int i=0;
	for(i=0; i<size; i++){
		init_dlist(&tab[i]);
	}
}

void ins_hash_free(struct block *blk)
{
	int key = 0;
	key = (blk->size)/HASH_FREE;
	if(key > HASH_FREE-1){
		key = HASH_FREE-1;	
	}
	ins_gdlist_tail(&(hash_free[key], &(blk->list_free)));
}

void ins_hash_malloc(struct block *blk)
{
	;		
}

void *min_malloc(size_t size)
{	
	void *pblock = NULL;
	void *pmem;

	if(large_block == NULL){
		if(size+size_block > MAX_SIZE){
			printf("the size is larger than MAX_SIZE, implement in next phase.\n");
			return NULL;
		}else{
			printf("It's first alloc, use system malloc()\n");	
			large_block = malloc(MAX_SIZE);
			if(large_block == NULL){
				printf("system malloc error\n");
				return NULL;	
			}
			init_dlist(&head);
			pmem =  (void *)((size_t)large_block + size_block);
			pblock = (struct block *)large_block;
			pblock->size = size;
			ins_dlist_tail(&head,pblock);
		}
	}
}

