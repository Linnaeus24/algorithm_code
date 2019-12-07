#include<iostream>
using namespace std;

const int N=7;
void MatrixChain(int *p,int m[N][N],int s[N][N],int n)
{		
	int r,i,j,k,t=0;	//m[i][i]ֻ��һ������������˴���Ϊ0����m[i][i]=0;	
	for(i=1;i<=n;i++)	
	{		
		m[i][i]=0;//�Խ���λ��	
	}
	for(int r=2;r<=n;r++)//l=2Ϊ�Խ��߽��ڵ�����λ�ã�����l�����󣬼��������Ͻǵķ���������������ĳ���	
	{		
		for(i=1;i<=n-r+1;i++)		
		{			
			j=i+r-1; //��iΪ��ʼλ�ã�jΪ����Ϊl������ĩλ��			
			m[i][j]=m[i+1][j]+p[i-1]+p[i]*p[j];			//k��i��j-1,��kΪλ�û���
			s[i][j]=i;			
			for(k=i+1;k<j;k++){				
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];				
				if(t<m[i][j]){					
					m[i][j]=t;					
					s[i][j]=k;				
				}			
			}		
		}	
	}	
	cout << m[1][N-1] << endl;
}

void PrintAnswer(int s[N][N],int i,int j){	
	if(i==j)//ֻ��һ������ֱ�����	
	{		
		cout<<"A"<<i;	}
	else//�Ƿ���Ҫ�����һ��������������󣬼������������	
	{		
	cout<<"(";	
	PrintAnswer(s,i,s[i][j]);//�ݹ飬�ӵõ����Ž�ĵط���ʼs[i][j]���Ͽ�		
	PrintAnswer(s,s[i][j]+1,j);		
	cout<<")";	
	}
}

int main()
{
	int p[N]={30,35,15,5,10,20,25};
	int m[N][N],s[N][N];
	MatrixChain(p,m,s,N);
	PrintAnswer(s,1,N-1);
	return 0;
}
