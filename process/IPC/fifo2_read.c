#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FIFO "/tmp/my_fifo"

int main()
{
	int pipe_fd;
	int res;
	char buffer[4096];
	
	memset(buffer, '\0', sizeof(buffer));	
	printf("read process:%d opening FIFO O_RDONLY\n",getpid());
	pipe_fd = open(FIFO, O_RDONLY);
	if(pipe_fd != -1){
		res = read(pipe_fd, buffer, sizeof(buffer));
		if(res == -1){
			fprintf(stderr, "read error on pipe\n");
			exit(EXIT_FAILURE);
		}
		printf("read data is: %s,%d bytes is read\n",buffer,res);
		close(pipe_fd);
	}else{
		exit(EXIT_FAILURE);	
	}
	
	printf("read process %d finished\n", getpid());
	exit(EXIT_SUCCESS);
}

