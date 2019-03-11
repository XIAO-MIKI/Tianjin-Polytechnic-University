#include <stdio.h>
#include <stdlib.h>

#define OK   1
#define ERROR   0
#define TRUE 1
#define FALSE 0
#define OVERFLOW   -2
typedef  int  ElemType;
typedef  int  Status;

//----- 顺序表的顺序存储表示 -----
#define LIST_INIT_SIZE 100 // 存储空间的初始分配量
#define LISTINCREMENT 10 // 存储空间的分配增量
typedef struct {
	ElemType	*elem;	// 存储空间的基址
	int length; // 表长
	int size;// 存储容量
	int increment; // 扩容时，增加的存储容量
} SqList;  //顺序表结构类型定义

// 构造一个空顺序表 
Status InitSqlist(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.size = LIST_INIT_SIZE;
	L.increment = LISTINCREMENT;
	return OK;
}

// 判顺序表是否为空表 
Status ListEmpty(SqList L) {
	if (L.length == 0) return TRUE;
	else return FALSE;
}

//顺序表插入函数
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	int *newbase; 
	if (i<1 || i>L.length + 1) return ERROR;//i值不合法
	if (L.length >= L.size) {
		newbase = (ElemType *) realloc(L.elem,(L.size+L.increment)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);
		L.elem =  newbase;
		L.size += L.increment;
	}
	int *q = & (L.elem[i-1]);
	int *p;
	for(p = &(L.elem[L.length-1]);p>=q;--p)*(p+1)  = *p;
	*q = e;
	++L.length;
	return OK;
}

Status GetElem(SqList L, int i, ElemType  &e){
	int *p,*q;
	if (i<1 || i>L.length) return ERROR;//i值不合法
	p = & (L.elem[i-1]);
	e = *p;
	return e;
}


//顺序表删除元素函数
Status ListDelete_Sq(SqList &L, int i, ElemType  &e) {
	int *p,*q;
	if (i<1 || i>L.length) return ERROR;//i值不合法
	p = & (L.elem[i-1]);
	e = *p;
	q = L.elem+L.length-1;
	for(++p; p<=q; ++p)*(p-1)  = *p;
	--L.length;
	return OK;
}

//输出顺序表函数
void OutList_Sq(SqList L)
{
	int i;
	ElemType  e;
	if (ListEmpty(L)) {
		printf("这是一个空表！");
	}
	else
	{
		printf("顺序表为：");
		for (i = 0; i < L.length; i++)
			printf("%6d", L.elem[i]);
	}
	printf("\n");
}

void MergeList(SqList La,SqList Lb,SqList &Lc) {
	int i = 1;
	int j = 1;
	int k = 0;
	ElemType  ai;
	ElemType  bj;
	int La_len = La.length;
	int Lb_len = Lb.length;
	while((i <= La_len) && (j <= Lb_len)){
		GetElem(La ,i ,ai);
		GetElem(Lb ,j ,bj);
		if(ai <= bj){
			ListInsert_Sq(Lc ,++k ,ai);++i;
		}
		else{
			ListInsert_Sq(Lc ,++k ,bj);++j;
		}				
	}
	while(i <= La_len){
		GetElem(La ,i++ ,ai);ListInsert_Sq(Lc ,++k ,ai);
	}
	while(j <= Lb_len){
		GetElem(Lb ,j++ ,bj);ListInsert_Sq(Lc ,++k ,bj);
	}
	OutList_Sq(Lc);
}

int main(){
	SqList La,Lb,Lc;
	int cord, i;
	ElemType a;
	printf("第一次使用必须初始化！\n");
	do {
		printf("\n 主菜单 \n");
		printf(" 1 初始化顺序表La ");
		printf(" 2 初始化顺序表Lb ");
		printf(" 3 合并表La与表Lb ");
		printf(" 4 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			InitSqlist(La);
			printf("请输入要插入表La元素的个数：\n");
			int b ,c ,num ;
			scanf("%d",&num);
			printf("请按照从小到大的顺序依次输入初始顺序表的%d个元素：\n",num);
			for(b=1;b<=num;b++){
				scanf("%d",&c);
				if (ListInsert_Sq(La, b, c) == ERROR){
					printf("第%d个数插入操作失败\n",b);
				}
			}
			OutList_Sq(La);
			break;
		case 2:
			InitSqlist(Lb);
			printf("请输入要插入表Lb元素的个数：\n");
			int b2 ,c2 ,num2 ;
			scanf("%d",&num2);
			printf("请按照从小到大的顺序依次输入初始顺序表的%d个元素：\n",num2);
			for(b2=1;b2<=num2;b2++){
				scanf("%d",&c2);
				if (ListInsert_Sq(Lb, b2, c2) == ERROR){
					printf("第%d个数插入操作失败\n",b);
				}
			}
			OutList_Sq(Lb);
			break;
		case 3:
			InitSqlist(Lc);
			MergeList(La,Lb,Lc);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}

