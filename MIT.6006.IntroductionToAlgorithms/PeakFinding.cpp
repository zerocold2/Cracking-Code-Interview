#include "Main.h"

class PeakFinding
{
public:
	/*
	 * Binary Search for finding the Peak on one dimension array
	 */
	static int FindPeak(int arr[], int length)
	{
		int pos, start = 0, end = length - 1;

		while (start <= end)
		{
			pos = start + (end - start) / 2;
			if (start == end)return arr[pos];
			if (arr[pos] < arr[pos + 1])start = pos;
			else if (arr[pos] < arr[pos - 1])end = pos;
			else return arr[pos];
		}
		return arr[pos];
	}

	/*
	 * Gready Ascent Algorithm O(NM) , O(N^2) if M=N
	 */
	static int FindPeak(int arr[][2],int length)
	{

		return 0;
	}
};