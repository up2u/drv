#include <stdio.h>
#include <signal.h>

void sigterm_handler(int signo)
{
	printf("Have caught sign NO.%d\n",signo);	
	exit(0);
}

int main()
{
		printf("start \n");
		signal(SIGINT, sigterm_handler);
		signal(SIGTERM, sigterm_handler);
		while(1);

		return 0;	
}

