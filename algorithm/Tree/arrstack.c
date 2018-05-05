//Array Stack g가 한번더 실행되는 오류 있음 

#include "node.h"
#define MAX 100

Node* StackArr[MAX];
int TopNum;

void InitializeStack();
void Push(Node *);
Node* Pop();
int IsStackEmpty();

void InitializeStack() {
	TopNum = 0;
	StackArr[TopNum] = NULL;
}

void Push(Node *ptrNode) {
	StackArr[TopNum] = ptrNode;
		TopNum++;
}

Node* Pop() {
	Node* rtNode;

	if(TopNum != 0)
		rtNode = StackArr[--TopNum];
	else {
		rtNode = StackArr[TopNum];
		StackArr[TopNum] = NULL;
	}
	return rtNode;
}

int IsStackEmpty(){
	if(StackArr[0] == NULL&& TopNum == 0)	return TRUE;
	else	return FALSE;
}
