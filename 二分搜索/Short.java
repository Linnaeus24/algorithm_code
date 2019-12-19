package com.zhbit;
import java.util.PriorityQueue;
class Node implements Comparable<Node>{
	int id;
	int length;//��ǰ����µ���ö���ĳ���
	public int compareTo(Node d){
		if(this.length < d.length)
			return -1;
		else if(this.length == d.length)
			return 0;
		return 1;
	}
}
public class Short {
	public static int INFINITE = Integer.MAX_VALUE;
	int n=5;
	int[] prev = new int[n];//���ڴ洢�ڵ��ǵ�ǰ���ڵ㡣
	int[] dist = new int[n];//���ڴ洢Դ�ڵ㵽�ڵ��ǵ���̾��롣
	//�Խڵ�֮��ľ�����Ϣ���г�ʼ����ȫ���洢�ڶ�ά�����С�
	int[][] c = {{0,100,30,INFINITE,10},{INFINITE,0,INFINITE,INFINITE,INFINITE},
			{INFINITE,60,0,60,INFINITE},{INFINITE,10,INFINITE,0,INFINITE},
			{INFINITE,INFINITE,INFINITE,50,0}};
	public void shorttestPath(int t){
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		for(int i=0;i<dist.length;i++)
			dist[i] = INFINITE;
		for(int i=0;i<prev.length;i++)
			prev[i] = -1;
		//�Ը�����Դ�ڵ���г�ʼ����
		Node source = new Node();
		source.id = t;
		source.length = 0;
		dist[t] = 0;
		pq.add(source);
		while(!pq.isEmpty()){
			Node fatherNode = pq.poll();
			//ȡ�����иýڵ��ܹ�������ҵ����ܳ��Ȳ������ѷ��ֵ����ų��ȵĽڵ�
			for(int j=0;j<n;j++){
				if(c[fatherNode.id][j]<INFINITE 
						&& fatherNode.length+c[fatherNode.id][j]<dist[j]){
					//���¸ú��ӽڵ�����ų��Ⱥ�ǰ���ڵ㡣Ȼ���ٽ���������ȶ����С�
					dist[j] = fatherNode.length+c[fatherNode.id][j];
					prev[j] = fatherNode.id;
					Node newNode = new Node();
					newNode.id = j;
					newNode.length = dist[j];
					pq.add(newNode);
				}
			}
		}
		
		System.out.println(t+"�Žڵ㵽�����ڵ�����·�����Ⱥ�·���ֱ�Ϊ��");
		for(int i=0;i<n;i++){
			System.out.println("��"+i+"�Žڵ����̳���Ϊ:"+((dist[i]==INFINITE)?"���ɴ�":""+dist[i]));
			if(dist[i]!=INFINITE && i!=t){
				System.out.print("��·��Ϊ:  "+i+"----");
				int temp = i;
				while(prev[temp]!=t){
					System.out.print(prev[temp]+"----");
					temp = prev[temp];
				}
				System.out.println(prev[temp]);
			}
		}
		
	}
	public static void main(String[] args){
		Short sp = new Short();
		sp.shorttestPath(4);
	}
 
}
