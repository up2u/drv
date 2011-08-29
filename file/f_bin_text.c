#include <stdio.h>

int main()
{
	FILE *fp_binary = NULL, *fp_text = NULL;
	int w1 = 5678;
	
	/*use od -x to check, they are same*/
	fp_binary = fopen("/tmp/f_b.txt", "wb+"); 
	fp_text = fopen("/tmp/f_t.txt", "w+"); 

	fwrite(&w1, 4, 1, fp_binary);
	fwrite(&w1, 4, 1, fp_text);

	return 0;	
}

