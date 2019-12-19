#include <iostream>
typedef int Type;
#define max 1000 
//#define H 1000
#define inf 10000  
//template<class Type>
//
template<class Type>
class Graph{

	friend void main(void);
		public:
			void ShortestPaths(int);
		private:
			int n,*prev;//ͼG�Ķ����� ��ǰ���������� 
			int **c,*dist;//ͼG���ڽӾ�����̾����� 
}; 
template<class Type>//class   MinHeap;
class MinHeapNode{
	public:
		operator int() const{return length;}
	private:
		int i;//������ 
		int length;//��ǰ·�� 
};
template<class Type>
void Graph<Type>::ShortestPaths(int v){//��Դ���·�������ȶ��з�֧���� 
	  MinHeapNode<Type> H(1000);
	MinHeapNode<Type> E;//��ʼ��չ��� 
	E.i=v;//��ʼ�� 
	E.length=0;
	while(true){//��������Ľ�ռ� 
		for(int j=1;j<=n;j++){
			if((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j])){
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;// ����������ȶ��� 
				N.i=j;
				N.length=dist[j];
				H.Insert(N);//������� 
			}
		
				H.DeleteMin(E);//ȡ�Ѷ� 
		}
	}
}
int main(){
	int n=5;
	int c[6][6];
	int dist[6];
	int prev[6]; 
	c[n][n]={{0,2,3,4,max,max},
	{max,0,3,max,2,max},//�����ڽӾ��� 
	{max,max,0,max,9,2},
	{max,max,max,0,max,2},
	{max,max,max,max,0,1},
	{max,max,max,max,max,0}};
	ShortestPaths(1);//����    
	return 0;
}
