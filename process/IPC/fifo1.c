#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define FIFO "/tmp/fifo"

int main()
{
	pid_t pid;
	int fd;
	char buffer[80];
	unlink(FIFO); // if FIFO exist,delete it
	mkfifo(FIFO, 0744);
	if((pid=fork()) > 0){
		char s[] = "Hello";
		fd=open(FIFO,O_WRONLY);
		printf("parent:pid=%d, write data is %s\n",getpid(),s);
		write(fd,s,sizeof(s));
		close(fd);
		exit(EXIT_SUCCESS);
	}else if(pid == 0){
		sleep(2);
		fd=open(FIFO, O_RDONLY);
		read(fd, buffer,80);
		printf("child:pid=%d, read data is %s\n", getpid(),buffer);
		close(fd);
		exit(EXIT_SUCCESS);
	}else{
		perror("fork");
		exit(EXIT_FAILURE);	
	}

	return 0;	
}

