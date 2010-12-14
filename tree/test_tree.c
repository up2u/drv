#include <stdio.h>
#include "tree.h"

int main()
{
	btree *root;
	create_tree(&root);

	preorder_tree(root);
	return 0;
}

