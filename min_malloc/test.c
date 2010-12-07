#include <stdio.h>
#include "block.h"
#include "link_operation.h"

int main()
{
	struct gdlist head_gdlist;
	struct gdlist *gptr = NULL;
	struct block *ptr = NULL;
	struct block blk[5];
	int i = 0;

	init_dlist(&head_gdlist);

	for(i=0; i<5; i++)
	{
		blk[i].flag = 2*i;
		blk[i].size = 100+i;
		ins_gdlist_tail(&head_gdlist, &(blk[i].list));
	}
	
	gptr = get_glist_head(&head_gdlist);

	for(i=0; i<5; i++)
	{
		ptr = (struct block *)(container_of(struct block, list, (size_t)gptr));
		printf("flag=%d, size=%d\n",ptr->flag, ptr->size);
		gptr = get_glist_next(gptr);		
	}

	return 0;
}

