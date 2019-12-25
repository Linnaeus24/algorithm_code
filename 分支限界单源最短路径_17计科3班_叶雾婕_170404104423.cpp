#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f
class MinHeapNode
{
public:
	friend bool operator < (const MinHeapNode &a, const MinHeapNode &b)
	{
		return a.length < b.length;
	}
	friend bool operator > (const MinHeapNode &a, const MinHeapNode &b)
	{
		return a.length > b.length;
	}
public:
	int i; 
	int length; //����ʼ�� v ���� id �ľ���
};
const int max_ = 0x3f3f3f;
int n,						//ͼG�Ķ����� 
	prev[100];				//ǰ���������� 
int c[100][100],		//ͼG���ڽӾ��� 
	dist[100];				//��̾������� 
int m,						//ͼG�ı���
	v;						//��� 
void ShortestPaths()
{
	priority_queue<MinHeapNode, vector<MinHeapNode>, greater<MinHeapNode> > H; // С���� 
	memset(dist, max_, sizeof(dist));
	MinHeapNode E;
	E.i = v;
	E.length = 0;
	dist[v]=0;
	prev[v] = v;
	H.push(E);
	while(true)
	 {
	 	if(H.empty() == 1)	break;
	 	E= H.top(); //ȡ���Ѷ��ĵ�
		H.pop(); // �����ȶ�����ɾ����ȡ���ĵ�
	 	for(int j=1;j<=n;j++)
	 	{
		 	if((c[E.i][j]<inf) && (E.length+c[E.i][j] < dist[j]))
		 	{
		 		dist[j] = E.length+c[E.i][j];
				prev[j] = E.i;
				MinHeapNode N;
				N.i = j;
				N.length=dist[j];
				H.push(N);
			}
		 }
	}
}
void InPut()
{
	int x, y, len;
	cin>>v>>n>>m;
	 memset(c, max_, sizeof(c));
	for(int i = 1; i <= m; ++i)
	{
		cin>>x>>y>>len;
		c[x][y] = c[y][x] = len;	
	}
}
void OutPutPath(int i)
{
	if(i == prev[i])
	{
		cout<<i<<"\t";
		return;
	}
	else
	{
		OutPutPath(prev[i]);
		cout<<i<<"\t";
	}
}
void OutPut()
{
	for(int i = 1; i <= n; ++i)
	{
		 if(i != v)
		{
			 cout<<"��"<<v<<"��"<<i<<"����̾�����"<<dist[i]<<endl;
			 cout<<"·��Ϊ��";
			 OutPutPath(i);
			 cout<<endl;
		}
	}
}
int main()
{
	 InPut();
	 ShortestPaths();
	 OutPut();
}
/*��������
1 5 7
1 2 10
1 5 100
1 4 30
2 3 50
3 5 10
4 3 20
4 5 60
*/ 
