#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void cleanup()
{
	printf("clean up \n");		
}

void *test_cancel(void)
{
	pthread_cleanup_push(cleanup, NULL);  // push function cleanup() to stack
	printf("test_cancel\n");
	while(1){
		printf("test message\n");	
		sleep(1);
	}
	pthread_cleanup_pop(1);   // non-zero means pop stack && execute cleanup()
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, (void *)test_cancel, NULL);
	sleep(2);
	pthread_cancel(tid);
	pthread_join(tid, NULL);
}

