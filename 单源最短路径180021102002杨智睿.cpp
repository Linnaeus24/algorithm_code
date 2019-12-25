#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const int INF = 1 << 30;
int T, n, m;
int Map[maxn][maxn];//�ڽӾ����ͼ
int v[maxn];//v[i] = 1��ʾ�Ѽ��뼯��S
int d[maxn];//dist[i]��ʾ����Դ�����̾���
int path[maxn];//��¼·��
void dijkstra(int u0)//�󶥵�Ϊu��������������·
{
    memset(v, 0, sizeof(v));
    for(int i = 0; i < n; i++)d[i] = (i == u0 ? 0 : INF);
    for(int i = 0; i < n; i++)path[i] = -1;
    for(int i = 0; i < n; i++)//ÿ�μ���һ���ڵ㣬ѭ��n��
    {
        int x, m = INF;
        for(int y = 0; y < n; y++)if(!v[y] && d[y] <= m)m = d[x = y];//��¼��ǰ��Сֵ
        v[x] = 1;//����Ѿ����뼯��
        for(int y = 0; y < n; y++)
        {
            if(d[y] > d[x] + Map[x][y])//�ɳڲ���
            {
                d[y] = d[x] + Map[x][y];
                path[y] = x;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(i == u0)continue;
        printf("��%d��%d�����ǣ�%2d   ", u0, i, d[i]);
        stack<int>q;
        int x = i;
        while(path[x] != -1)
        {
            q.push(x);
            x = path[x];
        }
        cout<<u0;
        while(!q.empty())
        {
            cout<<"->"<<q.top();
            q.pop();
        }
        cout<<endl;
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)Map[i][j] = 0;
            else Map[i][j] = INF;
        }
    }
    int x, y, z;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        Map[x][y] = z;
    }
    dijkstra(0);
    return 0;
}
