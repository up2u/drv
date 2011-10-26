#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int temp;
	int pipedes[2];
	char s[14] = "test message!";
	char d[14];
	//create pipe
	if((pipe(pipedes)) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);	
	}
	if((pid=fork()) == -1){
		perror("fork");	
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		printf("child:now write data to pipe\n");
		if((write(pipedes[1],s,14)) == -1){
			perror("write");
			exit(EXIT_FAILURE);	
		}else{
			printf("the written data is: %s\n",s);
			exit(EXIT_SUCCESS);	
		}
	}else{
		sleep(2);
		printf("parent:now read data from pipe\n");
		if((read(pipedes[0],d,14)) == -1){
			perror("read");	
			exit(EXIT_FAILURE);
		}
		printf("the data from pipe is: %s\n",d);
	}

	return 0;	
}

