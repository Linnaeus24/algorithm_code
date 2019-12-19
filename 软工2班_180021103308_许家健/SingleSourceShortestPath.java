/*
 * a[][]���±��1 ��ʼ;0ֻ����������λ�ã��������ô���-1��ʾ���㲻ͨ
 * v ����		a ͼ�ö�ά�����ʾ
 * dist �Ӷ��㵽ÿ����ľ����������ʾ	prev ǰ���������
 */
package greedyAlgorithm;

import java.util.Scanner;

public class SingleSourceShortestPath {
	
	public static void main(String[] args) {

		System.out.println("������ͼ����ĸ�����");
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		int n = Integer.parseInt(line);
		System.out.println("������ͼ��·�����ȣ��ö�ά�����ʾ�ڵ��ľ��룬-1�������㲻ͨ��");
		float[][] a = new float[n + 1][n + 1]; // �±��1��ʼ�����¶���
		float[] dist = new float[n + 1];
		int[] prev = new int[n + 1];
		for (int i = 0; i < n; i++) {
			line = sc.nextLine();
			String[] ds = line.split(",");
			for (int j = 0; j < ds.length; j++) {
				a[i + 1][j + 1] = Float.parseFloat(ds[j]);
			}
		}
		int v = 1; // �����1��ʼ
		dijkstra(v, a, dist, prev);
		sc.close();

	}
	
	public static void dijkstra(int v, float[][] a, float[] dist, int[] prev) {

		int n = dist.length - 1;
		if (v < 1 || v > n)// �Ϸ��Լ��
			return; 
		boolean[] s = new boolean[n + 1]; // �������򲻷���ı�־

		// ��ʼ��
		for (int i = 1; i <= n; i++) {
			dist[i] = a[v][i];
			s[i] = false;
			if(dist[i]==-1)
				prev[i] = 0;
			else
				prev[i] = v;
		}
		dist[v] = 0; // �������
		s[v] = true;
		for (int i = 1; i < n; i++) { // ��ɨ��n-1��
			float temp = Float.MAX_VALUE;
			int u = v; // u�����һ��������ĵ�
			for (int j = 1; j <= n; j++) { // ѭ���ҵ���һ��������̵ĵ�
				if (!s[j] && dist[j] < temp && dist[j] != -1) {
					u = j;
					temp = dist[j];
				}
			}
			s[u] = true;
			for (int m = 1; m <= n; m++) { // ѭ������ÿ�������̾���
				if (!s[m] && a[u][m] != -1) {
					float newdist = dist[u] + a[u][m];
					if (newdist < dist[m] || dist[m] == -1) {
						dist[m] = newdist;
						prev[m] = u;
					}
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			System.out.println(i + "�ڵ����̾����ǣ�" + dist[i] + "��ǰ�����ǣ�" + prev[i]);
		}
	}

}
