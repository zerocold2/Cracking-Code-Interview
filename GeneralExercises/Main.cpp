#include "MaxSum.cpp"

using namespace std;


int main() {

	MaxSum maxsum;
	int arr[4] = { -2,3,2,-1 };
	cout << maxsum.Kadane1DArray(arr,4) << endl;
	maxsum.SetColumns();
	maxsum.SetRows();
	maxsum.SetMatrix();
	maxsum.ComputeMaxSumOnMatrix();
	maxsum.PrintComputedMaxSumMatrix();
	cout << maxsum.SolveMaxSumOnMatrix() << endl;

	system("PAUSE");
	return 0;
}