#include <stdio.h>

int main()
{
	enum grade {common=1, better=5, best=9};
	enum grade system;

	//system = better;
	//system = 9;
	system = 10;
	switch(system)
	{
		case common: 
			printf("you are common\n");
			break;
		case better: 
			printf("you are better\n");
			break;
		case best: 
			printf("you are best\n");
			break;
		default:
			printf("not find\n");
			break;
	}
	
	for(system=common; system<=best; system++){/*when enum with discontinuous value, the elem handle it continuous*/
		printf("when with discontinuous value, grade: %d\n", system);
	}
	return 0;
}

