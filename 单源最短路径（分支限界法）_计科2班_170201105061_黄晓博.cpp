#include <iostream>
#include <queue>
#include<stdlib.h>
using namespace std;
#define MAX 9999//����Ϊ���޴�
#define N 60
int n,dist[N],a[N][N];
class HeapNode//��С�����洢��ڵ��
{
public:
int i,length;//�����ţ���ǰ��·������
HeapNode() { }
HeapNode(int ii,int l)
{
i=ii;
length=l;
}
bool operator<(const HeapNode& node)const
{
return length<node.length;
}
};
void shorest(int v)
{
priority_queue<HeapNode>  heap;
HeapNode enode(v,0);
for(int i=1; i<=n; i++)  dist[i]=MAX;
dist[v]=0;//��������Ľ�ռ�
while(1)
{
for(int j=1; j<=n; j++)
if(a[enode.i][j]<MAX && enode.length+a[enode.i][j]<dist[j])//����I��J�ǿɴ�ģ������������Լ��
{
dist[j]=enode.length+a[enode.i][j];
HeapNode node(j,dist[j]);
heap.push(node);//�����ڵ����ȶ���
}
if(heap.empty()) break;//���ȶ���Ϊ��
else
{
enode=heap.top();
heap.pop();
}
}
}
int main ()
{
int v,i;
cout<<"������";
cin>>n;
cout<<"Դ�㣺";
cin>>v; 
for(int i=1; i<=n; i++)
for(int j=1; j<=n; j++)
{
if(i!=j){
if((a[j][i]==0)||(a[j][i]==MAX))
a[i][j]=rand()%100+1;
else a[i][j]=MAX;
if(a[i][j]>50) a[i][j]=MAX;
}   
}
cout<<"\n·��:"<<endl;
for( i=1;i<n+1;i++){
for(int j=1;j<n+1;j++)
cout<<a[i][j]<<"  ";
cout<<endl;
}
shorest(v);
cout<<endl;
for( i=2; i<n; i++) {
cout<<v<<"��"<<i<<"�����·��Ϊ��"<<dist[i]<<endl;
}
cout<<v<<"��"<<i<<"�����·��Ϊ��"<<dist[n]<<endl;
system("pause");
return 0;
}
