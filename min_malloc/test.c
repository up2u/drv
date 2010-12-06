#include <stdio.h>
#include "block.h"
#include "link_operation.h"

int main()
{
	struct dlink_list dll;
	struct dlink_list dll1;
	struct dlink_list dll2;
	struct dlink_list dll3;
	struct dlink_list dll4;

	int i=0;
	struct dlink_list *ptr = NULL;

	init_list(&dll);

	ins_list(&dll,&dll1);
	ins_list(&dll,&dll2);
	ins_list(&dll,&dll3);
	ins_list(&dll,&dll4);
	
	printf("add:%08x,%08x,%08x,%08x\n", &dll1, &dll2, &dll3, &dll4);
	for(ptr = dll.next; ptr != &dll; ptr=ptr->next)
	{
		printf("add = %08x\n", ptr);
	}

	del_list(&dll1);

	for(ptr = dll.next; ptr != &dll; ptr=ptr->next)
	{
		printf("add = %08x\n", ptr);
	}
		
	del_list(&dll3);

	for(ptr = dll.next; ptr != &dll; ptr=ptr->next)
	{
		printf("add = %08x\n", ptr);
	}
	return 0;
}

