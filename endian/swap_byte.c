#include <stdio.h>

/* the swap only swap byte by byte (8bits) , not swap bit
   this is associate with endian and bitfield !
   example:
       0x1234 -> 0x3412
	   0x12345678 -> 0x78563412
   if you want to swap bit
   like
        0x1234 -> 0x4321
        0x12345678 -> 0x87654321
   this one does not work !
*/

#define swap_byte(x) (((x)>>24)&0xff|((x)>>8)&0xff00|((x)<<8)&0xff0000|(x)<<24)

int main(void)
{
	 long l1 = 0x12345678;
	 long l2 = swap_byte(l1);

	 printf("original is 0x%08x \n", l1);
	 printf("swapped  is 0x%08x \n", l2);

	 return 0;
}
