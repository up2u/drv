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

/* insert node2 after node1 */
#define ins_dlist_after(node1, node2) \
	(node2)->next = (node1)->next; \
	(node2)->next->prev = (node2); \
	(node2)->prev = (node1); \
	(node2)->prev->next = (node2)
	
/* insert node2 before node1 */
#define ins_dlist_before(node1, node2) \
	(node2)->prev = (node1)->prev; \
	(node2)->prev->next = (node2); \
	(node2)->next = (node1); \
	(node2)->next->prev = (node2)
	
/* insert to the tail of list */
#define ins_dlist_tail(head,node) ins_dlist_before(head, node)

/* insert to the head of list */
#define ins_dlist_head(head, node) ins_dlist_after(head, node)

#define del_dlist(node) \
	(node)->prev->next = (node)->next; \
	(node)->next->prev = (node)->prev

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

/* delete from general list */
#define del_gdlist(node) del_dlist(node)

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

/* get prev of general list*/
#define get_glist_prev(node) \
	(node)->prev

#endif

