#include <stdio.h>

struct bitfield
{
	unsigned int bit0:2;
	unsigned int bit1:3;
	unsigned int 	 :0;
	int 		 bit2:3;
	int 		 bit3:1;
	int 		 bit4:3;
	int 		 bit5:3;
};

int main()
{

	struct bitfield bits = {
							.bit0 = 4, 
							.bit1 = 7, 
							.bit2 = 7, 
							.bit3 = 1,
							.bit4 = 3,
							.bit5 = 6
						   };
	/* in bit field, when use unsigned int,output %u,it fill high bit with 0,and printf as 32bit
       when use int, if it is negative, and print as %u/%d, it'll fill high bit with 1 to 32bit,
       like when bit3=1, it will extend 0xFFFFFFFF,that output %u 4294967295, */
	printf("bit0=%d,bit1=%d,bit2=%d,bit3=%d\n",bits.bit0,bits.bit1,bits.bit2,bits.bit3);
	/*the 2 lines output same */ 
	printf("bit0=%u,bit1=%u,bit2=%d,bit3=%d\n",bits.bit0,bits.bit1,bits.bit2,bits.bit3);

    /*the bit2/3 will output 4294967295 !!, bit4 will output 3 */
	printf("bit0=%d,bit1=%d,bit2=%u,bit3=%u,bit4=%u,bit5=%u,bit5=%d\n",
            bits.bit0,bits.bit1,bits.bit2,bits.bit3,bits.bit4,bits.bit5,bits.bit5);
	return 0;
}

