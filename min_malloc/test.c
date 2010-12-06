#include <stdio.h>
#include "block.h"
#include "link_operation.h"

int main()
{
	struct gslist head_sgl;
	struct gslist *gptr = NULL;
	struct block *ptr = NULL;
	struct block blk[5];
	int i = 0;

	head_sgl.next = NULL;

	for(i=0; i<5; i++)
	{
		blk[i].flag = 2*i;
		blk[i].size = 100+i;
		ins_gslist_head(&head_sgl, &(blk[i].list));
	}
	
	gptr = head_sgl.next;
	for(i=0; i<5; i++)
	{
		ptr = (struct block *)(container_of(struct block, list, (size_t)gptr));
		printf("flag=%d, size=%d\n",ptr->flag, ptr->size);
		gptr = gptr->next;		
	}

	return 0;
}

