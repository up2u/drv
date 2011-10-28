#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int sem_id;
void init()
{
	key_t key;
	int ret;
	unsigned short sem_array[2];
	union semun
	{
		int val;
		struct semid_ds *buf;
		unsigned short *array;
	}arg;
	
	key = ftok(".", 'S');
	sem_id = semget(key, 2, 0644|IPC_CREAT);
	sem_array[0] = 0;
	sem_array[1] = 100;
	arg.array = &sem_array[0];
	ret = semctl(sem_id, 0, SETALL, arg);
	if(ret == -1){
		printf("SETALL failed\n");
	}
	printf("productor init is %d\n", semctl(sem_id, 0, GETVAL));
	printf("space init is %d\n", semctl(sem_id, 1, GETVAL));
}

int main(int argc, char *argv[])
{
	struct sembuf sops[2];
	sops[0].sem_num = 0;
	sops[0].sem_op = 1;   // product number
	sops[0].sem_flg = 0;
	sops[1].sem_num = 1;
	sops[1].sem_op = -1;  // space number
	sops[1].sem_flg = 0;

	init();
	while(1){
		printf("\nbefore produce\n");	
		printf("productor num: %d\n",semctl(sem_id, 0, GETVAL));	
		printf("space num: %d\n",semctl(sem_id, 1, GETVAL));
		semop(sem_id, (struct sembuf *)&sops[1], 1); // store into space	
		printf("after produce\n");
		semop(sem_id, (struct sembuf *)&sops[0], 1); // tell the customer	
		printf("after tell the customer\n");
		printf("productor num: %d\n",semctl(sem_id, 0, GETVAL));	
		printf("space num: %d\n",semctl(sem_id, 1, GETVAL));
		sleep(4);
	}
	semctl(sem_id, IPC_RMID, 0);
}

