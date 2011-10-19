#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t p1, p2;
	while((p1=fork())== -1);
	if(0==p1){
		printf("b");// puzzle ? why execute 2 times 
	}else{
		printf("a");// puzzle ? why execute 2 times 	
	}
	
	while((p2=fork()) == -1);
	if(0==p2){
		printf("c");	
	}
	
	return 0;
}
