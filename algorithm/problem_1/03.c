//1-03 최대공약수 구하기

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void get_number();
int get_gcd(int, int);
int divisor[MAX];


void get_number() {
	int num1, num2;
	int gcd;
	printf("약수를 구할 두 정숫값을 입력하시오.\n");
	printf("입력1 : ");
	scanf("%d", &num1);
	printf("입력2 : ");
	scanf("%d", &num2);

	gcd = get_gcd(num1, num2);

	printf("%d와 %d의 최대공약수는 %d이다. \n", num1, num2, gcd);
}

int get_gcd(int num1, int num2) {
	int gcd, check;
	int i = 1;

	(num1 > num2) ? (check = num1) : (check = num2);

	while(1){

		if(0 == num1%i && 0 == num2%i) {
			gcd = i;
		}

		if(i > check) break;

		i++;
	}


	return gcd;
}
int main(){
	get_number();
}
