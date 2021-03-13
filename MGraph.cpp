#include <iostream>

const int MaxSize=100;
template<class DataType>
class MGraph
{
public:
	MGraph(DataType a[],int n,int e);
	~MGraph(){}
	void DFSTraverse(int v);
	void BFSTraverse(int v);
private:
	DataType vertex[MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum,arcNum;
	int visited[MaxSize];
};

template<class DataType>
MGraph<DataType>::MGraph(DataType a[],int n,int e)
{
	vertexNum=n;
	arcNum=e;
	for (int i=0;i<vertexNum;i++)
	{
		vertex[i]=a[i];
		visited[i]=0;
	}
	for (int i=0;i<vertexNum;i++)
		for (int j=0;j<vertexNum;j++)
			arc[i][j]=0;
	for (int k=0;k<arcNum;k++)
	{
		int i,j;
		std::cin>>i>>j;
		arc[i][j]=1;arc[j][i]=1;
	}
}

template<class DataType>
void MGraph<DataType>::DFSTraverse(int v)
{
	std::cout<<vertex[v];
	visited[v]=1;
	for (int j=0;j<vertexNum;j++)
	{
		if (arc[v][j]==1&&visited[j]==0) DFSTraverse(j);
	}
}

template<class DataType>
void MGraph<DataType>::BFSTraverse(int v)
{
	
}
