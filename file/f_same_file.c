#include <stdio.h>

/*use od to check the contents*/

int main()
{
	FILE *fp1 = NULL, *fp2 = NULL, *fp3 = NULL;
	char a = '7', b = '8',c = '9';

	fp1= fopen("/tmp/f1.txt","w+");
	fp2= fopen("/tmp/f1.txt","w+");
	fp3= fopen("/tmp/f1.txt","a+");

	fwrite(&a, 1, 1, fp1);
	fwrite(&b, 1, 1, fp2); // will override the previous contents
	fwrite(&c, 1, 1, fp3); // append to the end of previous contents

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}

