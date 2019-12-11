/*
 *��ҽ� 180021103308 ������̶���
 * ���ö�̬�滮����������˵�����
 */
package dynamicProgramming;

public class MatrixMultiplying {
	public static void MatrixChain(int[] p,int n, int[][] m, int[][] s) {
		   for (int i = 1; i <= n; i++) {
		     m[i][i] = 0;
		   }
		    for(int r = 2;r <= n; r++ ) {
		      for(int i = 1; i <= n-r+1; i++) {
		        int j = i+r-1;										//j��Ϊ��ʹ��ά�������������½���ֵ���б���
		        m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];				//�õ��ʼλ�õľ���˻���������λ�ÿ���Ϊ�������˴���
		        s[i][j] = i;										//�õ���ʼ����ĶϿ�λ��
		        for(int k = i+1; k < j; k++) {
		          int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];	//ͨ��i+1�𽥰ѶϿ�λ�����ƣ��ٴμ���������˴�������λ�ÿ���Ϊ�������˴���
		          if(t < m[i][j]) {									//�Ƚϵ�ǰֵ��ǰ��洢��ֵ���Ƿ�Ϊ�������˴���
		            m[i][j] = t;									//�������������˴���
		            s[i][j] = k;									//���������ŶϿ�λ��
		          }
		        }
		      }
		    }
		  }
		  public static void Traceback(int i, int j, int[][] s) {
		    if(i == j) return;
		    Traceback(i,s[i][j],s);
		    Traceback(s[i][j] + 1,j,s);
		    System.out.println("Multiply  A" + i + "," + s[i][j] + "and A" + (s[i][j] + 1) + "," + j);
		  }
		  public static void main(String[] args) {
			System.out.println("���н��Ϊ��");
		    MatrixMultiplying mc = new MatrixMultiplying();
		    int n = 7;
		    int p[] = { 30, 35, 15, 5, 10, 20, 25 };
		    int m[][] = new int[n][n];
		    int s[][] = new int[n][n];
		    int l = p.length-1;
		    mc.MatrixChain(p, l,m, s);
		    for (int i = 1; i < n; i++) {							//��ӡm[i][j]�ľ�����˴�������
		      for (int j = 1; j < n; j++) {
		        System.out.print(m[i][j] + "\t");
		      }
		      System.out.println();
		    }
		    System.out.println();
		    for (int i = 1; i < n; i++) {							//��ӡs[i][j]���Ŵ���ĶϿ�λ�þ���
		      for (int j = 1; j < n; j++) {
		        System.out.print(s[i][j]+" ");
		      }
		      System.out.println();
		    }
		    mc.Traceback( 1, 6, s);									//���նϿ�λ�þ��������������ż������
		  }
	
	
	
	}


