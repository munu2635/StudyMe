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
	char buf[ 10 ];
	struct sockaddr_in servaddr;
	static int s;
	pid_t pid;

	if(argc != 3){
		printf(" 사용법 : %s server_ip port\n", argv[0]);
		exit(0);
	}


	if((s = socket(PF_INET, SOCK_STREAM, 0 )) < 0) {
		perror("Client: Can't open stream socket.\n");
		exit(0);
	}

	bzero((char*)&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	servaddr.sin_port = htons(atoi(argv[2]));

	if(connect(s, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("Client: can't connect to server.\n");
		exit(0);
	}

	while(1) {
		printf("----------------------------------\n");
		printf("할행동을 입력해주세요.\n");
		printf("get, put, exit\n -> ");
		

		if(fgets(buf, sizeof(buf), stdin) != NULL) {
			send(s,	buf, sizeof(buf), 0);
			if(strstr(buf, PUT_STRING) != NULL)
				put_and_send(s);
			else if(strstr(buf, GET_STRING) != NULL)
				get_and_save(s);
			else if(strstr(buf, EXIT_STRING) != NULL){
				puts("end."); close(s); exit(0);
			} else puts("잘못 입력하셨습니다.\n");
			
		}	
	}
	close(s);
	return 0;
}
	

int put_and_send(int sd){
	char buf[ MAXLINE + 1 ];
	int nbyte;
	size_t fsize = 0, nsize = 0, fpsize = 0; 
	size_t fsize2 = 0;
	FILE *file = NULL;
	
	
	printf("----------------------------------\n");
	printf("보낼 파일명을 입력해주세요.\n");
	printf("->");
		
	if(fgets(buf, sizeof(buf), stdin) != NULL){
		send(sd, &buf, sizeof(buf), 0);
		

		file =	fopen(buf, "r");
		
		fseek(file, 0, SEEK_END); 
	
		fsize = ftell(file); fseek(file, 0, SEEK_SET); 
		fsize2 = htonl(fsize);

		send(sd, &fsize2, sizeof(fsize), 0);
 	
		while(nsize != fsize)
	 	{ 
			fpsize = fread(buf, 1, 256, file); 
			printf(buf);
			nsize = nsize + fpsize; 
			send(sd, busend(sd, &fsize2, sizeof(fsize), 0);f, fpsize, 0); 
		}
		close(file);
	}
	printf("----------------------------------\n");
	return 0;
}

int get_and_save(int sd) {
	char buf[ MAXLINE + 1 ];
	int nbyte;
	FILE *file = NULL;
	size_t filesize = 0, bufsize = 0;
	printf("----------------------------------\n");
	printf("받을 데이터를 입력해주세요.\n");
	printf(" -> ");

	if(fgets(buf, sizeof(buf), stdin) != NULL){

		send(sd, &buf, sizeof(buf), 0);			
		
		file = fopen(buf, "wb");


		recv(sd, &filesize, sizeof(filesize), 0);
		if(sizeof(filesize) == 0){
			printf("데이터가 없습니다.\n");
			return 0;
		}
		bufsize = 256;

		while(filesize !=0){
			if(filesize < 256) bufsize = filesize;
	
			nbyte = recv(sd, buf, bufsize, 0);
			filesize = filesize - nbyte;
			fwrite(buf, sizeof(char), nbyte, file);
			nbyte = 0;
		}
		close(file);
	}
	return 0;
}
