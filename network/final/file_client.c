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

	while(fgets(buf, sizeof(buf), stdin) != NULL) {
		printf("할 행동을 입력해주세요(get, put) -> ");
		scanf("%s", &data);

		if(data == GET_STRING)
			put_and_send();
		else if(data == PUT_STRING)
			get_and_save();
	}	


	if(( pid = fork()) > 0 )
		put_and_send(accp_sock);
	else if ( pid == 0 )
		get_and_save(accp_sock);

	close(listen_sock);
	close(accp_sock);
	return 0;
}


int put_and_send(int sd){
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

int get_and_save(int sd) {
	char buf[ MAXLINE + 1 ];
	int nbyte;
	while(1) {
		if((nbyte = read(sd, buf, MAXLINE))< 0 ){
			perror("read fail");
			close(sd);
			exit(0);
		}
		buf[nbyte] = 0;

		if(strstr(buf, EXIT_STRING) != NULL)
			break;
		printf("%s", buf); 
	}
	return 0;
}
