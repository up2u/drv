#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define FIFO "/tmp/my_fifo"

int main()
{
	int pipe_fd;
	int res;
	char buffer[] = "MAOLIJIE say:hello world!";
	if((access(FIFO, F_OK)) == -1){ // tests for the  existence of the file
		res = mkfifo(FIFO, 0766); //create fifo
		if(res != 0){
			fprintf(stderr,"could not create fifo: %s\n", FIFO);
			exit(EXIT_FAILURE);	
		}	
	}
	
	printf("write process:%d opening FIFO O_WRONLY\n",getpid());
	pipe_fd = open(FIFO, O_WRONLY);
	if(pipe_fd != -1){
		res = write(pipe_fd, buffer, sizeof(buffer));
		if(res == -1){
			fprintf(stderr, "write error on pipe\n");
			exit(EXIT_FAILURE);
		}
		printf("write data is: %s,%d bytes is written\n",buffer,res);
		close(pipe_fd);
	}else{
		exit(EXIT_FAILURE);	
	}
	
	printf("write process %d finished\n", getpid());
	exit(EXIT_SUCCESS);
}

