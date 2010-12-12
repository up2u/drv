#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cirqueue.h"

/*when can't estimate the size of queue, use link queue, else 
can use the following fixsize queue */

#define MAXQSIZE 5

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool init_queue(cqueue *q)
{
	q->base = (qelemtype *)malloc(sizeof(qelemtype) * MAXQSIZE);
	if(!q->base){
		return false;
	}
	q->rear = 0;
	q->front = 0;
	return true;
}


/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool enqueue(cqueue *q, qelemtype e)
{
	if((q->rear + 1)%MAXQSIZE == q->front){/*full*/
		return false;
	}
	*(q->base+q->rear) = e; /*en queue from rear.*/
	q->rear = (q->rear + 1)%MAXQSIZE;
	return true;
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool dequeue(cqueue *q, qelemtype *e)
{
	if(q->rear == q->front){/*empty*/
		return false;
	}
	*e = *(q->base + q->front);
	q->front= (q->front+1)%MAXQSIZE;
	return true;
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
int queue_length(cqueue *q)
{
	return (q->rear - q->front + MAXQSIZE)%MAXQSIZE;
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool print(cqueue *q)
{
	int t = q->front;
	if(q->rear == q->front){/*empty*/
		return false;
	}
	
	while(q->front != q->rear){ /* !! */
		printf("traverse elem : %d\n", *(q->base + q->front));
		q->front = (q->front + 1)%MAXQSIZE;
	}
	q->front = t;
	return true;
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool traverse(cqueue *q, bool (* visit)(cqueue *q1))
{
	return (visit)(q);
}

