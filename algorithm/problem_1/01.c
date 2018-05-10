//1-01 10진수 16진수 변환프로그램

#include <stdio.h>

char get_data();
void set_data(char);
void dectohex();
void hextodec();

char get_data() {
	char data;
	printf("10진수 16진수 변화 프로그램입니다.\n");
	printf("10 -> 16은 [A] 키를 누르세요.\n");
	printf("16 -> 10은 [B] 키를 누르세요.\n");
	printf("->");
	scanf("%c", &data);

	return data;
}

void set_data(char data) {

	if (data == 'a' || data == 'A')
		dectohex();
	else if ( data == 'b' || data == 'B')
		hextodec();
	else printf("잘못된 값을 입력하셨습니다\n");

}

void dectohex() {
	int num;

	printf("값을 입력해 주세요. (10진수) : ");
	scanf("%d", &num);

	printf("16진수 값 : %x \n", num);

}

void hextodec() {
	int num;

	printf("값을 입력해 주세요. (16진수) : ");
	scanf("%x", &num);

	printf("10진수 값 : %d \n", num);
}



void main(){
	char data;

	data = get_data();

	set_data(data);
}
