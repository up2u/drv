#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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


/*------------------------------create_tree1()--------------------------------
* Function:create_tree1
* Purpose:not use recursive function to create a tree, order by size, from left 
*         to right child.
* Parameters:
*		  root(IN) -- address of tree point
*         e(IN) -- element will be insert to tree.
* Return:
*-----------------------------------------------------------------------------*/
void create_tree1(btree **root, telemtype e)
{
	btree *ptr = NULL;
	btree *ptr1 = NULL;
	if((*root) == NULL){
		if(!((*root) = (btree *)malloc(sizeof(btree)))){
			exit(-1);	
		}
		(*root)->data = e;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
	}else{
		ptr = *root;
		if(e < (*root)->data){/*left tree*/
			while((*root) != NULL && e < (*root)->data){
				ptr1 = *root;
				(*root) = (*root)->lchild;
				while((*root) != NULL && e > (*root)->data){
					ptr1 = *root;
					(*root) = (*root)->rchild;
				}
			}
		}else{/*right tree*/
			while((*root) != NULL && e >= (*root)->data){
				ptr1 = *root;
				(*root) = (*root)->rchild;
				while((*root) != NULL && e < (*root)->data){
					ptr1 = *root;
					(*root) = (*root)->lchild;
				}
			}
		}

		if(e < ptr1->data){/*insert to lchild*/
			if(!((ptr1->lchild) = (btree *)malloc(sizeof(btree)))){
				exit(-1);	
			}
			ptr1->lchild->data = e;
			ptr1->lchild->lchild = NULL;
			ptr1->lchild->rchild = NULL;
		}else{/*insert to rchild*/
			if(!((ptr1->rchild) = (btree *)malloc(sizeof(btree)))){
				exit(-1);	
			}
			ptr1->rchild->data = e;
			ptr1->rchild->lchild = NULL;
			ptr1->rchild->rchild = NULL;
		}
		*root = ptr;
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
;	
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

