#include <iostream>
#include<stdlib.h>
using namespace std;

#define MaxInt 65535    
#define MNum 6       

void Dijkstra(int n,int v,int dist[],int prev[],int c[][MNum]){
	 bool s[MaxInt];
	 for(int i=1;i<=n;i++){
	 	dist[i]=c[v][i];
	 	s[i]=false;
	 	if(dist[i]==MaxInt)
	 		prev[i]=0;
	 	else
	 		prev[i]=v;
	 }
	 dist[v]=0;
	 s[v]=true;
	 for(int i=1;i<n;i++)
	{
		int temp=MaxInt;
		int u=v;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j])&&(c[u][j]<MaxInt)){
					int newdist=dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			}
		}
	}
}

void Printprev(int prev[],int begin,int temp)
{
	if(prev[temp]!=0){
		Printprev(prev,begin,prev[temp]);
		cout << prev[temp] << "-->";
	}
}

int main()
{
	cout <<"��Դ���·��"<< endl;
    int n=5;
    int begin=2; 	//Դͷ
    int dist[MNum];	 //��¼���·�ĳ���
    int prev[MNum];	//��¼ǰ���ڵ�
   
    int c[MNum][MNum]={{MaxInt,15,MaxInt,MaxInt,60,MaxInt},
	                     {MaxInt,MaxInt,10,MaxInt,30,100},
						 {20,MaxInt,MaxInt,40,MaxInt,MaxInt},
						 {MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,10},
						 {MaxInt,30,20,20,MaxInt,80}};
    
	

    Dijkstra(n,begin,dist,prev,c);
    
	cout << endl <<begin<<"�����������·��Ϊ��\n";
	for(int i=1;i<=n;i++) 
	{
	   if(i!=begin&&dist[i]<MaxInt) 
	   {
	   	 Printprev(prev,begin,i);
	     cout <<i;
	     
	     cout <<"���·������Ϊ��"<<dist[i]<<endl;
	   }
	   if(i!=begin&&dist[i]==MaxInt) 
	    {
	     cout <<begin<<"��"<<i<<"�޿ɴ�·��"<<endl;
	   }	   
	}
	return 0;
}

