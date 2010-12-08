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

#endif

