#include<stdio.h> 
#include<malloc.h>
#include<stdlib.h>

//��������
#define  MAX_VERTEX   20
#define VertexType  char
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define  MAXQSIZE  30 // �洢�ռ�ĳ�ʼ������

//���Ͷ���
typedef  int  ElemType;

typedef struct {//ѭ���������Ͷ���
	ElemType  *base;
	int front;
	int rear;
	int maxSize;
} SqQueue;

typedef struct { // ͼ���ڽӾ���洢�ṹ����
     VertexType    vexs[MAX_VERTEX];   // ������Ϣ
     int    arcs [MAX_VERTEX] [MAX_VERTEX];  // ������Ϣ                     
     int    vexnum, arcnum;   // ������������      
} MGraph;

typedef int Status;

//ȫ�ֱ���
int visited[MAX_VERTEX];//���ʱ�־


//��������
Status InitQueue(SqQueue &Q);
Status QueueEmpty (SqQueue Q);
Status EnQueue (SqQueue &Q, ElemType e) ;
Status DeQueue (SqQueue &Q, ElemType &e) ;

int Locate(MGraph G, VertexType e); //�ڽӾ����ж�λ����λ��
void CreateMGraph(MGraph &G,int kind); //�����ڽӾ���洢
void BFSTraverse(MGraph G);

//��������
main()
{
	//�������G���洢һ��ͼ�Ķ������ڽӾ���
	MGraph G;
	//�ڽӾ����ʼ��ֵΪ0
	for(int i=0;i<MAX_VERTEX;i++)
		for(int j=0;j<MAX_VERTEX;j++)
			G.arcs[i][j] = 0;
	//�����û����룬�����ڽӾ���洢
	CreateMGraph(G);
	//��ͼ���й��������������
	BFSTraverse(G);	
	printf("\n");
}

int Locate(MGraph G, VertexType e){
//����e����ʾ�Ķ�����G�Ķ�����еĴ洢λ��
	int i;
	for(i=0; i<G.vexnum ;i++){
		if(vexs[i]==e) break;	
	}
	return i;
}

void BFSTraverse(MGraph G) {
  //��������ȱ���ͼG��ʹ�ø�������Q�ͷ��ʱ�־����
  int v;
  SqQueue Q; 
  for(v=1; v<=G.vexnum; v++)	visited[v] = 0;
  InitQueue(Q);
  for(v=1; v<=G.vexnum; v++)
       if(!visited[v])	
       {	    
	   		visited[v]=1; Visit(v);	
	    	EnQueue(Q,v);   
	    	while(!QueueEmpty(Q))
	    		{    DeQueue(Q,u);
	          		for(w=1; w<=G.vexnum; w++){  
						if(G.arcs[u][w]!=0 && !visited[w])
		      				{
							  	visit(w);     visited[w] = 1;
		       					EnQueue(Q,w); 
		       				} 
					}
        		}
       }
}



void CreateMGraph(MGraph &G){
//����G���ڽӾ���洢
	printf("�����붥�����ͱ��������ŷָ�����");
		scanf("%d,%d",&G.vexnum,&G.arcnum);
	printf("����%d��������Ϣ(��Ҫ�ӷָ���)��\n",G.vexnum);
	fflush(stdin);  //�ڽ����ַ����ַ�������֮�䣬������뻺����
	for(i=0; i<G.vexnum ;i++)
		scanf("%c",&G.vexs[i]);
	printf("����ߵ���Ϣ(��������֮���ö��ŷָ�):\n");
	for(i=0;i<G.arcnum;i++){
		fflush(stdin);
		scanf("%c,%c",&e1,&e2);
		m = Locate(G,e1);  //��������Ķ����ڶ�����еĴ洢λ��
		n = Locate(G,e2);		 
		G.arcs[m][n]=1;
		G.arcs[n][m]=1; 			
	

}  

//��ʼ���ն���
Status InitQueue(SqQueue &Q){
	Q.base=(ElemType*)malloc(MAXQSIZE*sizeof(ElemType));
	if(!Q.base)	exit(OVERFLOW);
	Q.front=Q.rear=0;
	Q.maxSize = MAXQSIZE;
	return OK;
}
//�ж����Ƿ�Ϊ��
Status QueueEmpty (SqQueue Q) {
	if(Q.rear==Q.front) return   TRUE;
	else 
		return   FALSE ;
}
//��Ӻ���
Status EnQueue (SqQueue &Q, ElemType e) {
	//������������ʧ�� 
	if((Q.rear + 1)%Q.maxSize==Q.front)	return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear +1)%Q.maxSize; 
	return OK;	 
}
//���Ӻ���
Status DeQueue (SqQueue &Q, ElemType &e) {
	//����ӿգ�����ʧ�� 
	if(Q.rear==Q.front)	return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front +1)%Q.maxSize; 
	return OK;	 
}
