// 1-06 소수구하기

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void prime_num();
int get_num();

void prime_num() {

	int num = get_num();
	int pnum = 0;
	int i, j = 1, max_dnum = 0;

	while(1) {
		if(num > MAX) {
			printf("%d 보다 큰 값을 입력했습니다.\n", MAX);
			break;
		} else if(num < 1) {
			printf("1 보다 작은 값을 입력했습니다. \n");
			break;
		}

		pnum++;

		for(i = 1; i < pnum; i++){
			if(pnum%i == 0)	max_dnum = i;
		}

		if(max_dnum == 1){
			printf(" %3d", pnum);
			if((j++)%10 == 0) printf("\n");
		}

		if(pnum == num) break;
	}

	printf("\n");
	printf("1부터 %d 사이의 소수는 %d 개 이다.\n", num, j);
}


int get_num(){
	int num;
	printf("소수를 구하는 알고리즘입니다.\n");
	printf("1-1000 사이의 값을 입력해 주세요. \n");
	printf("--> ");
	scanf("%d", &num);

	return num;
}


void main() {

	prime_num();

}
