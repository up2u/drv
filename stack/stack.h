#ifndef _STACH_H_
#define _STACH_H_

typedef int selemtype;

typedef struct sqstack
{
	selemtype *base;
	selemtype *top;
	int stacksize;
}sqstack;

#endif
