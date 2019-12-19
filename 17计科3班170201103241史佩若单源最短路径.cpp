#include <iostream>  
#define MAX 1000
#define LEN 100
int k=0, b[LEN];
using namespace std;

//-------------------------------------��������------------------------------------------------
//c[i][j]��ʾ�� (i,j)��Ȩ
//dist[i]��ʾ��ǰ��Դ������i���������·������
//prev[i]��¼��Դ������i�����·���ϵ�i��ǰһ������
//---------------------------------------------------------------------------------------------

void Dijkstra(int n, int v, int dist[], int prev[], int c[][LEN])
{
	bool s[LEN];		// �ж��Ƿ��Ѵ���õ㵽S������
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];
		s[i] = false;	//��ʼ��δ�ù��õ�
		if (dist[i] == MAX)
			prev[i] = 0;	//��ʾv��iǰһ���㲻����
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < n; i++)
	{
		int temp = MAX;
		int u = v;	
		for (int j = 1; j <= n; j++)
			if ((!s[j]) && (dist[j] < temp))  //j����s�У�v��j���벻��Ϊ�����
			{
				u = j;							   	 // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
				temp = dist[j];	
			}
		s[u] = true;
		k++;
		b[k] = u;
		cout << "----------------------------------------------------------" << endl;
		cout << "����������" << i << endl;
		cout << "����Ϊ��";
		cout << v << "\t";
		for (int i = 1; i <= k; i++)
			cout << b[i] << "\t";
		cout << endl;

		for (int j = 1; j <= n; j++)
			if ((!s[j]) && c[u][j] < MAX)
			{
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;		//����dist
					prev[j] = u;			//��¼ǰ������
				}
			}
		cout << "��Դ·���ֱ�Ϊ��" << endl;
		for (int i = 2; i <= n; i++)
			if (dist[i] != MAX)
				cout << dist[i] << "     ";
		cout << endl;
	 }
	cout << "----------------------------------------------------------" << endl;
//	for (int i = 1; i <= n; i++)
	//	t[i] = prev[i];
	int p[LEN];
	for (int i = 2; i <= n; i++)
	{
		cout << "dist[" << i << "]=" << dist[i] << "              ";
		cout << "·��Ϊ��" << v << "\t";
		/*while (t[i] != v)
		{
			cout << t[i] << "\t";
			t[i] = prev[t[i]];
		}*/
		int m = prev[i];
		int k=0;
		while (m != v)
		{
			k++;
			p[k] = m;
			m = prev[m];
		}
		for (int x = k; x >= 1; x--)
			cout << p[x] << "\t";
		cout << i;
		cout << endl;
	}
}

int main()
{
	int i, j,k, m,n, v=1;
	int dist[LEN], prev[LEN], c[LEN][LEN];
	cout << "�����붥�����:" << endl;
	cin >> n;
	cout << "������ߵĸ���:" << endl;
	cin >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				c[i][j] = 0;
			else
				c[i][j] = MAX;
		}
	cout << "������ÿ���ߵ�Ȩ_��ʽΪ�� i j Ȩ" << endl;
	for (k = 1; k <= m; k++)
	{
		cin >> i;
		cin >> j;
		cin >> c[i][j];
	}
	Dijkstra(n, v, dist, prev, c);
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return 0;
}

