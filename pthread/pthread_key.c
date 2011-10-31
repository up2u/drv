#include <pthread.h>
#include <stdio.h>

/* protoi type:
*  void *pthread_getspecific(pthread_key_t key);
*  int   pthread_setspecific(pthread_key_t key, const void *value);
*/


pthread_key_t key;
void echomsg(void *t)
{
	printf("destructor executed in thread %u, parameter: 0x%x\n", pthread_self(),t);	
}

void *child1(void *arg)
{
	int i = 10;
	int tid=pthread_self();	
	printf("set key value %d in thread %u\n", i, tid);
	pthread_setspecific(key, &i);
	printf("child 1 sleep 2 until child 2 finish\n");
	sleep(2);
	printf("thread %u return %d, add is 0x%x\n", tid, *(int *)pthread_getspecific(key), pthread_getspecific(key));
}

void *child2(void *arg)
{
	int k = 20;
	int tid=pthread_self();	
	printf("set key value %d in thread %u\n", k, tid);
	pthread_setspecific(key, &k);
	printf("thread %u return %d, add is 0x%x\n", tid, *(int *)pthread_getspecific(key), pthread_getspecific(key));
}

int main(int argc, char *argv[])
{
	pthread_t tid1, tid2;
	// &key as the parameter of echomsg(void *t)
	pthread_key_create(&key, echomsg);  // echomsg() execute when last thread exit ??
	pthread_create(&tid1, NULL, child1, NULL);
	pthread_create(&tid2, NULL, child2, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_key_delete(key);
	return 0;
}

