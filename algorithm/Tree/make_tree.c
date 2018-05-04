#include "node.h"

void InitializeTree();
void MakeTree();

Node *Parent, *LeftChild, *RightChild;
Node *HeadNode, *EndNode;

void InitializeTree(){
	HeadNode = (Node *)malloc(sizeof(Node));
	EndNode = (Node *)malloc(sizeof(Node));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;
}

void MakeTree(){
	Parent = (Node *)malloc(sizeof(Node));
	Parent->data ='A';

	LeftChild = (Node *)malloc(sizeof(Node));
	LeftChild->data = 'B';

	RightChild = (Node *)malloc(sizeof(Node));
	RightChild->data = 'C';

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

	HeadNode->Left = Parent;
	HeadNode->Right = Parent;

	Parent = Parent->Left;

	LeftChild = (Node *)malloc(sizeof(Node));
	LeftChild->data = 'D';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (Node *)malloc(sizeof(Node));
	RightChild->data = 'E';
	RightChild->Left = EndNode;
	RightChild->Right =EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

	Parent = HeadNode->Right->Right;

	LeftChild = (Node *)malloc(sizeof(Node));
	LeftChild->data = 'F';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (Node *)malloc(sizeof(Node));
	RightChild->data ='G';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;


	Parent->Left = LeftChild;
	Parent->Right = RightChild;
}


