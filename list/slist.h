#ifndef __SLIST_H__
#define __SLIST_H__

typedef int elem_type;

typedef struct snode
{
  elem_type elm;
  struct snode *next;
} snode;

typedef snode *ptr_snode;

typedef ptr_snode position;
typedef ptr_snode slist;

int is_empty(slist l);
int is_last(slist l, position p);
position find(slist l, elem_type elm);
position find_prev(slist l, elem_type elm);

#endif // __SLIST_H__
