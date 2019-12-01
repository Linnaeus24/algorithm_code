#include <iostream>

using namespace std;

class BianrySearch
{
public:
	BianrySearch(double* a, int left, int right, double findNum);
	int search();
	friend void binarySearch(double* a, int l, int r, double x);

private:
	double* a;
	int left, right;
	double x;
};

BianrySearch::BianrySearch(double* a, int left, int right, double x){
	this->left = left;
	this->right = right;
	this->x = x;
	this->a = a;
}

int BianrySearch::search() {
	while (left <= right) {
		int middle = (left + right) / 2;
		if (a[middle] == x) {
			return middle;
		}
		if (x > a[middle]) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return -1;
}

extern void binarySearch(double* a, int l, int r, double x) {
	BianrySearch b(a, l, r, x);
	int re = b.search();
	if (re == -1) {
		cout << "δ�ҵ�Ԫ��λ�ã�" << endl;
	}
	else {
		cout << "Ԫ�ص�λ��Ϊ��" << re << endl;
	}
}