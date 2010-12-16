#include <stdio.h>

/*
	0x00000000,0x80000000, zero
	0x7F800000,0xFF800000, inf
	0x7F800001,0xFF800001  NaN
*/
#define MASK 0x80000001

int main()
{
	printf("signed int bit xor:\n");
	int i1 = 0x00000000;
	int i2 = i1 ^ MASK;
	printf("\ti1=%d[%08X],i1^MASK=%d[%08X]\n",i1,i1, i2,i2);
	i1 = 0x80000000;
	i2 = i1 ^ MASK;
	printf("\ti1=%d[%08X],i1^MASK=%d[%08X]\n",i1,i1, i2,i2);

/*assign a decimal */
	printf("signed: assign an decimal\n");
	i1 = -1;
	i2 = i1 ^ MASK;
	printf("\ti1=%d[%08X],i1^MASK=%d[%08X]\n",i1,i1, i2,i2);
	i1 = -0;
	i2 = i1 ^ MASK;
	printf("\ti1=%d[%08X],i1^MASK=%d[%08X]\n",i1,i1, i2,i2);
	i1 = 0;
	i2 = i1 ^ MASK;
	printf("\ti1=%d[%08X],i1^MASK=%d[%08X]\n",i1,i1, i2,i2);
	i1 = 1;
	i2 = i1 ^ MASK;
	printf("\ti1=%d[%08X],i1^MASK=%d[%08X]\n",i1,i1, i2,i2);
	
	printf("\nunsigned int bit xor:\n");
	unsigned int ui1 = 0x00000000;
	unsigned int ui2 = ui1 ^ MASK;
	printf("\tui1=%u[%08X],ui1^MASK=%u[%08X]\n",ui1,ui1, ui2,ui2); /* %u to unsigned int*/
	ui1 = 0x80000000;
	ui2 = ui1 ^ MASK;
	printf("\tui1=%u[%08X],ui1^MASK=%u[%08X]\n",ui1,ui1, ui2,ui2);

/*assign a decimal */
	printf("unsigned: assign an decimal\n");
	ui1 = -1;
	ui2 = ui1 ^ MASK;
	printf("\tui1=%u[%08X],ui1^MASK=%u[%08X]\n",ui1,ui1, ui2,ui2);
	ui1 = -0;
	ui2 = ui1 ^ MASK;
	printf("\tui1=%u[%08X],ui1^MASK=%u[%08X]\n",ui1,ui1, ui2,ui2);
	ui1 = 0;
	ui2 = ui1 ^ MASK;
	printf("\tui1=%u[%08X],ui1^MASK=%u[%08X]\n",ui1,ui1, ui2,ui2);
	ui1 = 1;
	ui2 = ui1 ^ MASK;
	printf("\tui1=%u[%08X],ui1^MASK=%u[%08X]\n",ui1,ui1, ui2,ui2);

	return 0;
}

