#include <stdio.h>

/*
  test the fopen mode w+
*/
int main(int argc, char *argv[])
{
	 FILE *wp = fopen("/tmp/wp.file", "w+");
	 char a = 'c'; 
	 char b = 'd';
	 fwrite(&a, 1, 1, wp);
	 fwrite(&b, 1, 1, wp);
	 
	 fclose(wp);
	 return 0;
}
