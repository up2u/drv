#include <stdio.h>

void shell(int *arr, int n, int inc)
{
	int i = 0, j = 0;
	for(i=0; i+inc<n; i++){
		int val = arr[i+inc];
		j = i + inc;
		while(j-inc>=0 && arr[j-inc] > val){
			arr[j] = arr[j-inc];
			j -= inc;
		}
		arr[j] = val;
	}
}
int main()
{
    int a[8] = {3, 7, 4, 8, 5, 2, 6, 1};
    int i = 0;
    shell(a,8,2);
//   shell(a,8,1);
    printf("the new arr is: ");
    for(i=0; i<8; i++){
        printf("%d ", a[i]);
    }
    putchar('\n');
    return 0;
}

