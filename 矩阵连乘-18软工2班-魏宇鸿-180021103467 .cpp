#include<stdio.h>
#define N 100 //����������˾���ĸ���
/* **m�����洢�������С���˴���   **s�����洢��С���˴����Ͽ���λ��k
 */ 
void MatrixChain(int p[],int m[N+1][N+1],int s[N+1][N+1]){
	int n = N; 
    for(int i=1;i<=n;i++)//��Խ��ߣ��Խ����ϵ�Ԫ��ȫ������ 
       m[i][i]=0;
    for(int r=2;r<=n;r++){//r��ʾб�Խ��ߵĲ�������2ȡ��n 
    	for(int i=1;i<=n-r+1;i++){//��ʾ�����r��б�Խ����ϵ�i��Ԫ�ص�ֵ 
    		int j=i+r-1;//j��ʾ��б�Խ��߲���Ϊr�����±�Ϊiʱ�����±� 
    		m[i][j]=m[i+1][j]=p[i-1]*p[i]*p[j];//���㵱�Ͽ�λ��Ϊiʱ��Ӧ�����˴��� 
    		s[i][j]=i;//�Ͽ�λ��Ϊi 
    		for(int k=i+1;k<j;k++){
    			int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
    			if(t<m[i][j]){
    				m[i][j]=t;
    				s[i][j]=k;//����Ӧ�ĶϿ�λ��k����s[i][j] 
				}
			}			
		}
	}		
}

void traceback (int i, int j, int s[][N+1]){
	if(i==j){
		printf("A%d",i);
	}else{
		printf("(");
		traceback(i,s[i][j],s);
		traceback(s[i][j]+1,j,s);
		printf(")");
	}
}

int main(){
	int n;
	int q[2*N];
	int p[N+1],flag=1;
	int m[N+1][N+1];
	int s[N+1][N+1];
	printf("���������ĸ�����С��100��:");
	scanf("%d",&n);
	for(int i=0;i<=2*n-1;i++){
		if(i%2==0){
			printf("********************\n");
			printf("������A%d����:",(i/2)+1);
		}
		else{
			printf("�����������:");	
		}
		scanf("%d",&q[i]);
	}
	for(int i=1;i<=2*n-2;i++){
		if(i%2!=0&&q[i]!=q[i+1]){
			flag=0;
			break;
		}
	}
	for(int j=1;j<=n;j++){
		p[j]=q[2*n];
	}
	if(flag!=0){
		p[0]=q[0];
		p[n]=q[2*n-1];
		MatrixChain(p,m,s);
		printf("ʽ�����£�\n");
		traceback(1,n,s);
		printf("\n");
		printf("��С���˴���Ϊ��%d\n",m[1][n]); 
	}
	else{
		printf("��%d�����������ˣ�\n",n);
	}
}
