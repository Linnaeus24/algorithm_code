#include<bits/stdc++.h>
using namespace std;
void matrixChain(int n,int p[],int m[][100],int s[][100])//����
{
   for(int i=1;i<=n;i++){//�Խ�����Ϊ0
    m[i][i]=0;
   }
   for(int r=2;r<=n;r++){//һ��n-1���Խ���
    for(int i=1;i<=n-r+1;i++){//��i��
        int j=i+r-1;//�ڸ��еĶԽ����ϵĵ��Ӧ��jֵ
        m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];//��ʼ����ʱ��i��ȡ�����Ž�
        s[i][j]=i;
        for(int k=i+1;k<j;k++){//����и�С�����滻
            int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            if(t<m[i][j])
            {
                m[i][j]=t;
                s[i][j]=k;
            }
        }
    }
   }
}
void print_optimal_parents(int s[100][100],int i,int j)//��ӡ���ֵĽ��
 {
     if( i == j)
         cout<<"A"<<i;
     else
     {
         cout<<"(";
         print_optimal_parents(s,i,s[i][j]);
         print_optimal_parents(s,s[i][j]+1,j);
         cout<<")";
     }

 }
int main()
{
    int p[1000];//ÿ����������������һ��������
    int m[100][100];//�洢�����ӽṹ
    int s[100][100];//�洢��ǰ�ṹ�����Ŷϵ�
    memset(p,0,sizeof(p));
    memset(m,0,sizeof(m));
    memset(s,0,sizeof(s));
    cout << "���������ĸ���"<< endl;
    int n;
    cin >> n;
    cout << "����������ÿ����������������һ�����������"<< endl;
    for(int i=0;i<=n;i++){
        cin >> p[i];
    }
    matrixChain(n,p,m,s);
    cout <<"��Щ������˵����ٴ�����"<<m[1][n]<<endl;
    cout<<"�����:"<<endl;
    print_optimal_parents(s,1,n);
    return 0;
}
