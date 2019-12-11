#include <iostream>
using namespace std;




void MatrixChain(int *p,int n,int **m,int **s)	//�������ٴ��� 
{
	for(int i=1;i<=n;i++)    
	    m[i][i]=0;           //���Լ����ü��� 
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n-r+1;i++)
		{		
		   int j=i+r-1;
		   m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];   //�����i������j������ 
		   s[i][j]=i;
		   for(int k=i+1;k<j;k++)
		   {
		   	  int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
		   	  if(t<m[i][j])               
		   	  {
		   	     m[i][j]=t;
			     s[i][j]=k;				  	//��i������j�����ŵĶ���λ�� 
			  }
		   }
		}
	}
 
}

void Traceback(int i,int j,int **s,int **m)
{
	if(i==j) return;
	Traceback(i,s[i][j],s,m);
	Traceback(s[i][j]+1,j,s,m);
	
	if(i==s[i][j])
	    cout<<"����A"<<i;
	else	
	    cout<<"����A"<<i<<"~"<<s[i][j];
	if(s[i][j]+1==j)
	    cout<<"��A"<<j<<"�ĳ˻�"<<endl;		    
	else
	    cout<<"��A"<<(s[i][j]+1)<<"~"<<j<<"�ĳ˻�"<<endl;	
}

int main()
{
int *p,n,**m,**s;
	cout<<"���������1�ľ�������"<<endl;
	cin>>n;
	while(n<=1)
	{
	   cout<<"���������1�ľ�������"<<endl;
	   cin>>n;
	}
	
	p=new int[n+1];
	m=new int*[n+1];
	s=new int*[n+1];
	
	for(int i=0;i<=n;i++)
	{
		m[i]=new int[n+1];
		s[i]=new int[n+1];		
	}
	
	cout<<"������"<<n<<"�������ά������"<<endl;
	for(int i=1;i<=n;i++) //ֻ�����������ά�� 
	{
        
        if(i==1)
        {
        	cout<<"p"<<i-1<<"=";
        	cin>>p[i-1];    
			while(p[i-1]<=0)
			{
			    cout<<"������Ϸ�����������1��������";
			    cout<<"p"<<i-1<<"=";
        	    cin>>p[i-1];    
			} 	
		}
         	cout<<"p"<<i<<"=";
        	cin>>p[i];
			while(p[i]<=0)
			{
			    cout<<"������Ϸ�����������1��������";
			    cout<<"p"<<i<<"=";
        	    cin>>p[i];    
			} 	  

        cout<<"A["<<i<<"]="<<p[i-1]<<"*"<<p[i]<<endl<<endl;
        

	} 

	
	MatrixChain(p,n,m,s);
	cout<<"����m[1]["<<n<<"]��˵����ֵΪ��"<<m[1][n]<<"��"<<endl<<endl;


	cout<<"����������ŵļ������"<<endl;
	Traceback(1,n,s,m);
	
	delete []p;
	delete []m;
	delete []s; 
	return 0;
}
