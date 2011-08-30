#include <stdio.h>

int main()
{
	FILE *fp = NULL;
	fp = fopen("/tmp/f4", "w+");
	int n = 0;
	char c = 'a';
	fwrite(&c, 1, 1, fp);
	
	fseek(fp, 0L, SEEK_SET);
	while(!feof(fp)){
		fread(&c, 1, 1, fp);
		n++;
	}
	printf("length is %d\n", n);
	return 0;
}

