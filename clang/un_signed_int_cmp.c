#include <stdio.h>

int main()
{
	unsigned int a = 0xffff1234;
	int b = 0xffff1234;
	if(a == b){                 // they are identical ??
		printf("a=b\n");
	}
	return 0;
}
