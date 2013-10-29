#include <stdio.h>
#include "queue2.h"

int main()
{
  ptrqueue_record q = NULL;

  q = create_queue();

  if (!q)
  {
    printf("create queue fatal error\n");
    return -1;
  }

  enqueue(q, 11);
  printf("queue size is %d\n", q->size);
  printf("front elem is %d\n", front_elem(q));

  enqueue(q, 22);
  printf("queue size is %d\n", q->size);
  printf("front elem is %d\n", front_elem(q));

  dequeue(q);
  printf("queue size is %d\n", q->size);
  printf("front elem is %d\n", front_elem(q));

  enqueue(q, 33);
  printf("queue size is %d\n", q->size);
  printf("front elem is %d\n", front_elem(q));

  enqueue(q, 44);
  printf("queue size is %d\n", q->size);
  printf("front elem is %d\n", front_elem(q));

  return 0;
}
