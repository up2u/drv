#include <stdio.h>

int main()
{
	FILE *fp = NULL;
	int i = 0, j = 0;
	int seek_length = 0;
	int file_length = 0;
	char c = '\0';

	fp = fopen("/tmp/f2.txt", "r");
	fseek(fp, 0L, SEEK_END);
	file_length = ftell(fp);
	printf("file length is %lu\n",file_length);
	
	fseek(fp, 0L, SEEK_SET);

//	while(!feof(fp)){  // feof will do 1 more time !!
	while(seek_length < file_length){
		int k = 1,l = 0;
		fread(&i, 4, 1, fp);
		fread(&j, 4, 1, fp);
	
		for(l=0; l<i*j; l++){
			fread(&c,1, 1, fp);
			putchar(c);
			if(k%j == 0) putchar('\n');
			k++;
		}
		seek_length += 2*4 + i*j;
	}

	return 0;	
}

