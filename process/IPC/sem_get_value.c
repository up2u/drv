#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define MAX_SEMAPHORES 5

int main(int argc, char *argv[])
{
	int i, ret, semid;
	unsigned short sem_array[MAX_SEMAPHORES];
	unsigned short sem_read_array[MAX_SEMAPHORES];
	union semun
	{
		int val;
		struct semid_ds *buf;
		unsigned short *array;
	}arg;

	semid = semget(IPC_PRIVATE, MAX_SEMAPHORES, 0666|IPC_CREAT);
	if(semid != -1){
		for(i = 0; i < MAX_SEMAPHORES; i++){
			sem_array[i] = (unsigned short)(i+1);	
		}	
		arg.array = sem_array;
		ret = semctl(semid, 0, SETALL, arg);
		if(ret == -1){
			printf("SETALL failed (%d)\n", errno);	
		}
		arg.array = sem_read_array;
		ret = semctl(semid, 0, GETALL, arg);
		if(ret == -1){
			printf("SETALL failed (%d)\n", errno);	
		}

		for(i = 0; i<MAX_SEMAPHORES; i++){
			printf("semaphore %d, value %d\n",i, sem_read_array[i]);
		}
		for(i = 0; i<MAX_SEMAPHORES; i++){
			ret = semctl(semid, i, GETVAL);
			printf("semaphore %d, value %d\n", i, ret);
		}
		ret = semctl(semid ,0, IPC_RMID);
	}else{
		printf("count not allocate semaphore (%d)\n",errno);
	}
	
	return 0;	
}

