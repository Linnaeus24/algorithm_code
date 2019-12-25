#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int INF=1e9+7;

struct Node
{
	int id;
	int length;
};

bool operator > (const Node &a, const Node &b)
{
    return a.length > b.length;
}

int c[N][N];
int dist[N];
int n,m,v;

void ShortestPaths()
{
    priority_queue<Node, vector<Node>, greater<Node> > q; // С���� 
    dist[v] = 0; 											//��ʼ��
    Node E;													//��ǰ�ڵ� 
    E.id = v;
    E.length = 0;
    q.push(E);
    while(!q.empty())
    {
        E = q.top(); 										//ȡ���Ѷ��ĵ�
        q.pop(); 
		for(int i = 1; i <= n; i ++)						//Ѱ����E�����ĵ�(������) 
        {
            if(c[E.id][i]!=INF && (E.length + c[E.id][i] < dist[i]))
            {
                dist[i] = E.length + c[E.id][i];
                Node N;
                N.id = i;
                N.length = dist[i];
                q.push(N);
            }
        }
    }
}

void init()
{
	cout << "������ͼ�ĵ���,��������㣺";
	cin >> n >> m >> v;
	//��ʼ������ 
	for (int i=0;i<=n;i ++) for (int j=0;j<=n;j ++) c[i][j] = INF;
	for (int i=0;i<=n;i ++) dist[i] = INF;
	cout << "����������ÿ���߼�Ȩֵ" << endl;
	for(int i=1;i<=m;i++)
	{
		int x,y,len;
		cin >> x >> y >> len;
		c[x][y]=len;
	}
}

void print()			//���ÿ��������·�� 
{
	for(int i=1;i<=n;i++)
		if(i!=v)
			cout << "��" << v << "����" << i << "����̾���Ϊ��" << dist[i] << endl;
	
}

int main()
{
    init();
    ShortestPaths();
    print();
    return 0;
}
