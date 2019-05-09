#include <stdio.h>  
#define MaxVertexNum 50  
#define QueueSize 50  
 
typedef enum{FALSE,TRUE}shifou;  
shifou visited[MaxVertexNum];                                                     
 
typedef struct    //ͼ���ڽӾ���洢�ṹ
{  
 
   char vexs[MaxVertexNum];  //��������  
 
    int edges[MaxVertexNum][MaxVertexNum];     //�ڽӾ���  
 
    int vexnum,arcnum;    //ͼ�е�ǰ�Ķ������ͱ���  
 
}MGraph;  
 
/* �ڽӾ���Ľ���*/ 
 
void CreateGraph(MGraph *G)  
{   
    int i,j,k;  
    char ch1,ch2;  
 
    printf("�����붥�����ͱ��������ŷָ�����");  
 
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));  
 
    printf("�����붥������(�����ʽΪ:a,b,c...)��");  
 
    for(i=0;i<G->vexnum;i++)  
    {  
       getchar();
       scanf("%c",&(G->vexs[i]));  
    }  
 
    for(i=0;i<G->vexnum;i++)  //�ڽӾ����ʼ�� 
        for(j=0;j<G->vexnum;j++)  
            G->edges[i][j]=0;  
 
        printf("������ÿ���߶�Ӧ��������������(�����ʽΪ:a,b):\n");  
 
        for(k=0;k<G->arcnum;k++)  
        {  
            getchar();  
            printf("�������%d���ߵ������������ƣ�",k+1);  
            scanf("%c,%c",&ch1,&ch2);  
            for(i=0;ch1!=G->vexs[i];i++);  
            for(j=0;ch2!=G->vexs[j];j++);  
	        G->edges[j][i]=1;
            G->edges[i][j]=1;  
        }  
}  
 
/* ������ȱ��� */ 
 
void Depth(MGraph *G,int i)  
{  
    int j;  
 
    printf("%c",G->vexs[i]);   //���ʶ���vi  
 
    visited[i]=TRUE;          
 
    for(j=0;j<G->vexnum;j++)           //��������vi�ڽӵ�  
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
 
/*������ȱ���*/ 
 
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
        printf("����������ʧ��");  
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
        printf("�ӿգ�����ʧ��");  
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
    printf("��������������Ϊ��");
    printf("\n");  
    Depthsearch(&G); 
    printf("��������������Ϊ��");
    printf("\n");  
    Breadthsearch(&G);  
}

