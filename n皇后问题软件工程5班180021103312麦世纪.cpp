#include <stdio.h>
 
#define N 4 //4�ʺ� 
#define M N-1
 
int Num = 0; //NumΪ��ĸ���
 
int attack(int a[][N], int i, int j) //attack����ģ��(i,j)λ���ϵĻʺ��ܷ񹥻��������ʺ����ǿ��Թ�������������0�����򷵻�1��
{
	int n,m;
	for(n = 0; n < N; n ++) //�м�� 
	{
		if(n == i)
			continue;
		if (a[n][j] != 0)
			return 0;
	}
	if(i != M && j != M) //���a[i][j]�Ƿ������±߽� 
		for(n = i + 1, m = j + 1; n != N && m != N; n ++, m ++)	  // ���¶Խ��߼��	
			if(a[n][m] != 0)
				return 0;
	if(i != 0 && j != 0) //���a[i][j]�Ƿ������ϱ߽� 
		for(n = i - 1, m = j - 1; n != -1 && m != -1; n --, m --) // ���϶Խ��߼��	
			if(a[n][m] != 0)
				return 0;
	if(i != M && j != 0) //���a[i][j]�Ƿ������±߽� 
		for(n = i + 1, m = j - 1; n != N && m != -1; n ++, m --)  // ���¶Խ��߼��
			if(a[n][m] != 0)
				return 0;
	if(i != 0 && j != M) //���a[i][j]�Ƿ������ϱ߽� 
		for(n = i - 1, m = j + 1; n != -1 && m != N; n --, m ++)  // ���϶Խ��߼��
			if(a[n][m] != 0)
				return 0;
	return 1;
}
 
void put (int a[][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
 
void BT (int a[][N], int i)
{
	int j;
	if(i == N)
	{
		Num ++;
	}
	else
		for(j = 0 ; j < N; j ++)
		{
			a[i][j] = 1;
			if(attack(a,i,j) == 1)
				BT(a,i+1);
			a[i][j] = 0;
		}
}
 
int main ( void )
{
	int a[N][N] = {};
	BT(a,0);
	printf("Num = %d\n",Num);
	return 0;
}

