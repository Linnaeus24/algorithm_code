
public class Demo {
	
		static void max(int[] p){
			int n = p.length - 1;//�ӵ�0����ʼ
			int[][] a1 = new int[n][n];
			int[][] a2 = new int[n][n];
			for(int i = 0;i<n;i++)
				a1[i][i] = 0;
			//����Ϊ2������������Ϊn������
			for(int a3 = 2;a3<=n;a3++){
				for(int i = 0;i<=n-a3;i++){
						int j = i+a3-1;
						a1[i][j] = Integer.MAX_VALUE;
					//Ѱ����ѷָ��
					for(int k = i;k<j;k++){
						int temp = a1[i][k] +a1[k+1][j] + p[i]*p[k+1]*p[j+1];
							if(temp<a1[i][j])
								a1[i][j] = temp;
								a2[i][j] = k;
					}
				}
			}
			System.out.println(a1[0][n-1]);
		}
		public static void main(String[] args) {
			int[] p = {20,30,40,50,60};
			max(p);
		}
		
	}
	
