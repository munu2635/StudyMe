//linkedlist Stack

#include "node.h"

typedef struct _StackNode{
	Node *data;
	struct _StackNode *Next;
}StackNode;

StackNode *TopNode;

void InitializeStack();
void Push(Node *);
Node* Pop();
int IsStackEmpty();

void InitializeStack() {
	TopNode = (StackNode *)malloc(sizeof(StackNode));
	TopNode->Next = NULL;
}

void Push(Node *ptrNode) {
	StackNode *NextNode = (StackNode *)malloc(sizeof(StackNode));
	NextNode->data = ptrNode;

	NextNode->Next = TopNode->Next;
	TopNode->Next = NextNode;
}

Node* Pop() {
	StackNode *RemvNode = (StackNode *)malloc(sizeof(StackNode));
	Node* rtNode = (Node *)malloc(sizeof(Node));

	RemvNode = TopNode->Next;
	TopNode->Next = TopNode->Next->Next;

	rtNode = RemvNode->data;
	free(RemvNode);
	return rtNode;
}

int IsStackEmpty(){
	if(TopNode->Next == NULL)
		return TRUE;
	else	return FALSE;
}
