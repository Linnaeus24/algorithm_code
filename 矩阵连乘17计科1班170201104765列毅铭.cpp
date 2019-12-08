#include<iostream>

using namespace std;

void matrixMultply(int **a,int **b,int **c,int ra,int ca,int rb,int cb){
	if(ca!=rb){
		cout<<"���󲻿ɳ�"; 
		return;
	}
	for(int i=0;i<ra;i++){
		for(int j=0;j<cb;j++){
			int sum=a[i][0]*b[0][j];
			for(int k=1;k<ca;k++){
				sum+=a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}
	}
} 

void MatrixChain(int *p,int n,int **m,int **s){
	for(int i=1;i<=n;i++){
		m[i][i]=0;
	}
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
	
}

void Traceback(int i,int j,int **s){
	if(i==j){
		return;
	}
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A "<<i<<", "<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<<", "<<j<<endl; 
}

int main(){
	int n;
	cout<<"����������";cin>>n;
	int **m=new int*[n+1];
	int *p=new int[n+1];
	int **s=new int*[n+1];
	
	for(int i=0;i<=n;i++){
		m[i]=new int[n+1];
		s[i]=new int[n+1];
	}
	
	
	for(int i=0;i<=n;i++){
		if(i!=n){
			cout<<"�����"<<i+1<<"������ĳ���";cin>>p[i];
		}	
		else{
			cout<<"�����"<<i<<"������Ŀ�";cin>>p[i];
		}	
	}
	
	cout<<"�����������"<<endl;
	for(int i=0;i<n;i++){
		cout<<"��"<<i+1<<"��:"<<p[i]<<"*"<<p[i+1]<<endl;
	}
	
	MatrixChain(p,n,m,s);
	cout<<"��С������"<<m[1][n]<<endl;
	Traceback(1,n,s);
	
	return 0;
}
