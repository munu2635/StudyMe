//linked_list를 이용한 queue.
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node *next;
}Node;

Node *front, *rear;

void InitializeQueue();
void Put(int num);
int get();

void InitializeQueue(){
	front = (Node *)malloc(sizeof(Node));
	rear = (Node *)malloc(sizeof(Node));
	front->next = rear;
	rear->next = front;
}

void put(int num){
	Node * ptrNode = (Node *)malloc(Node));
	ptrNode->data = num;

	if(front->next == rear){
		ptrNode->next = front;
		rear->next = ptrnode;
	}
	else {
		ptrNode->next = rear->next;
		rear->next = ptrNode->next;
	}

}

int get(){
	Node *getNode;
	int num;

	if(front -> next == rear) return 0;

	getNode = front->next;
	num = getNode->Data;
	front->next = front->next->next;

	free(getNode);
	return num;
}
