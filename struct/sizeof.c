#include <stdio.h>

typedef union 
{
    long a;
	int  b[5]; // 20
	char c;
}un1;

struct bit_field1
{	
	char a:4;  // bit 0->3
	char b:4;  // bit 4->7
	short c:8; // bit 16->31
	int d;     // bit 32->63
};

struct struct1
{
	char a;
	un1 b;    // 4 bytes alignment
	int c;	
};


int main(int argc, char *argv[])
{
	printf("size of un1 is %d\n", sizeof(un1));
	printf("size of bit_field1 is %d\n", sizeof(struct bit_field1));
	printf("size of struct1 is %d\n", sizeof(struct struct1));
	return 0;	
}

