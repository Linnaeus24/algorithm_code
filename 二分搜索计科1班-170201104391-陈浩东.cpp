#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a[10]={-1,0,3,8,9,10,11,12,13,15};
	int x;
	int low=0,high=9;
	int mid;
	cout<<"������Ҫ���ҵ�����"<<endl;
	cin>>x;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)break;
		if(a[mid]<x)low=mid+1;
		else high=mid-1;
	}
	if(low<=high)cout<<"�ɹ��ҵ�"<<endl;
	else cout<<"��Ҫ�ҵ����ֲ�����"<<endl;
return 0;
}
