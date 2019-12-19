#include <iostream>
using namespace std;

#define MaxInt 32767                    					//��ʾ����ֵ������
#define MVNum 100                       					//��󶥵���
typedef char VerTexType;              						//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                  						//����ߵ�Ȩֵ����Ϊ����

int *D=new int[MVNum];	                    				//���ڼ�¼���·�ĳ���
bool *S=new bool[MVNum];          							//��Ƕ����Ƿ����S����
int *Path=new int[MVNum];									//���ڼ�¼���·�����ǰ��


typedef struct{ 
	VerTexType vexs[MVNum];            						//����� 
	ArcType arcs[MVNum][MVNum];      						//�ڽӾ��� 
	int vexnum,arcnum;                						//ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;


int LocateVex(AMGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
   return -1;
}//LocateVex


void CreateUDN(AMGraph &G){ 
    //�����ڽӾ����ʾ��������������G   
	int i , j , k;
	cin >> G.vexnum >> G.arcnum;							//�����ܶ��������ܱ���
    for(i = 0; i < G.vexnum; ++i)
	{   
		cin >> G.vexs[i];                        			//������������Ϣ 
	}
    for(i = 0; i < G.vexnum; ++i)                			//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = MaxInt; 
	for(k = 0; k < G.arcnum;++k){							//�����ڽӾ��� 
		VerTexType v1 , v2;
		ArcType w;
		cin >> v1 >> v2 >> w;								//����һ���������Ķ��㼰Ȩֵ
	i = LocateVex(G, v1);  j = LocateVex(G, v2);
		G.arcs[i][j] = w;									//��<v1, v2>��Ȩֵ��Ϊw 
	  //	G.arcs[j][i] = G.arcs[i][j]; //***���ĳ�������****��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵҲΪw 
	}//for
}//CreateUDN



void ShortestPath_DIJ(AMGraph G, int v0){ 
    //��Dijkstra�㷨��������G��v0���㵽���ඥ������·�� 
    int v , i , w , min;
	int n = G.vexnum;                    					//nΪG�ж���ĸ��� 

	for(v = 0; v < n; ++v){             					//n���������γ�ʼ�� 
		S[v] = false;                  						//S��ʼΪ�ռ� 
		D[v] = G.arcs[v0][v];           					//��v0�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ 
		if(D[v] < MaxInt)  Path [v] = v0;  					//���v0��v֮���л�����v��ǰ����Ϊv0 
		else Path [v] = -1;               					//���v0��v֮���޻�����v��ǰ����Ϊ-1 
	}//for 

	S[v0]=true;                    							//��v0����S 
	D[v0]=0;                      							//Դ�㵽Դ��ľ���Ϊ0 

	/*�D��ʼ����������ʼ��ѭ����ÿ�����v0��ĳ������v�����·������v�ӵ�S���D*/ 
	for(i = 1;i < n; ++i){									//������n-1�����㣬���ν��м��� 
        min= MaxInt; 
        for(w = 0; w < n; ++w) 
			if(!S[w] && D[w] < min){						//ѡ��һ����ǰ�����·�����յ�Ϊv 
				v = w; 
				min = D[w];
			}//if         	
		S[v]=true;                   						//��v����S 
		for(w = 0;w < n; ++w)           					//���´�v0����������V?S�����ж�������·������ 
			if(!S[w] && (D[v] + G.arcs[v][w] < D[w])){ 
				D[w] = D[v] + G.arcs[v][w];   				//����D[w] 
				Path [w] = v;              					//����w��ǰ��Ϊv 
			}//if 
    }//for  
}

void DisplayPath(AMGraph G , int begin ,int temp ){
	//��ʾ���·
	if(Path[temp] != -1){
		DisplayPath(G , begin ,Path[temp]);
		cout << G.vexs[Path[temp]] << "-->";
	}
}

main()
{
	int i , j ,num_qidian , num_zhongdian;
	VerTexType qidian,zhongdian;
	AMGraph G;
	CreateUDN(G);
	cin >> qidian >> zhongdian;
	num_qidian = LocateVex(G , qidian);
	num_zhongdian = LocateVex(G , zhongdian);
	ShortestPath_DIJ(G , num_qidian);
	ShortestPath_DIJ(G,0);
	if(D[num_zhongdian]<MaxInt)  
	{		
		cout << endl <<"���·��Ϊ��";
		DisplayPath(G , num_qidian , num_zhongdian);
		cout << G.vexs[num_zhongdian]<<endl;
		cout <<"���·������Ϊ��" <<D[num_zhongdian]<<endl; 
	}
} 

