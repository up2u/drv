#ifndef	 _TREE_H_
#define  _TREE_H_

#include <stdbool.h>

typedef int telemtype;

typedef struct btree
{
	telemtype data;
	struct btree *lchild;
	struct btree *rchild;
}btree;

#endif

