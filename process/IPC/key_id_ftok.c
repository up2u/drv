// ftok - convert a pathname and a project identifier to a System V IPC key

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	key_t key;
	int i;
	struct stat buf;
	if(argc != 3){
		printf("usage: command path number\n");
		return 1;
	}

	i = atoi(argv[2]);
	if((stat(argv[1], &buf)) == -1){
		perror("stat");
		exit(EXIT_FAILURE);
	}
	printf("ID of device containing file(st_dev): %x\n",buf.st_dev);
	printf("inode number(st_ino): %x\n",buf.st_ino);
	printf("number:%x\n",i);
	// key
	key = ftok(argv[1], i);
	printf("key=0x%x, key>>24=%x, (key>>16)&oxff=%x, key&0xffff=%x\n",key,key>>24,(key>>16)&0xff,key&0xffff);

	return 0;	
}

