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
int Save(int sd);
int Send(int sd);

#define MAXLINE 511



int main(int argc, char *argv[]){
	char get_message[ 10 ];
	struct sockaddr_in cliaddr, servaddr;
	int listen_sock, accp_sock, addrlen = sizeof(cliaddr);
	pid_t pid;

	if(argc != 2){
		printf(" 사용법 : %s port\n", argv[0]);
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
	while(1){
		puts("서버가 클라이언트를 기다리고 있습니다. ");
		listen(listen_sock, 1);
	
		if((accp_sock = accept(listen_sock, (struct sockaddr *)&cliaddr, &addrlen)) < 0) {
			perror("accept fail");
			exit(0);
		}

		puts("클라이언트가 연결되었습니다. ");
	
		while(1) {
			recv(accp_sock, get_message, sizeof(get_message),0);
			puts(get_message);
			if(strstr(get_message, GET_STRING) != NULL)
				Send(accp_sock);
			else if(strstr(get_message, PUT_STRING) != NULL)
				Save(accp_sock);
			else if(strstr(get_message, EXIT_STRING) != NULL){
				puts("end."); close(accp_sock); break;
			}
		}
	}
	close(listen_sock);
	close(accp_sock);
	return 0;
}


int Send(int sd){
	char buf[ MAXLINE + 1 ];
	int nbyte;
	char getname[ MAXLINE + 1 ];
	size_t fsize = 0, nsize = 0, fpsize = 0; 
	size_t fsize2 = 0;
	FILE *file = NULL;
	
	if(recv(sd, &getname, sizeof(getname), 0) == -1){
		perror("recverror");
		return 0;
	}

	printf(getname);

	file =	fopen(buf, "wr");
	
	if(file == NULL) {
		printf("파일 없음\n");
		send(sd, 0, 0, 0);
		return 0;
	}else {
		printf("파일을 전송\n");

			
		fseek(file, 0, SEEK_END); 
	
		fsize = ftell(file); fseek(file, 0, SEEK_SET); 
		fsize2 = htonl(fsize);
	
		send(sd, &fsize2, sizeof(fsize), 0);
 		printf("1\n");
		printf(fsize + fsize2);
		while(nsize != fsize)
 		{ 
			fpsize = fread(buf, 1, 256, file); 
			nsize = nsize + fpsize; 
			send(sd, buf, fpsize, 0); 
			printf("1\n");
		}
	printf("end\n");
	}
	return 0;
}

int Save(int sd) {
	char buf[ MAXLINE + 1 ];
	int nbyte;
	char getname[ MAXLINE + 1 ];
	size_t filesize = 0, bufsize = 0;
	while (1) { 
	FILE *file = NULL; 
	
	recv(sd, &getname, sizeof(getname), 0);
	file = fopen(getname, "wb");

	ntohl(filesize); 
	recv(sd, &filesize, sizeof(filesize), 0); 
 
	bufsize = 256; 
	while(filesize != 0) { 
		if(filesize < 256) bufsize = filesize; 
		nbyte = recv(sd, buf, bufsize, 0);
		filesize = filesize - nbyte; 
		fwrite(buf, sizeof(char), nbyte, file); 
		nbyte = 0; 
	}	
		

		close(file);
	}
}
