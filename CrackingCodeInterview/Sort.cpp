#include "Main.h"

class Sort
{
public:
	Sort() {}
	~Sort() {}
	void MergeSort(int *arr, int size) {
		MergeSort(arr, 0, size);
	}
private:
	void MergeSort(int *arr, int l, int r) {
		if (l < r) {
			int m = l + (r - l) / 2;
			MergeSort(arr, l, m);
			MergeSort(arr, m + 1, r);
			Merge(arr, l, m, r);
		}
	}
	void Merge(int *arr, int l, int m, int r) {
		int i, j, k = l, ln = m - l + 1, rn = r - m;
		int L[101], R[101];
		REP(i, ln)
			L[i] = arr[l + i];
		REP(j, rn)R[j] = arr[m + 1 + j];
		i = 0;
		j = 0;
		while (i < ln&&j < rn) {
			if (L[i] <= R[j]) {
				arr[k] = L[i++];
			}
			else {
				arr[k] = R[j++];
			}
			k++;
		}
		while (i < ln)
			arr[k++] = L[i++];
		while (j < rn)
			arr[k++] = R[j++];

	}
};
