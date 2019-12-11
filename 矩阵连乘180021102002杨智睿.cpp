
/*

����������A[i:j]�����Ŵ����������ļ���������� A[i:k]��A[k+1:j]�Ĵ���Ҳ�����ŵġ�

�������˼��������������Ž������������������Ž⡣�������ʳ�Ϊ�����ӽṹ���ʡ�

����������ӽṹ�����Ǹ�������ö�̬�滮�㷨��������������

 */

 

#include<iostream>

#include<iomanip> 

#include<memory.h>

using namespace std;

//�������A[i:j]���������˴���m[i][j]���ͼ�¼����A[i:j]��ʱ�ĶϿ�λ��s[i][j]

void MatrixChain(int *p, int n, int m[100][100], int s[100][100] )

{

        for (int i = 1; i <= n; i++) m[i][i] = 0; //��ʼ����ʹ�þ�����±��1��1��ʼ        

		for (int r = 2; r <= n; r++)

           for (int i = 1; i <= n - r+1; i++) {

              int j=i+r-1;

              m[i][j] = m[i+1][j]+ p[i-1]*p[i]*p[j];

              s[i][j] = i;

              for (int k = i+1; k < j; k++) {

                 int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                 if (t < m[i][j]) { m[i][j] = t; s[i][j] = k;}

              }

          }

}

 

//���öϿ�λ��s[i][j]�������A[i:j]�����ż����ŷ�ʽ

void print_optimal(int s[100][100], int i ,int j, int a[])

{

	if(i==j)	cout<<" A["<<a[i-1]<<","<<a[i]<<"]";

	else{

		cout<<" ( ";

		print_optimal(s,i,s[i][j],a);

		print_optimal(s,s[i][j]+1,j,a);

		cout<<" ) ";

	}

}

 

void putout(int a[100][100], int n)

{

	int i,j;

	for(i=1;i<=n;i++){

		for(j=1;j<=n;j++)

			cout<<setw(6)<<a[i][j];

		cout<<endl;

	}

}

 

int main()  

{   

	int n,k; 

	int array[100], m[100][100], s[100][100];

	memset(array,0,sizeof(array));

	memset(m,0,sizeof(m));

	memset(s,0,sizeof(s));

 

	while(1)

	{

		cout<<endl<<"�������ĸ��� "<<endl; 

		cin>>n;  

		if(n<=0)break;

		

		cout<<"������ "<<n+1<<" �����������ֱ��Ǹ��������������"<<endl;  

		for(k=0;k<n+1;k++)  

			cin>>array[k];  

		cout<<endl; 

		cout<<"ԭʼ����Ϊ���¾���"<<endl;

		for(k=0;k<n;k++)

			cout<<endl<<setw(3)<<array[k]

			<<" * "<<setw(3)<<array[k+1];  

		cout<<endl; 

 

		MatrixChain(array,n,m,s); 

		

		cout<<"m����"<<endl; 

		putout(m,n);

 

		cout<<"s����"<<endl; 

		putout(s,n);

		

		cout<<endl<<"���ŵ����㷽ʽ�ĳ˷�����Ϊ: "<<m[1][n]<<endl

			<<"�����ŵķ�ʽΪ��"<<endl;

		print_optimal(s,1,n,array);

		

	}

	return 0;

}

