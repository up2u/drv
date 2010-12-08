#ifndef	 _BLOCK_H_
#define  _BLOCK_H_

#include <string.h>

typedef	unsigned int uint;

#define FREE 1
#define USED 0

struct gdlist
{
	struct gdlist *next;
	struct gdlist *prev;	
};

struct gslist
{
	struct gslist *next;
};

struct block
{
	unsigned char flag;
	uint	 size;
	struct   block *next;
	struct 	 block *prev;
	struct   gdlist list_free;
	struct 	 gdlist list_malloc;
};

#define size_block sizeof(struct block)

#define init_new_block(block) \
	(block)->next = NULL; \
	(block)->prev = NULL; \
	(block)->list_free.next = NULL; \
	(block)->list_free.prev = NULL; \
	(block)->list_malloc.next = NULL; \
	(block)->list_malloc.prev = NULL

#endif

