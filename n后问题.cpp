#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;

class Queen {
	friend int nQueen(int);

	bool Place(int k) {
		for (int j = 1; j < k; ++j)
			if ((abs(k-j) == abs(x[j] - x[k])) || (x[j] == x[k]))
				return false;
		return true;
	}
	void Backtrack(int t) {
		if (t > n)
			sum++;
		else {
			for (int i = 1; i <= n; ++i) {
				x[t] = i;
				if (Place(t)) Backtrack(t+1);
			}
		}
	}
	int n, *x; // n�ʺ���� x��ǰ��
	long sum; // ��ǰ���ҵ��Ŀ��з�����
};
int nQueen(int n) {
	Queen X;
	X.n = n, X.sum = 0;
	int *p = new int[n+1];
	for (int i = 0; i <= n; ++i) p[i] = 0;
	X.x = p;
	X.Backtrack(1);
	delete[] p;
	return X.sum;
}

int main() {
	int n;
	cin >> n; // ����n��
	cout << nQueen(n); // �������
	return 0;
}