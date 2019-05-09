#include <stdio.h>
#include <stdlib.h>

#define OK   1
#define ERROR   0
#define TRUE 1
#define FALSE 0
#define OVERFLOW   -2
typedef  int  Status;
//-------ͼ�����飨�ڽӾ��󣩴洢��ʾ --------
#define INFINITY  10000							//���ֵ
#define MAX_VERTEX_NUM  20						//��󶥵����
typedef enum { DG, DN , UDG , UDN } GraphKind;	//{����ͼ�������� ������ͼ ��������}
typedef struct ArcCell{
	VRType	adj;								//VRType�Ƕ����ϵ���͡�����Ȩͼ����1��0
												//��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ���͡�
	InfoType  * info;							//�û������Ϣ��ָ�� 
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];			//��������
	AdjMatrix  arcs;							//�ڽӾ���
	int 	   vexnum, arcnum;					//ͼ�ĵ�ǰ�������ͻ���
	GraphKind  kind;							//ͼ�������־		 
}MGraph; 


Status CreateGraph(MGraph &G){
	//�������飨�ڽӾ��󣩱�ʾ��������ͼG��
	scanf(&G.kind);
	switch(G.kind){
		case  DG: return CreateDG(G);			//��������ͼG
		case UDN: return CreateUDN(G);			//����������G
		default : return ERROR;			 
	} 
}//CreateGraph


Status CreateUDN(MGraph &G){
	//�������飨�ڽӾ��󣩱�ʾ��������������G��
	int i,j,k;
	scanf(&G.vexnum, &G.arcnum, &IncInfo);		//IncInfoΪ 0 ���������������Ϣ 
	for(i=0; i<G.arcnum ; ++i)
		scanf(&G.vexs[i]);						//���춥������
	for(i=0; i<G.arcnum ; ++i) 					//��ʼ���ڽӾ��� 
		for(j=0; j<G.arcnum ; ++j)
			G.arcs[i][j] = { INFINITY, NULL };	//{ adj,info }
	for(k=0; k<G.arcnum ; ++k){
		//�����ڽӾ���
		scanf(&v1,&v2,&w);						//����һ���������Ķ��㼰Ȩֵ
			i = LocateVex(G,v1);
			j = LocateVex(G,v2);				//ȷ��v1��v2��G��λ��
		 	G.arcs[i][j].adj = w;				//��<v1,v2>��Ȩֵ
		if(IncInfo) Input( * G.arcs[i][j].info);//�����������Ϣ��������
			G.arcs[j][i] = G.arcs[i][j];		//��<v1,v2>�ĶԳƻ�<,v2,v1> 
	}
	return OK;	 
}//CreateUDN


Status Locatevex(G,u){
	
} 



