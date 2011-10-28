#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int semaphore_v(void);
static int set_semvalue(void);
static int get_semvalue(void);

union semun
{
	int val;                  // for SETVAL
	struct semid_ds *buf;     // for IPC_STAT,IPC_SET	
	unsigned short int *array;// for GETALL, SETALL
	struct seminfo *__buf;    // for IPC_INFO
};

int sem_id;

int main(int argc, char *argv[])
{
	pid_t pid;
	int value;
	key_t key;
	
	if((pid=fork()) == -1){
		perror("fork");	
		exit(EXIT_FAILURE);
	}else if (pid == 0){
		if((sem_id=semget((key_t)123456, 1, 0770|IPC_CREAT)) == -1){
			perror("semget");	
			exit(EXIT_FAILURE);
		}
		if(!set_semvalue()){
			printf("failed initialized semaphore\n");
			exit(EXIT_FAILURE);	
		}
		value = get_semvalue();
		printf("child: the current value is %d\n",value);
		if(!semaphore_v()){
			printf("failed to v operator\n");
			exit(EXIT_FAILURE);
		}
		value = get_semvalue();
		printf("child: v operator, value=%d\n", value);
		printf("child: exit success\n");
		exit(EXIT_SUCCESS);	
	}else{
		sleep(3);
		if((sem_id = semget((key_t)123456, 1, 0770|IPC_CREAT)) == -1){
			perror("semget");
			exit(EXIT_FAILURE);	
		}
		value=get_semvalue();
		printf("parent: the current value is %d\n", value);
		printf("parent: will remove the sem\n");
		if(semctl(sem_id, 0, IPC_RMID, (struct msquid_ds *)0) == -1){
			perror("semclt");
			exit(EXIT_FAILURE);	
		}
	}
	return 0;
}

static int set_semvalue(void)
{
	union semun sem_union;
	int value = 5;
	sem_union.val = value;
	if((semctl(sem_id, 0, SETVAL, sem_union)) == -1){  // set value 5
		return 0;	
	}
	printf("set value success\n");
	printf("init value is %d\n", get_semvalue());
	return 1;	
}

static int get_semvalue(void)
{
	int res;
	if((res = semctl(sem_id, 0, GETVAL)) == -1){ // GETVAL
		perror("semctl");
		exit(EXIT_FAILURE);
	}
	return res;
}

static int semaphore_v(void)
{
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = 1;
#ifdef SEMUNDO
    sem_b.sem_flg = SEM_UNDO;
#else
	sem_b.sem_flg = 0;	
#endif
	if(semop(sem_id, &sem_b, 1) == -1){
		perror("semop");
		return 0;
	}
	return 1;
}

