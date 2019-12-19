//��Դ���·������ ��֧ �޽編���  
//������㵽�������ж�������·������ 

#include "MinHeap2.h"  
#include <iostream> 
#include<iomanip> //��I/O������ͷ�ļ�����Ҫ�Ƕ�cin,cout֮���һЩ����������    
#include <fstream>  
#include<stdlib.h> 
using namespace std;  
#define MaxInt 32767    //��ʾ����ֵ������  
ifstream fin("intput6-2-(1).txt"); 
//ifstream fin("intput6-2-(2).txt");   
  
template<class Type>  
class Graph  
{  
   public:  
    void ShortesPaths(int);  
    void input(int n1, Type **c1,Type *dist1,int *prev1)    	   
	  {
	  	 n=n1; 
    	 c=c1;  
    	 dist=dist1;  
    	 prev=prev1; 
	  }   
    
    private:  
        int     n,         //ͼG�Ķ�����  
                *prev;     //ǰ����������  
        Type    **c,       //ͼG����Ӿ���  
                *dist;     //��̾�������  
};   
  
template<class Type>  
class MinHeapNode  
{  
   friend Graph<Type>;  
   public:  
       operator int ()const
	   {
	      return length;
	   } 
	    
   private:  
       int       i;       //������  
       Type  length;      //��ǰ·��  
};   
  
template<class Type>  
void Graph<Type>::ShortesPaths(int v)//��Դ���·����������ȶ���ʽ��֧�޽編  
{   
    MinHeap< MinHeapNode<Type> > H(1000);  
    MinHeapNode<Type> E;  
  
    //����ԴΪ��ʼ��չ�ڵ�  
    E.i=v;  
    E.length=0;  
    dist[v]=0;  
  
    while (true)//��������Ľ�ռ�  
    {  
       for (int j = 1; j <= n; j++)  
            if ((c[E.i][j]<MaxInt)&&(E.length+c[E.i][j]<dist[j])) 
            {                  
				 // ����i������j�ɴ���������Լ��  
                 dist[j]=E.length+c[E.i][j];  
                 prev[j]=E.i;  
  
                 // ����������ȶ���  
                 MinHeapNode<Type> N;  
                 N.i=j;  
                 N.length=dist[j];  
                 H.Insert(N);  
            }  

        if (H.currentsize==0)// ���ȶ��п�  
        {  
            break;  
        }  
        else 
          {
          	H.DeleteMin(E); // ȡ��һ��չ��� 
          }                     
    }  
} 

void DisplayPath(int prev[],int begin,int temp )
{	//��ʾ���·
	if(prev[temp]!=0){
		DisplayPath(prev,begin,prev[temp]);
		cout << prev[temp] << "-->";
	}
}//DisplayPath 
  
int main()  
{    
    int n=11; //ͼ�Ķ����� 
    int *prev=new int[n+1]; //0�ŵ�Ԫ��ʹ��  
    int *dist=new int[n+1];  //0�ŵ�Ԫ��ʹ�� 
	
	//��ʼ��prev[]��Ϊ0��dist[]��Ϊ����ֵ 
	for(int i=1;i<=n;i++) //0�ŵ�Ԫ��ʹ�� 
	 {
	 	prev[i]=0;
	 	dist[i]=MaxInt;
	 } 
    cout<<"ͼ���ڽӾ������£�"<<endl;  
    int **c = new int*[n+1];  
  
    for(int i=1;i<=n;i++)  
    {  
        c[i]=new int[n+1];  
        for(int j=1; j<=n; j++)  
        {  
            fin>>c[i][j];  
            cout<< setw(6)<<c[i][j]<<" ";  
        }  
        cout<<endl;  
    }  
    
	cout<<"ͼ�Ķ�����Ϊ:";
    for(int i=1;i<=n;i++)
      cout<<i<<" ";
    cout<<endl;
    
	int start;  
    cout<<"��������㣺";
    cin>>start;
    Graph<int> G;  
    G.input(n, c,dist,prev);
    
    G.ShortesPaths(start);  
	 
    for (int i = 1; i <= n; i++)  
    {          
		cout<<"prev("<<i<<")="<<prev[i]<<"   "<<endl;  
    }  
  
    for (int i = 1; i <= n; i++)  
    {  
        if(i!=start)
        {
        	if(dist[i]<MaxInt)
        	{
				cout<<"��"<<start<<"��"<<i<<"�����·���ǣ�"<<dist[i]<<",  ·��Ϊ��";
				DisplayPath(prev,start,i);
	    		cout <<i<<endl;  
        	}
        	else
        	 	cout<<"��"<<start<<"��"<<i<<"û��·�����"<<endl;			
        }
		
    }  
 
    for(int i=1;i<=n;i++)  
    {  
        delete []c[i];  
    }  
  
    delete []c;  
    c=0; 
	system("pause");     
    return 0;  
} 


