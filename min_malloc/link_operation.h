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

#define init_dlist(node) \
	(node)->next = (node); \
    (node)->prev = (node)

/* inser to the tail of head */
#define ins_dlist_tail(head,node) \
	(head)->prev->next = (node); \
	(node)->prev = (head)->prev; \
	(node)->next = head; \
	(head)->prev = (node)

#define del_dlist(node) \
	(node)->prev->next = (node)->next; \
	(node)->next = (node)->prev->next


/**************************************
 * 
 * singly link list.  
 *
 **************************************/

#define ins_slist_head(head, node) \
	(node)->next = (head)->next; \
	(head)->next = (node)

/**************************************
 * 
 * general singly link list
 *
 **************************************/

#define ins_gslist_head(head, node) \
	(node)->next = (head)->next; \
	(head)->next = (node)
	
#endif

