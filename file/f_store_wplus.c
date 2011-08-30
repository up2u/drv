#include <stdio.h>

void store(char *buf, int x_size, int y_size);

int main()
{
	int i = 0;
	char buf_w [2][3] = {
						 {'a', 'b', 'c'},
						 {'x', 'y', 'z'}
					    };

	for(i=0; i<2; i++)
		store((char *)(buf_w+i), i, 3);
	
	// last the file content is: xyz
	return 0;	
}

void store(char *buf, int x_size, int y_size)
{
	FILE *fp = NULL;

	fp = fopen("/tmp/f2.txt", "w+");  // in this kind, when was called,will override previous contents
	fwrite(buf, 1, y_size, fp);

	fclose(fp);
}

