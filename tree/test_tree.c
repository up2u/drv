#include <stdio.h>
#include "tree.h"

int main()
{
	btree *root = NULL;
	int i = 0;
	telemtype tnode[9] = {8,6,10,4,7,9,11,12,5};
	for(i=0; i<9; i++){
		create_tree1(&root,tnode[i]);
	}

	postorder_tree(root);
	return 0;
}

