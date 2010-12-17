#include <stdio.h>


/*
*  int x = 0x1234557; &x = 0x100
*
*  MSB  0x100    0x101    0x102    0x103
*   ----+--------+--------+--------+--------+----  
*       |   01   |   23   |   45   |   57   |   
*   ----+--------+--------+--------+--------+----  
*                                  |01010111|        
*                               ---+--------+----
*                                 bit0,...  bit7
*       
*  LSB  0x100    0x101    0x102    0x103
*   ----+--------+--------+--------+--------+----  
*       |   57   |   45   |   23   |   01   |   
*   ----+--------+--------+--------+--------+----  
*       |11101010|
*   ----+--------+----
*      bit0,.   bit7
*/

struct bitfield
{
	unsigned int bit0: 1;	
	unsigned int bit1: 1;	
	unsigned int bit2: 1;	
	unsigned int bit3: 1;	
	unsigned int bit4: 1;	
	unsigned int bit5: 1;	
	unsigned int bit6: 1;	
	unsigned int bit7: 1;	
};

union bitfield_char
{
	char chr;
	struct bitfield bits;
};

int main()
{
	int x = 0x1234557;
	char *ptr =(char *)&x;
	printf("byte is 0x%X\n", *ptr);

	puts("now test bits of a char\n");
	union bitfield_char u;
	u.chr =*(char *)&x;
	printf("u.chr is 0x%X\n", u.chr);
	printf("char is: %c[0x%X]\nbits in it is:%d%d%d%d%d%d%d%d\n", u.chr,u.chr,u.bits.bit0,u.bits.bit1,u.bits.bit2,u.bits.bit3,u.bits.bit4,u.bits.bit5,u.bits.bit6,u.bits.bit7);
	return 0;	
}

