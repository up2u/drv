#ifndef _CIRQUEUE_H_
#define _CIRQUEUE_H_

#include <stdbool.h>

typedef int qelemtype;

typedef struct 
{
	qelemtype *base;
	int front;
	int rear;	
}cqueue;

bool init_queue(cqueue *q);
bool enqueue(cqueue *q, qelemtype e);
bool dequeue(cqueue *q, qelemtype *e);
bool print(cqueue *q);
bool traverse(cqueue *q, bool (* visit)(cqueue *q1));

#endif
