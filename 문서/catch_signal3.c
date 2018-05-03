#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

int count;

void catch_sigint(int signum){
	printf("\n(count = %d) CTRL - C pressed! \n", count);
	return;
}

int main(int argc, char *argv[]){
	struct sigaction act;
	sigset_t masksets;
	int i;
	char buf[10];
	sigfillset(&masksets);

	act.sa_handler = catch_sigint;
	act.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act, NULL);

	for(count = 0; count < 3; count++){
		int n = read(0, buf, sizeof(buf));
		if( n == -1 && errno == EINTR)
			printf("read function Interrrupted\n");
		else
			printf("\t** %d byer input\n", n);
	}

	return 0;
}
