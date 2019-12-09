#include<iostream>
using namespace std;
 
/*�������һά����ĺ���*/
void print(int array[], int n)
{
     for (int i = 0; i < n; i++)
     {
         cout << array[i] << " ";
     }
     cout << endl;
 }
 
/*������������ĺ���:array,�������У�n�����г��ȣ�x��Ҫ���ҵ���*/
int binarySearch(int array[], int n, int x)
{
     //��ʼ�����ұ߽�
     int left = 0, right = n - 1;
     //�����ұ߽粻�غ�ʱ
     while (left <= right)
     {
         //��ʼ���߽���е�
         int middle = (left + right) / 2;
         //�ж�������Ԫ�غ͵�ǰ�е�Ԫ���Ƿ���ȣ��������򷵻��е�Ԫ�����ڵ�λ��
         if (x == array[middle])
         {
             return middle;
         }
         else if (x > array[middle])
         {
             //���������Ԫ�ش����е�Ԫ�أ���������Ԫ�����Ҳ��֣�����߽�������
             left = middle + 1;
         }
         else{
             //˵��������Ԫ��С���е�Ԫ�أ���������Ԫ���������֣����ұ߽�������
             right = middle - 1;
         }
     }
     //����Ҳ������򷵻�-1
     return -1;
 }

int main()
{
     //����������һά����
     int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
     //���ԭʼ����
     cout << "ԭʼ�����ǣ�" << endl;
     print(array, 10);
     //����Ҫ���ҵ���
     int number;
     //����Ҫ���ҵ���
     cout << "������Ҫ���ҵ�����";
     cin >> number;
     //���ö��������ĺ������в���
     int location = binarySearch(array, 10, number);
     if (location > 0)
     {
         //˵���ҵ���
         cout << number << "�ڸ������У��ǵ�" << (location + 1) << "����" << endl;
     }
     else
     {
         //˵��û�ҵ�
         cout << number << "���ڸ�������..." << endl;
 
     }
     return 0;
}
