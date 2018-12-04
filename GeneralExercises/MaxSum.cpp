#include "CP.h"

class MaxSum {
private:
	int n, m;
	int mat[1001][4];
public:
	MaxSum() {}
	~MaxSum() {}
	int SetRows() {
		cin >> n;
		return n;
	}
	int SetColumns() {
		cin >> m;
		return m;
	}
	void SetMatrix() {
		for (int i = 0;i < n;++i) {
			for (int j = 0;j < m;++j)
				cin >> mat[i][j];
		}
	}
	void ComputeMaxSumOnMatrix() {
		for (int i = 0;i < n;++i) {
			for (int j = 0;j < m;++j) {
				if (i > 0)mat[i][j] += mat[i - 1][j];
				if (j > 0)mat[i][j] += mat[i][j - 1];
				if (i > 0 && j > 0)mat[i][j] -= mat[i - 1][j - 1];
			}
		}
	}
	void PrintComputedMaxSumMatrix() {
		for (int i = 0;i < n;++i) {
			for (int j = 0;j < m;++j) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};