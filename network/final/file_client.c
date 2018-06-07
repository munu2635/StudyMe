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
int get_and_save(int sd);
int put_and_send(int sd);


#define MAXLINE 511



int main(int argc, char *argv[]){
	string data;

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

	while(1) {
		printf("----------------------------------");
		printf("할 행동을 입력해주세요.\n");
		printf("get, put, exit\n->")
		

		if(fgets(buf, sizeof(buf), stdin) != NULL) {
			if(buf == GET_STRING)
				put_and_send(s);
			else if(buf == PUT_STRING)
				get_and_save(s);
			else if(buf == EXIT_STRING){
				puts("end."); close(s) exit(0);
			} else put("잘못 입력하셨습니다.\n");
			
		}	
	}

	close(listen_sock);
	close(accp_sock);
	return 0;
}
	

int put_and_send(int sd){
	char buf[ MAXLINE + 1 ];
	int nbyte;
	FILE *file = NULL;	
	
	printf("----------------------------------");
	printf("보낼 데이터를 입력해주세요.\n");
	printf("->");
		
	if(fgets(buf, sizeof(buf), stdin) == NULL)){
		//error side 
	}
	
	file =	fopen(buf, "wb");
	fseek(file, 0 , SEEK_END);
	fsize = ftell(file);
	fseek(file, 0, SEEK_SET);	

 	fsize2 = htonl(fsize);
	send(sd, &fsize2, strlen(fsize), 0);

	return 0;
}

int get_and_save(int sd) {
	char buf[ MAXLINE + 1 ];
	int nbyte;
	FILE *file = NULL;
	size_t filesize = 0, bufsize = 0;
	printf("----------------------------------");
	printf("받을 데이터를 입력해주세요.\n");
	printf("->");

	if(fgets(buf, sizeof(buf), stdin) == NULL)){
		//error side 
	}
	file = fopen(buf, "wb");

	recv(sd, &filesize, sizeof(filesize), 0);
	bufsize = 256;

	while(filesize !=0){
		if(filesize < 256)
			bufsize = filesize;
	
		nbyte = recv(sd, buf, bufsize, 0);
		filesize = filesize - nbyte;
		fwrite(buf, sizeof(char), nbyte, file);
		nbyte = 0;
	}

	return 0;
}
