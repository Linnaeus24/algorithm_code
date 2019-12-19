#include<iostream>
using namespace std;
#define maxint 1000

int n;//����ͼ�Ķ�����
int pre[100];//pre[i]��¼���Ǵ�Դ�㵽����i�����·����ǰһ������
int dis[100];//dis[i]��ʾ��ǰ��Դ������i���������·��
int c[100][100];//c[i][j]��ʾ��(i,j)��Ȩ ��ͨ�ıߵ�ȨΪ����� ������1000����
int v;//Դ����
int PATH[100];//�洢·��
 
void input()
{
    cout<<"����������ͼ����ĸ���:"<<endl;
    cin>>n;
    cout<<"������Դ:"<<endl;
    cin>>v;
    cout<<"���Զ�ά�������ʽ��������ͼ�и�������Ȩ(·��),��������1000��ʾ"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
}
void Dijkstra()
{
    //��ʼ������
    bool s[maxint];
    for(int i=1;i<=n;i++)
    {
        dis[i]=c[v][i];
        s[i]=false;//����S����Ϊ��
        if(dis[i]==maxint)
            pre[i]=0;
        else
            pre[i]=v; 
    }
    //Դ�㵽Դ�����Ϊ0���Ȱ�Դ����뵽����S
    dis[v]=0;
    s[v]=true;
    for(int i=1;i<n;i++)//����n-1��
    {
        //�ҳ���Դ�����������������̾�����Ǹ����㲢�������뼯��S
        int temp = maxint;
        int u=v;
        for(int j=1;j<=n;j++)
            if((!s[j])&&(dis[j]<temp))
            {
                u=j;
                temp=dis[j];
            }
        s[u]=true;
        //����·��
        for(int j=1;j<=n;j++)
        {
            if((!s[j])&&(c[u][j]<maxint))
            {
                int newdis=dis[u]+c[u][j];
                if(newdis<dis[j])
                {
                    dis[j]=newdis;
                    pre[j]=u;
                }
            }
        } 
    }
}

void Path(int destination)//����pre�������pre����洢�������·������һ�����
{
    int Count=0;
    for(int i=pre[destination];i!=v;i=pre[i])
    {
        PATH[Count++]=i;
    }
    //��Ϊpre��¼������һ��λ�ý�㣬������Ҫ���������
    cout<<v;
    for(int i=Count-1;i>=0;i--)
    {
        cout<<"-->"<<PATH[i];
    }
    cout<<"-->"<<destination<<endl;
}

int main()
{
    int destination;
    input();
    Dijkstra();
    cout<<"������Ŀ�ĵ�"<<endl;
    cin>>destination;
    Path(destination);
    return 0;
}

