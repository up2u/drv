#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/*------------------------------create_tree()recursive------------------------
* Function: create_tree
* Purpose: create bin tree, and the elem is from array,use recursive function
*          and is ordered by size from lchild to rchild
* Parameters:
*         root(IN) -- the address of tree point
*         e(IN) -- the element will be insert to tree
* Return: 
*-----------------------------------------------------------------------------*/
void create_tree(btree **root, telemtype e)
{
	if(*root == NULL){
	   *root = (btree *)malloc(sizeof(btree));
	   if(!*root){
		  exit(-1);  
	   }	
	   (*root)->data = e;
	   (*root)->lchild = NULL;
	   (*root)->rchild = NULL;
	}else{
		if(e < (*root)->data){/*less than root*/
			create_tree(&(*root)->lchild, e);		

		}else{
			create_tree(&(*root)->rchild, e);		
		}
	}
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void preorder_tree(btree *root)
{
	if(root != NULL){
		printf("preorder: %d\n", root->data);
		preorder_tree(root->lchild);	
		preorder_tree(root->rchild);	
	}
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool inorder_tree()
{
	
}

/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
bool postorder_tree()
{
	
}

