import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;
	 // ��Դ���·������--��֧�޽編	
	//��2��-180021104310-�½���	 
		public class Demo3 {
			public static class Heapnode implements Comparable{
				int id;//������
				float length;//��ǰ·��
				public Heapnode(int ii,float ll){
					id=ii;
					length=ll;
				}
				public int compareTo(Object x) {
					float xl=((Heapnode)x).length;
					if(length<xl) 
						return -1;
					if(length==xl) 
						return 0;
					return 1;
				}

				
			}
			public static void shortest(float[][] a,int v,float[] dist,int[] p){
				//dist[j]�����Դ������j�ľ���;p[j]��¼��Դ������j��·���ϵ�ǰ������
				int n=p.length-1;
				LinkedList<Heapnode> nodes=new LinkedList<Heapnode>();//��LinkedList�洢��С��
				Heapnode enode=new Heapnode(v,0);
				for(int j=1;j<=n;j++){
					dist[j]=Float.MAX_VALUE;
				}
				while(true){//���������ռ�			
					for(int j=1;j<=n;j++){
						if(a[enode.id][j]!=-1&&enode.length+a[enode.id][j]<dist[j]){
							//����i��j�ɴͬʱ����С��dist[j]
							dist[j]=enode.length+a[enode.id][j];
							p[j]=enode.id;
							Heapnode e=new Heapnode(j,dist[j]);
							nodes.add(e);
							Collections.sort(nodes);
						}
					}
					//ȡ��һ����չ���
					if(nodes.isEmpty())
						break;
					else{				
						enode=(Heapnode) nodes.poll();
					}
					
				}
				for(int i=2;i<=n;i++){
					System.out.println(i+"�ڵ����̾����ǣ�"+dist[i]+"��ǰ�����ǣ�"+p[i]);
				}
			}
			public static void main(String[] args) {
				System.out.println("������ͼ����ĸ�����");
				Scanner sc = new Scanner(System.in);
				String line = sc.nextLine();
				int n = Integer.parseInt(line);
				System.out.println("������ͼ��·�����ȣ�");
				float[][] a = new float[n+1][n+1];//�±��1��ʼ�����¶���
				float[] dist = new float[n+1]; 
				int[] prev = new int[n+1];
				for(int i=0;i<n;i++){
					line =  sc.nextLine();			
					String[] ds = line.split(",");
					for(int j = 0;j<ds.length;j++){
						a[i+1][j+1]=Float.parseFloat(ds[j]);
					}
				}				
				int v =1;//�����1��ʼ
				shortest(a,v,dist,prev);
			}
		}