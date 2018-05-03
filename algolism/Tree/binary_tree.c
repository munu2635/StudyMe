 
void Push(Node *);
Node* Pop();

void Visit() { printf("%c ", RootNode->data); }
void Visit(Node *);
void traverse(Node *);

//pre-order
void traverse(Node *ptrNode){
	Visit();

	while(!isStackEmpty()){
		ptrNode = Pop(); //처음에는 루트값이 출력된다.
		Visit(ptrNode);

		if(ptrNode->Right != EndNode)
			Push(ptrNode->right);

		if(ptrnode->letf != EndNode)
			push(ptrNode->left);
	}
}


void Visit(Node *ptrNode){

}

