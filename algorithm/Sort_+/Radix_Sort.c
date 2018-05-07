#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int Data;
	struct _NODE Next;
}Node;

Node *Front[10], *Rear[10];
Node ptrNode;
int Buf[MAX];


void MackRandomNumber();
void RadixSort();
void DisplayBuffer();
int IsNumberExit(int, int);
void InitializeQueue();
void Put(int, int);
int get(int);


void MakeRandomNumber() {
	int i, Num;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < MAX) {
		Num = rand()%MAX;
		if(!IsNumberExit(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void RadixSort() {
	int i, j, num, digit;


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
	ptrNode->data = num;

	if(Front[index]->Next == Rear[index]) {
		Front[index]->Next = prtNode;
		ptrNode->Next = Rear[index];
		Rear[index]->Next = ptrNode;
	}
	else {
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
	ret = deleteNode->data;

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
