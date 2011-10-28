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
	key=ftok(".", 'S');	
	sem_id = semget(key, 2, 0644|IPC_CREAT);
}

int main()
{
	init();
	struct sembuf sops[2];
	sops[0].sem_num = 0;	
	sops[0].sem_op = -1; // product number
	sops[0].sem_flg = 0;	
	sops[1].sem_num = 1;	
	sops[1].sem_op = 1;	 // space number
	sops[1].sem_flg = 0;
	init();
	printf("this is customer\n");
	while(1){
		printf("\nbefore custome:\n");	
		printf("productor is %d\n",semctl(sem_id, 0, GETVAL));	
		printf("space is %d\n",semctl(sem_id, 1, GETVAL));
		semop(sem_id, (struct sembuf *)&sops[0], 1);
		printf("after custome\n");	
		semop(sem_id, (struct sembuf *)&sops[1], 1);
		printf("now tell productor\n");	
		printf("productor is %d\n",semctl(sem_id, 0, GETVAL));	
		printf("space is %d\n",semctl(sem_id, 1, GETVAL));
		sleep(3);
	}	
}

