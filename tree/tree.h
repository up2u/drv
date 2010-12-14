#ifndef	 _TREE_H_
#define  _TREE_H_

#define  MAX_TREE_NODE 100

typedef int telemtype;

typedef struct btree
{
	telemtype data;
	struct btree *lchild;
	struct btree *rchild;
}btree;

typedef struct tstack
{
	btree *root[MAX_TREE_NODE];
	unsigned char flag[MAX_TREE_NODE];
	int top;
}tstack;

#endif

