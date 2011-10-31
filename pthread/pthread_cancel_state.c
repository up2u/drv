#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *thread_fun(void *arg);
int main(int argc, char *argv[])
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	if(pthread_create(&a_thread, NULL, thread_fun, NULL) != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	sleep(2);
	printf("now cancelling thread...\n");
	res = pthread_cancel(a_thread);
	if(res != 0){
		perror("pthread_cancel");
  	    exit(EXIT_FAILURE);	
	}
	printf("waiting for thread to finish ..\n");
	res = pthread_join(a_thread, &thread_result);
	if(res != 0){
		perror("pthread_join");
  	    exit(EXIT_FAILURE);	
	}
	exit(EXIT_SUCCESS);
}

void *thread_fun(void *arg)
{
	int i, j ,res;
	sleep(1);
	res = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	if(res != 0){
		perror("pthread_setcancelstate");
  	    exit(EXIT_FAILURE);	
	}
	sleep(3);
	printf("thread cancel state is disable, can't cancel this thread\n");
	for(i=0; i<3; i++){
		printf("thread is running, (%d)..\n", i);
		sleep(1);	
	}
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if(res != 0){
		perror("pthread_setcancelstate");
  	    exit(EXIT_FAILURE);	
	}else{
		printf("now change the cancel state is ENABLE\n");
		sleep(200);	
		pthread_exit(0);
	}
}

