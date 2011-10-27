#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
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
	struct my_msg_st some_data;
	int msgid;
	char buff[BUFSIZE];

	// creat msg queue !?
	if((msgid=msgget((key_t)12345, 0666|IPC_CREAT)) == -1){
		perror("msgget");	
		exit(EXIT_FAILURE);
	}
	while(running){
		printf("Enter message to send:");
		fgets(buff, BUFSIZE, stdin);
		some_data.type = 1;
		strcpy(some_data.msg, buff);

		if((msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0)) == -1){
			perror("msgsnd");	
			exit(EXIT_FAILURE);
		}
		if(strncmp(buff, "end", 3) == 0){
			running = 0;	
		}
	}

	return 0;	
}

