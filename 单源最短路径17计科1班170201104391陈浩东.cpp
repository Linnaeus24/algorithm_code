#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int maxint=65535;
int c[6][6]={{0,0,0,0,0,0},{0,0,10,65535,30,100},{0,65535,0,50,65535,65535},{0,65535,65535,0,65535,10},{0,65535,65535,20,0,60},{0,65535,65535,65535,65535,0}};
bool s[6];
 
 
void Dijkstra(int n,int v,int dist[],int prev[]){
	for(int i=1;i<=n;i++){
		dist[i]=c[v][i];//��dist������г�ʼ������Դ�㵽i�ľ��룺V->i ��ֵ��dist 
		s[i]=false;//��s�����ÿ� 
		if(dist[i]==maxint)prev[i]=0;//�ж�V->i�Ƿ����ֱ��������ֱ��Ļ�����prev���鸳ֵΪ��ǰһ���ڵ� 
		else prev[i]=v;
	}
	dist[v]=0;s[v]=true;//�Ƚ�Դ����Ϊtrue����������s���� 
	for(int i=1;i<=n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(dist[j]<temp)){//�ҳ���s������ģ���·����̵�һ���� 
				u=j;
				temp=dist[j];
			}
		}
		s[u]=true;//������ѭ�����ҵ��ĵ㣬����s������ 
		for(int j=1;j<=n;j++){//��u��ΪԴ������dist�����е����� 
			if((!s[j])&&(c[u][j]<maxint)){//j����j�����У��Ҵ�u->j����ֱ��ĵ� 
				int newdist = dist[u]+c[u][j]; 
				if(newdist<dist[j]){//��ͨ��u->j��·�ߣ���ԭ����·��Ҫ�̣������dist�����е����� 
					dist[j]=newdist; 
					prev[j]=u;
				}
			}
		}
		for(int k=1;k<=n;k++){
			cout<<dist[k]<<" ";
		}
		cout<<endl;
	}	
}
void foundDist(int dist,int prev[]){
	int prevNode=prev[dist];
	vector<int> vec;
	vec.push_back(dist);
	vec.push_back(prevNode);
	while(prevNode!=1){
		prevNode=prev[prevNode];
		vec.push_back(prevNode);
	}
	cout<<"���·��Ϊ��";
	for(int i=vec.size()-1;i>=0;i--){
		cout<<vec[i]<<" ";
	}
}
int main(){
	int distNum;
	int dist[6];
	int prev[6];
	cout<<"dist�����е����ݣ�"<<endl; 
	Dijkstra(5,1,dist,prev);
	cout<<"prev�����е����ݣ�"; 
	for(int i=1;i<=5;i++){
		cout<<prev[i]<<" ";
	}
	cout<<endl;
	cout<<"�������յ㣺";
	scanf("%d",&distNum);
	foundDist(distNum,prev);
}

