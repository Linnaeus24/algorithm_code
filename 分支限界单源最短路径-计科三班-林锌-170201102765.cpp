#include<iostream>
using namespace std;
const int size = 100;
const int inf = 5000;   //��������Ͻ�

const int n = 6;    //ͼ���������1
int prev[n];     //ͼ��ǰ������
int dist[] = {0,0,5000,5000,5000,5000};       //��̾�������
int c[n][n] = {{0,0,0,0,0,0},{0,0,2,3,5000,5000},    //ͼ���ڽӾ���
    {0,5000,0,1,2,5000},{0,5000,5000,0,9,2},
   {0,5000,5000,5000,0,2},{0,5000,5000,5000,5000,0}};


class MinHeapNode{

public :
 int i;    //������
 int length;   //��ǰ·��

};

//ѭ������
class CirQueue{
private:
  int front,rear;
  MinHeapNode data[size];
public:
   CirQueue(){
   front = rear = 0;
  }
  
  //Ԫ����Ӳ���
  void queryIn(MinHeapNode e){
   
   if((rear +1)%size != front){
    rear = (rear+1)%size; //��βָ����ѭ�������¼�1
    data[rear] = e;   //�ڶ�β����Ԫ��
   }
  }
  
  //Ԫ�س��Ӳ���
  MinHeapNode queryOut(){
   if(rear != front){
    front = (front+1)%size;  //������ѭ�������¼�1
    return data[front];
   }
  }
  //��ȡ��ͷԪ�أ���������
  MinHeapNode getQuery(){
   if(rear != front){
    return data[(front+1)%size];
   }
  }
  
  //�ж϶����Ƿ�Ϊ��
  bool empty(){
   return front == rear;
   
  }
  //�ж϶����Ƿ�Ϊ��
  bool full(){
   return (rear +1)%size == front;
  }
 };//CirQueue����

//ͼ�ı�ʾ 
class Graph{

public:
 /**
  * ��Դ���·����������ȶ���ʽ��֧�޽編
  */
 void shortestPath(int v){
  //��������
  CirQueue qq;
  
  //����ԴΪ��ʼ��չ���
  MinHeapNode e;
  e.i = v;
  e.length = 0;
  dist[v] = 0;
  qq.queryIn(e);
  //��������Ľ�ռ�
  while(true){
   for(int j = 1;j<n;j++){
    if(j>=n){
     break;
    }
    MinHeapNode m = qq.getQuery();
    if((c[m.i][j]<inf)&&(m.length + c[m.i][j] < dist[j])){
     
     //����i������j�ɴ���������Լ��
     dist[j] = m.length + c[m.i][j];
     prev[j] = m.i;
    //����������ȶ���
    MinHeapNode mi;
    mi.i = j;
    mi.length  = dist[j];
    if(qq.full()){
     break;
    }
    qq.queryIn(mi);   //Ԫ�����
    }
   }//forѭ������
   if(qq.empty()){
     break;
    }
   qq.queryOut();    //���ý��ĺ��ӽ��ȫ����Ӻ�ɾ���ý��
  }//whileѭ������
 }//��������
};//�����

int main(){

  Graph g;
  g.shortestPath(1);
  cout<<"���·����Ϊ "<<dist[n-1]<<endl;

  cout<<"�м�·��Ϊ�� ";
  for(int i =3;i<n;i++){
   cout<<prev[i]<<" ";
  }
 return 0;
}
