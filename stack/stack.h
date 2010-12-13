#ifndef _STACH_H_
#define _STACH_H_

#include <stdbool.h>

typedef long long selemtype;

typedef struct sqstack
{
	selemtype *base;
	selemtype *top;
	int stacksize;
}sqstack;

bool init_stack(sqstack *s);
bool push(sqstack *s, selemtype e);
bool pop(sqstack *s, selemtype *e);
bool print(sqstack *s);
bool traverse(sqstack *s, bool (* visit)(sqstack *pstack));

#endif
