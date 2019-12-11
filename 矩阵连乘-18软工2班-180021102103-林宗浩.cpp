#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=105;

//bool Judge(int ra, int ca, int rb, int cb)
//{
//	if(ca!=rb)
//		return false;
//	return true;
//}

//��������ֵ,�������˴��� 
void MatrixChain(int p[], int n, int m[][N], int s[][N])
{
	for(int i=1;i<=n;i++)
	{
		m[i][i]=0;//�Խ��� 
	}
	for(int r=2;r<=n;r++)
	{//rΪ�γ� 
		for(int i=1;i<=n-r+1;i++)
		{//iΪ����� 
			int j=i+r-1;//jΪ���յ�
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];//�ȳ�ʼ��,�ϵ��ȶ���i��i+1�� 
			s[i][j]=i;//��¼�ϵ�λ�� 
			for(int k=i+1;k<j;k++)
			{//kΪ�ϵ�λ�� 
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t;//�������˴������ٵ� 
					s[i][j]=k;//���¶ϵ� 
				}
			}
		}
	}
}

//�������Ž�
void Traceback(int i, int j, int s[][N])
{
	if(i==j)
		return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout << "Multiply A " << i << "," << s[i][j];
	cout << " and A " << (s[i][j]+1) << ", " << j << endl;
}

//��һ�ִ�ӡ����
void Traceback1(int i, int j, int s[][N])
{
	if(i==j)
		cout << "A" << i;
	else
	{
		cout << "(";
		Traceback1(i,s[i][j],s);
		Traceback1(s[i][j]+1,j,s);
		cout << ")";
	}
}

int main()
{
	int p[N*10];//ÿ�����������,p[0]Ϊ��һ����������� 
	int m[N][N];//�洢���Ž��
	int s[N][N];//�洢��ǰ�ṹ�����Ŷϵ�
	cout << "���������ĸ�����";
	int n;
	int flag=1;
	while(cin >> n)
	{
		memset(p,0,sizeof(p));
		memset(m,0,sizeof(m));
		memset(s,0,sizeof(s));
//		cout << "�밴˳����������ÿ����������������һ�������������" << endl; 
//		for(int i=0;i<=n;i++)
//		{
//			cin >> p[i];
//			if(i!=1)
//			{
//				if(!Judge(p[i-2],p[i-1],p[i-1],p[i]))
//				{
//					cout << "���󲻿ɳ�" << endl;
//					flag=0;
//					break;
//				}
//			}
//		}
		for(int i=1;i<=n;i++)
		{
			cout << "�������" << i << "��������к��У�";
			if(i==1)
			{
				cin >> p[0] >> p[1];//��һ��������к��� 
			}
			else
			{
				int a,b;
				cin >> a >> b;
				if(a!=p[i-1])
				{
					cout << "���󲻿ɳ�" << endl;
					flag=0;
					break;
				}
				p[i]=b;
			}
		}
		if(flag)
		{
			MatrixChain(p,n,m,s);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i>j)
						cout << "\t";
					else
						cout << m[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl;
			cout << "������˵��������˴���Ϊ��" << m[1][n] << endl;
			cout << endl << "������˷�ʽ˳��" << endl;
			Traceback(1,n,s);
			cout << "���ߣ�" << endl;
			Traceback1(1,n,s);
			cout << endl << endl;
		}
		cout << "���������ĸ�����";
	}
	return 0;
}
