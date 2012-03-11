#include <string.h>

void dsend(char *to, char *from, int count)
{
    int n = (count+7)/8;
	
    switch(count%8)
    {
	    case 0:  do {  *to = *from++;
		case 7:        *to = *from++;
		case 6:        *to = *from++;	  
		case 5:        *to = *from++;	  
		case 4:        *to = *from++;	  
		case 3:        *to = *from++;	  
		case 2:        *to = *from++;	  
		case 1:        *to = *from++;	  
		            } while(--n > 0);
	}
}

int main(void)
{
	 char  port;
	 char *src1 = "this is a test !";
	 char *src2 = "this is an intersting test !";
	 
	 dsend(&port, src1, strlen(src1)+1);
	 dsend(&port, src2, strlen(src2)+1);

	 return 0;
}
