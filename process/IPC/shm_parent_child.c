#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int childpid;
	int id;
	int i;
	char *ptr;
	if((childpid = fork()) == -1){
		perror("fork");	
		exit(EXIT_FAILURE);
	}
	if(childpid == 0){
		if((id = shmget((key_t)12345, 50*sizeof(char), IPC_CREAT)) == -1){
			perror("failed to create shared memory\n");	
			exit(EXIT_FAILURE);
		}
		if((ptr = shmat(id, NULL, 0)) == NULL){
			if(shmctl(id, IPC_RMID, 0) == -1){
				perror("shmctl");	
				exit(EXIT_FAILURE);
			}	
		}
		// write to shm
		for(i=0; argv[1][i] != '\0'; i++){
			*ptr = argv[1][i];
			ptr++;	
		}
		printf("child: write argv[1]:%s to shm, input character num is %d\n",argv[1], i);
		exit(EXIT_SUCCESS);
	}else{
		wait(NULL);
		if((id = shmget((key_t)12345, 50*sizeof(char), IPC_CREAT)) == -1){
			perror("failed to create shared memory\n");	
			exit(EXIT_FAILURE);
		}	
		if((ptr = (char *)shmat(id, NULL, 0)) == NULL){
			perror("shmat");
			if(shmctl(id, IPC_RMID, NULL) == -1){
				perror("shmctl");
				exit(EXIT_FAILURE);
			}
		}
		printf("parent: input charaer is %s\n", ptr);
		if(shmctl(id, IPC_RMID, NULL) == -1){
			perror("shmctl");
			exit(EXIT_FAILURE);
		}

		exit(EXIT_FAILURE);
	}
}

