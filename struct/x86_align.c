#include <stdio.h>

struct struct_4_8{
	int a;	
	long long int b;
};

int main()
{
	/* in x86, the address of long long int should not the integer times of 8, 
	but it is integer times of 4, means 4 bytes align.
	
	in nds, it must be 8 bytes align
	 */
	struct struct_4_8 s1 = {1, 2};  

	return 0;	
}

