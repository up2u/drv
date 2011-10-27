#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	key_t key;
	int msgid;
	struct msqid_ds buf;
	if((key=ftok(".", 'A')) == -1){
		perror("ftok");
		exit(EXIT_FAILURE);	
	}
	if((msgid = msgget(key, 0666|IPC_CREAT)) == -1){  // create msg queue
		perror("msgget");	
		exit(EXIT_FAILURE);
	}
	msgctl(msgid, IPC_STAT, &buf); // Copy  information from the kernel data structure
    printf("key=%d\n" 
		   "uid=%d\n" 
		   "gid=%d\n" 
		   "cuid=%d\n"
		   "cgid=%d\n" 
		   "mode=%o\n" 
		   "sequence=%d\n",
			buf.msg_perm.__key,
			buf.msg_perm.uid,
			buf.msg_perm.gid,
			buf.msg_perm.cuid,
			buf.msg_perm.cgid,
			buf.msg_perm.mode,
			buf.msg_perm.__seq);
	printf("the max bytes is:%d\n", buf.msg_qbytes);
	msgctl(msgid, IPC_RMID, (struct msqid_ds *)0);  // remove msg queue
	
	return 0;	
}


