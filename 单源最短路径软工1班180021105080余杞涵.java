import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
/** ��Դ���·������ */
public class MinimumPath {
/** �ڵ���� */
private int mapSize = 5;
private int totalNum = 0;
/** ��֯�ڵ���ϵ�Ķ�ά���� */
private int[][] map = null;
/** ��㼯�ϣ���¼�Ѿ����߹��Ķ��� */
private List<Integer> redPoint = new ArrayList<Integer>();
/** ���㼯�ϣ���¼δ�߹��Ķ��� */
private List<Integer> bluePoint = new LinkedList<Integer>();
public MinimumPath() {
// ��ʼ������ת���ɵĶ�ά����
initiMap();
setMap();

// ��ʼ��δ�߹��Ľڵ�
for (int i = 0; i < mapSize; ++i) {
bluePoint.add(i);
}

// ��ӡ����ת���ɵĶ�ά���飬���������Ѱ�����·��
printMap();
}
/**
* ̰���㷨�ݹ�������·��
* @param startPoint����ʼ���ҽڵ㣬�±���㿪ʼ
*/
public void minStep(int startPoint) {
// ������벻�Ϸ�������˳�
if (startPoint >= mapSize || startPoint < 0) {
totalNum = Integer.MAX_VALUE;
return;
}
// ��startPoint��Ϊ�߹��Ľڵ�ȥ�������뵽�߹��Ľڵ�
redPoint.add(new Integer(startPoint));
bluePoint.remove(new Integer(startPoint));
// ���������˳�
if (startPoint == mapSize - 1) {
return;
}
// ��δ�߹��Ľڵ���ѡ����̵�·��
int temp = Integer.MAX_VALUE;
int step = 0;
Iterator<Integer> iter = bluePoint.iterator();
for (int i = 0; i < bluePoint.size() && iter.hasNext(); ++i) {
int j = iter.next();
if (temp > map[startPoint][j]) {
temp = map[startPoint][j];
step = j;
}
}
// �����·����������������ݹ����
totalNum += temp;
minStep(step);
}
/**
* ��ӡmap
*/
private void printMap() {
System.out.println("�����������ϵĽڵ�Ϊ���� $��������Զ");
for (int j = 0; j < mapSize; ++j) {
for (int i = 0; i < mapSize; ++i) {
if (map[j][i] == Integer.MAX_VALUE) {
// $��ʾ���ܵ���
System.out.print("$\t");
} else {
System.out.print(map[j][i] + "\t");
}
}
System.out.println();
}
}
/**
* Ϊmap����ֵ
*/
private void setMap() {
// ������ڵ�������ڵ�ľ��룬δ��ֵ��������Զ
map[0][0] = 0;
map[0][1] = 10;
map[0][3] = 30;
map[0][4] = 100;
// ��һ���ڵ㵽�����ڵ�ľ��룬δ��ֵ��������Զ
map[1][1] = 0;
map[1][2] = 50;
// �ڶ����ڵ㵽�����ڵ�ľ��룬δ��ֵ��������Զ
map[2][2] = 0;
map[2][4] = 10;
// �������ڵ㵽�����ڵ�ľ��룬δ��ֵ��������Զ
map[3][2] = 20;
map[3][3] = 0;
map[3][4] = 60;
// ���ĸ��ڵ㵽�����ڵ�ľ��룬δ��ֵ��������Զ
map[4][4] = 0;
}
/**
* ��ʼ��map
*/
private void initiMap() {
// ʵ��������ʼ��map, Integer.MAX_VALUE��ʾ���ܵ���
map = new int[mapSize][mapSize];
for (int j = 0; j < mapSize; ++j) {
for (int i = 0; i < mapSize; ++i) {
map[j][i] = Integer.MAX_VALUE;
}
}
}
public List<Integer> getRedPoint() {
return redPoint;
}
public int getTotalNum() {
return totalNum;
}
public static void main(String[] args) {
MinimumPath path = new MinimumPath();
System.out.println("�����뿪ʼ�Ľڵ㣨�±���㿪ʼ����");

// ��ȡ����ڵ㣬 �ȼ��㵽��ĩ�ڵ�ĵ�Դ���·��
Scanner sc = new Scanner(System.in);
int v = sc.nextInt();
path.minStep(v);

// ����·��
List<Integer> red = path.getRedPoint();
for (Integer i : red) {
System.out.print(i + " -> " + "\t");
}

// �����̾���
int total = path.getTotalNum();
if(total != Integer.MAX_VALUE){
System.out.println("���·����" + total);
} else {
System.out.println("�Բ��𣬲��ܵ��");
}
}
}