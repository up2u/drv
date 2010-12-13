#include <stdio.h>
#include "stack.h"


/*------------------------------conversion( )----------------------------------
* Function: conversion
* Purpose: change decimal to other format 
*          example:(66)D = (102)O
* Parameters:
*   	elem(IN) -- the data that will be convert
*		to(IN) -- format type,it will be 2,8,16,etc      
* Return: 
*-----------------------------------------------------------------------------*/
void conversion(int elem, int to)
{
	sqstack head;
	selemtype oe;
	init_stack(&head);

	unsigned char rem = 0;
	while(elem){
		rem = elem%to;
		push(&head,rem);
		elem = elem/to;
	}
	while(pop(&head, &oe)){
		printf("%d",oe);
	}
	putchar('\n');
}

int main()
{
	int elem = 255;
	conversion(elem, 2);
	return 0;	
}

