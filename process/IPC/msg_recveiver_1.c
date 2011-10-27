#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT 512
#define BUFSIZE  128

struct my_msg_st
{	
	int type;
	char msg[MAX_TEXT];
};

int main(int argc, char *argv[])
{
	int running = 1;
	int msgid;
	char buff[BUFSIZE];
	struct my_msg_st some_data;
	some_data.type = 0;

	if((msgid=msgget((key_t)12345, 0666|IPC_CREAT)) == -1){
		perror("msgget");	
		exit(EXIT_FAILURE);
	}
	while(running){
		if(msgrcv(msgid, (void *)&some_data, MAX_TEXT, some_data.type, 0) == -1){
			perror("msgrcv");
			exit(EXIT_FAILURE);
		}	
		if((strncmp(some_data.msg,"end", 3)) == 0){
			running = 0;
		}
		printf("receive message: %s", some_data.msg);
  		memset(some_data.msg, '\0', sizeof(some_data.msg));
	}
	
	if((msgctl(msgid, IPC_RMID, 0)) == -1){
		printf("msgclt (IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
		
	return 0;	
}

