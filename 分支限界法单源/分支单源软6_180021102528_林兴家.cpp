#include <iostream>
#include<queue>
using namespace std;
 
typedef struct {
    int w;//Ȩ
    int dist;//���·��
}Maxtrix;
 
typedef struct{
    int i;
    int length;
}Node;
 
typedef struct{
	int n;//n is number of point
	Node N[100];
	Maxtrix M[100][100];//ͼ���ڽӾ��� 
}Graph;
 
Graph G;
queue<int> q;

void GetGraph()
{
    int m,n,t;
    cout<<"���������Ϊ��"<<endl;
    cin>>G.n;
    
    cout<<"���붥�㣺"<<endl;
    for(int i=1;i<=G.n;i++)
    {
        cin>>G.N[i].i;
        G.N[i].length=10000;
    }
 
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
        {
            G.M[i][j].w=0;
        }
 
    cout<<"������Ȩ�أ�";//num
    int num;
    cin>>num;
    for(int i=1;i<=num;i++)
        {
            cin>>m>>n>>t;
            G.M[m][n].w=1;
            G.M[m][n].dist=t;
        }
 
}
 
int NextNode(int a,int b)
{
    for(int i=b+1;i<=G.n;i++)
        if(G.M[a][i].w)
            return i;
    return 0;//�Ҳ��� 
}
 
void ShortestPaths(int v)
{
    int k=0;//���׸��ڵ㿪ʼ����
    int t;
    G.N[v].length=0;
    q.push(G.N[v].i);
    while(!q.empty())
    {
        t=q.front();
        k=NextNode(t,k);
        while(k!=0)
        {
            if(G.N[t].length+G.M[t][k].w<=G.N[k].length)//��֦
            {
                G.N[k].length=G.N[t].length+G.M[t][k].w;
                q.push(G.N[k].i);
            }
            k=NextNode(t,k);
        }
        q.pop();
    }
}
 
void printf()
{
    for(int i=1;i<=G.n;i++)
        printf("%d�����·��Ϊ��%d\n",G.N[i].i,G.N[i].length);
}
 
int main()
{
    GetGraph();
    ShortestPaths(1);
    printf();
    return 0;
}

