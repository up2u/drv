#include <stdio.h>

void fun(int *p)
{
	int i = 0;
	for(i=0;i<6;i++){
		*p= 10+i;
		printf("p is %d\n", *p);
		p++;
	}
}

int main()
{
	int a[2][3] = {0};
	fun((int *)a);
	return 0;	
}

