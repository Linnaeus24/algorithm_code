
import java.util.Scanner;
public class Test {

    private static int N;
    private static int M;
    private static int max;
    private static int[] v;
    private static int[][] d;
    private static int[] b;
    private static String[] p;
    
    public static void Dijkstra() {
        v[1] = 1;
        b[1] = 0;
        
        for(int l = 2; l <= N; l++) {
            int Dtemp = max;
            int k = -1;
          
            for(int i = 2; i <= N; i++) {
                if(v[i] == 0 && d[1][i] < Dtemp) {
                    Dtemp = d[1][i];
                    k = i;
                }
            }
            v[k] = 1;
            b[k] = Dtemp;
      
            for(int i = 2; i <= N; i++) {
                if(v[i] == 0 && (d[1][k] + d[k][i]) < d[1][i]) {
                    d[1][i] = d[1][k] + d[k][i];
                    p[i] = p[k] + "-->" + i;
                }
            }
        }
        
        for(int i=1;i<=N;i++) {
             System.out.println("��"+1+"������"+i+"�����·��Ϊ��"+p[i]);   
        }
        System.out.println("=====================================");
        for(int i = 1; i <= N; i++) {
            System.out.println("��1������" + i + "�����̾���Ϊ��" + b[i]);
        }
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub

        Scanner input = new Scanner(System.in);
        System.out.print("������ڵ����N��·������M�� ");
        N = input.nextInt();
        M = input.nextInt();
        max = 10000;
        b = new int[N+1];
        d = new int [N+1][N+1];
        v = new int[N+1];
        p=new String[N+1];
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j) {
                    d[i][j] = 0;
                }else {
                    d[i][j] = max;
                }
            }
            b[i] = max;
            p[i] = new String("1-->" + i);
        }
        
        System.out.println("������" + M +"������x��y��z����ʾx�㵽y��ľ���Ϊz����");
        for(int i = 1; i <= M; i++) {
            int x = input.nextInt();
            int y = input.nextInt();
            int z = input.nextInt();
            d[x][y] = z;
        }
        input.close();
        
        Dijkstra();
    }

}