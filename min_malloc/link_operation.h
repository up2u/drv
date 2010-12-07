#ifndef _LINK_OPERATION_H_
#define _LINK_OPERATION_H_

/* for general link list */
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

/* inser to the tail of list */
#define ins_dlist_tail(head,node) \
	(head)->prev->next = (node); \
	(node)->prev = (head)->prev; \
	(node)->next = head; \
	(head)->prev = (node)

/* insert to the head of list */
#define ins_dlist_head(head, node) \
	(head)->next->prev = (node); \
	(node)->next = (head)->next; \
	(head)->next = (node); \
	(node)->prev = (head)

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
 * general double circular link list
 *
 **************************************/

/* insert to tail of list */
#define ins_gdlist_tail(head, node) ins_dlist_tail(head, node)

/* insert to head of list */
#define ins_gdlist_head(head, node) ins_dlist_head(head, node)

/**************************************
 * 
 * general singly link list
 *
 **************************************/

/* insert to head of list */
#define ins_gslist_head(head, node) ins_slist_head(head, node)

/* get first of general list */
#define get_glist_head(head) \
	(head)->next
	
/* get next of general list */
#define get_glist_next(node) \
	(node)->next

#endif

