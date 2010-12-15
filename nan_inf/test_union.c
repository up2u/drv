#include <stdio.h>


union uint_float
{
	unsigned int uui;
	float uf;
};
#define SIZE 6
unsigned int uif_table[SIZE] = {
		0x00000000,0x80000000, /*zero*/
		0x7F800000,0xFF800000, /*inf*/
		0x7F800001,0xFF800001 /*NaN*/
};

int main()
{
	union uint_float u1;
	union uint_float u2;
	union uint_float u3;
	int i = 0;
	int j = 0;
	for(i=0; i<SIZE; i++){
		u1.uui = uif_table[i];

		for(j=0; j<SIZE; j++){
			u2.uui = uif_table[j];
			u3.uf = u1.uf + u2.uf;
			printf("add: %e[0x%08X] + %e[0x%08X] = %e[%08X]\n",u1.uf,u1.uui, u2.uf,u2.uui, u3.uf,u3.uui);
			u3.uf = u1.uf - u2.uf;
			printf("sub: %e[0x%08X] - %e[0x%08X] = %e[%08X]\n",u1.uf,u1.uui, u2.uf,u2.uui, u3.uf,u3.uui);
			u3.uf = u1.uf * u2.uf;
			printf("mul: %e[0x%08X] * %e[0x%08X] = %e[%08X]\n",u1.uf,u1.uui, u2.uf,u2.uui, u3.uf,u3.uui);
			u3.uf = u1.uf / u2.uf;
			printf("div: %e[0x%08X] / %e[0x%08X] = %e[%08X]\n",u1.uf,u1.uui, u2.uf,u2.uui, u3.uf,u3.uui);
		}
	}
	return 0;
}

