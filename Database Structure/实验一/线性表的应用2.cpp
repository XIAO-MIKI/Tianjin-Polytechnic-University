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

//�����ǽ���������
void CreatList_L(LinkList &head)
{
	LinkList tail, p;
	int n, i;
	head = tail = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	printf("\n����������ĳ���:");
	scanf("%d", &n);
	printf("\n������%d����������Ԫ��", n);
	for (i = 1; i <= n; i++) {
		p = (LNode *)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	printf("\n������Ľ����ɹ�!");
}

//����i��Ԫ�ص�ֵ��ֵ��e�������ص�i���ڵ�ĵ�ַ
LNode* GetElem_L(LinkList L, int  i, ElemType e)
{
	LNode *p;
	int  j = 0;
	if (L == NULL || L->next == NULL)	return NULL;
	p = L;
	//���ڴ���д���룬�����㷨�����������μ��α��Ϳμ�����½�
	while(p && j < i){
		p = p->next;
		++j;
	}
	if (p == NULL) return ERROR;
	e = p->data;
	return  p;
}

//��ָ��pָ��Ľ��������ָ��qָ��Ľ��     
Status InsertAfter_L(LNode *p, ElemType &e) {
	LNode *q;
	if (NULL == p) return ERROR;
	//���ڴ���д���룬�����㷨�����������μ��α��Ϳμ�����½�
	q = (LNode*)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return OK;
}
//ɾ��ָ��pָ����ĺ�̽�㣬������̽��Ԫ�ص�ֵ��ֵ������e
Status DeleteAfter_L(LNode *p, ElemType &e) {
	LNode *q;
	if (NULL == p || NULL == p->next)     return ERROR;
	//���ڴ���д���룬�����㷨�����������μ��α��Ϳμ�����½�
	q=p->next;	
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}
//���������������
void OutputList_L(LinkList L) {
	LinkList p = L->next;
	if (p == NULL) {
		printf("��һ���ձ�\n");
		return;
	}
	printf("��������:");
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
	printf("\n��һ��ʹ�����ȴ���һ��������\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ����һ�������� ");
		printf(" 2 ����һ��Ԫ�� ");
		printf(" 3 ɾ��һ��Ԫ�� ");
		printf(" 4 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			CreatList_L(L);
			OutputList_L(L);
			break;
		case 2:
			printf("\n������Ҫ�����λ�ú�Ԫ��ֵ����:3 20��");
			scanf("%d %d", &i, &a);
			p = GetElem_L(L, i - 1,a);
			if (ERROR == InsertAfter_L(p, a))
			{
				printf("����ʧ�ܣ�");
				OutputList_L(L);
				break;
			}
			printf("\n����ɹ�!����%dԪ��֮���:\n", a);
			OutputList_L(L);
			break;
		case 3:
			printf("\n������Ҫɾ��Ԫ�ص�λ�ã��磺 3��");
			scanf("%d", &i);
			p = GetElem_L(L, i - 1,a);
			if (ERROR == DeleteAfter_L(p, a))
			{
				printf("ɾ��ʧ�ܣ�");
				OutputList_L(L);
				break;
			}
			printf("Ҫɾ������%d�����Ԫ��\n", p->data);
			printf("\nɾ���ɹ�����ɾ��Ԫ���� %d\n", a);
			printf("\nɾ����%d��λ�õ�Ԫ��֮��\n", i);
			OutputList_L(L);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}
