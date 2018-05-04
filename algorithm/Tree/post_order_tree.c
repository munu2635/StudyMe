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
		Recursive_Traverse(ptrNode->Right);
		Visit(ptrNode);
	}
}

void Stack_Traverse(Node *ptrNode){
	int Finish = 0;
	Node *ptrVisited = EndNode;
	Node *ptrPushed = EndNode;

	do{
		while(ptrNode != EndNode && ptrNode != ptrVisited){
			if(ptrNode != ptrPushed)
				Push(ptrNode);
			if(ptrNode->Right != EndNode)
				Push(ptrNode -> Right);
			if(ptrNode->Left != EndNode)
				Push(ptrNode->Left);

			ptrPushed = ptrNode->Left;
			ptrNode = ptrNode->Left;
		}
		if(!IsStackEmpty()){
			ptrNode = Pop();

			if(ptrNode->Left != EndNode && ptrNode->Right == EndNode && ptrNode->Left != ptrVisited){
				Push(ptrNode);
				ptrNode = ptrNode->Left;
			}

			if(ptrNode->Right == EndNode || ptrNode->Right == ptrVisited){
				Visit(ptrNode);
				ptrVisited = ptrNode;
			}
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
