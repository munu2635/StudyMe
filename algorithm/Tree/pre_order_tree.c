#include "node.h"

extern void InitializeStack();
extern void Push(Node *);
extern Node* Pop();
extern int IsStackEmpty();

extern void InitializeTree();
extern void MakeTree();

void Visit(Node *);
void Traverse(Node *);

Node *Parent, *LeftChild, *RightChild;
Node *HeadNode, *EndNode;

void Traverse(Node *ptrNode){
	Push(ptrNode);

	while(!IsStackEmpty()){
		ptrNode = Pop(); //처음에는 루트값이 출력된다.
		Visit(ptrNode);

		if(ptrNode->Right != EndNode)
			Push(ptrNode->Right);

		if(ptrNode->Left != EndNode)
			Push(ptrNode->Left);
	}
	printf(" end\n");
}


void Visit(Node *ptrNode){
	printf("%2c ->", ptrNode->data);
}

void main(){
	InitializeStack();
	InitializeTree();
	MakeTree();
	Traverse(HeadNode->Left);
}
