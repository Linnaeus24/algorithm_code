#include<stdio.h>
#define maxsize 1000  
#define n 7  //������Ŀ
void dijkstra(int C[][n],int v);
int main()
{
 printf("                           ������Ԫ���·���㷨����\n");
 int C[n][n]={
  {maxsize,13,8,maxsize,30,maxsize,32},
  {maxsize,maxsize,maxsize,maxsize,maxsize,9,7},
  {maxsize,maxsize,maxsize,5,maxsize,maxsize,maxsize},
  {maxsize,maxsize,maxsize,maxsize,6,maxsize,maxsize},
  {maxsize,maxsize,maxsize,maxsize,maxsize,2,maxsize},
  {maxsize,maxsize,maxsize,maxsize,maxsize,maxsize,17},
  {maxsize,maxsize,maxsize,maxsize,maxsize,maxsize,maxsize}
 },v=1,i,j;
 printf("������ͼ���ڽӾ���\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("\t%d",C[i][j]);
  }
  printf("\n");
 }
 printf("��ԭ��1��������������·�����䳤�ȡ�\n");
 dijkstra(C,v);
}
void dijkstra(int C[][n],int v)
{
 int D[n];
 int P[n],S[n];
 int i,j,k,v1,pre;
 int min,max=maxsize,inf=1200;
 v1=v-1;
 for(i=0;i<n;i++)
 {
  D[i]=C[v1][i];   
  if(D[i]!=max)
   P[i]=v;
  else
   P[i]=0;
 }
 for(i=0;i<n;i++)
  S[i]=0;      
 S[v1]=1;D[v1]=0;  
 for(i=0;i<n-1;i++)   
 {
  min=inf;
  for(j=0;j<n;j++)
  {
   if((!S[j])&&(D[j]<min))
   {
    min=D[j];
    k=j;
   }
  }
  S[k]=1;    
  for(j=0;j<n;j++)
  {
   if((!S[j])&&(D[j]>D[k]+C[k][j]))
   {
    D[j]=D[k]+C[k][j];  
    P[j]=k+1;    
   }
  }
 } 
 for(i=0;i<n;i++)
 {
  printf("%d��%d����̾���Ϊ",v,i+1);
  printf("%d\n",D[i]);  
  pre=P[i];
  printf("·����%d",i+1);
  while(pre!=0) 
  {
   printf("<����%d",pre);
   pre=P[pre-1];
  }
  printf("\n");
 }
}
