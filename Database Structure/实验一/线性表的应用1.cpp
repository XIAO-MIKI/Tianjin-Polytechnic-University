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
	//���ڴ���д���룬�����㷨�����������μ��α��Ϳμ�����½� 
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


//˳���ɾ��Ԫ�غ���
Status ListDelete_Sq(SqList &L, int i, ElemType  &e) {
	//���ڴ���д���룬�����㷨�����������μ��α��Ϳμ�����½�
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
//������
int main()
{
	SqList L;
	int cord, i; ElemType a;
	printf("��һ��ʹ�ñ����ʼ����\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ��ʼ��˳��� ");
		printf(" 2 ����һ��Ԫ�� ");
		printf(" 3 ɾ��һ��Ԫ�� ");
		printf(" 4 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			InitSqlist(L);
			printf("������Ҫ����Ԫ�صĸ�����\n");
			int b ,c ,num ;
			scanf("%d",&num);
			printf("�����������ʼ˳����%d��Ԫ�أ�\n",num);
			for(b=1;b<=num;b++){
				scanf("%d",&c);
				if (ListInsert_Sq(L, b, c) == ERROR){
					printf("��%d�����������ʧ��\n",b);
				}
			}
			OutList_Sq(L);
			break;
		case 2:
			printf("\n������Ҫ����Ĳ���λ�ú�����Ԫ�أ��磺3 20��");
			scanf("%d%d", &i, &a);
			if (ListInsert_Sq(L, i, a) != ERROR)
				printf("\n����%dԪ��֮���", a);
			else 	printf("\n�������ʧ��!");
			OutList_Sq(L);
			break;
		case 3:
			printf("\n������Ҫɾ��������Ԫ�ص�λ�ã��磺 3��");
			scanf("%d", &i);
			if (ListDelete_Sq(L, i, a) != ERROR)
				printf("\nɾ����%d��λ�õ�Ԫ��֮��", i);
			else	printf("\nɾ������ʧ�ܣ�");
			OutList_Sq(L);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}
