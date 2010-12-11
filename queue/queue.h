#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef int qelemtype;

typedef struct qnode
{
	qelemtype data;
	struct qnode *next;	
}qnode, *qpoint;

typedef struct 
{
	qpoint front;
	qpoint rear;
}linkqueue;

bool init_queue(linkqueue *q);
bool enqueue(linkqueue *q, qelemtype e);
bool print(linkqueue *q);
bool traverse(linkqueue *q, bool (* visit)(linkqueue *q1));
bool dequeue(linkqueue *q, qelemtype *e);

#endif
