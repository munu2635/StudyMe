#include "node.h"

extern void InitializeQueue();
extern void Put(Node *);
extern Node* Get();
extern int IsQueueEmpty();

extern void InitializeTree();
extern void MakeTree();

void Visit(Node *);
void Queue_Traverse(Node *);

Node *Parent, *LeftChild, *RightChild;
Node *HeadNode, *EndNode;


void Queue_Traverse(Node *ptrNode){
	Put(ptrNode);

	while(!IsQueueEmpty()){
		ptrNode = Get();
		Visit(ptrNode);

		if(ptrNode->Left != EndNode)
			Put(ptrNode->Left);
		if(ptrNode->Right != EndNode)
			Put(ptrNode->Right);
	}

	printf(" end\n");
}

void Visit(Node *ptrNode){
	printf("%2c ->", ptrNode->data);
}

void main(){
	InitializeQueue();
	InitializeTree();
	MakeTree();

	printf("Queue_ver---------------------------\n");
	Queue_Traverse(HeadNode->Left);

	printf("------------------------------------\n");
}
