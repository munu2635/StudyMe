#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define MAXLINE 1024

int main(int argc, char *argv[]){
	struct sockaddr_in servaddr, cliaddr;
	int listen_sock, accp_sock, addrlen = sizeof(cliaddr), nbyte;
	unsigned long buf_time;
	time_t t;


	if(argc != 2){
		printf("usage : %s port_num\n", argv[0]);
		exit(0);
	}

	if((listen_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket fail");
		exit(0);
	}

	bzero((char *)&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if(bind(listen_sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0 ){
		perror("bind fail");
		exit(0);
	}

	listen(listen_sock, 5);

	while(1){
		puts("server wait connecting...");
		accp_sock = accept(listen_sock, (struct sockaddr*)&cliaddr, &addrlen);

		if(accp_sock < 0){
			perror("Accept fail");
			exit(0);
		}

		puts("connect client...");

		buf_time = ntohl(buf_time) -220988800lu;
		t = (time_t)buf_time;
		nbyte = MAXLINE ;
		write(accp_sock, ctime(&t), nbyte);
		close(accp_sock);
	}

	close(listen_sock);
	return 0;
}

