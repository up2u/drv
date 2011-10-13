#include <stdio.h>

int main()
{
	int i1 = 0xFFFFFFFE;
	int i2 = i1>>1;
	printf("bit right shift to check whether logic shift or arithmetic shift\n\n");
	printf("type 1: signed int\n");
	printf("i1=%d[0x%08x],i1>>1 = %d[0x%08x]\n",i1, i1, i2, i2);
	
	unsigned int ui1 = 0xFFFFFFFE;
	unsigned int ui2 = ui1>>1;
	printf("type 2: unsigned int\n");
	printf("ui1=%d[0x%08x],ui1>>1 = %d[0x%08x]\n",ui1, ui1, ui2, ui2);
	return 0;
}

