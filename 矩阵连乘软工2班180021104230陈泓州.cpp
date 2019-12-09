//�������� 
#include <iostream>
using namespace std;
void MatrixChain(int p[],int n,int m[][15],int s[][15]){
	//p�����ڴ�ž���������������,n�Ǿ�����,m������ֵ���� 
	//s�Ǽ�¼���ŶϿ�λ�õ����� 
	for(int i = 1;i <= n;i++)
	m[i][i] = 0;
	for(int r = 2;r <= n;r++){	//r�Ƕγ� 
		for(int i = 1;i <= n-r+1;i++){	//i�Ƕ���� 
			int j = i + r-1;	//j�Ƕ��յ� 
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];		//i������ 
			s[i][j] = i;	//��ʼ�� 
			for(int k = i + 1; k < j;k++){		//��k������,��������k����� 
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < m[i][j]){		//�����ǰ��������,��ˢ�� 
					m[i][j] = t;
					s[i][j] = k;		//m[i][j]��¼ 
				}
			}
		}
	} 
}

void Traceback(int i,int j,int s[][15]){
	if(i == j)
	return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<", "<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<<", "<<j<<endl;
}

int main(){
	int m[15][15] = {0};
	int s[15][15] = {0};
	int p[20] = {0};
	int n;
	cout<<"������������:"<<endl;
	while(cin>>n)
	{
		cout<<"�ֱ�����"<<n<<"�����������������:"<<endl;
		for(int i = 1;i <= n;i++)
		{
			int a,b;
			cin>>a>>b;
			if(i == 1)	//�жϲ���������������� 
			{
				p[0] = a;
				p[1] = b;
			}
			else if(a == p[i-1])
				p[i] = b;
			else if(b == p[i-1])
				p[i] = a;
			else
			{
				cout<<"����ľ��󲻷�������."<<endl;
				break;
			}
		}
		MatrixChain(p,n,m,s);
		cout<<"���ٵ����˴���:"<<m[1][n]<<"."<<endl;
		Traceback(1,n,s);
		cout<<endl; 
		cout<<"������������:"<<endl;
	}
	return 0;
	 
} 
