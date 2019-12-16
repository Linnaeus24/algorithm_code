
#include <iostream>
using namespace std;

const int maxint = 999999;
const int maxnum = 100;
int n, line;             // ͼ�Ľ������·����
int dist[maxnum];     // ��ʾ��ǰ�㵽Դ������·������
int prev[maxnum];     // ��¼��ǰ���ǰһ�����
int c[maxnum][maxnum];   // ��¼ͼ�������·������

void Dijkstra(int n,int v,int dist[], int prev[], int c[maxnum][maxnum]){
	bool s[maxint];
	for(int i=1;i<=n;i++){
		dist[i] = c[v][i];
		s[i]=false;
		if(dist[i]==maxint){
			prev[i]=0;
		}else{
			prev[i]=v;
		}
	}
	dist[v]=0;s[v]=true;
	for(int i=1;i<n;i++){
		int temp = maxint;
		int u=v;
		for(int j=1;j<=n;j++){
			if((!s[j]) && (dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j])&&(c[u][j]<maxint)){
					int newdist = dist[u] + c[u][j];
					if(newdist < dist[j]){
						dist[j] = newdist;
						prev[j]=u;
					}
				}
			}
		}
	}
} 
 
 
int main()
{
     freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> line;
    int p, q, len;

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;

    for(int i=1; i<=line; ++i){
        cin >> p >> q >> len;
        if(len < c[p][q]){
            c[p][q] = len;
            c[q][p] = len;
        }
    }

    for(int i=1; i<=n; ++i)
        dist[i] = maxint;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            printf("%8d", c[i][j]);
        printf("\n");
    }

    Dijkstra(n, 1, dist, prev, c);

    cout << "Դ�㵽���һ����������·������: " << dist[n] << endl;
}
