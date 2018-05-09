#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int key;
	struct _NODE *left;
	struct _NODE *right;
} Node;

Node *ptrNode;
Node *head, *end;

void MackRandomNumber();
void QuickSort(int data[], int, int);
void DisplayBuffer();
int IsNumberExit(int, int);

void BSTInitialize(void);
void BSTInsert(int);
void BSTDisplay(Node *);

int Buf[MAX];
int CompareCount;

void MakeRandomNumber() {
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while (i < MAX) {
		Num = rand()%200;
		if(!IsNumberExit(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void QuickSort(int data[], int left, int right) {
	int i, j, num, temp;

	if(right > left){
		num = data[right];
		i = left - 1;
		j = right;

		while(TRUE){
			while(data[++i] < num);
			while(data[--j] > num);
			if(i >= j)
				break;
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
		temp = data[i];
		data[i] = data[right];
		data[right] = temp;

		QuickSort(data, left, i-1);
		QuickSort(data, i+1, right);
	}
}

void DisplayBuffer() {
	int i;

	for(i = 0; i < MAX; i++){
		if((i % 10) == 0)
			printf("\n");

		printf("%4d ", Buf[i]);

	}
	printf("\n");
}

int IsNumberExit(int number, int index) {
	int i;

	for( i = 0; i < index; i++){
		if(Buf[i] == number || number == 0)
			return TRUE;
	}

	return FALSE;
}

void BSTInitialize() {
	end = (Node *)malloc(sizeof *end);
	end->left = end;
	end->right = end;
	end->key = -1;

	head = (Node *)malloc(sizeof *head);
	head->right = end;
	head->key = 0;
}

void BSTInsert(int num) {
	Node *p, *x;
	p = head;
	x = head->right;

	while(x != end) {
		p = x;
		x = (num < x->key) ? x->left : x->right;
	}

	x = (Node *)malloc(sizeof *x);

	x->key = num;
	x->left = end;
	x->right = end;

	if(num < p->key) p->left = x;
	else p->right = x;

}

void BSTDisplay(Node *ptr) {
	if(ptr != end) {
		BSTDisplay(ptr->left);
		printf("%5d ", ptr->key);
		BSTDisplay(ptr->right);
	}
}

void BSTDelete(int num)
{
	Node *g, *p, *x;
	Node *temp;
	end->key = num;
	p = head; x = head->right;

	while (num != x->key) {
		p = x;
		if(num < x->key) x = x->left;
		else x = x->right;
	}

	temp = x;

	if (temp->right == end) x = x->left;
	else if (temp->right->left == end) {
		x = x->right;
		x->left = temp->left;
	} else {
		g = x->right;

		while (g->left->left != end) g = g->left;

		x = g->left;
		g->left = x->right;
		x->left = temp->left;
		x->right = temp->right;
	}

	free(temp);

	if(num < p->key) p->left = x;
	else p->right = x;

}


void main() {

	int i, ret;
	CompareCount = 0;

	MakeRandomNumber();

	QuickSort(Buf, 0, MAX-1);
	DisplayBuffer();
	BSTInitialize();

	for(i = 0; i < MAX; i++)
		BSTInsert(Buf[i]);

	printf("\n root node : %d\n", head->right->key);

	BSTDisplay(head->right);
}
