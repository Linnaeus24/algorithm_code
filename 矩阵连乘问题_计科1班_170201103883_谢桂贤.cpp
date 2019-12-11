
#include <iostream>
using namespace std;
int MatrixChain(int *p,int n,int **m,int **s)//���㽫m������������ 
{	
		for(int i=1;i<=n;i++)
			m[i][i]=0;//����������˼������Ϊ0 
	
		for(int r=2;r<=n;r++)
	{		
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}		
	}
	return m[1][n];
}

void Traceback(int i,int j,int **s){
	if(i==j)
		return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A "<<i<<","<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<<","<<j<<endl;
}

int main()

{		
	int n;
	cout<<"���������ĸ�����"<<endl;
	cin>>n;
	int p[n+1]; 
	for(int i=0;i<=n;i++)
	{
		cout<<"�������"<<i+1<<"��Pֵ: "<<endl;
		cin>>p[i];
	}
	int **s = new int *[n+1];
	int **m = new int *[n+1];
	for(int i=0;i<=n;i++){
		s[i]=new int[n+1];
		m[i]=new int[n+1];
	}
		
	cout<<"��С�������Ϊ��"<<MatrixChain(p,n,m,s)<<endl;
	cout<<"���ż���˳��Ϊ��"<<endl;
	Traceback(1,n,s);
	return 0;

}

