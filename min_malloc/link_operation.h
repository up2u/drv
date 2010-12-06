#ifndef _LINK_OPERATION_H_
#define _LINK_OPERATION_H_

#define offsetof(TYPE, MEMBER) (size_t)&(((TYPE *)0)->MEMBER)
#define container_of(TYPE, MEMBER, ADDR) (size_t)((size_t)ADDR - offsetof(TYPE,MEMBER))

struct dlink_list
{
	struct dlink_list *next;
	struct dlink_list *prev;	
};

/**************************************
 * 
 * double circular link list.  
 *
 **************************************/

#define init_list(node) \
	(node)->next = (node); \
    (node)->prev = (node)

/* inser to the tail of head */
#define ins_list(head,node) \
	(head)->prev->next = (node); \
	(node)->prev = (head)->prev; \
	(node)->next = head; \
	(head)->prev = (node)

#define del_list(node) \
	(node)->prev->next = (node)->next; \
	(node)->next = (node)->prev->next


/**************************************
 * 
 * singly link list.  
 *
 **************************************/

#define ins_list_sgl(head, node) \
	(node)->next = (head)->next; \
	(head)->next = (node)

/**************************************
 * 
 * general singly link list
 *
 **************************************/

#define gslist_add_head(head, node) \
	(node)->next = (head)->next; \
	(head)->next = (node)
	
#endif

