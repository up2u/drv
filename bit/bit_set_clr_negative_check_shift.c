#include <stdio.h>

/*
	0x00000000,0x80000000, zero
	0x7F800000,0xFF800000, inf
	0x7F800001,0xFF800001  NaN
*/

/*bit 31*/
#define MASK 0x80000000

int main()
{
	printf("bit set with MASK \n");
	printf("set bit:\n");
	int i1 = 0x00000000;
	int i2 = i1 | MASK;
	printf("\ti1=%d[%08X],i1|MASK=%d[%08X]\n",i1,i1, i2,i2);

	printf("clear bit:\n");
	i1 = 0x80000000;
	i2 = i1 & ~MASK;
	printf("\ti1=%d[%08X],i1|MASK=%d[%08X]\n",i1,i1, i2,i2);

	printf("negative bit:\n");
	i1 = -1;/* same as i1 = 0xFFFFFFFF */
	i2 = i1 ^ MASK;
	printf("\ti1=%d[%08X],i1|MASK=%d[%08X]\n",i1,i1, i2,i2);

	printf("check bit:\n");
	i1 = 0x00000000;
	i2 = i1 | MASK;
	if((i2 & MASK) == MASK){
		printf("bit set succeed\n");
	}
	printf("\ti1=%d[%08X],i1|MASK=%d[%08X]\n",i1,i1, i2,i2);

	printf("\nbit set with shift \n");
	unsigned int i = 01;
	unsigned int offset = 31;
	i <<= offset;
	printf("set bit:\n");
	i1 = 0x00000000;
	i2 = i1 | i;
	printf("\ti1=%d[%08X],i1|i=%d[%08X]\n",i1,i1, i2,i2);

	printf("clear bit:\n");
	i1 = 0x80000000;
	i2 = i1 & ~i;
	printf("\ti1=%d[%08X],i1|i=%d[%08X]\n",i1,i1, i2,i2);

	printf("negative bit:\n");
	i1 = -1;/* same as i1 = 0xFFFFFFFF */
	i2 = i1 ^ i;
	printf("\ti1=%d[%08X],i1|i=%d[%08X]\n",i1,i1, i2,i2);

	printf("check bit:\n");
	i1 = 0x00000000;
	i2 = i1 | i;
	if((i2 & i) == i){
		printf("bit set succeed\n");
	}
	printf("\ti1=%d[%08X],i1|i=%d[%08X]\n",i1,i1, i2,i2);
	return 0;
}

