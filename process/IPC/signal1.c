#include <signal.h>
#include <stdio.h>

void handler(int sig)
{
	signal(sig, handler);
	switch(sig){
		case SIGHUP:
		printf("get a signal SIGHUP\n");	
		break;
		case SIGINT:
		printf("get a signal SIGINT\n");	
		printf("sig is %d\n", sig);
		break;
		case SIGQUIT:
		printf("get a signal SIGQUIT\n");	
		break;
		default:
		printf("get a other signal\n");
	}
}

int main()
{
	signal(SIGINT, handler);

	printf("main function\n");
	while(1);
	return 0;	
}
