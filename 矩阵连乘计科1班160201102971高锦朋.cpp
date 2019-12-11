#define _CRT_SECURE_NO_WARNINGS

#include<math.h>
#include <stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

//��������
void matixMultiply(int **a,int **b, int **c,int ra,int ca, int rb, int cb) {
	if (ca != rb) {
		printf("���󲻿�����\n");
		return;
	}
		
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < cb; j++) {
			int sum = a[i][0] * b[0][j];
			for (int k = 1; k < ca; k++) {
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	}
}

//չʾ����
void displayAll(int **array,int row,int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (j == 0)
				cout << " |\t";
			cout << array[i][j] << "\t";
			if (j == column - 1)
				cout << "|" << endl;
		}
	}
	cout << endl;
}

//��̬�����ά����
int** getArray(int row, int column) {
	int** array = (int **)malloc(row * sizeof(int *));
	for (int i = 0; i < row; i++)
	{
		array[i] = (int *)malloc(column * sizeof(int));
	}
	return array;
}


int main() {


	//int int a[3][4], b[4][5], c[3][5]
	int ra = 3, ca = 4, rb = 4, cb = 5,rc=3,cc=5;
	int **a = getArray(ra,ca);
	int **b = getArray(rb, cb);
	int **c = getArray(rc, cc);

	//�򵥸�ֵ 	int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int temp = 1;
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < ca; j++) {
			a[i][j] = temp;
			temp++;
		}
	}
	//�򵥸�ֵ int b[4][5] = { {11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30} };
	temp = 11;
	for (int i = 0; i < rb; i++) {
		for (int j = 0; j < cb; j++) {
			b[i][j] = temp;
			temp++;
		}
	}

	cout << "��ά����a��" << endl;
	displayAll(a,ra,ca);
	cout << "��ά����b��" << endl;
	displayAll(b, rb, cb);
	matixMultiply(a, b, c, 3, 4, 4, 5);
	cout << "����a������b���˺�õ�������c:" << endl;
	displayAll(c, rc, cc);

	system("pause");
	return 0;
}