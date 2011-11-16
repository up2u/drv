#include <stdio.h>

void selection(int *arr, int n)
{
	int ipos = 0, imin = 0;
	int i = 0;
	for(ipos=0; ipos<n; ipos++){
		imin = ipos;
		for(i=ipos+1; i<n; i++){
			if(arr[i] < arr[imin]){
				imin = i;       // find the smallest element position
				printf("ipos = %d, imin = %d\n",ipos, imin);
			}
		}
		if(imin != ipos){
			int tmp = arr[ipos];
			arr[ipos] = arr[imin];
			arr[imin] = tmp;	
		}
	}
}

int main(int argc, char *argv[])
{
	int a[5] = {64, 25, 12, 22, 11};
	int i = 0;

	selection(a, 5);
	printf("the new arr is:");
	for(i=0; i<5; i++){
		printf("%d ", a[i]);
	}
	putchar('\n');
}

