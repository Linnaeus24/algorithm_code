#include <stdio.h>
#include <stdlib.h>
void MatrixChain(int p[6],int n,int m[][7],int s[][7])
{
int r=0,i=0,j=0,k=0,t=0;
for(i=1;i<=n;i++)
    m[i][i]==0;
for(r=2;r<=n;r++)
for(i=1;i<=n-r+1;i++)//n-r+1��ʾ��֤��r���������
{
    j=i+r-1;//��r=3ʱ ���������� ��j=i+2��������Ҫ-1
    m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];//Ĭ���ڳ�ʼ�±�֮��Ͽ����õ���ʼֵ
    s[i][j]=i;
    for(k=i+1;k<j;k++)
    {
        t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
        if(t<m[i][j]){
            m[i][j]=t;
            s[i][j]=k;
        }

    }
}
}
void TrackBack(int i,int j, int s[][7])
{
    if(i==j) return;
    TrackBack(i,s[i][j],s);//�ݹ��һ�ζϿ�֮ǰ
    TrackBack(s[i][j]+1,j,s);
    printf("A%d",i);
    printf(" and A%d",j);
    printf("\n");

}
int main()
{
   int n=6;
   int p[]={30,35,15,5,10,20,25};
   int s[7][7]={0};
   int m[7][7]={0};
   MatrixChain(p,n,m,s);
   TrackBack(1,n,s);
}

