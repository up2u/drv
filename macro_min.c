#include <stdio.h>

#define min(x, y) ({ \
const typeof(x) _x = (x); \
const typeof(y) _y = (y); \
(void) (&_x == &_y); \
_x < _y ? _x : _y;})

/* the "void &_x==&_y" is to check the type if consistent ! how it work? */

int main()
{
	int a = 5;
	float b = 4.3;
	int c = min(a,b);
	printf("the min is %d\n",c);
}

