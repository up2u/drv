#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
static pthread_rwlock_t rwlock;

int time_to_exit;
void *thread_read1(void *arg);
void *thread_read2(void *arg);
void *thread_write1(void *arg);
void *thread_write2(void *arg);

int main(int argc, char *argv[])
{
	int res;
	pthread_t t1, t2, t3, t4;
	void *thread_result;
	
	res = pthread_rwlock_init(&rwlock, NULL);	
	if(res != 0){
		perror("pthread_rwlock_init");
		exit(EXIT_FAILURE);	
	}
	res = pthread_create(&t1, NULL, thread_read1, NULL);
	if(res != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);	
	}
	res = pthread_create(&t2, NULL, thread_read2, NULL);
	if(res != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);	
	}
	res = pthread_create(&t3, NULL, thread_write1, NULL);
	if(res != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);	
	}
	res = pthread_create(&t4, NULL, thread_write2, NULL);
	if(res != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);	
	}
	res = pthread_join(t1, &thread_result);
	if(res != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);	
	}
	res = pthread_join(t2, &thread_result);
	if(res != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);	
	}
	res = pthread_join(t3, &thread_result);
	if(res != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);	
	}
	res = pthread_join(t4, &thread_result);
	if(res != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);	
	}
	pthread_rwlock_destroy(&rwlock);
	exit(EXIT_SUCCESS);
}

void *thread_read1(void *arg)
{
	printf("thread read-1 try to get lock\n");
	pthread_rwlock_rdlock(&rwlock);
	while(strncmp(work_area, "end", 3) != 0){
		printf("thread read-1 read: %s\n", work_area);
		pthread_rwlock_unlock(&rwlock);
		sleep(2);
		pthread_rwlock_rdlock(&rwlock);
		while(work_area[0] == '\0'){  // !!!
			pthread_rwlock_unlock(&rwlock);
			sleep(2);
			pthread_rwlock_rdlock(&rwlock);
		}
	}
	pthread_rwlock_unlock(&rwlock);
	time_to_exit = 1;
	pthread_exit(0);
}

void *thread_read2(void *arg)
{
	printf("thread read-2 try to get lock\n");
	pthread_rwlock_rdlock(&rwlock);
	while(strncmp(work_area, "end", 3) != 0){
		printf("thread read-2 read: %s\n", work_area);
		pthread_rwlock_unlock(&rwlock);
		sleep(5);
		pthread_rwlock_rdlock(&rwlock);
		while(work_area[0] == '\0'){  // !!!
			pthread_rwlock_unlock(&rwlock);
			sleep(2);
			pthread_rwlock_rdlock(&rwlock);
		}
	}
	pthread_rwlock_unlock(&rwlock);
	time_to_exit = 1;
	pthread_exit(0);
}

void *thread_write1(void *arg)
{
	while(!time_to_exit){
		pthread_rwlock_wrlock(&rwlock);
		printf("thread write-1  get lock\n");
		printf("thread write-1, input sth Enter 'end' to finish :");
		fgets(work_area, WORK_SIZE, stdin);
		pthread_rwlock_unlock(&rwlock);
		sleep(15);
	}
	printf("thread write-1 time to exit\n");
	pthread_rwlock_unlock(&rwlock);  // ?? no match lock ?
	pthread_exit(0);
}

void *thread_write2(void *arg)
{
	sleep(10);
	while(!time_to_exit){
		pthread_rwlock_wrlock(&rwlock);
		printf("thread write-2  get lock\n");
		printf("thread write-2, input sth Enter 'end' to finish :");
		fgets(work_area, WORK_SIZE, stdin);
		pthread_rwlock_unlock(&rwlock);
		sleep(20);
	}
	printf("thread write-2 time to exit\n");
	pthread_rwlock_unlock(&rwlock);  // ?? no match lock ?
	pthread_exit(0);
}
