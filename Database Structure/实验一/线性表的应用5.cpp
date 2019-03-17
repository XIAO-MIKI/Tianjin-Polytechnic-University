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

//以下是建立单链表
void CreatPolyn(Polynomial &lp, int n)
{    
	int i;
	LNode  *p,  *q;
	ElemType w;
    InitList_L(lp);
    p = lp;	
    printf("请按照（0.1 2）格式输入，其中0.1为多项式系数项，2为指数项\n");
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
    while(pa!=NULL&&pb!=NULL){ //确定遍历范围
	if (( pa->data.e ) < ( pb->data.e))  
		{
			ha = pa;
			pa = pa->next;
		}
    	else if (( pa->data.e ) == ( pb->data.e)) //找到指数相等项时
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
		else  if (( pa->data.e ) > ( pb->data.e))  //前插
		{	
			ha->next = pb;
			ha = ha->next;
			pb = pb->next;
			ha->next = pa;
		}
   }//end while
   		if(pb != NULL)   //如果LB中还有未处理的元素
   		pa->next  = pb;
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
	printf("多项式为:\n");
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
	printf("\n请先创建多项式！\n");
	do {
		printf("\n 主菜单 \n");
		printf(" 1 初始化多项式LA ");
		printf(" 2 初始化多项式LB ");
		printf(" 3 合并多项式LA与LB ");
		printf(" 4 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			printf("\n输入LA的项数！\n");
			scanf("%d",&a) ;
			CreatPolyn(LA, a);
			OutputList_L(LA);
			break;
		case 2:
			printf("\n输入LB的项数！\n");
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
