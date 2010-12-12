#include <stdio.h>
#include <stdbool.h>

int main()
{
	enum grade {common=1, better=5, best=9};
	enum grade system;
	bool grade_match;
	int i = 0;
	char instring[10] = {'\0'};
	const char *grade_array[3] = {"common","better", "best"};	
	
	system = best;
	
	printf("please enter the grade: one of (common, better, best), or ENTER to end\n");
	while(gets(instring) != NULL && instring[0] != '\0'){
		for(i=0; i<3; i++){
			if(strcmp(instring, grade_array[i]) == 0){
				grade_match = true;
				if(i == 0){
					system = common;
				}
				if(i == 1){
					system = better;
				}
				if(i == 2){
					system = best;
				}
				break;
			}
		}
		if(grade_match){
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
				
			grade_match = false;	
		}else{
			printf("not find ,please enter next grade or ENTER to end\n");
			continue;	
		} 
	}
	printf("end of input\n");
	return 0;
}

