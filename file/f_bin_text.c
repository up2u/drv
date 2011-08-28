#include <stdio.h>

/*in windows system, can open with 't' or 'b' mode
*  fopen("1.txt", "wt+"); when write, change '\n' -> '\r\n'
*  fopen("2.txt", "wb+"); when write, '\n' no change, still '\n'
* but in unix/linux, there are no difference between the 2 modes
*/
int main()
{
	FILE *fp_binary = NULL, *fp_text = NULL;
	int w1 = 5678;
	char w2[2] = {'a','b'};
	
	/*use od -x to check, they are same*/
	fp_binary = fopen("/tmp/f_b.txt", "wb+"); 
	fp_text = fopen("/tmp/f_t.txt", "w+");  // in fact they all opened in binary mode !

	fwrite(&w1, 4, 1, fp_binary);
	fwrite(&w1, 4, 1, fp_text);

	fwrite(w2, 1, 2, fp_binary);
	fwrite(w2, 1, 2, fp_text);

	fclose(fp_binary);
	fclose(fp_text);
	return 0;	
}

