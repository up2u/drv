#include <stdio.h>

int main()
{
	/*enum colors is a type*/
	enum colors {red, orange, yellow, green, blue};/*when not init the elem ,start from 0.red=0,blue=4*/
	enum colors testcolor;

	for(testcolor=red; testcolor<blue; testcolor++){
		printf("testcolor is %d\n", testcolor);
	}
	
	return 0;
}
