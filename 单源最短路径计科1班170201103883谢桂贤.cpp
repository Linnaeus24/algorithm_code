#include <iostream> 
#include <fstream>  
#include <string> 
using namespace std; 
 
const int N = 5;//����� 
const int maxint = 999;
 
template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1]);
void Traceback(int v,int i,int prev[]);//������·�� vԴ�㣬i�յ�
 
int main()
{
	int v = 1;//Դ��Ϊ1
	int dist[N+1],prev[N+1],c[N+1][N+1];
 
	cout<<"����ͼȨ�ľ���Ϊ��(���ɴ������999)"<<endl;
	for(int i=1; i<=N; i++)
	{
		cout<<"������"<<i<<"�ŵ㵽������ĳ���"<<endl; 
		for(int j=1; j<=N; j++)
		{
			cin>>c[i][j];                  
		}	
	}
 
	Dijkstra(N,v,dist,prev,c);
 
	for(int i=2; i<=N; i++)
	{
		cout<<"Դ��1����"<<i<<"�����·������Ϊ:"<<dist[i]<<"����·��Ϊ";
		Traceback(1,i,prev);
		cout<<endl;
	}
 
	return 0;
}
 
 
template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1])
{
	bool s[N+1];
	for(int i=1; i<=n; i++)
	{
		dist[i] = c[v][i];//dist[i]��ʾ��ǰ��Դ������i���������·������
		s[i] = false;
 
		if(dist[i] == maxint)
		{
			prev[i] = 0;//��ǰ�� 
		}
		else
		{
			prev[i] = v;//ǰ�� 
		}
	}
 
	dist[v] = 0;
	s[v] = true;
 
	for(int i=1; i<n; i++)//ÿ��ת��һ��Ϊ��� 
	{
		int temp = maxint;
		int u = v;//��һ����
 
		//�Ǻ��������̵�����·�� 
		for(int j=1; j<=n; j++)
		{
			if((!s[j]) && (dist[j]<temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;
 
		for(int j=1; j<=n; j++)
		{
			if((!s[j]) && (c[u][j]<maxint))
			{
				Type newdist = dist[u] + c[u][j];
				if(newdist < dist[j])
				{
					dist[j] = newdist;//�޸�����·�� 
					prev[j] = u;
				}
			}
		}
	}
}
 
//�ݹ�������·�� vԴ�㣬i�յ�
void Traceback(int v,int i,int prev[])
{
	if(v == i)
	{
		cout<<i;
		return;
	}
	Traceback(v,prev[i],prev);
	cout<<"->"<<i;
} 
