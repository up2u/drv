#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;
pthread_mutex_t work_mutex;

void *thread_fun(void *arg);

int main(int argc, char *argv[])
{
	int res;
	pthread_t tid;
	void *thread_result;
	res = pthread_mutex_init(&work_mutex, NULL);
	if(res != 0){
		perror("pthread_mutex_init");	
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&tid, NULL, thread_fun, NULL);
	if(res != 0){
		perror("pthread_create");	
		exit(EXIT_FAILURE);
	}
	pthread_mutex_lock(&work_mutex);
	printf("input some textm, Enter 'end' to finish\n");
	while(!time_to_exit){
		fgets(work_area, WORK_SIZE, stdin);
		pthread_mutex_unlock(&work_mutex);
		while(1){
			pthread_mutex_lock(&work_mutex);
			if(work_area[0] != '\0'){
				pthread_mutex_unlock(&work_mutex);
				sleep(1);
			}else{
				break;	
			}
		}	
	}
	pthread_mutex_unlock(&work_mutex);
	printf("waiting for thread to finish..\n");
	res = pthread_join(tid, &thread_result);
	if(res != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);	
	}
	printf("thread joined \n");
	pthread_mutex_destroy(&work_mutex);
	exit(EXIT_SUCCESS);
}

void *thread_fun(void *arg)
{
	sleep(1);
	pthread_mutex_lock(&work_mutex);
	while(strncmp(work_area, "end", 3) != 0){
		printf("you input %d characters:%s\n", strlen(work_area)-1, work_area);	 // strlen()-1('\n')
		work_area[0] = '\0';
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
		pthread_mutex_lock(&work_mutex);
		while(work_area[0] == '\0'){
			pthread_mutex_unlock(&work_mutex);	
			sleep(1);
			pthread_mutex_lock(&work_mutex);	
		}
	}	
	time_to_exit = 1;
	work_area[0] = '\0';
	pthread_mutex_unlock(&work_mutex);
	pthread_exit(0);
}

