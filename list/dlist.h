#ifndef __DLIST_H__
#define __DLIST_H__

typedef int elem_type;

typedef struct dnode
{
  elem_type elm;
  struct dlist *prev;
  struct dlist *next;
} dnode;

typedef dlist *ptr_node;
typedef ptr_node dlist;

#endif // __DLIST_H__
