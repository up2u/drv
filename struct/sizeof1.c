#include <stdio.h>

// NOTE the address difference, when with &
int main(int argc, char *argv[])
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p1 = a;  
	int *p2 = &a + 1; // the address is a+sizeof(int)*5 + 1 

	printf("add1 value = %d\n", *(p1+1));
	printf("add2 value = %d\n", *(p2-1));
	 	
	return 0;	
}

