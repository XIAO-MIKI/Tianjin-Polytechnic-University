#include <stdio.h>  
#define MaxVertexNum 50  
#define QueueSize 50  
 
typedef enum{FALSE,TRUE}shifou;  
shifou visited[MaxVertexNum];                                                     
 
typedef struct    //图的邻接矩阵存储结构
{  
 
   char vexs[MaxVertexNum];  //顶点向量  
 
    int edges[MaxVertexNum][MaxVertexNum];     //邻接矩阵  
 
    int vexnum,arcnum;    //图中当前的顶点数和边数  
 
}MGraph;  
 
/* 邻接矩阵的建立*/ 
 
void CreateGraph(MGraph *G)  
{   
    int i,j,k;  
    char ch1,ch2;  
 
    printf("请输入顶点数和边数（逗号分隔）：");  
 
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));  
 
    printf("请输入顶点名称(输入格式为:a,b,c...)：");  
 
    for(i=0;i<G->vexnum;i++)  
    {  
       getchar();
       scanf("%c",&(G->vexs[i]));  
    }  
 
    for(i=0;i<G->vexnum;i++)  //邻接矩阵初始化 
        for(j=0;j<G->vexnum;j++)  
            G->edges[i][j]=0;  
 
        printf("请输入每条边对应的两个顶点名称(输入格式为:a,b):\n");  
 
        for(k=0;k<G->arcnum;k++)  
        {  
            getchar();  
            printf("请输入第%d条边的两个顶点名称：",k+1);  
            scanf("%c,%c",&ch1,&ch2);  
            for(i=0;ch1!=G->vexs[i];i++);  
            for(j=0;ch2!=G->vexs[j];j++);  
	        G->edges[j][i]=1;
            G->edges[i][j]=1;  
        }  
}  
 
/* 深度优先遍历 */ 
 
void Depth(MGraph *G,int i)  
{  
    int j;  
 
    printf("%c",G->vexs[i]);   //访问顶点vi  
 
    visited[i]=TRUE;          
 
    for(j=0;j<G->vexnum;j++)           //依次搜索vi邻接点  
        if(G->edges[i][j]==1 && !visited[j])  
            Depth(G,j);  
}  
 
void Depthsearch(MGraph *G)  
{  
 
    int i;  
 
    for(i=0;i<G->vexnum;i++)  
        visited[i]=FALSE;     
 
    for(i=0;i<G->vexnum;i++)  
        if(!visited[i])   
            Depth(G,i);  
}  
 
/*广度优先遍历*/ 
 
typedef struct 
{  
    int front;  
    int rear;  
    int count;  
    int data[QueueSize];  
}AQueue;   
 
void InitQueue(AQueue *Q)  
{  
    Q->front=Q->rear=0;  
    Q->count=0;  
}  
 
int QueueEmpty(AQueue *Q)  
{  
    return Q->count!=QueueSize;  
 
}  
 
int QueueFull(AQueue *Q)  
{  
    return Q->count==QueueSize;  
}  
 
void EnQueue(AQueue *Q,int x)  
{   
 
    if (QueueFull(Q))  
        printf("队满，出队失败");  
    else 
    {   
        Q->count++;  
        Q->data[Q->rear]=x;  
        Q->rear=(Q->rear+1)%QueueSize;  
    }  
}  
 
int DeQueue(AQueue *Q)  
{  
    int temp;  
    if(QueueEmpty(Q))  
    {   
        printf("队空，出队失败");  
        return 0;  
    }  
    else 
    {  
        temp=Q->data[Q->front];  
        Q->count--;  
        Q->front=(Q->front+1)%QueueSize;  
        return temp;  
    }  
}  
 
void Breadth(MGraph *G,int k)  
{   
    int i,j;  
    AQueue Q;  
    InitQueue(&Q);  
    printf("%c",G->vexs[k]);  
    visited[k]=TRUE;  
    EnQueue(&Q,k);  
    while (!QueueEmpty(&Q))  
    {  
        i=DeQueue(&Q);  
        for (j=0;j<G->vexnum;j++)  
            if(G->edges[i][j]==1&&!visited[j])  
            {  
                printf("%c\n",G->vexs[j]);  
                visited[j]=TRUE;  
                EnQueue(&Q,j);  
            }  
    }  
}  
 
void Breadthsearch(MGraph *G)  
{  
    int i;  
    for (i=0;i<G->vexnum;i++)  
        visited[i]=FALSE;  
    for (i=0;i<G->vexnum;i++)  
        if (!visited[i])   
            Breadth(G,i);  
}  
 
int main()  
{  
    MGraph G;  
    CreateGraph(&G);
    printf("深度优先搜索结果为：");
    printf("\n");  
    Depthsearch(&G); 
    printf("广度优先搜索结果为：");
    printf("\n");  
    Breadthsearch(&G);  
}

