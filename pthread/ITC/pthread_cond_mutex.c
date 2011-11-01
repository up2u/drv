#include <pthread.h>
#include <stdio.h>

#define BUFSIZE 2

struct prodcons
{
	int buffer[BUFSIZE];
	pthread_mutex_t lock;
	int readpos;
	int writepos;
	pthread_cond_t notempty;
	pthread_cond_t notfull;
};

void init(struct prodcons *prod)
{
	pthread_mutex_init(&prod->lock, NULL);	
	pthread_cond_init(&prod->notempty, NULL);
	pthread_cond_init(&prod->notfull, NULL);
	prod->readpos = 0;
	prod->writepos = 0;
}

void put(struct prodcons *prod, int data)
{
	pthread_mutex_lock(&prod->lock);
	while((prod->writepos + 1) % BUFSIZE == prod->readpos){
		printf("producer wait for not full\n");	
		pthread_cond_wait(&prod->notfull, &prod->lock);
	}
	prod->buffer[prod->writepos] = data;
	prod->writepos = (prod->writepos + 1)% BUFSIZE;
	pthread_cond_signal(&prod->notempty);
	pthread_mutex_unlock(&prod->lock);
}

int get(struct prodcons *prod)
{
	int data;
	pthread_mutex_lock(&prod->lock);
	while(prod->writepos == prod->readpos){
		printf("consumer wait for not empty\n");
		pthread_cond_wait(&prod->notempty, &prod->lock);	
	}
	data = prod->buffer[prod->readpos];
	prod->readpos = (prod->readpos + 1) % BUFSIZE;
	pthread_cond_signal(&prod->notfull);
	pthread_mutex_unlock(&prod->lock);
	return data;
}

#define OVER (-1)
struct prodcons buffer;
void *producer()
{
	int n;
	for(n = 0; n <= 5; n++){
		printf("producer sleep 1 second ... \n");
		sleep(1);
		printf("put the %d product\n", n);
		put(&buffer, n);
	}
	for(n = 6; n <= 10; n++){
		printf("producer sleep 3 second ... \n");
		sleep(3);
		printf("put the %d product\n", n);
		put(&buffer, n);
	}
	put(&buffer, OVER);
	printf("producer stopped\n");
	return 0;
}

void *consumer()
{
	int d = 0;
	while(1){
		printf("consumer sleep 2 second ...\n");
		sleep(2);
		d = get(&buffer);
		printf("get the %d product\n", d);
		if(d == OVER)
			break;
	}
	printf("consumer stopped!\n");
	return 0;
}

int main(int argc, char *argv[])
{
	pthread_t th_a, th_b;
	void *retval;
	init(&buffer);
	pthread_create(&th_a, NULL, producer, 0);
	pthread_create(&th_b, NULL, consumer, 0);
	pthread_join(th_a, &retval);
	pthread_join(th_b, &retval);
	return 0;
}

