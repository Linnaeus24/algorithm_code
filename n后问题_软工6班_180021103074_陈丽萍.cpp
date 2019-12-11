#include<iostream> 
#include<math.h> 
using namespace std;
class Queen{
	friend int nQueen(int);
	private:
		bool Place(int k);
		void Backtrack(int t);
		int n,*x;
		long sum;
};
bool Queen::Place(int k){//����������Ƿ��ͻ 
	for(int j=1;j<k;j++)
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
		//�����Щ�ʺ��Ƿ���ͬһ�л���ͬһ�� 
			return false;
		return true;
}
void Queen::Backtrack(int t){//��̽��i���ʺ�÷��� 
	if(t>n)//tΪ�к� 
		sum++;
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;
			if(Place(t))
				Backtrack(t+1);
				//��������ɻʺ�ķ��ã���ʼ���� 
		}
	}
}
int nQueen(int n){
	Queen X;//��ʼ�� 
	X.n=n;
	X.sum=0;
	int *p=new int[n+1];//���붯̬�ڴ棬����p[0] 
	for(int i=0;i<=n;i++)
		p[i]=0;
	X.x=p;
	X.Backtrack(1);// ��̽��1 �лʺ���� 
	delete[] p;//�ͷ��������� 
	return X.sum;//���غϷ������� 
}
int main(){
	int n;
	cout<<"�����������n�ʺ������n��"<<endl;
	cin>>n;
	int k=nQueen(n);
	cout<<"�����n�ʺ����⻥���������÷�������"<<endl;
	cout<<k<<endl;
	return 0;
}
