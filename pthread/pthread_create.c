#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct message
{
	int i;
	int j;
};

int hello(struct message *str)
{
	printf("the arg.i is %d\n", str->i);
	printf("the arg.j is %d\n", str->j);
	printf("thread sleep now\n");
	sleep(10);
}

int main()
{
	struct message test;
	pthread_t thread_id;
	test.i = 10;
	test.j = 20;
	pthread_create(&thread_id, NULL, (void *)hello, &test);
	printf("the new thread_id is %u\n", thread_id);
	pthread_join(thread_id, NULL);
	printf("main thread return now\n");
	return 0;
}


