#ifndef	 _BLOCK_H_
#define  _BLOCK_H_

typedef	unsigned int uint;

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
	struct   block *prev;
	struct   block *free_next;
	struct   block *free_prev;
	struct   block *malloc_next;
	struct   block *malloc_prev;		
	struct 	 gslist list;
};

#endif

