#include <stdio.h>

// calculate sum of below.
//  1 2 3
//    1 2
//      1

int main()
{
	int i = 1;
	int j = 0;
	int n = 3;
	int sum = 0;

	for ( j = 1; i <= n; i++)
	{
		//for (j = i; j <= n; j++)
		{
			sum += ( 1 + i ) * i / 2;
		}
	}

	printf("the sum is %d\n", sum);	
}
