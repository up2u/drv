#include <stdio.h>

void store(char *buf, int x_size, int y_size);

int main()
{
	char buf_w1 [2][3] = {
						 {'a', 'b', 'c'},
						 {'x', 'y', 'z'}
					    };
	char buf_w2 [3][4] = {
						 {'e', 'f', 'g','h'},
						 {'i', 'j', 'k','l'},
						 {'m', 'n', 'o','p'}
					    };

	store((char *)(buf_w1), 2, 3);
	store((char *)(buf_w2), 3, 4);
	
	return 0;	
}

void store(char *buf, int x_size, int y_size)
{
	FILE *fp = NULL;

	fp = fopen("/tmp/f3.txt", "a+");
	fwrite(&x_size, 4, 1, fp);
	fwrite(&y_size, 4, 1, fp);
	fwrite(buf, 1, x_size*y_size, fp);

	fclose(fp);
}

