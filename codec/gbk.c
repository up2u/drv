#include  <stdio.h> 
#include  <stdint.h> 

void  encode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
	const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
	uint8_t*  out  =  (uint8_t*)raw_out; 

	uint32_t  seed  =  password  ^  0x34f1b001u; 
	size_t  i  =  0;
	for  (;  i  <  len;  ++i)  { 
		uint8_t  a  =  (  in[i]  ^  seed  )  >>  4; 
		uint8_t  b  =  (  (  ((uint32_t)in[i])  <<  15  )  ^  seed  )  >>  (15-4); 
		a  &=  15; 
		b  &=  240; 
		a  =  15  &  (  a  ^  (b  <<  3)); 
		out[i]  =  a  |  b; 
		seed  =  ((seed  ^  in[i])  *  1792013  +  in[i]); 
	} 
} 

void  decode(const  void*  raw_in,  void*  raw_out,  uint32_t  password,  size_t  len) 
{ 
	const  uint8_t*  in  =  (const  uint8_t*)raw_in; 
	uint8_t*  out  =  (uint8_t*)raw_out; 

	uint32_t  seed  =  password  ^  0x34f1b001u; 
	size_t  i  =  0;
	for(;  i  <  len;  ++i)  { 
		;
	} 
} 
int  main() 
{ 
	const  uint8_t  buf1[]  =  {0x35,  0x2a,  0x18,  0xb3,  0xfe,  0xf8,  0xa5,  0x17,  0x5a,  0xc7,  0x62,  0xa2,  0x74,  0x88,  0xff,  0xe2,  0x80,  0x47,  0xd3,  0xc1,  0xe6,  0x46,  0x70,  0x5e,  0x9d,  0xa5,  0x8d,  0x7c,  0x4e,  0x00,  0x84,  0x4b,  0xae,  0x18,  0x71,  0x6c,  0x01,  0xd1,  0xa2,  0xe4,  0x22,  0x5c,  0xb6,  0x24,  0xa1,  0xca,  0xdf,  0xcd,  0x10,  0x3f,  0x36,  0xf1,  0xa1,  0x2a,  }; 
	uint8_t  buf2[100]  =  {}; 
	const  uint32_t  password  =  0x571d9d96u; 
	const  size_t  len  =  sizeof(buf1); 
	decode(buf1,  buf2,  password,  len); 
	printf("%s\n",  buf2); 
	
	return 0;
}
