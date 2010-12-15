#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include "cirqueue.h"


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

cqueue q;
int a = 1; /*accumulator for create_tree2( )*/
btree *subroot = NULL;
/*------------------------------create_tree2( )--------------------------------
* Function: create_tree2
* Purpose: create tree according to level,from left to right child
*          use queue to store the root, so that the subroot every time get from
*          queue will in order.!!
*
* Parameters:root(IN) -- address of tree point
*            e(IN) -- element
* Return: void
*-----------------------------------------------------------------------------*/
void create_tree2(btree **root, telemtype e)
{
	btree *ptr = NULL;
	if(*root == NULL){
		if(!(*root = (btree *)malloc(sizeof(btree)))){
			exit(-1);
		}
		(*root)->data = e;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
		init_queue(&q);
		enqueue(&q, *root);
		a++;
	}else{
			if(a%2 == 0){
				dequeue(&q, &subroot);
			}
			if(a%2 == 0){/*left child*/
				if(!(ptr = (btree *)malloc(sizeof(btree)))){
					exit(-1);
				}
				ptr->data = e;
				ptr->lchild = NULL;
				ptr->rchild = NULL;
				subroot->lchild = ptr;
				enqueue(&q,ptr);
				a++;
			}else{/*right child*/
				if(!(ptr = (btree *)malloc(sizeof(btree)))){
					exit(-1);
				}
				ptr->data = e;
				ptr->lchild = NULL;
				ptr->rchild = NULL;
				subroot->rchild = ptr;
				enqueue(&q,ptr);
				a++;
			}
	}
}

/*------------------------------preorder_tree()--------------------------------
* Function:preorder_tree
* Purpose: recursive.
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


/*------------------------------preorder_tree1()-------------------------------
* Function:preorder_tree1,(need to complete.!!)
* Purpose:not recursive, use stack to store the node point, and shoud del some  
*         unneeded node, and directory go to his parent node for go throuth his 
*         rchild,!!! 
* Parameters:
*
* Return:
*-----------------------------------------------------------------------------*/
void preorder_tree1(btree *root)
{
	btree *ptr = root;
	btree *proot[20] = {NULL};
	int top = 0;
	if(root){
		proot[top++] = root;
	}

	while(ptr != NULL && top != 0){/*while1: */
		printf("pre order, elem is %d\n", ptr->data);
		ptr = ptr->lchild;
		proot[top++] = ptr; /*push*/
		while(ptr == NULL && top != 0){/*while2:left tree */
			ptr = proot[--top]; /*pop NULL*/
			ptr = proot[--top]; /*del from stack of this node,so next will get his parent node*/
			ptr = ptr->rchild;
			proot[top++] = ptr;
			while(ptr == NULL && --top != 0){/*right tree NULL,
				                              if in right tree,when get lastest one top will equ -1 */
				ptr = proot[top];/*pop NULL*/	
				ptr = proot[--top];
				ptr = ptr->rchild;
				proot[top++] = ptr;
			}
		}
	}
}

/*------------------------------preorder_tree2()-------------------------------
* Function: preorder_tree2, not use recursive, refer to net. quite smart.!!
* Purpose:
*
* Parameters:
*
* Return:
*-----------------------------------------------------------------------------*/
void preorder_tree2(btree *root)
{
	btree *ptr = root;
	btree *proot[20] = {NULL};
	int top = 0;
	
	while(ptr || top > 0){
		if(ptr){
			printf("pre2: elem is %d\n", ptr->data);
			proot[top++] = ptr;
			ptr = ptr->lchild;	
		}else{
			ptr = proot[--top]->rchild;	
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

