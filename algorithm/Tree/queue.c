//linkedlist Queue.

#include "node.h"

typedef struct _QueueNode{
	Node *data;
	struct _QueueNode *Next;
}QueueNode;

QueueNode *FrontNode, *RearNode;

void InitializeQueue();
void Put(Node *);
Node* Get();
int IsQueueEmpty();

void InitializeQueue() {
	FrontNode = (QueueNode *)malloc(sizeof(QueueNode));
	RearNode = (QueueNode *)malloc(sizeof(QueueNode));
	FrontNode->Next = RearNode;
	RearNode->Next = RearNode;
}

void Put(Node *ptrNode) {
	QueueNode *NextNode = (QueueNode *)malloc(sizeof(QueueNode));
	NextNode->data = ptrNode;

	if(FrontNode->Next == RearNode) {
		FrontNode->Next = NextNode;
		RearNode->Next = NextNode;
		NextNode->Next = RearNode;
	} else {
		RearNode->Next->Next = NextNode;
		NextNode->Next = RearNode;
		RearNode->Next = NextNode;
	}
}

Node* Get() {
	QueueNode *RemvNode;
	Node* rtNode;

	RemvNode = FrontNode->Next;
	FrontNode->Next = FrontNode->Next->Next;

	rtNode = RemvNode->data;
	free(RemvNode);
	return rtNode;
}

int IsQueueEmpty(){
	if(FrontNode->Next == RearNode)
		return TRUE;
	else	return FALSE;
}
