#include "MaxSum.cpp"

using namespace std;


int main() {
	
	MaxSum maxsum;
	maxsum.SetColumns();
	maxsum.SetRows();
	maxsum.SetMatrix();
	maxsum.ComputeMaxSumOnMatrix();
	maxsum.PrintComputedMaxSumMatrix();
	system("PAUSE");
	return 0;
}