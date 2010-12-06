#ifndef	 _BLOCK_H_
#define  _BLOCK_H_

typedef	unsigned int uint;

struct block
{
	unsigned char flag;
	uint	 size;
	struct   block *next;
	struct   block *previous;
	struct   block *free_next;
	struct   block *free_previous;
	struct   block *malloc_next;
	struct   block *malloc_previous;		
};

#endif

