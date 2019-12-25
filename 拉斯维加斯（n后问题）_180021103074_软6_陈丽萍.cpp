#include<iostream>
#include"time.h"
using namespace std;
const unsigned long maxshort=65536L;
const unsigned long multiplier=1194211693L;
const unsigned long adder=12345L;
class RandomNumber{
	private:
		unsigned long randSeed;
	public:
		RandomNumber(unsigned long s=0);
		unsigned short Random(unsigned long n);
		double fRandom(void);
};
RandomNumber::RandomNumber(unsigned long s){
	if(s==0)randSeed=time(0);
	else randSeed=s;
}
unsigned short RandomNumber::Random(unsigned long n){
	randSeed=multiplier*randSeed+adder;
	return (unsigned short)((randSeed>>16)%n);
}
double RandomNumber::fRandom(void){
	return Random(maxshort)/double(maxshort);
}



#include"RandomNumber.h"
#include<iostream>
#include<math.h>
#define false 0
#define true 1
using namespace std; 
 class Queen{
 	friend void nQueen(int);
 	private:bool Place(int k);//���Իʺ�K���ڵ�x[k]�еĺϷ��� 
 	bool QueensLV(void);//�������n���ʺ���˹ά��˹�㷨 
 	int n,//�ʺ���� 
 		*x,y[1000];//������ 
 };
 bool Queen::Place(int k){//���Իʺ�K���ڵ�x[k]�еĺϷ��� 
 	for(int j=1;j<k;j++){
 		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
 			return false;
 	}
 	return true;
 } 
 bool Queen::QueensLV(void){//�������n���ʺ���˹ά��˹�㷨
 	RandomNumber rnd;//����������� 
 	int k=1;//��һ���ʺ���õı�� 
 	int count=3;
 	while((k<=n)&&(count>0)){//�����н���δ�����һ�� 
 		count=0;
 		for(int i=1;i<=n;i++){
 			x[k]=i;
 			if(Place(k))//��k���Ƿ�Ϸ� 
 				y[count++]=i;//����ÿһ���Ϸ���λ�� 
 		}
 		if(count>0)
 			x[k++]=y[rnd.Random(count)];//������� 
 	}
 	return (count>0);//count>0��ʾ���óɹ� 
 }
 void nQueen(int n){
 	Queen X;
 	X.n=n;
 	int *p=new int[n+1];
 	for(int i=0;i<=n;i++)
 		p[i]=0;	
 	X.x=p;//���������������n���ʺ����˹ά��˹�㷨��ֱ�����óɹ� 
 	while(X.QueensLV()){//���ɹ������е�ɢ��Ϊֹ
 		cout<<"���Ϊ"<<endl;
 		for(int i=1;i<=n;i++){
 			for(int j=1;j<=n;j++){
 				if(j==p[i])
 					cout<<"Q"<<"";
 				else
 					cout<<"*"<<"";
 			}
 			cout<<endl;
		}//����ҵ��Ϸ��ķ��� 
		break;
 	} 
	delete[] p; 
 } 
 int main(){
 	int n;
 	cout<<"������ʺ����"<<endl;
 	cin>>n;
 	nQueen(n);
 	system("pause");
 }
