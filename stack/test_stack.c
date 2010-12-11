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

int main()
{
	sqstack stack;
	selemtype i = 9;
	selemtype j = 0;
	int id = 0;

	init_stack(&stack);
	while(id++ < 4){/*after loop id=3 ! */
		if(!push(&stack, id)){
			printf("push error.\n");
		}
	}
	
//	while(id-- > 0){/*after loop id=-1,so the loop time is 1 time more than below loop.
//					or can use (id-- > 1) */
	while(id-- > 1){
		if(!pop(&stack, &j)){
			printf("pop error.\n");
		}else{
			printf("pop element is %d\n", j);
		}
	}

	return 0;
}

