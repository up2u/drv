#include <stdio.h>

/*
	0x00000000,0x80000000, zero
	0x7F800000,0xFF800000, inf
	0x7F800001,0xFF800001  NaN
*/

int main()
{
  /*when assigned an 0x????? to an int(signed or unsigned), 
    it will store the 0x????? to memory, then check whether 
    it is signed or unsigned ,then print out the data,example
    int i = 0xFFFFFFFF, then memeory will store as FFFFFFFF,
    then changed FFFFFFFF to signed int, it is -1, similarly
    unsigned i = 0xFFFFFFFF, changed to unsigned int ,it is 
    4294967295 */
	printf("signed int bit not:\n");
	int i1 = 0x00000000;
	int i2 = ~i1;
	printf("\ti1=%d[%08X],~i1=%d[%08X]\n",i1,i1, i2,i2);
	i1 = 0x80000000;
	i2 = ~i1;
	printf("\ti1=%d[%08X],~i1=%d[%08X]\n",i1,i1, i2,i2);

/*assigne a decimal */
	printf("signed: assigne an decimal\n");
	i1 = -1;
	i2 = ~i1;
	printf("\ti1=%d[%08X],~i1=%d[%08X]\n",i1,i1, i2,i2);
	i1 = -0;
	i2 = ~i1;
	printf("\ti1=%d[%08X],~i1=%d[%08X]\n",i1,i1, i2,i2);
	i1 = 0;
	i2 = ~i1;
	printf("\ti1=%d[%08X],~i1=%d[%08X]\n",i1,i1, i2,i2);
	i1 = 1;
	i2 = ~i1;
	printf("\ti1=%d[%08X],~i1=%d[%08X]\n",i1,i1, i2,i2);
	
	printf("\nunsigned int bit not:\n");
	unsigned int ui1 = 0x00000000;
	unsigned int ui2 = ~ui1;
	printf("\tui1=%u[%08X],~ui1=%u[%08X]\n",ui1,ui1, ui2,ui2); /* %u to unsigned int*/
	ui1 = 0x80000000;
	ui2 = ~ui1;
	printf("\tui1=%u[%08X],~ui1=%u[%08X]\n",ui1,ui1, ui2,ui2);

/*assigne a decimal */
	printf("unsigned: assigne an decimal\n");
    /*when assign a decimal to an int(signed or unsigned), it will put the 2's-complement
      of the decimal to the memory of the variable.then check the whether it is signed or
      not, at last assign the data in memory to variable. example: i=-1, the memory is
      FFFFFFFF,if 'i' is signed int, output will be -1, if 'i' is unsigned int, output will
      be 4294967295*/
	ui1 = -1;
	ui2 = ~ui1;
	printf("\tui1=%u[%08X],~ui1=%u[%08X]\n",ui1,ui1, ui2,ui2);
	ui1 = -0;
	ui2 = ~ui1;
	printf("\tui1=%u[%08X],~ui1=%u[%08X]\n",ui1,ui1, ui2,ui2);
	ui1 = 0;
	ui2 = ~ui1;
	printf("\tui1=%u[%08X],~ui1=%u[%08X]\n",ui1,ui1, ui2,ui2);
	ui1 = 1;
	ui2 = ~ui1;
	printf("\tui1=%u[%08X],~ui1=%u[%08X]\n",ui1,ui1, ui2,ui2);

	return 0;
}

