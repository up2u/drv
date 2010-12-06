#ifndef _LINK_OPERATION_H_
#define _LINK_OPERATION_H_

struct dlink_list
{
	struct dlink_list *next;
	struct dlink_list *prev;	
};

#define init_list(node) \
	(node)->next = (node); \
    (node)->prev = (node)

#define ins_list(head,node) \
	(head)->prev->next = (node); \
	(node)->prev = (head)->prev; \
	(node)->next = head; \
	(head)->prev = (node)

#define del_list(node) \
	(node)->prev->next = (node)->next; \
	(node)->next = (node)->prev->next
	
#endif
