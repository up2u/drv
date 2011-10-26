#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	pid_t p1 = 0;
	int count = 0;
	p1 = fork();
	if(p1 < 0){
		printf("error in fork\n");	
	}else if(p1 == 0){
		count++;
		printf("this is child,pid=%d,variable count=%d\n",getpid(),count);	
	}else{
		count++;
		printf("this is parent,pid=%d,variable count=%d\n",getpid(),count);	
	}
	return 0;	
}

