#include <stdio.h>
#include <stdlib.h>
#define OK   1
#define ERROR   0
#define TRUE  1
#define FALSE  0
#define OVERFLOW   -2
typedef  int  ElemType;
typedef  int  Status;
//----- ջ��˳��洢��ʾ -----
#define STACK_INIT_SIZE 10 // �洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 5// �洢�ռ�ķ�������
typedef struct {
	ElemType *base;
	int  *top;
	int  stackSize;
	} SqStack;
// ����һ����ջ S
Status InitStack(SqStack &S){
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
		if(!S.base) exit (OVERFLOW);
	S.top = S.base;
	S.stackSize = STACK_INIT_SIZE;
	return OK;
}

// ��ջ S �Ƿ�Ϊ��ջ
Status StackEmpty(SqStack S){
	if (S.top == S.base) return  TRUE;
		else return  FALSE;
	}
	
//��ջ����
Status Push (SqStack &S, ElemType e) {
//�������д���룬�����㷨�����������μ��α��Ϳμ�����½�
	if(S.top-S.base >= S.stackSize){
		S.base = (ElemType * ) realloc (S.base,
					(S.stackSize+STACKINCREMENT) * sizeof (ElemType));
		if(!S.base) exit(OVERFLOW);
		S.top = S.base + S.stackSize;
		S.stackSize += STACKINCREMENT;
	}
		*S.top++ = e;
		return OK; 
}


//��ջ����
Status Pop (SqStack &S, ElemType &e) {
//���ڴ���д���룬�����㷨�����������μ��α��Ϳμ�����½�
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}


//���˳��ջ����
void OutStack(SqStack S)
{  
	ElemType  e;
		if(TRUE == StackEmpty(S)){
			printf("����һ����ջ��");
			}
		else
			while(FALSE == StackEmpty(S)){
				Pop(S,e);
				printf("%6d", e);
			}
printf("\n");
}



main(){ 	
	SqStack s;
	int n;
	int rad;
	ElemType e;
	InitStack(s);
	scanf("%d %d",&n,&rad);
	while(n!=0){
		Push(s,n%rad);
		n=n/rad;
	}
	while(!StackEmpty(s)){
		Pop(s,e);
		printf("%d",e);
	}
}

