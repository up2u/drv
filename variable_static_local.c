#include <stdio.h>

int main()
{
	int a = 0;
	
	for(; a < 5; a++)
	{
		static int b = 3; 
		printf("variable a is %d\n", b);  // result is always 3 4 5 ... ! 
		b++;
	}

	return 0;	
}

