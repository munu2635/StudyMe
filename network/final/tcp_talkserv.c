#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

char *EXIT_STRING = "exit";
char *GET_STRING = "get";
char *PUT_STRING = "put";
int save(int sd);
int send(int sd);



#define MAXLINE 511



int main(int argc, char *argv[]){

	struct sockaddr_in cliaddr, servaddr;
	int listen_sock, accp_sock, addrlen = sizeof(cliaddr);
	pid_t pid;

	if(argc != 2){
		printf(" 사용법 : %s port", argv[0]);
		exit(0);
	}


	if((listen_sock = socket(PF_INET, SOCK_STREAM, 0 )) < 0) {
		perror("socket fail");
		exit(0);
	}

	bzero((char*)&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if(bind(listen_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
		perror("bind fail");
		exit(0);
	}

	puts(" 서버가 클라이언트를 기다리고 있습니다. ");
	listen(listen_sock, 1);

	if((accp_sock = accept(listen_sock, (struct sockaddr *)&cliaddr, &addrlen)) < 0) {
		perror("accept fail");
		exit(0);
	}


	puts(" 클라이언트가 연결되었습니다. ");
	if(( pid = fork()) > 0 )
		send(accp_sock);
	else if ( pid == 0 )
		save(accp_sock);

	close(listen_sock);
	close(accp_sock);
	return 0;
}


int send(int sd){
	char buf[ MAXLINE + 1 ];
	int nbyte;
	while(fgets(buf, sizeof(buf), stdin) != NULL) {
		nbyte = strlen(buf);
		write(sd, buf, strlen(buf));

		if(strstr(buf, EXIT_STRING) != NULL) {
			puts("Good bye....");
			close(sd);
			exit(0);
		}
	}
	return 0;
}

int save(int sd) {
	char buf[ MAXLINE + 1 ];
	int nbyte;
	char getname[ MAXLINE + 1 ];
	size_t filesize = 0, bufsize = 0; 
	FILE *file = NULL; 
	recv(sd, &getname, sizeof(getname), 0);
	file = fopen(getname, "wb");

	ntohl(filesize); 
	recv(client_sockfd, &filesize,	sizeof(filesize), 0); 
	printf("file size = [%d]\n", filesize); 
	bufsize = 256; 
	while(filesize != 0) { 
		if(filesize < 256) bufsize = filesize; 
		nbyte = recv(client_sockfd, buf, bufsize, 0);
		filesize = filesize - nbyte; 
		fwrite(buf, sizeof(char), nbyte, file); 
		nbyte = 0; 
	}
	close(file);
}
