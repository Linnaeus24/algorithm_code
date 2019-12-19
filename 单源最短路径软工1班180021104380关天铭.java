import java.util.Scanner;

public class SSSP
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        
        System.out.print("������ͼ�Ķ���ͱߵĸ���(��ʽ��������� �߸���)��");
        int n = input.nextInt(); //����ĸ���
        int m = input.nextInt(); //�ߵĸ���
        
        System.out.println();
        
        int[][] a = new int[n + 1][n + 1];
        //��ʼ���ڽӾ���
        for(int i = 0; i < a.length; i++)
        {
            for(int j = 0; j < a.length; j++)
            {
                a[i][j] = -1; //��ʼ��û�б�
            }
        }
        
        System.out.println("������ͼ��·������(��ʽ����� �յ� ����)��");
        //�ܹ�m����
        for(int i = 0; i < m; i++)
        {
            //��㣬��Χ1��n
            int s = input.nextInt();
            //�յ㣬��Χ1��n
            int e = input.nextInt();
            //����
            int l = input.nextInt();
            
            if(s >= 1 && s <= n && e >= 1 && e <= n)
            {
                //������Ȩͼ
                a[s][e] = l;
                a[e][s] = l;
            }
        }
        
        System.out.println();
        
        //��������
        int[] dist = new int[n+1];
        //ǰ���ڵ�����
        int[] prev = new int[n+1];
        
        int v =1 ;//���㣬��1��ʼ
        dijkstra(v, a, dist, prev);
    }
    
    //��Դ���·���㷨(�Ͻ�˹�����㷨)
    public static void dijkstra(int v, int[][] a, int[] dist, int[] prev)
    {
        int n = dist.length;
        /**
         * �����1��ʼ����n������һ��n�����
         */
        if(v > 0 && v <= n)
        {
            //�����Ƿ����ı�־
            boolean[] s = new boolean[n];
            
            //��ʼ��
            for(int i = 1; i < n; i++)
            {
                //��ʼ��Ϊ v �� i �ľ���
                dist[i] = a[v][i];
                //��ʼ������δ����
                s[i] = false;
                //v��i��·��i��ǰ���ڵ��ÿ�
                if(dist[i] == -1)
                {
                    prev[i] = 0;
                }
                else
                {
                    prev[i] = v;
                }
            }
            
            //v��v�ľ�����0
            dist[v] = 0;
            //�������
            s[v] = true;
            
            //��ɨ��n-2�Σ�v��v�Լ�����ɨ
            for(int i = 1; i < n - 1; i++)
            {
                int temp = Integer.MAX_VALUE;
                //uΪ��һ��������Ľڵ�
                int u = v;
                
                //���forѭ��Ϊ�ڶ������۲���Ϊv�Ĺ۲���
                //�������ж����ҵ���һ��������̵ĵ�
                for(int j = 1; j < n; j++)
                {
                    //jδ���룬��v��j��·����v����ǰ�ڵ�·����С
                    if(!s[j] && dist[j] != -1 && dist[j] < temp)
                    {
                        u = j;
                        //tempʼ��Ϊ��С��·������
                        temp = dist[j];
                    }
                }
                
                //���õ�����һ�ڵ����
                s[u] = true;
                
                //���forѭ��Ϊ����������u���¹۲���
                for(int k = 1; k < n; k++)
                {
                    if(!s[k] && a[u][k] != -1)
                    {
                        int newdist=dist[u] + a[u][k];
                        if(newdist < dist[k] || dist[k] == -1)
                        {
                            dist[k] = newdist;
                            prev[k] = u;
                        }
                    }
                }
            }
        }
        
        for(int i = 2; i < n; i++)
        {
            System.out.println(i + "�ڵ����̾����ǣ�"
                + dist[i] + "��ǰ�����ǣ�" + prev[i]);
        }

    }
}