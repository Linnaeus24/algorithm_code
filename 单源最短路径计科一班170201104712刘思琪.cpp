#include <stdio.h>
#define M	999999 //����� ���ǲ��ɴ� ľ��·�� 
#define N	5 //������
//��������㵽�����������·��
void Dijkstra(int Cost[][N], int v0, int Distance[], int prev[])
{
    int s[N];
    int mindis,dis;
    int i, j, u;
    for(i=0; i<N; i++)//��ʼ��
    {
        Distance[i] = Cost[v0][i];
        s[i] = 0;
        if(Distance[i] == M)
			prev[i] = -1;
        else
			prev[i] = v0;
    }
    Distance[v0] = 0;
    s[v0] = 1; 
    for(i=1; i < N; i++)
    {
        mindis = M;
        u = v0;
        for (j=0; j < N; j++) //�������������Ķ���
			if(s[j]==0 && Distance[j]<mindis)
			{
				mindis = Distance [j];
				u = j;
			} 
        s[u] = 1;
        for(j=0; j<N; j++) 
        if(s[j]==0 && Cost[u][j]<M)
        { 
            dis = Distance[u] +Cost[u][j];
            if(Distance[j] > dis)// ����µ�·�����̣���ˢ�� 
            {
                Distance[j] = dis;
                prev[j] = u;
            }
        } 
    } 
}
void PrintPrev(int prev[],int v0,int vn)// ������·��
{
    int tmp = vn;
    int i, j;
    int tmpprv[N];
    for(i=0; i < N; i++)//��ʼ��
		tmpprv[i] = 0;
    tmpprv[0] = vn+1;
    for(i =0, j=1; j < N ;j++)
    {
        if(prev[tmp]!=-1 && tmp!=0)
        {
            tmpprv[i] = prev[tmp]+1;
            tmp = prev[tmp];
            i++;
        }
        else break;
    }
    for(i=N-1; i >= 0; i--)//���·��
    {
        if(tmpprv[i] != 0)
        { 
            printf("p%d", tmpprv[i]);
            if(i)  
                printf("->");
        }
    }
	printf("->p%d", vn+1);
}
int main()
{
    char *Vertex[N]={"p1", "p2", "p3", "p4", "p5"};
    //�������������ڽӾ���
    int Cost[N][N]={
		{0, 20, M, 40, 80},
        {M, 0, 30, M, M},
        {M, M, 0, M, 20},
        {M, M, 50, 0, 100},
        {M, 20, M, M, 0},
    };
    int Distance[N]; //���·������
    int prev[N];  //���·��
	int i;
    Dijkstra(Cost, 0, Distance, prev); //����Dijkstra�㷨�������󶥵�V1�������������·��
    for(i=0; i < N; i++)
    {
        printf("%s->%s:%d\t", Vertex[0], Vertex[i], Distance[i]); 
        PrintPrev(prev, 0, i); 
        printf("\n");
    }
    return 0;
}
