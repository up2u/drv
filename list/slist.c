#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int is_empty(slist l)
{
  return l == NULL;
}

int is_last(slist l, position p)
{
  return p->next == NULL;
}

position find(slist l, elem_type elm)
{
  slist pl = l;

  while (pl != NULL && pl->elm != elm)
  {
    pl = pl->next;
  }

  return pl;
}

position find_prev(slist l, elem_type elm)
{
  slist pl = l;

  // if elm is 1st, return NULL
  // if elm not exist , return NULL
  // else return previous position
  position pre = NULL;
  while (NULL != pl && pl->elm != elm)
  {
    pre = pl;
    pl = pl->next;
  }
  // not the last one
  if (NULL == pl)
    return NULL;

  return pre;
}

int insert(slist *l, elem_type elm)
{
  ptr_snode ptr = (ptr_snode)malloc(sizeof(snode));

  ptr->elm = elm;

  ptr->next = *l;
  *l = ptr;
}

int length(slist l)
{
  int len = 0;

  while (l)
  {
    len++;
    l = l->next;
  }

  return len;
}

void delete(slist *l, elem_type elm)
{
  slist pl = *l;
  ptr_snode pre = *l;

  while (pl != NULL && pl->elm != elm)
  {
    pre = pl;
    pl = pl->next;
  }

  if (pl == *l)
  { // the 1st one, need update list header
    ptr_snode tmp = pl->next;
    *l = tmp;
  } else
  { // in mid
    pre->next = pl->next;
  }

  free(pl);
  pl->next = NULL;
}

void trace_slist(slist l)
{
  while (l)
  {
    printf("the elem is %d\n", l->elm);
    l = l->next;
  }
}

int main()
{
  slist plist = NULL;
  elem_type e1 = 1;
  elem_type e2 = 2;
  elem_type e3 = 3;

  insert(&plist, e1);
  insert(&plist, e2);
  insert(&plist, e3);

  position p1 = NULL;

  printf("length is %d\n", length(plist));

  // not find
  p1 = find_prev(plist, 4);
  if (p1)
  {
    printf("find previous, and it's elem is %d\n", p1->elm);
  } else
  {
    printf("not find previous\n");
  }

  // the 1st one, not find
  p1 = find_prev(plist, 3);
  if (p1)
  {
    printf("find previous, and it's elem is %d\n", p1->elm);
  } else
  {
    printf("not find previous\n");
  }

  // find
  p1 = find_prev(plist, 2);
  if (p1)
  {
    printf("find previous, and its elem is %d\n", p1->elm);
  } else
  {
    printf("not find previous\n");
  }

  // find
  p1 = find_prev(plist, 1);
  if (p1)
  {
    printf("find previous, and its elem is %d\n", p1->elm);
  } else
  {
    printf("not find previous\n");
  }

  trace_slist(plist);
  delete(&plist, 2);
  trace_slist(plist);

  return 0;
}
