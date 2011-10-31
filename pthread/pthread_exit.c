#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *helloword(char *arg)
{
	int *p;
	p = (int *)malloc(10*sizeof(int));
	printf("the message give thread is: %s\n", arg);
	printf("the thread id is %u\n", pthread_self());
	memset(p, 'c', 10);
	printf("address:p=0x%x\n", p);
	pthread_exit(p); // use address p as the return value
}

int main(int argc, char *argv[])
{
	int error;
	int *temptr;
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, (void *)helloword, "hellotoyou");
	// compare 2 mode of function address
	printf("*fun = 0x%x, fun = 0x%x\n", *helloword, helloword);
	if((error = pthread_join(thread_id, (void **)&temptr)) == -1){
		perror("pthread_join");	
		exit(EXIT_FAILURE);
	}
	printf("return address:=0x%x, the char in the address *temp=%c\n", temptr, *temptr);
	*temptr = 'd';
	printf("after set a new char: %c\n", *temptr);
	free(temptr);
	return 0;
}

