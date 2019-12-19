#include <iostream>
using namespace std;
#define maxnum 100//��󶥵���
#define maxint 9999//���Ȩֵ


void Dijkstra(int n,int v,int *dist,int *prev,int c[maxnum][maxnum])
{
    bool s[maxnum];//s���飬���������·���ļ���
    for (int i=1;i<=n;i++)
    {
        dist[i] = c[v][i];
        if (dist[i]==maxint)
        {
            prev[i] = 0;
        }
        else
        {
            prev[i] = v;
        }
    }
    dist[v] = 0;
    s[v] = 1;//������ʼ���ѷ��ʣ�����ʼ����ʼ�����Ϊ0
    for (int i=2;i<=n;++i)//��Ѱ��ʣ�µ�n-1���ڵ�
    {
        int tmp = maxint;
        int u = v;
        for (int j=1;j<=n;++j)
        {
            if ((!s[j]) && dist[j]<tmp)//Ѱ���ڽ���̱��Լ���Ӧ��
            {
                u = j;
                tmp = dist[j];
            }
        }
        s[u] = 1;//��¼�õ�

        for (int j=1;j<=n;++j)
        {
            if ((!s[j]) && c[u][j]<maxint)//����ÿ�������������Сֵ
            {
                int newdist = dist[u] + c[u][j];
                if (newdist<dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;//����ǰ���ڵ�
                }
            }
        }
    }
}
//����һ�����鱣��prev��ǰ���ڵ�·����prev[j]��ʾ��j���ǰһ����
void MinPath(int *prev,int v,int n)
{
    int que[maxnum];
    int t = 2;
    que[1] = n;//��һ���㼴��������յ�
    int tmp = prev[n];//�յ�ǰ��һ����
    while (tmp != v)//ֻҪû��������������
    {
        que[t] = tmp;
        t++;
        tmp = prev[tmp];
    }
    que[t] = v;
    for (int j=t;j>=1;--j)//��ӡ·��
    {
        if (j!=1)
        {
            cout<<que[j]<<"->";
        }
        else
            cout<<que[j]<<endl;
    }
}
/*����Ϊ
5
7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
*/
int main()
{
    int n,edgenum;//���㣬����
    int dist[maxnum];
    int prev[maxnum];
    int c[maxnum][maxnum];
    while (cin>>n>>edgenum)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                c[i][j] = maxint;

        int p,q,weight;
        for (int i=1;i<=edgenum;i++)
        {
            cin>>p>>q>>weight;
            if (weight < c[p][q])
            { 
                c[p][q] = c[q][p] = weight;
            }
        }
        for (int i=1;i<=n;i++)
        {
            dist[i] = maxint;
        }
        for (int i=1;i<=n;++i)//��ӡȨֵ����
        {
            for (int j=1;j<=n;j++)
            {
                cout<<c[i][j];
                if (j == n)
                {
                    continue;
                }
                cout<<" ";
            }
            cout<<endl;
        }
        Dijkstra(n,1,dist,prev,c);
        cout<<"�����һ��������·������Ϊ��"<<dist[n]<<endl;
        cout<<"����㵽���һ�����·��Ϊ�� ";
        MinPath(prev,1,n);
    }
    return 0;
}

