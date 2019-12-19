#include <stdlib.h>
#include <stdio.h>
int* Dijkstra(int n,int u,int*dist,int*p,int**C,int*f)
{
	//���s[i]����true,˵������i�Ѽ��뼯��S;����,����i���ڼ���V-S;
	//����S��־�Ƿ�������
	int* s;
	int fi=1;
	s=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
//��ʼ��Դ��u����������֮������·������
		dist[i]=C[u][i];
		s[i]=0;
		
//��������˵������i��Դ��u�����ڣ�����p[i]=-1
		if(dist[i]==1000)
		{
			p[i]=-1;
		}
		else
		{
//˵������i��Դ��u���ڣ�����p[i]=u
			p[i]=u;
		}
	}
	
	dist[u]=0;
//��ʼʱ������s��ֻ��һ��Ԫ��:Դ��u
	s[u]=1;
	f[0]=u;
	for(int i=0;i<n;i++)
	{
		int temp=1000;
		int t=u;
		for(int j=0;j<n;j++)
		{
//���ڼ���S��
			if((!s[j])&&(dist[j]<temp))
			{
				t=j;
				f[fi]=j;
				fi++;
				temp=dist[j];
			}
		}
//����Ҳ���t������ѭ��
		
		if(t!=u){s[t]=1;}	
//����t���뼯��s��
		else
		{
			break;
		}
//������t���ڵĶ��㵽Դ��u�ľ���
		for(int j=0;j<n;j++)
		{
			if(!(s[j])&&(C[t][j]<1000))
			{
				if(dist[j]>(dist[t]+C[t][j]))
				{
					//���¾���
					dist[j]=dist[t]+C[t][j];
					//����ǰ��
					p[j]=t;
				}
			}
		}
	}
	return s;
}
int main()
{
int **C;//��Ȩ��
int i;
int d;//������
int j;
int n;//��ʼ��
int m;//������
int q;//Ȩֵ
int* s;
int flag=1;
int *f;
//��ʼ����Ȩ�ڽӾ���
printf("������ߺ�Ȩ\n");
printf("�������м�������\n");
scanf("%d",&d);
C=(int**)malloc(sizeof(int*)*d);//����ռ�
for(i=0;i<d;i++)
{
	C[i]=(int*)malloc(sizeof(int)*d);
}
f=(int*)malloc(sizeof(int)*d);
//Ԥ�ñ�ȨΪһ������
for(i=0;i<d;i++)
{
	for(j=0;j<d;j++)
	{
		C[i][j]=1000;
	}
}
for(i=0;i<(d*(d-1));i++){
printf("���㶼�ǰ�˳�������磺����0������1,���������밴���ϵı�ֵ������ʼ�ߺͽ�����\n");
printf("��ֱ�������ʼ�ߺͽ�����\n");
printf("��ʼ��:");
scanf("%d",&n);
printf("\n");
printf("������:");
scanf("%d",&m);
printf("\n");
printf("������Ȩֵ:");
scanf("%d",&q);
//���ڽӾ���ֵ
C[n][m]=q;
printf("������ϣ�δ���밴1\n");
scanf("%d",&flag);
if(flag==0)
{
	break;
}
}
//����ǰ�����
int* p;
p=(int*)malloc(sizeof(int)*d);
//�������·������
int* dist;
dist=(int*)malloc(sizeof(int)*d);
for(int i=0;i<d;i++)
{
	dist[i]=1000;
	p[i]=-1;
}
//����
s=Dijkstra(d,0,dist,p,C,f);
printf("���p��dist:\n");
for(int i=0;i<d;i++)
{
	printf("%d,%d\n",p[i],dist[i]);
	/*for(int j=0;j<d;j++)
	{
		printf("%d",C[i][j]);
		printf("\n");
	}*/
}
//s=Dijkstra(d,0,dist,p,C);
//���
for(i=0;i<d;i++)
{
printf("%d ",f[i]);
}
}
