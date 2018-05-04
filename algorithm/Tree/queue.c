//linkedlist Queue.

#include "node.h"

typedef struct _QueueNode{
	Node *data;
	struct _QueueNode *Next;
}QueueNode;

QueueNode *TopNode, *BottomNode;

void InitializeQueue();
void Put(Node *);
Node* Get();
int IsQueueEmpty();

void InitializeQueue() {
	TopNode = (QueueNode *)malloc(sizeof(QueueNode));
	BottomNode = (QueueNode *)malloc(sizeof(QueueNode));
	TopNode->Next = BottomNode;
	BottomNode->Next = BottomNode;
}

void Put(Node *ptrNode) {
	QueueNode *NextNode = (QueueNode *)malloc(sizeof(QueueNode));
	NextNode->data = ptrNode;

	NextNode->Next = TopNode->Next;
	TopNode->Next = NextNode;
}

Node* Get() {
	QueueNode *RemvNode;
	Node* rtNode = (Node *)malloc(sizeof(Node));

	RemvNode = BottomNode->Next;
	BottomNode->Next = BottomNode->Next->Next;

	rtNode = RemvNode->data;
	free(RemvNode);
	return rtNode;
}

int IsQueueEmpty(){
	if(TopNode->Next == BottomNode)
		return TRUE;
	else	return FALSE;
}
