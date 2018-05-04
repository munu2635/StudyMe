#include "node.h"

extern void InitializeStack();
extern void Push(Node *);
extern Node* Pop();
extern int IsStackEmpty();

extern void InitializeTree();
extern void MakeTree();

void Visit(Node *);
void Recursive_Traverse(Node *);
void Stack_Traverse(Node *);

Node *Parent, *LeftChild, *RightChild;
Node *HeadNode, *EndNode;

void Recursive_Traverse(Node *ptrNode){
	if(ptrNode != EndNode){
		Recursive_Traverse(ptrNode->Left);
		Visit(ptrNode);
		Recursive_Traverse(ptrNode->Right);
	}
}

void Stack_Traverse(Node *ptrNode){
	int Finish = 0;
	do{
		while(ptrNode != EndNode){
			Push(ptrNode);
			ptrNode = ptrNode->Left;
		}
		if(!IsStackEmpty()){
			ptrNode = Pop();
			Visit(ptrNode);
			ptrNode = ptrNode->Right;
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
