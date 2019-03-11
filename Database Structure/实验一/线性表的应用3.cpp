#include <stdio.h>
#include <stdlib.h>

#define OK   1
#define ERROR   0
#define TRUE 1
#define FALSE 0
#define OVERFLOW   -2
typedef  int  ElemType;
typedef  int  Status;

//----- ˳����˳��洢��ʾ -----
#define LIST_INIT_SIZE 100 // �洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10 // �洢�ռ�ķ�������
typedef struct {
	ElemType	*elem;	// �洢�ռ�Ļ�ַ
	int length; // ��
	int size;// �洢����
	int increment; // ����ʱ�����ӵĴ洢����
} SqList;  //˳���ṹ���Ͷ���

// ����һ����˳��� 
Status InitSqlist(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.size = LIST_INIT_SIZE;
	L.increment = LISTINCREMENT;
	return OK;
}

// ��˳����Ƿ�Ϊ�ձ� 
Status ListEmpty(SqList L) {
	if (L.length == 0) return TRUE;
	else return FALSE;
}

//˳�����뺯��
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	int *newbase; 
	if (i<1 || i>L.length + 1) return ERROR;//iֵ���Ϸ�
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
	if (i<1 || i>L.length) return ERROR;//iֵ���Ϸ�
	p = & (L.elem[i-1]);
	e = *p;
	return e;
}


//˳���ɾ��Ԫ�غ���
Status ListDelete_Sq(SqList &L, int i, ElemType  &e) {
	int *p,*q;
	if (i<1 || i>L.length) return ERROR;//iֵ���Ϸ�
	p = & (L.elem[i-1]);
	e = *p;
	q = L.elem+L.length-1;
	for(++p; p<=q; ++p)*(p-1)  = *p;
	--L.length;
	return OK;
}

//���˳�����
void OutList_Sq(SqList L)
{
	int i;
	ElemType  e;
	if (ListEmpty(L)) {
		printf("����һ���ձ�");
	}
	else
	{
		printf("˳���Ϊ��");
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
	printf("��һ��ʹ�ñ����ʼ����\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ��ʼ��˳���La ");
		printf(" 2 ��ʼ��˳���Lb ");
		printf(" 3 �ϲ���La���Lb ");
		printf(" 4 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			InitSqlist(La);
			printf("������Ҫ�����LaԪ�صĸ�����\n");
			int b ,c ,num ;
			scanf("%d",&num);
			printf("�밴�մ�С�����˳�����������ʼ˳����%d��Ԫ�أ�\n",num);
			for(b=1;b<=num;b++){
				scanf("%d",&c);
				if (ListInsert_Sq(La, b, c) == ERROR){
					printf("��%d�����������ʧ��\n",b);
				}
			}
			OutList_Sq(La);
			break;
		case 2:
			InitSqlist(Lb);
			printf("������Ҫ�����LbԪ�صĸ�����\n");
			int b2 ,c2 ,num2 ;
			scanf("%d",&num2);
			printf("�밴�մ�С�����˳�����������ʼ˳����%d��Ԫ�أ�\n",num2);
			for(b2=1;b2<=num2;b2++){
				scanf("%d",&c2);
				if (ListInsert_Sq(Lb, b2, c2) == ERROR){
					printf("��%d�����������ʧ��\n",b);
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

