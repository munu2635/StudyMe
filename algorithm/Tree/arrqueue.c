//Array Queue.

#include "node.h"
#define MAX 100

Node *QueueArr[MAX];
int RearNum = 0;

void InitializeQueue();
void Put(Node *);
Node* Get();
int IsQueueEmpty();

void InitializeQueue() {
	QueueArr[RearNum] = NULL;
}

void Put(Node *ptrNode) {
	QueueArr[RearNum] = ptrNode;
	RearNum++;
}

Node* Get() {
	int i = 0;
	Node * rtNode;

	if(RearNum == 0){
		rtNode = QueueArr[0];
		QueueArr[0] = NULL;
	}else{
		rtNode = QueueArr[0];
		for(i; i < RearNum; i++) {
			QueueArr[i] = QueueArr[i+1];
		}
		RearNum--;
	}
	return rtNode;
}

int IsQueueEmpty(){
	if(QueueArr[0] == NULL)	return TRUE;
	else return FALSE;
}
