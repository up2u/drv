#ifndef	 _TREE_H_
#define  _TREE_H_

#include <stdbool.h>

typedef int qelemtype;

typedef struct btree
{
	qelemtype data;
	struct btree *lchild;
	struct btree *rchild;
}btree;

#endif

