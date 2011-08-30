#include <stdio.h>

int main()
{
	FILE *fp = NULL;
	FILE *fp_w = NULL;
	int i = 0, j = 0;
	int seek_length = 0;
	int file_length = 0;
	char c = '\0';

	fp = fopen("/tmp/f2.txt", "r");
	fp_w = fopen("/tmp/f2_w.txt", "a+");
	fseek(fp, 0L, SEEK_END);
	file_length = ftell(fp);
	printf("file length is %lu\n",file_length);
	
	fseek(fp, 0L, SEEK_SET);

	while(!feof(fp)){  // feof will do 1 more time !!
		int l = 0;

		if(fread(&i, 4, 1, fp) < 1) // must add this judgement, when reach end, it will return 0
			return -1;
		if(fread(&j, 4, 1, fp) < 1)
			return -1;
		for(l=0; l<i*j; l++){
			if(fread(&c,1, 1, fp) < 1)
				return -1;
			if(fwrite(&c, 1, 1, fp_w) < 1)
				return -1;
		}
	}

	return 0;	
}

