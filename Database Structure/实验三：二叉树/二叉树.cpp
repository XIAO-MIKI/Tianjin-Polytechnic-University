#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100
#define OK   1
#define ERROR   0
#define TRUE  1
#define FALSE  0
#define OVERFLOW   -2
//--------------------�������Ķ�������洢��ʾ -----------------
typedef  char  TElemType;
typedef  int  Status;
typedef  struct  BiTNode{
	TElemType  data;
	struct  BiTNode  *lchild ,*rchild;//���Һ���ָ�� 
}BiTNode,  *BiTree;
//--------------------------------------------------------------



//--------------------ջ��˳��洢��ʾ -------------------------

#define STACK_INIT_SIZE 10 //ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 5//ջ�洢�ռ�ķ�������
typedef BiTree ElemType;
typedef struct {
	ElemType *base;
	ElemType  *top;
	int  stackSize;
} SqStack;
//--------------------------------------------------------------	



//��������������ĺ��� 
void safe_flush(FILE *fp){
	int ch;
	while( (ch = fgetc(fp)) != EOF && ch!= '\n');
}


//-------------------------������������------------------------- 


//���������������� 
Status  CreateBiTree(BiTree  &T){
	//�������������������нڵ��ֵ��һ���ַ������ո��ַ���ʾ���� 
	//������������ʾ�Ķ�����T 
	safe_flush(stdin);//��������� 
	char ch;
	scanf("%c",&ch);
	if(ch == ' ')  T = NULL;
	else{
		if(!(T = (BiTNode * )malloc(sizeof(BiTNode))))     exit(OVERFLOW);
		T->data = ch;					//���ɸ��ڵ� 
		printf("����%c�����ӽڵ㣺",ch);
		CreateBiTree(T->lchild);		//���������� 
		printf("����%c�����ӽڵ㣺",ch);
		CreateBiTree(T->rchild);		//���������� 
	} 
	return OK;
} //CreateBiTree


Status PrintElement(TElemType e){
	//Visit����---�������e��ֵ 
	printf("%c  ",e);
	return OK; 
} 


//������� 
Status PreOrderTraverse(BiTree T,Status( * Visit)(TElemType e) ){
	//���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
	//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
	//����ʵ����
	//PreOrderTraverse(T,PrintElement);
	if(T){
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))	return OK;
			return ERROR;
	} else	return OK;
} //PreOrderTraverse


//������� 
Status InOrderTraverse(BiTree T,Status( * Visit)(TElemType e)){
    if(T){
		if(InOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
				if(InOrderTraverse(T->rchild,Visit))	return OK;
			return ERROR;
	} else	return OK;
}


//�������� 
Status PostOrderTraverse(BiTree T,Status( * Visit)(TElemType e)){
    if(T){
		if(PostOrderTraverse(T->lchild,Visit))
			if(PostOrderTraverse(T->rchild,Visit))
				if(Visit(T->data))	return OK;
			return ERROR;
	} else	return OK;
}


//���ĸ߶� 
int TreeDeep(BiTNode *T){
    int deep = 0;
    if (T != NULL)
    {
        int leftdeep = TreeDeep(T->lchild);
        int rightdeep = TreeDeep(T->rchild);
        deep = leftdeep >= rightdeep?leftdeep+1:rightdeep+1;
    }
    else return 0;
    return deep;
}


//Ҷ���� 
int LeafCount(BiTNode *T){
    static int count;
    if (T != NULL)
    {
        if (T->lchild == NULL && T->rchild == NULL)
        {
            count++;
        }

        LeafCount(T->lchild);
        LeafCount(T->rchild);
    }
	else return 1;
    return count;
}

 
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
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}


//�ǵݹ��������������T
void InOrder(BiTree T)
{
	SqStack S;
	InitStack(S);
	BiTree p;
	p = T;
	do{
		if(p !=NULL)
		{
			Push(S,p);
			p=p->lchild;
		} 
		else
		{
			Pop(S,p);
			printf("%c",p->data);
			p=p->rchild;
		}
	}while(p!=NULL || !StackEmpty(S));
} 


//������
main()
{
	BiTree T;
	int cord;
	printf("ʹ��ǰ�����ȹ����������\n");
	do
	{
		printf("\n ���˵� \n");
		printf("\n-------------------------------------------------------------------\n");
		printf(" 1 ����������������      \n");
		printf(" 2 ����������������ݹ飩  \n");
		printf(" 3 ����������������ݹ飩  \n"); 
		printf(" 4 ����������������ݹ飩  \n");
		printf(" 5 ����������������ǵݹ飩\n");
		printf(" 6 ��������������        \n");
		printf(" 7 �����������Ҷ����      \n");
		printf(" 8 �˳�                    \n"); 
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4, 5, 6, 7, 8)");
		scanf("%d",&cord);
		printf("\n");
	switch(cord){  
	case 1:
			CreateBiTree(T);
			break;
	case 2:
			PreOrderTraverse (T,PrintElement);
			break;
	case 3:
			InOrderTraverse  (T,PrintElement);
			break;
	case 4: 
			PostOrderTraverse(T,PrintElement);
			break;
	case 5: 
			InOrder(T);
			break;
	case 6: 			
			TreeDeep(T);
			printf("���ĸ߶�Ϊ��%d",TreeDeep(T));
			break;
	case 7:
			LeafCount(T);
			printf("����Ҷ����Ϊ��%d",LeafCount(T));
			break;
	case 8:
			exit(0);
		}
	}
	while (cord<=8);
} 
