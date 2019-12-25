#include <iostream>
using namespace std;
#define MAX 9999

class Graph
{
public:
    void ShorestPaths(int);
    void ShowDist();
    Graph();
private:
    int n;					//ͼG�Ķ����� 
    int *prev;				//ǰ���������� 
    int **c;				//ͼG���ڽӾ���
    int *dist;				//��̾������� 
};


class MinHeapNode //��С�ѽ�� 
{
    friend Graph;
public:
    int getI() {return i;}
    void setI(int ii)
    {
        i = ii;
    }
    int getLength(){return length;}
    void setLength(int len)
    {
        length = len;
    }
private:
    int i;					//������
    int length;				//��ǰ·��
};

class MinHeap
{
    friend Graph;
public:
    MinHeap();
    MinHeap(int);
    void DeleteMin(MinHeapNode &);
    void Insert(MinHeapNode);
    bool OutOfBounds();
private:
    int length;
    MinHeapNode *node;
};

Graph::Graph()
{
    int a = 0;
    int b = 0;
    cout<<"������ͼ�Ľڵ������";
    cin>>n;
    cout<<"������ͼ���ڽӾ���(���������9999����)" << endl;
    c = new int*[n+1];
    dist = new int[n+1];
    prev = new int[n+1];
    for (a = 0; a <= n; a++)
    {
        c[a] = new int[n+1];
        if (a == 0)
        {
            for (b = 0; b <= n; b++)
            {
                c[a][b] = 0;
            }
        }
        else
        {
            for (b = 0; b <= n; b++)
            {
                if (b == 0)
                {
                    c[a][b] = 0;
                }
                else
                {
                    cin >> c[a][b];
                }
            }
        }
    }

    for (a = 0; a <= n; a++)
    {
        dist[a] = MAX;
        prev[a] = 0;
    }
}

void Graph::ShowDist()
{
    cout << "��Դ�㵽�ýڵ�����·��:" << endl;
    int i = 0;
    int temp = 0;
    for (i = 1; i <= n; i++)
    {
        cout << "dist[" << i << "] = " << dist[i] << endl;
    }
    cout << "��Դ�㵽�յ�����·������Ϊ:" << dist[n] << endl;
    cout << "��·��Ϊ��";
    temp = n;
    while(temp != 0)
    {
        if (prev[temp] == 0)
        {
            cout << temp;
        }
        else
        {
            cout << temp << "<-";
        }
        temp = prev[temp];
    }
    cout << endl;
}

void Graph::ShorestPaths(int v)
{
    MinHeap H(n);        
    MinHeapNode E;    
    E.i = v;
    E.length = 0;
    dist[v] = 0;
    while (true)
    {
        int j;
        for (j = 1; j <= n; j++)
        {
            if ((c[E.i][j] != MAX) && (c[E.i][j] != 0))
            {
                if (E.length + c[E.i][j] < dist[j])
                {
                    dist[j] = E.length + c[E.i][j];
                    prev[j] = E.i;
                    if (j != n)
                    {
                        MinHeapNode N;
                        N.i = j;
                        N.length = dist[j];
                        H.Insert(N);
                    }
                }
                else
                {
                    H.DeleteMin(E);
                }

            }
        }
        if (H.OutOfBounds())
        {
            break;
        }
        H.DeleteMin(E);      
    }
}

MinHeap::MinHeap()
{
    length = 10;
    node = new MinHeapNode[length+1];
    for (int i = 0; i <= length; i++)
    {
        node[i].setI(0);
        node[i].setLength(0);
    }
}

MinHeap::MinHeap(int n)
{
    length = n;
    node = new MinHeapNode[length+1];
    for (int i = 0; i <= length; i++)
    {
        node[i].setI(0);
        node[i].setLength(0);
    }
}

void MinHeap::DeleteMin(MinHeapNode &E)
{
    int i = 0;
    int j = 0;
    j = E.getI();		
    node[j].setI(0);			
    node[j].setLength(0);	
    int temp = MAX;
    for (i = 1; i <= length; i++)
    {
        if ((node[i].getLength() < temp) && (node[i].getLength() != 0))
        {
            E.setI(i);
            E.setLength(node[i].getLength());
            temp = node[i].getLength();				
        }
    }
}

void MinHeap::Insert(MinHeapNode N)
{
    node[N.getI()].setI(N.getI());
    node[N.getI()].setLength(N.getLength());
}

bool MinHeap::OutOfBounds()
{
    int i = 0;
    bool flag = true;
    for (i = 1; i <= length; i++)
    {
        if (node[i].getI() != 0)
        {
            flag = false;
        }
    }
    return flag;
}

int main()
{
    Graph graph;
    graph.ShorestPaths(1);
    graph.ShowDist();
    return 0;
}
