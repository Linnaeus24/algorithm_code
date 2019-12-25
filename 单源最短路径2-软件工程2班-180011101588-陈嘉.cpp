#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define inf 99999
using namespace std;
int n;//������� 
int dist[100];//��¼���·������ 
int G[100][100];//ͼ 
int prev[100];//��¼���·������ 
struct minheapnode{
	int i;		//������
	int length;		//��ǰ·�� 
}E,N;
int comp(minheapnode a,minheapnode b)
{
	return a.length>b.length;
}
void shortpaths(int v){
	vector<minheapnode> H;
	E.i=v;
	E.length=0;
	dist[v]=0;
	while(1){
		for(int j=1;j<=n;j++){
			if((G[E.i][j]<inf)&&(E.length+G[E.i][j]<dist[j])){
				dist[j]=E.length+G[E.i][j];
				prev[j]=E.i;
				N.i=j;
				N.length=dist[j];
				H.push_back(N);
				sort(H+1,H+n+1,comp);
			}
		}
	} 
}
int main()
{
	memset(G,inf,sizeof(G));
	memset(dist,0,sizeof(dist));
	memset(prev,0,sizeof(prev));
	int from,to,weight,t;
	cout<<"num?"<<endl;
	cin>>n;
	cout<<"from?to?weight? tip:end=0"<<endl;
	while(1){
		cin>>from;
		if(!from)
			break;
		cin>>to;
		cin>>weight;
		G[from][to]=weight;
	}
	
	for(int i=1;i<=n;i++){
		shortpaths(i);
	}
	
	return 0;
} 
