#include <stdio.h>

/* use od to check what is float 1.0 in file or memory
   1.0 is : 
   0 011 1111 1000 0000 0000 0000 0000 0000   == od -X ->  3f800000
*/
int main()
{
	FILE *fp = fopen("/tmp/fw.txt", "w+");
	float f = 1;

	fwrite(&f, 4, 1, fp);

	fclose(fp);
	return 0;	
}

