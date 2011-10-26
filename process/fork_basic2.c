#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	int i = 0;
	pid_t fpid = 0;
	printf("idx\t\tppid\t\tpid\t\tfpid\n");
	for(i=0; i<2; i++){
		fpid = fork();	
		if(fpid == 0){
			printf("%d:chi\t\t%d\t\t%d\t\t%d\n",i,getppid(),getpid(),fpid);	
		}else{
			printf("%d:par\t\t%d\t\t%d\t\t%d\n",i,getppid(),getpid(),fpid);	
		}
	}

	return 0;	
}

