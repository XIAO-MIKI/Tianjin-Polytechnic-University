#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100
#define OK   1
#define ERROR   0
#define TRUE  1
#define FALSE  0
#define OVERFLOW   -2
//--------------------二叉树的二叉链表存储表示 -----------------
typedef  char  TElemType;
typedef  int  Status;
typedef  struct  BiTNode{
	TElemType  data;
	struct  BiTNode  *lchild ,*rchild;//左右孩子指针 
}BiTNode,  *BiTree;
//--------------------------------------------------------------



//--------------------栈的顺序存储表示 -------------------------

#define STACK_INIT_SIZE 10 //栈存储空间的初始分配量
#define STACKINCREMENT 5//栈存储空间的分配增量
typedef BiTree ElemType;
typedef struct {
	ElemType *base;
	ElemType  *top;
	int  stackSize;
} SqStack;
//--------------------------------------------------------------	



//用于清除缓冲区的函数 
void safe_flush(FILE *fp){
	int ch;
	while( (ch = fgetc(fp)) != EOF && ch!= '\n');
}


//-------------------------基本操作函数------------------------- 


//先序遍历构造二叉树 
Status  CreateBiTree(BiTree  &T){
	//按先序次序输入二叉树中节点的值（一个字符），空格字符表示空树 
	//构造二叉链表表示的二叉树T 
	safe_flush(stdin);//清除缓冲区 
	char ch;
	scanf("%c",&ch);
	if(ch == ' ')  T = NULL;
	else{
		if(!(T = (BiTNode * )malloc(sizeof(BiTNode))))     exit(OVERFLOW);
		T->data = ch;					//生成根节点 
		printf("输入%c的左子节点：",ch);
		CreateBiTree(T->lchild);		//构造左子树 
		printf("输入%c的右子节点：",ch);
		CreateBiTree(T->rchild);		//构造右子树 
	} 
	return OK;
} //CreateBiTree


Status PrintElement(TElemType e){
	//Visit函数---输出函数e的值 
	printf("%c  ",e);
	return OK; 
} 


//先序遍历 
Status PreOrderTraverse(BiTree T,Status( * Visit)(TElemType e) ){
	//采用二叉链表存储结构，Visit是对数据元素操作的应用函数
	//先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
	//调用实例：
	//PreOrderTraverse(T,PrintElement);
	if(T){
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))	return OK;
			return ERROR;
	} else	return OK;
} //PreOrderTraverse


//中序遍历 
Status InOrderTraverse(BiTree T,Status( * Visit)(TElemType e)){
    if(T){
		if(InOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
				if(InOrderTraverse(T->rchild,Visit))	return OK;
			return ERROR;
	} else	return OK;
}


//后续遍历 
Status PostOrderTraverse(BiTree T,Status( * Visit)(TElemType e)){
    if(T){
		if(PostOrderTraverse(T->lchild,Visit))
			if(PostOrderTraverse(T->rchild,Visit))
				if(Visit(T->data))	return OK;
			return ERROR;
	} else	return OK;
}


//树的高度 
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


//叶子数 
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
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}


//非递归中序遍历二叉树T
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


//主函数
main()
{
	BiTree T;
	int cord;
	printf("使用前必须先构造二叉树！\n");
	do
	{
		printf("\n 主菜单 \n");
		printf("\n-------------------------------------------------------------------\n");
		printf(" 1 先序遍历构造二叉树      \n");
		printf(" 2 先序遍历二叉树（递归）  \n");
		printf(" 3 中序遍历二叉树（递归）  \n"); 
		printf(" 4 后序遍历二叉树（递归）  \n");
		printf(" 5 中序遍历二叉树（非递归）\n");
		printf(" 6 计算二叉树的深度        \n");
		printf(" 7 计算二叉树的叶子数      \n");
		printf(" 8 退出                    \n"); 
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4, 5, 6, 7, 8)");
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
			printf("树的高度为：%d",TreeDeep(T));
			break;
	case 7:
			LeafCount(T);
			printf("树的叶子数为：%d",LeafCount(T));
			break;
	case 8:
			exit(0);
		}
	}
	while (cord<=8);
} 
