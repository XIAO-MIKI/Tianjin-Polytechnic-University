#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1 
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//以下是建立单链表
void CreatList_L(LinkList &head)
{
	LinkList tail, p;
	int n, i;
	head = tail = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	printf("\n请输入链表的长度:");
	scanf("%d", &n);
	printf("\n请输入%d个整型数据元素", n);
	for (i = 1; i <= n; i++) {
		p = (LNode *)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	printf("\n单链表的建立成功!");
}

//将第i个元素的值赋值给e，并返回第i个节点的地址
LNode* GetElem_L(LinkList L, int  i, ElemType e)
{
	LNode *p;
	int  j = 0;
	if (L == NULL || L->next == NULL)	return NULL;
	p = L;
	//请在此填写代码，将该算法补充完整，参见课本和课件相关章节
	while(p && j < i){
		p = p->next;
		++j;
	}
	if (p == NULL) return ERROR;
	e = p->data;
	return  p;
}

//在指针p指向的结点后面插入指针q指向的结点     
Status InsertAfter_L(LNode *p, ElemType &e) {
	LNode *q;
	if (NULL == p) return ERROR;
	//请在此填写代码，将该算法补充完整，参见课本和课件相关章节
	q = (LNode*)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return OK;
}
//删除指针p指向结点的后继结点，并将后继结点元素的值赋值给参数e
Status DeleteAfter_L(LNode *p, ElemType &e) {
	LNode *q;
	if (NULL == p || NULL == p->next)     return ERROR;
	//请在此填写代码，将该算法补充完整，参见课本和课件相关章节
	q=p->next;	
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}
//以下是输出单链表
void OutputList_L(LinkList L) {
	LinkList p = L->next;
	if (p == NULL) {
		printf("是一个空表！\n");
		return;
	}
	printf("单链表是:");
	while (p) {
		printf("%4d", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkList L;
	int cord, i; ElemType a;
	LNode *p, *q;
	printf("\n第一次使用请先创建一个单链表！\n");
	do {
		printf("\n 主菜单 \n");
		printf(" 1 创建一个单链表 ");
		printf(" 2 插入一个元素 ");
		printf(" 3 删除一个元素 ");
		printf(" 4 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			CreatList_L(L);
			OutputList_L(L);
			break;
		case 2:
			printf("\n请输入要插入的位置和元素值（如:3 20）");
			scanf("%d %d", &i, &a);
			p = GetElem_L(L, i - 1,a);
			if (ERROR == InsertAfter_L(p, a))
			{
				printf("插入失败！");
				OutputList_L(L);
				break;
			}
			printf("\n插入成功!插入%d元素之后的:\n", a);
			OutputList_L(L);
			break;
		case 3:
			printf("\n请输入要删除元素的位置（如： 3）");
			scanf("%d", &i);
			p = GetElem_L(L, i - 1,a);
			if (ERROR == DeleteAfter_L(p, a))
			{
				printf("删除失败！");
				OutputList_L(L);
				break;
			}
			printf("要删除的是%d后面的元素\n", p->data);
			printf("\n删除成功！被删除元素是 %d\n", a);
			printf("\n删除第%d个位置的元素之后：\n", i);
			OutputList_L(L);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}
