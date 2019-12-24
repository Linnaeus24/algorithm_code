#include<iostream>
using namespace std;
const int size = 100;
const int inf = 5000;

const int n = 6;
int prev[n];
int dist[] = {0,0,5000,5000,5000,5000};
int c[n][n] = {{0,0,0,0,0,0},{0,0,2,3,5000,5000},{0,5000,0,1,2,5000},{0,5000,5000,0,9,2},{0,5000,5000,5000,0,2},{0,5000,5000,5000,5000,0}};
class MinHeapNode
{
public:
	int i;
	int length;
};
class CirQueue
{
private:
	int front,rear;
	MinHeapNode data[size];
public:
	CirQueue()
	{
		front = rear = 0;
	}
	void queryIn(MinHeapNode e)
	{
		if((rear +1)%size != front)
		{
			rear = (rear+1)%size;
			data[rear] = e;
		}
	} 
	MinHeapNode queryOut()
	{
		if(rear != front)
		{
			front = (front+1)%size;
			return data[front];
		}
	}
	MinHeapNode getQuery()
	{
		if(rear != front)
		{
			return data[(front+1)%size];
		}
	}
	bool empty()
	{
		return front == rear;
	}	
	bool full()
	{
		return (rear +1)%size == front;
	}	
};

class Graph
{
public:
	void ShortestPaths(int v)
	{
		CirQueue qq;
		MinHeapNode E;
		E.i = v;
		E.length = 0;
		dist[v] = 0;
		qq.queryIn(E);
		while(true)
		{
			for(int j = 1;j<n;j++)
			{
				if(j>=n){break;}
    			MinHeapNode m = qq.getQuery();
    			if((c[m.i][j]<inf)&&(m.length + c[m.i][j] < dist[j]))
				{
					dist[j] = m.length + c[m.i][j];
					prev[j] = m.i;
    				MinHeapNode N;
					N.i = j;
    				N.length  = dist[j];
    				if(qq.full()){break;}
    				qq.queryIn(N);
    			}
			}
			if(qq.empty())
			{
				break;
			}
		qq.queryOut();
		}
	}
};

int main()
{
	Graph g;
	g.ShortestPaths(1);
	cout<<"���·����Ϊ "<<dist[n-1]<<endl;
	cout<<"�м�·��Ϊ�� ";
	for(int i =3;i<n;i++)
	{
		cout<<prev[i]<<" ";
	}
	return 0;
}
