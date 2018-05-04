#include "node.h"

extern void InitializeQueue();
extern void Put(Node *);
extern Node* Get();
extern int IsQueueEmpty();

extern void InitializeTree();
extern void MakeTree();

void Visit(Node *);
void Recursive_Traverse(Node *);
void Queue_Traverse(Node *);

Node *Parent, *LeftChild, *RightChild;
Node *HeadNode, *EndNode;

void Recursive_Traverse(Node *ptrNode){
	if(ptrNode != EndNode){
		Visit(ptrNode);
		Recursive_Traverse(ptrNode->Left);
		Recursive_Traverse(ptrNode->Right);
	}
}

void Queue_Traverse(Node *ptrNode){
	int Finish = 0;
	do{
		while(ptrNode != EndNode){
		}
		if(!IsStackEmpty()){

		}
		else
			Finish = 1;
	}while(!Finish);

	printf(" end\n");
}

void Visit(Node *ptrNode){
	printf("%2c ->", ptrNode->data);
}

void main(){
	InitializeStack();
	InitializeTree();
	MakeTree();

	printf("Recursive_ver-----------------------\n");
	Recursive_Traverse(HeadNode->Left);
	printf(" end\n");

	printf("Stack_ver---------------------------\n");
	Stack_Traverse(HeadNode->Left);

	printf("------------------------------------\n");
}
