#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int running = 1;
	int shmid;
	int semid;
	int value;
	char *sharem = NULL;
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_flg = SEM_UNDO;

// semaphore	
	if((semid = semget((key_t)123456, 1, 0666|IPC_CREAT)) == -1){
		perror("semget");
		exit(EXIT_FAILURE);	
	}
	if(semctl(semid, 0, SETVAL, 0) == -1){
		perror("semctl");
		if(semctl(semid, 0, IPC_RMID, 0) == -1){
			perror("semctl");
		}
		exit(EXIT_FAILURE);	
	}

// share memory	
	if((shmid = shmget((key_t)654321, (size_t)2048, 0600|IPC_CREAT)) == -1){
		perror("shmget");
		exit(EXIT_FAILURE);	
	}
	sharem = shmat(shmid, NULL, 0);
	if(sharem == NULL){
		perror("shmat");
		exit(EXIT_FAILURE);	
	}
	while(running){
		if((value = semctl(semid, 0, GETVAL)) == 0){	  // if 0, that can write
			printf("write data, input: ");
			scanf("%s", sharem);
			sem_b.sem_op = 1;  // set V operation
			if(semop(semid, &sem_b, 1) == -1){
				printf("semaphore_p failed\n");
  			    exit(EXIT_FAILURE);
			}
		}
		if(strncmp(sharem, "end", 3) == 0){
			running = 0;	
		}
	}
	shmdt(sharem);
	return 0;	
}


