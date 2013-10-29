#include <stdio.h>
#include <stdlib.h>
#include "queue2.h"

#define MAX_QUEUE_SIZE 2

ptrqueue_record create_queue(void)
{
  ptrqueue_record q = NULL;

  q = (ptrqueue_record)malloc(sizeof(queue_record));
  if (!q)
  {
    printf("fatal error\n");
    return NULL;
  }
  q->array = (elemtype *)malloc(MAX_QUEUE_SIZE * sizeof(elemtype));
  if (!q->array)
  {
    printf("fatal error\n");
    goto free1;
  }

  q->front = q->rear = q->size = 0;
  return q;

free1:
  free(q);
  return NULL;
}

void enqueue(ptrqueue_record q, elemtype x)
{
  if (is_full(q))
  {
    printf("is full\n");
  }
  else
  {
    q->array[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->size++;
  }
}

void dequeue(ptrqueue_record q)
{
  if (is_empty(q))
  {
    printf("is empty\n");
    return;
  }

  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  q->size--;
}

int is_full(ptrqueue_record q)
{
  return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int is_empty(ptrqueue_record q)
{
  return q->front == q->rear;
}

elemtype front_elem(ptrqueue_record q)
{
  if (is_empty(q))
  {
    printf ("is empty\n");
    return -1;
  }

  return q->array[q->front];
}
