#include <stdio.h>
#include "defines.h"

#define M 42
#define ADD(x)  (M + x)

int main()
{
	#define N 28
	printf("Hello , world\n");
	#undef N
	printf("We are so creative\n");
	
	#define N 1279
	printf("Goodbye\n");
	
	return 0;
}
