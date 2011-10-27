#include <sys/types.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int sem;
	key_t key;

	if((key = ftok(".", 'B')) == -1){
		perror("ftok");
		exit(EXIT_FAILURE);	
	}
	if((sem = semget(key, 3, 0770|IPC_CREAT)) == -1){ // create sem set,contain 3 
		perror("semget");
		exit(EXIT_FAILURE);
	}
	printf("sem id is:%d\n",sem);
	semctl(sem, 0, IPC_RMID, (struct semqid_ds *)0);
	
	return 0;	
}

