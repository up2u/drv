#ifndef _STACH_H_
#define _STACH_H_

typedef long long selemtype;

typedef struct sqstack
{
	selemtype *base;
	selemtype *top;
	int stacksize;
}sqstack;

#endif
