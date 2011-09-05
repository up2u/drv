#include <stdio.h>

int main()
{
	int a = 0;
	
	for(; a < 5; a++)
	{
		int b = 3; 
		printf("variable a is %d\n", b);  // result is always =3 !! 
		b++;
	}

	return 0;	
}

