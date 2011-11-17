#include <stdio.h>

void comb(int *arr, int n)
{
	size_t gap = n;
	size_t i = 0;
	int swapped = 0;

// add 'swapped' may do 1 less time forloop.
// the last time when gap = 1, and no swap happen,
// that swapped = 0, so don't need the following execute step
	while(gap > 1 || swapped){  
		if(gap > 1){
			gap = (size_t)((double)gap/1.247330950103979);		
		}
		printf("gap = %d\n", gap);
		
		swapped = 0;
		for(i = 0; gap + i < n; i++){
			if(arr[i] > arr[i+gap]){
				int tmp = arr[i];
				arr[i] = arr[i+gap];
				arr[i+gap] = tmp;	
				swapped = 1;
			}	
		}
	}
}

int main()
{
    int a[8] = {3, 7, 4, 8, 5, 2, 6, 1};
    int i = 0;
    comb(a,8);
    printf("the new arr is: ");
    for(i=0; i<8; i++){
        printf("%d ", a[i]);
    }
    putchar('\n');
    return 0;
}

