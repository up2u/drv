#ifndef _QUEUE2_H_
#define _QUEUE2_H_

typedef int elemtype;
typedef struct
{
  elemtype *array;
  int front;
  int rear;
  int size;
} queue_record;
typedef queue_record * ptrqueue_record;

ptrqueue_record create_queue(void);
void enqueue(ptrqueue_record q, elemtype x);
void dequeue(ptrqueue_record q);
int is_full(ptrqueue_record q);
int is_empty(ptrqueue_record q);
elemtype front_elem(ptrqueue_record q);

#endif // _QUEUE2_H_
