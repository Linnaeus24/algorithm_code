//6.2��Դ���·������ 
#include<iostream>
#include<queue>

using namespace std;

#define inf 10000

template<class Type>
class Graph 
{
public:
	/**
	*
	*
	*@param k 
	*@return 
	*/ 
	void ShortestPaths(int k);
	Graph(int n, int *prev, Type (*c)[7], Type *dist)
	{
		this->n = n;
		this->prev = prev;
		this->c = c;
		this->dist = dist;	
	}
private:
	int n,  //������ 
		*prev;  //ǰ���������� 
	Type (*c)[7], //�ڽӾ��� 
		*dist;  //��̾������� 
};


template<class Type>
class MinHeapNode //��С�ѵĽ�� 
{
	friend Graph<Type>;
public:
	operator int() const 
	{ 
		return length; 
	}
private:
	int i;  //������ 
	Type length;  //��ǰ·�� 
};

template<class Type>
void Graph<Type>::ShortestPaths(int v)
{
	priority_queue<MinHeapNode<Type> > H; //���ȶ���H 
	MinHeapNode<Type> E;
	E.i = v;
	E.length = 0;
	dist[v] = 0;
	
	while(true)
	{
		for(int j=1; j<=n; j++)
		{
			if((c[E.i][j]<inf) && (E.length+c[E.i][j]<dist[j])) //�б� �� ͨ���ñ�·������ 
			{
				dist[j] = E.length+c[E.i][j];
				prev[j] = E.i;
				MinHeapNode<Type> N;
				N.i = j;
				N.length = dist[j];
				H.push(N); //ѹ�����ȶ��� 
			}
		}
		
		if(!H.empty())
		{
			E = H.top();
			H.pop();
		}else
			break;
	}
} 

void prepareData(int (*g)[7], int *dist, int *prev)
{	
	for(int i=1;i<7;i++){
		for(int j=1;j<5;j++){
			g[i][j]=inf;			
		}		
	}
	
	for(int i=0;i<7;i++){
		dist[i]=inf;
	}
	
	for(int i=0;i<7;i++){
		prev[i]=i;
	}
	
	g[1][2]=2; g[1][3]=3; g[1][4]=4;
	g[2][3]=4; g[2][5]=2;
	g[3][5]=9; g[3][6]=13;
	g[4][6]=4;
	g[5][6]=3;
}

int main(){
	int n=6;
	int prev[7];
	int g[7][7];
	int dist[7];
	
	prepareData(g, dist, prev);
	Graph<int>* G = new Graph<int>(n, prev, g, dist);
	
	G->ShortestPaths(1);		
	
	for(int i=1; i<7; i++)
	{
		cout<<"���1�����"<<i<<"�����·��:"<<dist[i]<<"\t";
		cout<<"ǰһ�������"<<prev[i]<<endl; 
	}
}

