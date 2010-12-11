#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool init_queue(linkqueue *q)
{
	q->front = q->rear = (qpoint)malloc(sizeof(qnode));
	if(!q->front){
		return false;
	}
	q->front->next = NULL;
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
bool enqueue(linkqueue *q, qelemtype e)
{
	qpoint ptr = (qpoint)malloc(sizeof(qnode));
	q->front->next = ptr;
	q->front = ptr; /*move front point forward*/
	q->front->data = e;
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool print(linkqueue *q)
{
	qpoint ptr = q->rear;

	if(q->front == q->rear){
		return false;
	}
	while(q->rear->next != NULL){
		printf("the queue input is %d\n", q->rear->next->data);
		q->rear = q->rear->next;
	}
	q->rear = ptr;
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
bool traverse(linkqueue *q, bool (* visit)(linkqueue *q1))
{
	return (visit)(q);
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool dequeue(linkqueue *q, qelemtype *e)
{
	if(q->front == q->rear){
		return false;
	}
	*e = q->rear->next->data;
	q->rear = q->rear->next; /*move rear point forward*/
}

