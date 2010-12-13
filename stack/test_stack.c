#include <stdio.h>
#include "stack.h"

int main()
{
	sqstack stack;
	selemtype i = 9;
	selemtype j = 0;
	int id = 0;

	init_stack(&stack);
	while(id++ < 4){/*after loop id=5 ! */
		if(!push(&stack, i++)){
			printf("push error.\n");
		}
	}

	/*traverse the stack*/
	traverse(&stack, print);

//	while(id-- > 0){/*after loop id=-1,so the loop time is 1 time more than below loop.
//					or can use (id-- > 1) */
	while(id-- > 1){
		if(!pop(&stack, &j)){
			printf("pop error.\n");
		}else{
			printf("pop element is %lld\n", j);
		}
	}
	
	return 0;
}

