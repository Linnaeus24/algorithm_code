#include<stdio.h>
#include<stdlib.h> 

class Queen{
	friend int nQueen(int);
private:
	bool Place(int k);
	void Backtrack(int t);
	int n;//�ʺ���� 
	int *x;//��ǰ�� 
	long sum;//��ǰ���ҵ��Ŀ��з����� 
}; 
bool Queen::Place(int k){
	for(int j=1;j<k;j++){
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	}
	return true;
} //����ͻ������k�еĻʺ����Ϸ����лʺ��Ƿ��ͻ 
void Queen::Backtrack(int t){
	if(t>n)
		sum++;
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;
			if(Place(t))
				Backtrack(t+1);
		}
	}
}
int nQueen(int n){
	Queen X;//��ʼ��x 
	X.n=n;
	X.sum=0;
	int *p=new int[n+1];//���붯̬�ڴ� 
	for(int i=0;i<=n;i++){
		p[i]=0;
	}
	X.x=p;
	X.Backtrack(1);
	delete[] p;
	return X.sum;
}

int main(){
	int m,n;
	printf("����ʺ������");
	scanf("%d",&n);
	m=nQueen(n);
	printf("��%d������",m);
	return 0;
}

