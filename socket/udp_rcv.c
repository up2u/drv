#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT  2048
int main(int argc, char *argv[])
{
	struct sockaddr_in s_addr;
	struct sockaddr_in c_addr;
	int sock;
	socklen_t addr_len;
	int len;
	char buff[128];
	printf("create socket \n");
	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
		perror("socket");
		exit(EXIT_FAILURE);	
	}
	memset(&s_addr, '\0', sizeof(struct sockaddr_in));
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);
	s_addr.sin_addr.s_addr = INADDR_ANY;
	printf("bind address to socket\n");
	if(bind(sock, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1){
		perror("bind");	
		exit(EXIT_FAILURE);
	}
	addr_len = sizeof(c_addr);
//	while(1){
		len = recvfrom(sock, buff, sizeof(buff)-1, 0, (struct sockaddr *)&c_addr, &addr_len);
		if(len < 0){
			perror("recvfrom");
			exit(EXIT_FAILURE);	
		}
		buff[len] = '\0';
		printf("received from %s:%d , message is: %s\n", inet_ntoa(c_addr.sin_addr), ntohs(c_addr.sin_port), buff);
//	}
	return 0;
}

