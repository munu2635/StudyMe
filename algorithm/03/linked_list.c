#include <stdio.h>
#include <stdlib.h>


//노드 구조체

typedef struct _NODE{
	char Data;
	struct _NODE *Next;
}Node;


Node *head, *end, *temp;
Node *temp1, *temp2, *temp3, *temp4;


//미리 전역변수로 설정하여 값을 따로 주지 않고 수행
void Initialize(void);
void InsertNode(Node *);
void DeleteNode(Node *);

void Initialize(void){
	Node *ptr;
	head = (Node *)malloc(sizeof(Node));
	end = (Node *)malloc(sizeof(Node));

	temp1 = (Node *)malloc(sizeof(Node));
	temp1->Data = 'A';
	head->Next = temp1;
	temp1->Next = end;
	end->Next = end;
	ptr = temp1;

	temp2 = (Node *)malloc(sizeof(Node));
	temp2->Data ='B';
	ptr->Next = temp2;
	temp2->Next = end;
	ptr = temp2;

	temp3 = (Node *)malloc(sizeof(Node));
	temp3->Data = 'D';
	ptr->Next = temp3;
	temp3->Next= end;
	ptr = temp3;

	temp4 = (Node *)malloc(sizeof(Node));
	temp4->Data = 'E';
	ptr->Next = temp4;
	temp4->Next = end;
	ptr = temp4;

}


//노드 삽입
void InsertNode(Node *ptr){
	Node *indexptr;

	for(indexptr = head; indexptr != end; indexptr = indexptr->Next){
		if(indexptr->Next->Data > ptr->Data)
			break;
	}

	ptr->Next = indexptr->Next;
	indexptr->Next = ptr;
}

//노드 삭제
void DeleteNode(Node *ptr){
	Node *indexptr;
	Node *deletptr;

	for(indexptr = head; indexptr != end; indexptr = indexptr -> Next){
		if(indexptr-> Next -> Data == ptr -> Data){
			deletptr = indexptr-> Next;
			break;
		}
	}

	indexptr->Next = indexptr->Next->Next;

	free(deletptr);
}




void main(){
	Node *ptr;
	int i = 0;

	Initialize();

	ptr = head->Next;

	for(i = 0 ; i < 4; i++){
		printf("%2c ", ptr->Data);
		ptr = ptr->Next;
	}
	printf("\n");

	temp = (Node *)malloc(sizeof(Node));
	temp->Data = 'C';

	InsertNode(temp);

	ptr = head->Next;

	for(i = 0; i < 5; i++){
		printf("%2c ", ptr->Data);
		ptr = ptr->Next;
	}
	printf("\n");

	DeleteNode(temp);

	ptr = head->Next;

	for(i = 0; i < 4; i++){
		printf("%2c ", ptr->Data);
		ptr = ptr->Next;
	}
	printf("\n");
}
