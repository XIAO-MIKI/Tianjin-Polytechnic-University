#include<stdio.h> 
#include<malloc.h>
#include<stdlib.h>

//常量定义
#define  MAX_VERTEX   20
#define VertexType  char
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define  MAXQSIZE  30 // 存储空间的初始分配量

//类型定义
typedef  int  ElemType;

typedef struct {//循环队列类型定义
	ElemType  *base;
	int front;
	int rear;
	int maxSize;
} SqQueue;

typedef struct { // 图的邻接矩阵存储结构定义
     VertexType    vexs[MAX_VERTEX];   // 顶点信息
     int    arcs [MAX_VERTEX] [MAX_VERTEX];  // 弧的信息                     
     int    vexnum, arcnum;   // 顶点数，弧数      
} MGraph;

typedef int Status;

//全局变量
int visited[MAX_VERTEX];//访问标志


//函数声明
Status InitQueue(SqQueue &Q);
Status QueueEmpty (SqQueue Q);
Status EnQueue (SqQueue &Q, ElemType e) ;
Status DeQueue (SqQueue &Q, ElemType &e) ;

int Locate(MGraph G, VertexType e); //邻接矩阵中定位顶点位标
void CreateMGraph(MGraph &G,int kind); //创建邻接矩阵存储
void BFSTraverse(MGraph G);

//函数定义
main()
{
	//定义变量G，存储一个图的顶点表和邻接矩阵
	MGraph G;
	//邻接矩阵初始化值为0
	for(int i=0;i<MAX_VERTEX;i++)
		for(int j=0;j<MAX_VERTEX;j++)
			G.arcs[i][j] = 0;
	//根据用户输入，创建邻接矩阵存储
	CreateMGraph(G);
	//对图进行广度优先搜索遍历
	BFSTraverse(G);	
	printf("\n");
}

int Locate(MGraph G, VertexType e){
//返回e所表示的顶点在G的顶点表中的存储位置
	int i;
	for(i=0; i<G.vexnum ;i++){
		if(vexs[i]==e) break;	
	}
	return i;
}

void BFSTraverse(MGraph G) {
  //按广度优先遍历图G，使用辅助队列Q和访问标志数组
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
//创建G的邻接矩阵存储
	printf("请输入顶点数和边数（逗号分隔）：");
		scanf("%d,%d",&G.vexnum,&G.arcnum);
	printf("输入%d个顶点信息(不要加分隔符)：\n",G.vexnum);
	fflush(stdin);  //在接收字符或字符串数据之间，清空输入缓冲区
	for(i=0; i<G.vexnum ;i++)
		scanf("%c",&G.vexs[i]);
	printf("输入边的信息(两个顶点之间用逗号分隔):\n");
	for(i=0;i<G.arcnum;i++){
		fflush(stdin);
		scanf("%c,%c",&e1,&e2);
		m = Locate(G,e1);  //查找输入的顶点在顶点表中的存储位置
		n = Locate(G,e2);		 
		G.arcs[m][n]=1;
		G.arcs[n][m]=1; 			
	

}  

//初始化空队列
Status InitQueue(SqQueue &Q){
	Q.base=(ElemType*)malloc(MAXQSIZE*sizeof(ElemType));
	if(!Q.base)	exit(OVERFLOW);
	Q.front=Q.rear=0;
	Q.maxSize = MAXQSIZE;
	return OK;
}
//判队列是否为空
Status QueueEmpty (SqQueue Q) {
	if(Q.rear==Q.front) return   TRUE;
	else 
		return   FALSE ;
}
//入队函数
Status EnQueue (SqQueue &Q, ElemType e) {
	//如果队满，入队失败 
	if((Q.rear + 1)%Q.maxSize==Q.front)	return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear +1)%Q.maxSize; 
	return OK;	 
}
//出队函数
Status DeQueue (SqQueue &Q, ElemType &e) {
	//如果队空，出队失败 
	if(Q.rear==Q.front)	return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front +1)%Q.maxSize; 
	return OK;	 
}
