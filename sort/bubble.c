#include <stdio.h>


// http://en.wikipedia.org/wiki/Bubble_sort
void bubble(int *arr, int length)
{
	int i = 0, j = 0;
	int pos = length;
    int tmp = 0;

	for(i=0; i<pos; i++){
		for(j=1; j<length; j++){
			if(arr[j-1] > arr[j]){
				tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;		
				// find the least loop
				pos = j;  //means after the pos, all sorted, so change the outside loop 
				printf("j = %d, pos = %d\n", j, pos);
			}	
		}	
	}
	printf("the last pos is %d\n", pos);	
}


int main(int argc, char *argv[])
{
	int a[5] = {5,1,4,2,8};	
	int i = 0;

	bubble(a, 5);
	printf("new arrary is : ");
	for(i=0; i<5; i++){
		printf("%d ", a[i]);
	}
	putchar('\n');
	return 0;	
}

