#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 2048

int main(int argc, char *argv[])
{
	struct sockaddr_in s_addr;
	int sock;
	int addr_len;
	int len;
	char buff[128];
	
	printf("create socket\n");
	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
		perror("socket");	
		exit(EXIT_FAILURE);
	}
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);
	if(argv[1]){
		s_addr.sin_addr.s_addr = inet_addr(argv[1]);
	}else{
		printf("please input IP\n");
		exit(0);
	}
	addr_len = sizeof(s_addr);
	strcpy(buff, "hello, i am here\n");
	len = sendto(sock, buff, strlen(buff), 0, (struct sockaddr *)&s_addr, addr_len);
	if(len < 0){
		printf("send error\n");
		return 3;	
	}
	printf("send success\n");
	return 0;	
}

