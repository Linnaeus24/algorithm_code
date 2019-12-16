#include<stdio.h>
#define maxint 100

int k=0,b[maxint];
//----------------------��������------------------------
//n��ʾ����
//V��ʾԴ��
//dist[]��ʾ��ǰ��Դ������i���������·������
//prve[]��ʾ��¼��Դ�㵽����i�����·���ϵ�i��ǰһ������
//c[][]��ʾ�ߣ�i��j����Ȩ
//-------------------------------------------------------

void Dijkstra(int n,int v,int dist[],int prev[],int c[][maxint]){
	bool s[maxint];            //�ж��Ƿ��Ѵ���õ㵽S����
	for(int i=1;i<=n;i++){
		dist[i]=c[v][i];
		s[i]=0;            //��ʼ��δ�ù��õ�
		if(dist[i]==maxint)
			prev[i]=0;	       //��ʾv��iǰһ���㲻����
		else
			prev[i]=v;
	}
	dist[v]=0;
	s[v]=1;
	for(int i=1;i<n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++)	
			if((!s[j])&&(dist[j]<temp)){         //j����s�У�v��j���벻��Ϊ�����
				u=j;                             //u���浱ǰ�ڽӵ��о�����С�ĵ��
				temp=dist[j];
			}
		s[u]=1;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(c[u][j]<maxint)){       
				int newdist=dist[u]+c[u][j];
				if(newdist<dist[j]){
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
		
	}
	
} 



int main(void){
	int i,j,k,m,n,v=1;
	int dist[maxint],prev[maxint],c[maxint][maxint];
	printf("�����붥�������\n");
	scanf("%d",&n);
	printf("������ߵĸ�����\n");
	scanf("%d",&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				c[i][j]=0;
			}
			else c[i][j]=maxint;
		}
	}
	printf("������ÿ���ߵ�Ȩ(��ʽΪ��i  j  Ȩ)��\n");
	for(k=1;k<=m;k++){
		scanf("%d",&i);
		scanf("%d",&j);
		scanf("%d",&c[i][j]);
	}
	Dijkstra(n,v,dist,prev,c);
	printf("---------------------------------\n");
	for(int i=1;i<=n;i++){
		printf("V1-->V%d:%d\t",i,dist[i]);
		printf("\n");
	} 

	return 0;
	
}
