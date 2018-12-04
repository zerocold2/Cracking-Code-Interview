#include "Main.h"


class ArrayAndStrings
{
public:
	/*
	* 1.1 Implement an algorithm to determine if a string has all unique characters What if you
		  can not use additional data structures?
	*/
	static bool Unique_Character(string str)
	{
		//O(N)
		int arr[256] = { 0 };
		for (int i = 0; i < str.length(); ++i)
		{
			if (arr[str[i]] > 0)return false;
			arr[str[i]]++;
		}

		/*sort(str.begin(), str.end());
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == str[i + 1])return false;
		}*/
		return true;
	}

	/*
	 * 1.2	Write code to reverse a C-Style String (C-String means that “abcd” is represented as
			fve characters, including the null character )
	 */
	static char* ReverseC_String(char str[])
	{
		int len = strlen(str);
		if (len <= 2) return str;
		int left = 0;
		int right = len - 1;
		while (left < right)
		{
			char tmp = str[left];
			str[left] = str[right];
			str[right] = tmp;
			left++;
			right--;
		}
		return str;
	}

	/*
	 * 1.3  Design an algorithm and write code to remove the duplicate characters in a string
			without using any additional buﬀer NOTE: One or two additional variables are fne
			An extra copy of the array is not
			FOLLOW UP
			Write the test cases for this method
	 */
	static char* Remove_Duplicate(char str[])
	{
		int t = 1;
		for (int i = 0; i < strlen(str); ++i)
		{
			int j;
			for (j = 0; j < t; ++j)
			{
				if (str[i] == str[j])break;
			}
			if (j == t)
			{
				str[t] = str[i];
				t++;
			}
		}
		str[t] = '\0';

		return str;
	}

	/*
	 * 1.4 Write a method to decide if two strings are anagrams or not
	 */
	static bool Anagram(string s1, string s2)
	{
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		return s1 == s2;
	}

	/*
	 *	1.5 Write a method to replace all spaces in a string with ‘%20’
	 */
	static void ReplaceSpaces(char str[])
	{
		int length = strlen(str), cnt = 0, newLength = length;
		for (int i = 0; i < length; ++i)if (str[i] == ' ')cnt++;
		newLength += cnt * 2;
		str[newLength] = '\0';
		for (int i = length - 1; i >= 0; --i)
		{
			if (str[i] == ' ')
			{
				str[--newLength] = '0';
				str[--newLength] = '2';
				str[--newLength] = '%';
			}
			else str[--newLength] = str[i];
		}
		cout << str << endl;
	}

	/*
	 * 1.6 Given an image represented by an NxN matrix, where each pixel in the image is 4
		  bytes, write a method to rotate the image by 90 degrees Can you do this in place?
	 */
	static void RotateImageBy90(char mat[][101], int n)
	{
		for (int layer = 0; layer < n / 2; ++layer)
		{
			int last = n - layer - 1;
			for (size_t i = layer; i < last; i++)
			{
				//save upper left corner
				int tmp = mat[layer][layer + i];
				mat[layer][layer + i] = mat[last - i][layer];
				mat[last - i][layer] = mat[last][last - i];
				mat[last][last - i] = mat[layer + i][last];
				mat[layer + i][last] = tmp;
			}
		}
	}
};


