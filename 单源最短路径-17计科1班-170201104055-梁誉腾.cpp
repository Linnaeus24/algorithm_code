#include <iostream>
#include<iomanip>
using namespace std;

//#define maxint 2147483647   //��ʵmaxint 
#define maxint 10000


template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type **c)   //v��Դ 
{
	bool s[maxint];
	for(int i=1;i<=n;i++)
	{
		dist[i]=c[v][i]; //c[][]�ڽӾ��󣬱�ʾ������֮���Ȩ��dist[]����ֵΪ�ߵ�Ȩ 
		s[i]=false;
		if(dist[i]==maxint) prev[i]=0;     //prev[]��ʾǰ����distΪmaxintָû�б� 
		else prev[i]=v;                    //��ʾi��ǰ����Դv 
	}
	dist[v]=0;s[v]=true;      //dist[v]=0��ʾԴ�㵽������̾���Ϊ0��s[v]=true��ʾvΪ��㼯����ȷ���ĵ㣩 
	for(int i=1;i<n;i++)
	{
		int temp=maxint;
		int u=v;                    
		for(int j=1;j<=n;j++)
			if((!s[j])&&(dist[j]<temp))    //j��v�б����ں�㼯�� 
			{
				u=j;                     
				temp=dist[j];
			}
			s[u]=true;                     //u��ɺ�� 
			for(int j=1;j<=n;j++)
			{
				if((!s[j])&&(c[u][j]<maxint))
				{
					Type newdist=dist[u]+c[u][j];
					if(newdist<dist[j])    //�޸�����·�� 
					{
						dist[j]=newdist;   //�޸ľ��� 
						prev[j]=u;         //�޸�ǰ�� 
					}
				}
			}
		
	}	
}

int main() 
{
    int n,v,*dist,*prev,**c;
    
    while(n<=0||n==NULL)
    {
    cout<<"������ͼG��������n(n>0)��";
    cin>>n;
    }    
    
    dist=new int[n+1];
    prev=new int[n+1];
    c=new int*[n+1];
    
    for(int i=1;i<=n;i++)   //��ʼ���ڽӾ��� 
    {
    	c[i]=new int[n+1];
    	for(int j=1;j<=n;j++)
		   c[i][j]=maxint;      
	}
	
	cout<<endl<<"���濪ʼ��������ͼͼG�ߵ�Ȩ��"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			while(c[i][j]<0||c[i][j]==maxint)      
			{
				cout<<"����"<<i<<"������"<<j<<"�ľ���Ϊ(�Ǹ�����0��ʾ�ޱ�)��";  
			    cin>>c[i][j];
			}
			if(c[i][j]==0) c[i][j]=maxint;
		}
	}
	
/*	for(int i=1;i<=n;i++)
	{
		if(i==1)  
		for(int k=1;k<=n;k++) 
		{   
		   if(k==1) cout<<" ";
		   cout<<setw(8)<<k;
		}  
		cout<<endl; 
		for(int j=1;j<=n;j++)
		{
           if(j==1) cout<<i<<setw(2);
		   cout<<setw(8)<<c[i][j];
		}
		cout<<endl;
	}	
*/
    cout<<"��ȷ��Դv��";
    cin>>v;
    while(v>n||v<1)
    {
       cout<<"��ȷ��Դv��";
       cin>>v;   	
	}
    
    Dijkstra(n,v,dist,prev,c);
    for(int i=1;i<=n;i++)
    {
    	cout<<"dist["<<i<<"]="<<dist[i]<<endl;
	}
    
	return 0;
}
