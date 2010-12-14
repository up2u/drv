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
	if((ch=getchar()) == '\n'){/*times of input ENTER to exit from recursive function 
		                         it's different from  the previous example when use ' ', 
								 when input charENTER,that every time:recursive 1/2,both
								 be gone through,so not need to 2*lines ,and once continuous 
								 input 2 ENTER, it will exit !!*/
		*root = NULL;	
	}else{
		*root = (btree *)malloc(sizeof(btree));
		(*root)->data = ch;
		create_tree(&((*root)->lchild)); /*recursive 1 */
		create_tree(&((*root)->rchild)); /*recursive 2 */
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

