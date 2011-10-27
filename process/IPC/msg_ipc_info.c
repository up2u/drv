#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define  BUFSIZE  128

struct msg_buf
{
	long type;
	char msg[BUFSIZE];	
};

int main()
{
	key_t key;
	int msgid;
	struct msg_buf msg_snd, msg_rcv;
	struct msginfo buf;
	char *ptr = "helloworld";
	memset(&msg_snd, '\0', sizeof(struct msg_buf));
	memset(&msg_rcv, '\0', sizeof(struct msg_buf));
	msg_snd.type = 1;
	msg_rcv.type = 1;
	memcpy(msg_snd.msg, ptr, strlen(ptr));
	if((key=ftok(".",'A')) == -1){
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	if((msgid=msgget(key, 0666|IPC_CREAT)) == -1){
		perror("msgget");	
		exit(EXIT_FAILURE);
	}
	// msg send
	printf("msgsnd_return=%d\n",msgsnd(msgid,(void *)&msg_snd,strlen(msg_snd.msg),0));
	msgctl(msgid, MSG_INFO,&buf);
	printf("buf.msgmax=%d\n"
		   "buf.msgmnb=%d\n"
		   "buf.msgpool=%d\n"
		   "buf.msgmap=%d\n"
		   "buf.msgmni=%d\n"
		   "buf.msgssz=%d\n"
		   "buf.msgtql=%d\n"
		   "buf.msgseg=%d\n",
			buf.msgmax,
			buf.msgmnb,
			buf.msgpool,
			buf.msgmap,
			buf.msgmni,
			buf.msgssz,
			buf.msgtql,
			buf.msgseg
	       );
	// msg rcv
	printf("msgrcv_return=%d\n",msgrcv(msgid, (void *)&msg_rcv, BUFSIZE,msg_rcv. type, 0));
	printf("rcv msg: %s\n",msg_rcv.msg);
	printf("msgctl_return=%d\n",msgctl(msgid, IPC_RMID, 0));

	return 0;
}
