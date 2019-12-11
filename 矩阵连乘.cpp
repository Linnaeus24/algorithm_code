
#include <iostream> 
#include <stdlib.h>
using namespace std; 


int MatrixChain(int *p,int n,int **m,int **s); 
void Traceback(int i,int j,int **s);
void Traceback1(int i,int j,int **s); 
int main()
{ 
	int n ;
	cout<<"�������ĸ�����" ;
	cin>>n; 
	int p[n+1]; 
	cout<<"�������������в�����"<<endl;
	for(int i=0;i<n+1;i++)
	{
		cin>>p[i];
	}
    int **s = new int *[n+1];
	int **m = new int *[n+1];
	for(int i=0;i<=n;i++)  
    {  
		s[i] = new int[n+1];
		m[i] = new int[n+1];
    } 
	cout<<"��������ټ������Ϊ��"<<MatrixChain(p,n,m,s)<<endl;
	cout<<"�������ż������Ϊ��"<<endl;
	Traceback(1,6,s);
	system("pause");
	return 0;
}

int MatrixChain(int *p,int n,int **m,int **s)
{
	for(int i=1; i<=n; i++)
	{
		m[i][i] = 0;
	}
	for(int r=2; r<=n; r++) //rΪ��ǰ������������������ģ��  
	{
		for(int i=1; i<=n-r+1; i++)//n-r+1Ϊ���һ��r����ǰ�߽�  
		{
			int j = i+r-1;//����ǰ�߽�Ϊr������Ϊr�����ĺ�߽�  

			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];//����ij����ΪA(i) * ( A[i+1:j] ) 

			s[i][j] = i;

			for(int k=i+1; k<j; k++)
			{
				//����ij����Ϊ( A[i:k] )* (A[k+1:j])   
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][n];
}

void Traceback(int i,int j,int **s)
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
}
