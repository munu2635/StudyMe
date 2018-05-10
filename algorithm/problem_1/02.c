//1-02 숫자맞추기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int set_random_num();
int set_num(int, int, int);
void check_num(int);

int set_random_num(){
	int rnum;

	srand((unsigned)time(NULL));
	rnum = rand()%MAX;

	return rnum;
}

int set_num(int max, int min, int i) {
	int snum;
	printf("\n--------------------------------------------\n");
	printf("[%d] %d - %d 사이의 값을 입력해주세요. \n", i, min, max);
	scanf("%d", &snum);

	return snum;
}

void check_num(int rnum) {
	int snum;
	int max = MAX, min = 0;
	int i = 0;

	while(1) {
		snum = set_num(max, min, ++i);

		if (snum > rnum) {
			printf("랜덤한 값보다 큽니다 \n");
			if(snum < max) max = snum;
		} else if (snum < rnum) {
			printf("랜덤한 값보다 작습니다.\n");
			if(snum > min) min = snum;
		} else {
			printf("정답! \n ");
			break;
		}

	}
}


void main() {

	int rnum;

	rnum = set_random_num();
	check_num(rnum);

}
