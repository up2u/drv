#include <stdio.h>

/*----------------------------------------po()---------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*       a(IN) -- 0 or 1
*       b(IN) -- power time
* Return:unsigned int
*-----------------------------------------------------------------------------*/

unsigned int po(unsigned char a, unsigned int b)
{
	unsigned int ret = 1;
	unsigned int i = 0;
	while(i < b){
		ret = ret*a;
		i++;
	}	
	return ret;
}

unsigned int bin2int(char *str)
{
	char *ptr = str;
	unsigned char arr[32] = {0};
	unsigned int len = 0;
	unsigned int index = 0;
	unsigned int ret = 0;
	while(*ptr != '\0'){
		if(*ptr != '0' && *ptr != '1'){
			printf("not a binary format\n");
			return -1;	
		}
		arr[len++] = *ptr;
		ptr++;
	}
	while(--len != -1){
		ret = ret + po(2*(arr[index++]-'0'), len);
	}
	return ret;
}

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("Usage: ./a.out 0101010\n");
		return 0;	
	}
	printf("the int of %s is %u\n", argv[1], bin2int(argv[1]));
}

