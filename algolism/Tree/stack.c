#include "node.h"
#define MAX 100

typedef struct _StactNode{
	Node *data;
	struct _StactNode *Next;
}StactNode;

StackNode* TopNode, NextNode;

void InitializeStack();
void Push(Node *)
Node* Pop();
int IsStackEmpty();

void InitializeStack(){
	TopNode = (StackNode *)malloc(sizeof(StackNode));
	TopNode->Next = NULL;
}

void Push(Node *ptrNode){
	NextNode = (StackNode *)malloc(sizeof(StackNode));
	NextNode->data = ptrNode;
	
	NextNode->Next = TopNode->Next;
	TopNode->Next = NextNode;
}

Node* Pop(){

}
