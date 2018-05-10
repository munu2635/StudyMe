//1-05 임의의 숫자 배수의 개수와 합구하기

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int set_number();
int check_multiple(int);

int set_number() {
	int num;

	printf("1-1000 사이에서 선택한 수의 배수가 몇 개고, 배수의 합은 얼마인가?\n");
	printf("1-1000사이의 수 중에서 임의의 숫자를 입력해주세요.\n");
	printf("-> ");
	scanf("%d", &num);

	return num;
}

int check_multiple(int num){
	int i = 0;
	int sum = 0;

	while(1) {
		i++;

		if(num < 0){
			printf("잘못된 값을 입력하였습니다.\n");
			break;
		}

		if(num*i <= 1000){
			sum += num*i;
		} else {
			printf("1-1000사이 %d의 배수의 개수 : %d, 개수의 합 : %d\n", num, i, sum);
			break;
		}
	}
}

void main() {
	int num;

	num = set_number();
	check_multiple(num);
}
