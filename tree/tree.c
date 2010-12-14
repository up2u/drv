#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/*------------------------------( )--------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void create_tree(btree **root)
{
	char ch;
	if((ch=getchar()) == ' '){/*how many times input,so that it can exit from the recursive function??
							   times=2*lines+1,(an line has one charENTER,without blank between char and ENTER)
							   2*lines is the protocol of return from recursive function*/

		*root = NULL;	
	}else{
		*root = (btree *)malloc(sizeof(btree));
		(*root)->data = ch;
		create_tree(&((*root)->lchild));
		create_tree(&((*root)->rchild));
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
		printf("preorder: [0x%X]%c\n", root->data, root->data);
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

