#include <iostream>
using namespace std;

#define maxint 110
int dist[maxint];
int p[maxint];
int c[maxint][maxint];
void Dijkstra(int n,int v)
{
	bool s[maxint];
	for (int i=1;i<n;i++)
	{
		dist[i] = c[v][i];
		s[i]=false;
		if (dist[i] == maxint)
			p[i]=0;
		else
			p[i]=v;
	}
	dist[v]=0;s[v]=true;
	for (int i=1;i<n;i++)
	{
		int temp=maxint;
		int u=v;
		for (int j=1;j<=n;j++)
		if(!s[j] && (dist[j]<temp))
		{
			u=j;
			temp=dist[j];
		}
		s[u]=true;
		for (int j=1;j<n;j++)
		{
			if((!s[j])&&(c[u][j]<maxint))
			{
				int newdist = dist[u]+c[u][j];
				if(newdist<dist[j])
				{
					dist[j]=newdist;
					p[j]=u;
				}
			}
		}
	}
}

int main()
{
	int n,v,e;
	cout<<"�������ĸ���"<<endl;
	cin>>n;
	cout<<"����������"<<endl; 
	cin>>v;
	cout<<"�������յ��"<<endl;
	cin>>e;
	cout<<"������ͼ�Ķ�Ӧ�ڽӾ���(0 or Ȩֵ)"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>c[i][j];
			if(c[i][j]==0)
			{
				c[i][j]=maxint;
			}
		}
	}
	
	Dijkstra(n,v);
	cout<<"��㵽�յ����·��Ϊ��"<<dist[e]<<endl;
	return 0;
}




