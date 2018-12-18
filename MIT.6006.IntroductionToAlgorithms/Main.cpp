#include "Main.h"
#include "peakfinding.cpp"

int main(int argc, char* argv[])
{
	char str[] = "Ahmed nasr ata alazbakawy";
	int arr[10] = { 50,14,3,13,6,7,8,1,12,0 };
	
	cout << PeakFinding::FindPeak(arr, sizeof(arr) / sizeof(int)) << endl;
	
}
