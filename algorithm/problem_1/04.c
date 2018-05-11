//1-04 피보나치 수열 구하기

#include <stdio.h>
#include <stdlib.h>
#define MAX 100;

int get_num();
void pibo(int);

int get_num() {
	int num;

	printf("피보나치 수열을 구합니다. 구할갯수를 입력하세요 : ");
	scanf("%d", &num);

	return num;
}

void pibo(int num) {
	int i;
	int pibo1 = 0, pibo2 = 1 ;

	printf(" %5d,", pibo1);

	for( i = 1; i < num-1; i++) {

		if(i%10 == 0) printf("\n");

		printf(" %5d,", pibo1 + pibo2);
		if(i%2 == 1) pibo1 = pibo1 + pibo2;
		else pibo2 = pibo1 + pibo2;

	}
	printf(" %5d \n", pibo1 + pibo2);
}

void main() {
	int num;

	num = get_num();

	pibo(num);

}
