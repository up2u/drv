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
	if((ch=getchar()) == '\n'){
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
		printf("preorder: %c\n", root->data);
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

