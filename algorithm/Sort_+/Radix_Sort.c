#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int Data;
	struct _NODE * Next;
}Node;

Node *Front[10], *Rear[10];
Node *ptrNode;
int Buf[MAX];


void MackRandomNumber();
void RadixSort();
void DisplayBuffer();
int IsNumberExit(int, int);
void InitializeQueue();
void Put(int, int);
int Get(int);


void MakeRandomNumber() {
	int i, Num;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < MAX) {
		Num = rand() % 100;
		if(!IsNumberExit(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void RadixSort() {
	int i, j, num, digit;

	j = 0;

	for(i = 0; i < MAX; i++) {
		num = Buf[i];
		digit = num % MAX;
		Put(digit, num);
	}

	printf("\n1의 자릿수로 정렬된 숫자 리스트\n");

	for(i = 0; i < MAX; i++) {
		printf("\n%d의 자리 : ", i);
		while(1) {
			num = Get(i);
			if(num != -1) {
				printf("%3d ", num);
				Buf[j++] = num;
			}
			else break;
		}
	}

	printf("\n\n1차 정렬 후 Buf 안 데이터들 \n");
	DisplayBuffer();

	j = 0;

	for(i = 0; i < MAX; i++) {
		num = Buf[i];
		digit = num/MAX;
		Put(digit, num);
	}


	printf("\n10의 자릿수로 정렬 된 숫자 리스트\n");

	for(i = 0; i < MAX; i++) {
		printf("\n%d의 자리 : " , i);
		while(1) {
			num = Get(i);

			if(num != -1){
				printf("%3d ", num);
				Buf[j++] = num;
			}
			else break;
		}
	}
	printf("\n\n2차 정렬 후 Buf 안 데이터들\n");
	DisplayBuffer();
}

void DisplayBuffer() {
	int i;

	for(i = 0; i < MAX; i++){
		if((i % 10) == 0)
			printf("\n");

		printf("%4d ", Buf[i]);

	}
	printf("\n");
}

int IsNumberExit(int number, int index) {
	int i;

	for( i = 0; i < index; i++){
		if(Buf[i] == number || number == 0)
			return TRUE;
	}

	return FALSE;
}

void InitializeQueue(){
	int i;

	for(i = 0; i < MAX; i++){
		Front[i] = (Node *)malloc(sizeof(Node));
		Rear[i] = (Node *)malloc(sizeof(Node));
		Front[i]->Next = Rear[i];
		Rear[i]->Next = Rear[i];
	}
}

void Put(int index, int num) {
	ptrNode = (Node *)malloc(sizeof(Node));
	ptrNode->Data = num;

	if ( Front[index]->Next == Rear[index] ) {
		Front[index]->Next = ptrNode;
		ptrNode->Next = Rear[index];
		Rear[index]->Next = ptrNode;
	} else {
		Rear[index]->Next->Next = ptrNode;
		Rear[index]->Next = ptrNode;
		ptrNode->Next = Rear[index];
	}
}

int Get(int index) {
	int ret;
	Node *deleteNode;

	if(Front[index]->Next == Rear[index])
		return -1;

	deleteNode = Front[index]->Next;
	Front[index]->Next = Front[index]->Next->Next;
	ret = deleteNode->Data;

	free(deleteNode);
	return ret;
}



void main() {

	InitializeQueue();

	printf("정렬할 데이터 초기화\n");

	MakeRandomNumber();
	DisplayBuffer();

	RadixSort();

	printf("\n\n");
	printf("\n");
}
