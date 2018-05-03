#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int Data;
	struct _Node *next;
}Node;

//stack 초기화, 설정


void IntializeStac(void);
void Push(int num);
int Pop();

Node *head, *end;

void InitializeStack(void){
	head = (Node *)malloc(sizeof(Node));
	end  = (Node *)malloc(sizeof(Node));

	head->next = end;
	end ->next = end;
}

void push(int num){
	Node *ptrNode = (Node *)malloc(sizeof(Node));
	ptrNode->Data = num;
	ptrNode->next = head-> next;
	head->next = ptrNode;
}

int Pop(){
	int num;
	Node *PopNode;

	if(head->next == end){
		printf("pop할 값이 없습니다.");
		return -1;
	}

	PopNode = head->next;
	num = PopNode->Data;
	head->next = PopNode->next;

	free(PopNode);
	return num;
}
