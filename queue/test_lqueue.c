#include <stdio.h>
#include "queue.h"

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
int main()
{
	linkqueue head;
	int i = 0;

	init_queue(&head);
	qelemtype qarray[5] = {1, 2, 3, 4, 5};
	
	for(i=0; i<5; i++)
		enqueue(&head, qarray[i]);

	traverse(&head, print);/*traverse queue*/
	
	return 0;
}

