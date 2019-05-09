#include <stdio.h>
#include <stdlib.h>

#define OK   1
#define ERROR   0
#define TRUE 1
#define FALSE 0
#define OVERFLOW   -2
typedef  int  Status;
//-------图的数组（邻接矩阵）存储表示 --------
#define INFINITY  10000							//最大值
#define MAX_VERTEX_NUM  20						//最大顶点个数
typedef enum { DG, DN , UDG , UDN } GraphKind;	//{有向图，有向网 ，无向图 ，无向网}
typedef struct ArcCell{
	VRType	adj;								//VRType是顶点关系类型。对无权图，用1或0
												//表示相邻否；对带权图，则为权值类型。
	InfoType  * info;							//该弧相关信息的指针 
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];			//顶点向量
	AdjMatrix  arcs;							//邻接矩阵
	int 	   vexnum, arcnum;					//图的当前顶点数和弧数
	GraphKind  kind;							//图的种类标志		 
}MGraph; 


Status CreateGraph(MGraph &G){
	//采用数组（邻接矩阵）表示法，构造图G。
	scanf(&G.kind);
	switch(G.kind){
		case  DG: return CreateDG(G);			//构造有向图G
		case UDN: return CreateUDN(G);			//构造无向网G
		default : return ERROR;			 
	} 
}//CreateGraph


Status CreateUDN(MGraph &G){
	//采用数组（邻接矩阵）表示法，构造无向网G。
	int i,j,k;
	scanf(&G.vexnum, &G.arcnum, &IncInfo);		//IncInfo为 0 则各弧不含其它信息 
	for(i=0; i<G.arcnum ; ++i)
		scanf(&G.vexs[i]);						//构造顶点向量
	for(i=0; i<G.arcnum ; ++i) 					//初始化邻接矩阵 
		for(j=0; j<G.arcnum ; ++j)
			G.arcs[i][j] = { INFINITY, NULL };	//{ adj,info }
	for(k=0; k<G.arcnum ; ++k){
		//构造邻接矩阵
		scanf(&v1,&v2,&w);						//输入一条边依附的顶点及权值
			i = LocateVex(G,v1);
			j = LocateVex(G,v2);				//确定v1，v2在G中位置
		 	G.arcs[i][j].adj = w;				//弧<v1,v2>的权值
		if(IncInfo) Input( * G.arcs[i][j].info);//若弧有相关信息，则输入
			G.arcs[j][i] = G.arcs[i][j];		//置<v1,v2>的对称弧<,v2,v1> 
	}
	return OK;	 
}//CreateUDN


Status Locatevex(G,u){
	
} 



