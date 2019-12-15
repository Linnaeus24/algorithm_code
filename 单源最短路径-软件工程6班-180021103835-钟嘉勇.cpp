#include<stdio.h>
#include<iostream>
using namespace std;

const int size=100;
const int inf=5000;
const int n=6;
int dist[]={0,0,5000,5000,5000};
int c[n][n]={{0,0,0,0,0,0},{0,0,2,3,5000,5000},{0,5000,0,1,2,5000},{0,5000,5000,0,9,2},{0,5000,5000,5000,0,2},{0,5000,5000,5000,5000,0}};

template<class Type>
class Graph{
	friend int main(void);
public:
	void ShortestPaths(int);
private:
	int n,        //ͼG�Ķ����� 
	*prev;    //ǰ���������� 
	Type**c, //ͼG����Ӿ���  
	*dist;    //��̾������� 
};
template<class Type>
class MinHeapNode {
	friend Graph<Type>;
public:
	operator int() const{ return length;}
private:
	int i;       //������ 
	Type length; //��ǰ·�� 
};

template<class Type>
void Graph<Type>::ShortestPaths(int v){
	MinHeapNode<MinHeapNode<Type>> H(100);
	MinHeapNode<Type> E;
	E.i=v;
	E.length=0;
	dist[v]=0;
	while(true){
		for(int j=1;j<=n;j++){
			if((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j])){
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;
				N.i=j;
				N.length=dist[j];
				H.Insert(N);
			}
			try{ 
				H.DeleteMin(E);
			}
			catch(OutOfBounds){
				break;
			}
		}
	}
}


int main(){
	int n=11;
	int prev[12]={0,0,0,0,0,0,0,0,0,0,0,0};//��ʼ��ǰ����������  
	int dist[12]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};//��ʼ����̾�������
	cout<<"��Դͼ����Ӿ������£�"<<endl;
	int **c=new int*[n+1];
	for(int i=1;i<=n;i++){//����ͼ����Ӿ��� 
		c[i]=new int[n+1];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	int v=1; //Դ���1
	Graph<int> G;
	G.n=n;
	G.c=c;
	G.dist=dist;
	G.prev=prev;

	G.ShortestPaths(v);//����ͼ�����·�������㷨   
	cout<<"��S��T�����·���ǣ�"<<dist[11]<<endl;//�����Դ�������·�� 
	for(int i=2;i<=n;i++){//���ÿ������ǰ����� 
		cout<<"prev("<<i<<")="<<prev[i]<<" "<<endl;
	}
	for(int i=2;i<=n;i++){//�����Դ��㵽�����������·������ 
		cout<<"��1��"<<i<<"�����·���ǣ�"<<dist[i]<<endl;
	}
	for(int i=1;i<=n;i++){ //ɾ����̬����ʱ���ڴ�  
		delete[] c[i];
	}
	delete[] c;
	c=0;
	cout<<endl;
	return 0;
}
