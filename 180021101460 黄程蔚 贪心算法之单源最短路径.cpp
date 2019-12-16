#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;
#define maxint 32767//��ʾ����ֵ,����(����Զ)
#define mvnum 1005//��󶥵���
const int N=1005,INF=1e9+7;
int start;//���
int c[N][N],dist[N],prev[N];

/*
���裺
��1���Ƚ����������ϣ��������Ѿ��ҵ������·���Ľ�㼴S={}��������δ�ҵ������·���Ľ�㼴U={}
	S ��U������S U U=ȫ�������н�㣩����UΪ��ʱ���㷨�������ҵ����·��
��2����Դ���iֱ����������dist[i]����Ȩ�أ���Դ��i��ֱ����������dist[i]=��
��3����������dist[i],��Դ��i��ľ��룬ѡȡ��С��dist[i]���뵽S�У���i��U���Ƴ�
	�����ҵ���·��������Դi ��δ�ҵ���ľ���dist[i]	����i�Ѿ���S��֮�󽫲��ٸ���dist[i]
��4���ظ���3�����裬ֱ��UΪ��ʱ�������㷨
*/

void Dijkstra(int n, int v)
{
	bool s[mvnum];//mvnum��ʾ��󶥵��� 
	//��ʼ�� 
	for(int i=1;i<=n;i++)
	{
		//��Դ�㵽i�����̾���dist 
		dist[i]=c[v][i];//vΪԴ��,iΪ��Դ��֮��ĵ�
		s[i]=false;//һ��ʼ����S���޵�,��ʾ��i��,�����е㶼������S������ 
		if(dist[i]==maxint)//��ʾ��Դ�㵽i����ʱ��·,������Զ 
		{
			prev[i]=0;
		}
		else
		{
			prev[i]=v;//һ��ʼ,����ֱ�Ӵ�Դ������i��,�����·,��������һ���,�����׵��¼��prev��
		}
	}
	dist[v]=0;//��Դ�㵽Դ�����Ϊ0
	s[v]=true;//��Դ��v���뼯��S��
	for(int i=1;i<n;i++)//����Դ��,��ֻҪѭ��n-1�� 
	{
		int temp=maxint;//�м����Ϊ����Զ
		int u=v;//һ��ʼ,�Ƚ�u����ΪԴ�� 
		for(int j=1;j<=n;j++)
		{//�������е�, ÿ�δ�ʣ�ඥ�����ҳ�һ����ǰ����Դ������Ķ���
			//�������㻹δ���뼯��S,���Ҵ�Դ�㵽�õ�ľ���С������Զ 
			if((!s[j]) && (dist[j]<temp))
			{//ֻ����Դ��ֱ�������ĵ�,����Դ������,��·�ĵ���ܽ�u��Ϊ�õ� 
				u=j;
				temp=dist[j];//Ȼ�󽫴�Դ�㵽�õ�ľ��븳��temp����,temp��ʾ��ǰΪ���뼯��S����Сdist 
			}
		}
		//u��ʾ��ǰΪ���뼯��S�ĵ�,��ʾ��ǰ����С���� 
		s[u]=true;//����u���뼯��S
		//�����u�����,���ܲ����ҵ��ı������㵽Դ�������,��ͨ��u�㵽Դ�����и��̵ľ��� 
		for(int j=1;j<=n;j++)
		{
			//�������㻹δ���뼯��S,���Ҵ��¼���ĵ�u�㵽�õ�ľ���С������Զ,��ʾ��·,u��j��·,��Դ�㵽�õ���· 
			if((!s[j]) && (c[u][j]<maxint))
			{
				int newdist=dist[u]+c[u][j];//�¾���,�����̵Ĵ�Դ�㵽j��ľ���
				if(newdist<dist[j])//���Դ�Դ�㵽u���ٵ�j����¾���,�ǲ��Ǳ�Ŀǰ�ľ������ 
				{//�����,��ô����dist[j],�������ĸ�����Ϊu��,��Ϊ��ͨ��u����ҵ��ĸ��Ӷ̵ľ��� 
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
	}
}

void find(int x)
{
	if(x!=start)
	{
		find(prev[x]);
		cout << " -> ";
	}
	cout << x;
}

int main()
{
	int n,m;//��������ͱߵĸ���
	cout << "������ͼ�Ķ���ͱߵĸ���(��ʽ��������� �߸���)��"; 
	cin >> n >> m;
//	memset(c,0x3f,sizeof(c));
//	memset(dist,0x3f,sizeof(dist));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i!=j)
				c[i][j]=c[j][i]=maxint;
			else
				c[i][j]=0;
		}
	}
	int minx,maxy;
	cout << "������ͼ��·������(��ʽ����� �յ� ����)��" << endl;
	for(int i=0;i<m;i++)
	{
		//cout << "�������" << i+1 << "���ߵ��������(��:1 2 10,��ʾ����1�붥��2����,��ȨֵΪ10):"; 
		int x,y,weight;
		cin >> x >> y >> weight;
		if(i!=0)
		{
			minx=min(minx,x);
			maxy=max(maxy,y);
		}
		else
		{
			minx=x;
			maxy=y;
		}
		if(weight<c[x][y])
        {
            //������Ȩͼ
            c[x][y]=weight;
            c[y][x]=weight;
        }
	}
	cout << endl;
	cout<<"����������ţ�";
	cin>>start;
	Dijkstra(n,start);
	for(int i=minx;i<=maxy;i++)
    {
    	cout << endl << i << "�Žڵ�:" << endl; 
    	if(dist[i]!=maxint)
    	{
    		cout << "���ŷ���:"; 
    		find(i);
    		cout << endl;
    		cout << "���" << start << "��" << i << "�ŵ����̾���Ϊ:" << dist[i] << endl;
    		cout << "ǰ�����ǣ�" << prev[i] << endl;
		}
		else
			cout << "���" << start << "����" << i << "�ŵ���·" << endl;
		cout << "----------------------" << endl; 
//          cout << i << "�ڵ����̾����ǣ�" << dist[i] << "��ǰ�����ǣ�" << prev[i] << endl;
    }
	return 0;
}
