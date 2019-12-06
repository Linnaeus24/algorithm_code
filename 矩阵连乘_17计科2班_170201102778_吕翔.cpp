//3.1 ������������
#include<iostream>

using namespace std;

/**
* ��������
*
*@param p �����������(��p[0]Ϊ��һ�����������) 
*@param n ������� 
*@param m[i][j]��ʾ��i�����󵽵�j���������ŷ���ʱ�������ٵ����˴��� 
*@param s[i][j]��ʾ��i�����󵽵�j���������˴�������ʱ�Ķϵ�λ�� 
*@return 
*/ 
void MatrixChain(int *p, int n, int (*m)[7], int (*s)[7])
{
	for(int i=1; i<=n; i++)
	{
		m[i][i]=0; //���Խ���Ԫ����Ϊ0
		s[i][i]=0; //�ϵ�λ������Ϊ0	
	}
	
	for(int r=2; r<=n; r++) //r�Ƕγ� 
	{
		for(int i=1; i<=n-r+1; i++) //i�Ƕε���� 
		{
			int j=i+r-1; //j�Ƕε��յ� 
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]; 
			s[i][j] = i;
			
			for(int k=i+1; k<j; k++) //��k�����ѣ������������ 
			{
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				
				if(t<m[i][j]) //������ν��t �� ��ʷ�ϵ����Ž�� 
				{
					//�������˴����Ͷϵ�λ�� 
					m[i][j] = t;  
					s[i][j] = k;  
				}
			}
		}
	}
}

int main()
{
	int p[7] = {30,35,15,5,10,20,25};
	int n = 6;
	int m[7][7], s[7][7]; 
	
	MatrixChain(p, n, m, s);
	
	cout<<"m[][]�Ľ��"<<endl; 
	for(int i=1;i<6;i++){
		for(int j=i;j!=1;j--)
			cout<<"\t";
			
		for(int j=i;j<=6;j++){
			cout<<m[i][j]<<"\t";	
		}		
		cout<<endl;
	}
	
	cout<<"s[][]�Ľ��"<<endl; 
	for(int i=1;i<6;i++){
		for(int j=i;j!=1;j--)
			cout<<"\t";
			
		for(int j=i;j<=6;j++){
			cout<<s[i][j]<<"\t";	
		}		
		cout<<endl;
	}
	
	return 0;
}
