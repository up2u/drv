#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_INIT_SIZE 3
#define STACK_INCREMENT 1

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool init_stack(sqstack *s)
{
	s->base = (selemtype *)malloc(STACK_INIT_SIZE * sizeof(selemtype));
	if(!s->base){
		return false;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;

	return true;
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/

bool push(sqstack *s, selemtype e)
{
	if(s->top - s->base >= (s->stacksize)*sizeof(selemtype)){
		s->base = (selemtype *)realloc(s->base, (s->stacksize + STACK_INCREMENT)*sizeof(selemtype));
		if(!s->base){
			return false;
		}
		s->top = s->base + (s->stacksize)*sizeof(selemtype);
		s->stacksize += STACK_INCREMENT;
	}
	*s->top++ = e;
	return true;
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool pop(sqstack *s, selemtype *e)
{
	if(s->top == s->base){
		return false;
	}
	*e = *(--s->top);
	
	return true;
}


/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool print(sqstack *s)
{
	selemtype *ptr = s->top;/*save the top point*/
	if(s->top == s->base){
		return false;
	}else{
		while(s->top != s->base)
			printf("traverse stack: get element is %lld\n", *(--s->top));

		s->top = ptr;/*restore*/
		return true;
	}
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool traverse(sqstack *s, bool (* visit)(sqstack *pstack))
{
	return visit(s);
}

