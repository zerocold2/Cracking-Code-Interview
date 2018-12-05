#include "CP.h"

class MaxSum {
	int n, m;
	int mat[101][101];
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
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> mat[i][j];
			}
		}
	}
	void ComputeMaxSumOnMatrix() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i > 0)mat[i][j] += mat[i - 1][j];
				if (j > 0)mat[i][j] += mat[i][j - 1];
				if (i > 0 && j > 0)mat[i][j] -= mat[i - 1][j - 1];
			}
		}
	}
	void PrintComputedMaxSumMatrix() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}


	/*
	 *This's the naive solution,
	 *precompute the sum of the matrix at each point
	 *so you can just access the sum with o(1)
	 *the overall time complexty is o(n^4)
	 */
	int SolveMaxSumOnMatrix()
	{
		int maxRect = EPS, x, y;
		int i, j, k, l;
		REP(i, n)
		{
			REP(j, m)
			{
				FOR(k, i, n, 1)
				{
					FOR(l, j, m, 1)
					{
						int subRect = mat[k][l];
						if (i > 0)subRect -= mat[i - 1][l];
						if (j > 0)subRect -= mat[k][j - 1];
						if (i > 0 && j > 0)subRect += mat[i - 1][j - 1];
						if (subRect > maxRect) {
							maxRect = subRect;
							x = i; y = j;
						}
					}
				}
			}
		}
		cout << endl << x << " " << y << endl;
		return maxRect;
	}

	int Kadane1DArray(int *arr, int n)
	{
		int maxSum = arr[0], i;
		//-2 3 2 -1
		/*
		 * 0  -2 = -2
		 * 1 -2, -2+3 = 1
		 * 2 1+2,2 = 3
		 * 3 -1,-1+3 = 3
		 */
		FOR(i, 1, n, 1)
		{
			maxSum = max(max(arr[i] + maxSum, arr[i]), maxSum);
		}
		return maxSum;
	}
};