#include<stdio.h>
#include<math.h>
#define N 4
/*�жϵ�k���ʺ�Ŀǰ����λ���Ƿ���ǰ��Ļʺ��ͻ*/
int isplace(int pos[],int k){
	int i;
	for(i=1;i<k;i++){
		if(pos[i] == pos[k] || fabs(i-k)==fabs(pos[i]-pos[k])){
			return 0;
		}
	}
	return 1;
}
int main(){
	int i,j,count=1;
	int pos[N+1];//��ʼ��λ��
	for(i=1;i<=N;i++){
		pos[i]=0;
	}
	j = 1;
	while(j>=1){
		pos[j]=pos[j]+1;
		/*���԰ڷŵ�i���ʺ�*/
		while(pos[j]<=N && isplace(pos, j) == 0){
			pos[j] = pos[j]+1;
		}
		/*�õ�һ���ڷŷ���*/
		if(pos[j] <= N && j == N){
			printf("����%d:",count++);
			for(i=1;i<=N;i++) {
				printf("%d",pos[i]);
			}
			printf("\n");
		}
		/*������һ���ʺ�*/
		if(pos[j]<=N&& j < N){
			j=j+1;
		}else{//���ؿ�����һ���ʺ�
			pos[j]=0;
			j=j-1;
		}
	}
	return 1;
}

