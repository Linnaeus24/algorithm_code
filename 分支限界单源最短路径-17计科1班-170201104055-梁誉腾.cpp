#include <iostream>
#include <iomanip>

using namespace std;

#define inf 1000000

template<class T>
class MinHeap   //��С����
{
	template<class Type>
	friend class Graph;
public:
	MinHeap(int maxheapsize=10);  //���캯�����ѵĴ�С��10
	~MinHeap(){delete[] heap;}     //��С�ѵ���������
	int Size() const{return currentsize;}  //Size()������С�ѵĸ���
	T Max(){if(currentsize) return heap[1];}   //��һ��Ԫ�س���
	MinHeap<T>& Insert(const T& x);   //��С�ѵĲ��뺯��
	MinHeap<T>& DeleteMin(T& x);    //��С�ѵ�ɾ������
	void Initialize(T x[],int size,int ArraySize);  //�ѵĳ�ʼ��
	void Deactivate();
//	void output(T a[],int n);
private:
	int currentsize,maxsize;  
	T *heap;   
};

/*
template<class T>
void MinHeap<T>::output(T a[],int n)    //������������a[]�����Ԫ��
{
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}
*/

template<class T>
MinHeap<T>::MinHeap(int maxheapsize)
{
	maxsize=maxheapsize;
	heap=new T[maxsize+1];  //������
	currentsize=0;
}

template<class T>
MinHeap<T>& MinHeap<T>::Insert(const T& x)
{
	if(currentsize==maxsize)   //������е�Ԫ���Ѿ����ڶѵ�����С
		return *this;     //��ô�����ڼ���Ԫ�ؽ������
	int i= ++currentsize;
	while(i!=1 && x<heap[i/2])
	{
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=x;
	return *this;
}

template<class T>
MinHeap<T>& MinHeap<T>::DeleteMin(T& x)  //ɾ���Ѷ�Ԫ��
{
	if(currentsize==0) 
	{
		cout<<"Empty heap!"<<endl;
		return *this;
	}
	x=heap[1];  

	T y=heap[currentsize--];
	int i=1,ci=2;
	while(ci<=currentsize)
	{
		if(ci<currentsize && heap[ci]>heap[ci+1])
			ci++;
		if(y<=heap[ci])
			break;
		heap[i]=heap[ci];
		i=ci;
		ci*=2;
	}
	heap[i]=y;
	return *this;
}

template<class T>
void MinHeap<T>::Initialize(T x[],int size,int ArraySize)  //�ѵĳ�ʼ��
{
	delete[] heap;
	heap=x;
	currentsize=size;
	maxsize=ArraySize;
	for(int i=currentsize/2;i>=1;i--)
	{
		T y=heap[i];
		int c=2*i;
		while(c<=currentsize)
		{
			if(c<currentsize && heap[c]>heap[c+1])
				c++;
			if(y<=heap[c])
				break;
			heap[c/2]=heap[c];
			c*=2;
		}
		heap[c/2]=y;
	}
}

template<class T>
void MinHeap<T>::Deactivate()
{
	heap=0;
}



template <class Type>
class Graph
{
	friend int main(void);
public:
    void ShortestPaths(int);
private:
    int n,//������ 
	*prev;	//ǰ��
	Type **c;//�ڽӾ���
	*dist;//��̾��� 
};

template <class Type>
class MinHeapNode
{
	friend Graph<Type>;
public:
	operator int () const{return length;}
private:
	int i;          //������ 
	Type length;    //��ǰ·�� 
};

template <class Type>
void Graph<Type>::ShortestPaths(int v)
{
	MinHeap < MinHeapNode<Type> > H(1000);   //��С������ 
	MinHeapNode<Type> E;//����ԴΪ��ʼ��չ���
	E.i=v;
	E.length=0;
	dist[v]=0;
	while(true){
		for(int j=1;j<=n;j++)
			if((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j]))
			{
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;
				N.i=j;
				N.length=dist[j];
				H.Insert(N);
			}
		
		try{ H.DeleteMin(E);}
		catch(int) {break;}
		if(H.currentsize==0) {break;}
	
	} 
}

int main()
{
    
    int n,v,*dist,*prev,**c;
    
    do
    {
    cout<<"������ͼG��������n(n>0)��";
    cin>>n;
    }while(n<=0||n==NULL) ;   
    
    dist=new int[n+1];
    prev=new int[n+1];
    c=new int*[n+1];
    
    for(int i=0;i<=n;i++)
    {
    	dist[i]=inf;
    	prev[i]=0;
	}
	
	cout<<"�������뵥Դͼ���ڽӾ���"<<endl;
	for(int i=1;i<=n;i++)  //����ͼ���ڽӾ���
	{
		c[i]=new int[n+1];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][j]==0) c[i][j]=inf;
		}
	}


	Graph<int> G;
	G.n=n;
	G.c=c;
	G.dist=dist;
	G.prev=prev;

    do
	{
		cout<<endl<<"������Դv: ";
        cin>>v;		
	}while(v<=0||v>n);

	G.ShortestPaths(v);//����ͼ�����·�������㷨

/*
	for(int i=1;i<=n;i++)//���ÿ������ǰ�����
	{
		cout<<"prev["<<i<<"]="<<prev[i]<<" "<<endl;
	}
*/	
    cout<<endl;
	for(int i=1;i<=n;i++)  //�����Դ��㵽�����������·������
	{
		if(i!=v) 
		{
			if(dist[i]>=inf) cout<<"��"<<v<<"�޷�����"<<i<<endl<<endl;
			else 
			{
			   cout<<"��"<<v<<"��"<<i<<"�����·���ǣ�"<<dist[i]<<endl;
			   cout<<"���·��Ϊ��"<<i;
			   int k=prev[i];
			   while(true)
			   {			   	     			   				   	   	
					cout<<"<=="<<k;	
					k=prev[k];
					if(k==0) break;		   	   					    			   	   	
			   }
			   cout<<endl<<endl;
			}			
		}
	}	

	for(int i=1;i<=n;i++)    //ɾ����̬����ʱ���ڴ�
	{
		delete[] c[i];
	}

	delete[] c;
	c=0;

    
	
	return 0;
}
