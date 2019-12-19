//4.5 ��Դ���·��
#include<iostream>

using namespace std;

#define maxint 10000

template<class Type>

/**
* ��Դ���·��
*
*@param n ������ 
*@param v Դ���� 
*@param dist[i] Դ���v�����i�����·������ 
*@param prev[i] ������i���·��ʱ����һ������� 
*@param c[i][j] �������ͼ��i��j�ıߵ�Ȩ 
*@return 
*/ 
void Dijkstra(int n, int v, Type *dist, int *prev, Type (*c)[6])
{
	bool s[maxint]; //���ڼ�¼��㼯 
	
	/*
	 ��ʼ�� 
	*/ 
	for(int i=1; i<=n; i++)
	{
		dist[i] = c[v][i];
		s[i] = false;
		
		if(dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	
	dist[v] = 0;
	s[v] = true;
	
	/*
	 core 
	*/ 
	for(int i=1; i<n; i++)
	{
		int temp = maxint;
		int u = v;
		
		for(int j=1; j<=n; j++)
			if((!s[j]) && (dist[j]<temp)) //ѡ�����ں�㼯 �� ·����̵Ľ�� 
			{
				u = j;
				temp = dist[j];
			}
		
		s[u] = true;
		
		for(int j=1; j<=n; j++) //���µ�����δ�����㼯�ڵ����̾��� 
		{
			if((!s[j]) && (c[u][j] < maxint))
			{
				Type newdist = dist[u] + c[u][j];
			
				if(newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
} 

int main()
{
	int n=5;
	int v=1;
	int dist[6] = {0};
	int prev[6] = {0};
	int c[6][6];
	c[1][2]=10; c[1][4]=30; c[1][5]=100;
	c[2][3]=50;
	c[3][5]=10;
	c[4][3]=20; c[4][5]=60;
	
	Dijkstra(n, v, dist, prev, c);
	
	for(int i=2; i<=n; i++){
		cout<<"���1�����"<<i<<"�����·��:"<<dist[i]<<"\t";
		cout<<"ǰһ�������"<<prev[i]<<endl; 
	}
	
	return 0;
}
