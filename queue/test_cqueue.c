#include <stdio.h>
#include <stdlib.h>
#include "cirqueue.h"

int main()
{
	cqueue head;
	init_queue(&head);
	int i = 0;
	qelemtype ie = 3;
	qelemtype oe;	
	
	for(i=0; i<4; i++){
		enqueue(&head, ie++);
	}
	printf("1st: full \n");
	traverse(&head,print);
	
	dequeue(&head, &oe);
	printf("2nd\n");
	traverse(&head,print);

	dequeue(&head, &oe);
	printf("3rd\n");
	traverse(&head,print);

	dequeue(&head, &oe);
	printf("4th\n");
	traverse(&head,print);

	dequeue(&head, &oe);
	printf("5th\n");
	traverse(&head,print);

	enqueue(&head, ie++);
	printf("6th\n");
	traverse(&head,print);

	enqueue(&head, ie++);
	printf("7th\n");
	traverse(&head,print);

	return 0;
}

