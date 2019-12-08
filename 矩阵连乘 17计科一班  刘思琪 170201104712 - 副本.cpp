#include <iostream>

using namespace std;

const int N=6;
int p[]={20,15,15,5,30,15,20};
int m[N+1][N+1];
int s[N+1][N+1];

void matrixMultiply(int *p,int m[][N+1],int s[][N+1])
{
    for(int i=1;i<=N;i++) m[i][i]=0;//�����ʼ��
  	  for(int r=2;r<=N;r++)//�������������ģ��r�����ˣ�
        for(int i=1;i<=N-r+1;i++)//������������
        {
            int j=i+r-1;               
            m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];//k��ʱΪi��
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];//�˴����ѣ�Ȼ����� 
                if(t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
}

void traceback(int i,int j,int s[][N+1])
{
    if(i==j||i==N)
    {
        cout<<"A"<<i;
        return ;
    }
    cout<<"(";
    traceback(i,s[i][j],s);
    cout<<")(";
    traceback(s[i][j]+1,j,s);
    cout<<")";
}

int main()
{

    matrixMultiply(p,m,s);
    cout<<m[1][N]<<endl;
    traceback(1,N,s);
    cout<<endl;
    return 0;
}

