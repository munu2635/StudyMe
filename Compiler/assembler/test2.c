//	.file 	"test2.c"
#include <stdio.h>
#define MAX 5

int buf[MAX] = { 3, 5, 2, 1, 4 };
//	-> int buf[MAX] = { 3, 5, 2, 1, 4 };
//	.globl buf
//	.data
//	.align	16
//	.type	buf, @object
//	.size	buf, 20
//buf:	-------------------------------- buf object 
//	.long	3			왭 int로 해놨는데 long형으로 설정되는거지?
//	.long	5
//	.long	2
//	.long	1
//	.long 	4
//	.text
//	.globl	main
//	.type	main,	@funtion



//	-> int buf[MAX];
// 	.comm buf,80,32 -> .comm 변수명,총 바이트,2^5
//	.text
//	.globl	main
//	.type	main, @funtion

void main(){
	int i;
	for(i = 0; i<MAX ;i++){}
	while(1){
		if( i == 4 ) break;
	}
}

//-------------------------------------- 함수 시작
// main:
// .LFBO:
//	.cfi_startproc
//	pushq	%rbp
//	.cfi_def_cfa_offset 16
//	.cfi_offset 6, -16
//	movq	%rsp, %rdp
//	.cfi_def_cfa_register 6

//	movl	$0, -4(%rbp)
//	jmp	.L2
// .L3:
//	addl	$1, -4(%rbp)
//
//
//
//
//
//
//
//








//-------------------------------------- 여기까지가 함수 선언/ 바디 시작
//case1	= > printf("a");
//	movl	$97, %edi
//	call	putchar
//	nop
//-------------------------------------- 함수 바디 끝
//	popq	%rbp
//	.cfi_def_cfa	7, 8
//	ref
//	.cf_endproc
//-------------------------------------- 함수 끝마무리
// .LFE0:
//	.size	main, .-main	-------- 함수 종료
//	.globl	a		-------- 다음 함수 정의
//	.type	a, @function




void a(){} //기본 함수 print
//-------------------------------------- a 함수 시작
// a:
// .LFB1:
//	.cfi_startproc
//	pushq	%rbp
//	.cfi_def_cfa_offset 16
//	.cfi_offset 6, -16
//	movq	%rsp, %rbp
//	.cfi_def_cfa_register 6
//	nop
//	popq	%rbp
//	.cfi_def_cfa 7, 8
//	ret
//	.cfi_endproc
// .LFE1:
//	.size	a, .-a
//	.ident "GCC: - "
//	.section	.note.GNU-stack, "",@progbits
//-------------------------------------- a 함수 끝

