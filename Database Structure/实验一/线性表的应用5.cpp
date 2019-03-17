#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1 
#define TRUE 1
#define FALSE 0

typedef struct{	
	double c;
    int e;
}ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

typedef LinkList  Polynomial;
typedef int Status;

Status   InitList_L(LinkList  &L)
{	L=(LNode *)malloc(sizeof(LNode));
	if(L==NULL)
	     exit(OVERFLOW);
	L->next=NULL;
	return OK;
} //InitList_L

//�����ǽ���������
void CreatPolyn(Polynomial &lp, int n)
{    
	int i;
	LNode  *p,  *q;
	ElemType w;
    InitList_L(lp);
    p = lp;	
    printf("�밴�գ�0.1 2����ʽ���룬����0.1Ϊ����ʽϵ���2Ϊָ����\n");
    for(i=1; i<=n; i++){	
		scanf("%lf%d", &w.c, &w.e );
		q = (LNode*)malloc(sizeof(LNode));
        q->data = w;      
		q->next = NULL;	p->next = q;     
		p = p->next;
    }
}

void AddPolyn(Polynomial &La, Polynomial &Lb){
    LNode  *ha,  *pa,  *pb;
    double tmp;
      	ha=La;
	    pa=La->next;
		pb=Lb->next;
    while(pa!=NULL&&pb!=NULL){ //ȷ��������Χ
	if (( pa->data.e ) < ( pb->data.e))  
		{
			ha = pa;
			pa = pa->next;
		}
    	else if (( pa->data.e ) == ( pb->data.e)) //�ҵ�ָ�������ʱ
			{	
				tmp  = pa->data.c + pb->data.c;
				if( tmp == 0 )	ha->next = pa->next; 
					else
						{	
							pa->data.c = tmp;		
							ha = pa; 					
						}
				pa = pa->next;	pb = pb->next;
			}
		else  if (( pa->data.e ) > ( pb->data.e))  //ǰ��
		{	
			ha->next = pb;
			ha = ha->next;
			pb = pb->next;
			ha->next = pa;
		}
   }//end while
   		if(pb != NULL)   //���LB�л���δ�����Ԫ��
   		pa->next  = pb;
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
	printf("����ʽΪ:\n");
	while (p) {
		printf("%lf\n", p->data.c);
		printf("%4d\n", p->data.e);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	Polynomial LA,LB;
	int cord;
	int a,b;
	printf("\n���ȴ�������ʽ��\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ��ʼ������ʽLA ");
		printf(" 2 ��ʼ������ʽLB ");
		printf(" 3 �ϲ�����ʽLA��LB ");
		printf(" 4 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			printf("\n����LA��������\n");
			scanf("%d",&a) ;
			CreatPolyn(LA, a);
			OutputList_L(LA);
			break;
		case 2:
			printf("\n����LB��������\n");
			scanf("%d",&b) ;
			CreatPolyn(LB, b);
			OutputList_L(LB);
			break;
		case 3:
			AddPolyn(LA,LB);
			OutputList_L(LA);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}
