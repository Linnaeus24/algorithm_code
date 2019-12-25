#include <iostream>
#include <queue>

using namespace std;

typedef struct ArcCell{
	int adj;
	int info;
}ArcCell,AdjMaxtrix[100][100];

typedef struct{
	int data;
	int length;
}VerType;

typedef struct{
	VerType vexs[100];
	AdjMaxtrix arcs;
	int vexnum;
	int arcnum;
}Graph;

Graph G;
queue<int> q;

void CreateGraph(){
	int m,n,t;
	cout<<"���붥�����ͻ�����";
	cin>>G.vexnum>>G.arcnum;
	cout<<"���붥�㣺";
	for(int i=1;i<=G.vexnum;i++){
		cin>>G.vexs[i].data;
		G.vexs[i].length=10000;
	}
	
	for(int i=1;i<=G.vexnum;i++){
		for(int j=1;j<=G.vexnum;j++){
			G.arcs[i][j].adj=0;
		}
	}
	
	cout<<"���뻡��Ȩ�أ�"<<endl;
	for(int i=1;i<=G.arcnum;i++){
		cin>>m>>n>>t;
		G.arcs[m][n].adj=1;
		G.arcs[m][n].info=t;
	}
}

int NextAdj(int v,int w){
	for(int i=w+1;i<=G.vexnum;i++)
		if(G.arcs[v][i].adj)
			return i;
	return 0;	
}

void ShortestPaths(int v){
	int k=0;
	int t;
	G.vexs[v].length=0;
	q.push(G.vexs[v].data);
	while(!q.empty()){
		t=q.front();
		k=NextAdj(t,k);
		while(k!=0){
			if(G.vexs[t].length+G.arcs[t][k].info<=G.vexs[k].length){
				G.vexs[k].length=G.vexs[t].length+G.arcs[t][k].info;
				q.push(G.vexs[k].data);
			}
			k=NextAdj(t,k);
		}
		q.pop();
	}
}

void Print(){
	for(int i=1;i<=G.vexnum;i++)
		cout<<G.vexs[i].data<<"------"<<G.vexs[i].length<<endl;
}

int main(){
	CreateGraph();
	ShortestPaths(1);
	Print();
	return 0;
}
