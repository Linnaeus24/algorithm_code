#include <iostream>
#include <cmath>
using namespace std;
//�ʺ�ĸ���,������Ŀ
int n,sum=0;
//��¼���÷���
int x[100];//������������int *x;
//�û��ݹ���ȡ����
void Queen1(void);
void TraceBack(int);
void PrintMethod(void);
//�����һ�ʺ���÷����Ƿ�����Ҫ��
int Place(int);

int main()
{


 cout << "����ʺ������" << endl;
 cin>>n;
 Queen1();
 return 0;
}

void Queen1(void)
{
TraceBack(0);
}
void TraceBack(int r)
{
 int i;
 if(r>=n){
 PrintMethod();//�����������ȷ�Ի�û�еõ���֤
 sum++;
}
 else{
 for(i=0;i<n;i++){
 x[r]=i;//����һ���жϵ�ǰ·�ǲ����е�֮�󣬽���ͬ���������·��
if(Place(r))//����̽��ǰ����·�ǿ��еģ��������һ��ѭ��
TraceBack(r+1);
} }
}
void PrintMethod(void)
{
 int i,j;
 cout<<"��"<<sum<<"������\n";
 for(i=0;i<n;i++){
for(j=0;j<n;j++){
 if(j==x[i])
cout<<"1";
 else
cout<<"0";
 }
 cout<<endl;
 }
}
int Place(int r)
{
 int i;
 for(i=0;i<r;i++)
 {
 if(x[r]==x[i] || abs(r-i)==abs(x[r]-x[i]))//�ڴ˴��жϻʺ��ߵ���һ��·�Ƿ���У�����������ԣ�return 0��
 return 0;
}
 return 1;
}

