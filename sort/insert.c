#include <stdio.h>

// do a ascending sort
void insert(int *arr, int n)
{
	int i = 0, j = 0;
	for(i=1; i<n; i++){
		int value = arr[i];
		j = i;
		while(j && arr[j-1] > value){
			arr[j] = arr[j-1]; // move forward
			j--;
			printf("find pos =%d\n", j);
		}
		arr[j] = value; //  at the correct postion, insert value into
		printf("now i=%d\n", i);
	}
}

int main(int argc, char *argv[])
{
	int a[8] = {3, 7, 4, 9, 5, 2, 6, 1};
	int i = 0;
	insert(a, 8);
	printf("the new arr is: ");
	for(i=0; i<8; i++){
		printf("%d ", a[i]);	
	}
	putchar('\n');

	return 0;	
}

