#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void *sig1(void *arg);
void *sig2(void *arg);
void report(int sig);

int main(int argc, char *argv[])
{
	int i;
	void *status;
	pthread_t t1, t2;
	if(pthread_create(&t1, NULL, sig1, NULL) !=0 ){
		perror("pthread_create");
		exit(EXIT_FAILURE);	
	}	
	if(pthread_create(&t2, NULL, sig2, NULL) !=0 ){
		perror("pthread_create");
		exit(EXIT_FAILURE);	
	}	
	sleep(1);

	printf("this is parent, send SIGUSR1, SIGUSR2 to thread 1\n");
	if(pthread_kill(t1, SIGUSR1)){
		perror("pthread_kill");
		exit(EXIT_FAILURE);	
	}
	if(pthread_kill(t1, SIGUSR2)){
		perror("pthread_kill");
		exit(EXIT_FAILURE);	
	}
	
	printf("this is parent, send SIGUSR1, SIGUSR2 to thread 2\n");
	if(pthread_kill(t2, SIGUSR1)){
		perror("pthread_kill");
		exit(EXIT_FAILURE);	
	}
	if(pthread_kill(t2, SIGUSR2)){
		perror("pthread_kill");
		exit(EXIT_FAILURE);	
	}

	sleep(1);
	if(pthread_kill(t1, SIGKILL)){
		perror("pthread_kill");
		exit(EXIT_FAILURE);	
	}
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}

void *sig1(void *arg)
{
	int i;
	sigset_t set;
	signal(SIGUSR1, report);
	sigfillset(&set);
	sigdelset(&set, SIGUSR2);
	pthread_sigmask(SIG_SETMASK, &set, NULL);
	for(i=0; i<5; i++){
		printf("thread 1:     set mask(%u)\n", pthread_self());	
		pause();
	}
}

void report(int sig)
{
	printf("in thread %u, the sig=%d\n", pthread_self(), sig);	
}

void *sig2(void *sig)
{
	int i;
	signal(SIGUSR2, report);
	for(i=0; i<5; i++){
		printf("thread 2: not set mask(%u)\n", pthread_self());	
		pause();
	}
}

