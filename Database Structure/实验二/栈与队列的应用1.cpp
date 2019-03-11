#include <stdio.h>
#include <stdlib.h>
#define OK   1
#define ERROR   0
#define TRUE  1
#define FALSE  0
#define OVERFLOW   -2
typedef  int  ElemType;
typedef  int  Status;
//----- 栈的顺序存储表示 -----
#define STACK_INIT_SIZE 10 // 存储空间的初始分配量
#define STACKINCREMENT 5// 存储空间的分配增量
typedef struct {
	ElemType *base;
	int  *top;
	int  stackSize;
	} SqStack;
// 构造一个空栈 S
Status InitStack(SqStack &S){
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
		if(!S.base) exit (OVERFLOW);
	S.top = S.base;
	S.stackSize = STACK_INIT_SIZE;
	return OK;
}

// 判栈 S 是否为空栈
Status StackEmpty(SqStack S){
	if (S.top == S.base) return  TRUE;
		else return  FALSE;
	}
	
//入栈函数
Status Push (SqStack &S, ElemType e) {
//请在填此写代码，将该算法补充完整，参见课本和课件相关章节
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


//出栈函数
Status Pop (SqStack &S, ElemType &e) {
//请在此填写代码，将该算法补充完整，参见课本和课件相关章节
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}


//输出顺序栈函数
void OutStack(SqStack S)
{  
	ElemType  e;
		if(TRUE == StackEmpty(S)){
			printf("这是一个空栈！");
			}
		else
			while(FALSE == StackEmpty(S)){
				Pop(S,e);
				printf("%6d", e);
			}
printf("\n");
}


//主函数
main()
{ 	
	SqStack s;
	int cord; ElemType a;
	printf("第一次使用必须初始化！\n");
	do
	{
		printf("\n 主菜单 \n");
		printf(" 1 初始化顺序栈 ");
		printf(" 2 插入一个元素 ");
		printf(" 3 删除栈顶元素 ");
		printf(" 4 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		scanf("%d",&cord);
		printf("\n");
	switch(cord){  
	case 1:
			InitStack(s);
			OutStack(s);
			break;
	case 2:
			printf("请输入要插入的数据元素：a=");
			scanf("%d",&a);
			Push(s,a);
			printf("%d 进栈之后的栈：",a);
			OutStack(s);
			break;
	case 3:
			Pop(s,a);
			printf("栈顶元素 %d 出栈之后的栈：",a);
			OutStack(s);
			break;
	case 4:
				exit(0);
		}
	}
	while (cord<=4);
}


