#include <stdio.h>
#include <stdlib.h>

#define  MAX_VERTEX   20
#define VertexType  char
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define  MAXQSIZE  30 // �洢�ռ�ĳ�ʼ������
typedef  int  Status;
typedef  int  ElemType;
typedef struct { // ͼ���ڽӾ���洢�ṹ����
    VertexType    vexs[MAX_VERTEX];   // ������Ϣ
    int    arcs [MAX_VERTEX] [MAX_VERTEX];  // ������Ϣ                     
    int    vexnum, arcnum;   // ������������      
  } MGraph;
typedef struct {
		ElemType  *base;
		int front;
		int rear;
		int maxSize;
		} SqQueue;
Status Locate(MGraph G, VertexType e); //�ڽӾ����ж�λ����λ��
void DFS(MGraph G,int v);

//ȫ�ֱ���
int visited[MAX_VERTEX];//���ʱ�־

void CreateMGraph(MGraph &G){
	int i,m,n;
	char e1,e2;
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
}
Status Locate(MGraph G,VertexType e)
{
	int i;
	for(i=0; i<G.vexnum ;i++)
	{
		if(G.vexs[i]==e) break;	
	}
	return i;
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

Status Visit(MGraph G,int e){
	//Visit����---�������e��ֵ 
	printf("%c  ",G.vexs[e]);
	return OK; 
} 

void BFSTraverse(MGraph G) {
  //��������ȱ���ͼG��ʹ�ø�������Q�ͷ��ʱ�־����
  int v,u,w;
  SqQueue Q; 
  for(v=0; v<G.vexnum; v++)	visited[v] = 0;
  InitQueue(Q);
  for(v=0; v<G.vexnum; v++)
       if(!visited[v])	
       {	    
	   		visited[v]=1; Visit(G,v);	
	    	EnQueue(Q,v);   
	    	while(!QueueEmpty(Q))
	    		{    DeQueue(Q,u);
	          		for(w=0; w<G.vexnum; w++){  
						if(G.arcs[u][w]!=0 && !visited[w])
		      				{
							  	Visit(G,w);     visited[w] = 1;
		       					EnQueue(Q,w); 
		       				} 
					}
        		}
       }
}

void DFSTraverse(MGraph G){
	int v;
	for(v=0;v<G.vexnum;++v) visited[v] = FALSE;
	for(v=0;v<G.vexnum;++v)
		if(!visited[v])  DFS(G,v);//����δ���ʵĶ������DFS 
} 

void DFS(MGraph G,int v){
	int w;
	Visit(G,v);
	visited[v] = TRUE;
	for(int w=0; w<G.vexnum; w++){  
		if(G.arcs[v][w]!=0 && !visited[w])
		DFS(G,w); 
		}
} 

main(){
	int i,j,v;
	//�������G���洢һ��ͼ�Ķ������ڽӾ���
	MGraph G;
	//�ڽӾ����ʼ��ֵΪ0
	for(int i=0;i<MAX_VERTEX;i++)
		for(int j=0;j<MAX_VERTEX;j++)
			G.arcs[i][j] = 0;
	CreateMGraph(G);
	//��ͼ���й��������������
	printf("BFS���Ϊ��");
	BFSTraverse(G);
	printf("\n");
	printf("DFS���Ϊ��");	
	DFSTraverse(G);
	printf("\n");
}
