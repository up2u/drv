#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// flush the stream

int main()
{
	pid_t p1, p2;
	while((p1=fork())== -1);
	if(0==p1){
		printf("b");
	// the reason that out 2 times 'a' may because of buffer
	// so use fflush() to flush stream
		fflush(stdout); 
	}else{
		printf("a");
		fflush(stdout);
	}
	
	while((p2=fork()) == -1);
	if(0==p2){
		printf("c");	
		fflush(stdout);
	}
	
	return 0;
}
