#pragma once
#include "../CP.h"


string sub(string in) {
	string ret = ""; int flg = 0;
	for (size_t i = 0; i < in.size(); i++)
	{
		if (in[i] == ' ') {
			flg = 1;
			continue;
		}
		if (flg == 1)ret += in[i];
	}
	return ret;
}

bool lexographical_Compare(string s1, string s2) {
	int mn = min(s1.length(), s2.length());
	for (size_t i = 0; i < mn; i++)
	{
		if (s1[i] > s2[i])return false;
		else if (s1[i] == s2[i])continue;
		else return true;
	}
	//if (s1.length() > s2.length())return false;
	return true;
}

vector<string> Core_orderedJunctionBoxes(int numberOfBoxes, vector<string> boxList)
{
	vector<string> ret;
	vector<string> num;

	int mn = INF;
	string ss = "";
	for (int i = 0; i < numberOfBoxes - 1; ++i) {
		if (boxList[i] == "-1")continue;
		string sn = sub(boxList[i]);
		if (sn[0] >= 48 && sn[0] <= 57) {
			num.push_back(boxList[i]);
			boxList[i] = "-1";
			continue;
		}
		else {
			for (size_t j = i + 1; j < numberOfBoxes; j++)
			{
				ss = sub(boxList[j]);
				if (ss[0] >= 48 && ss[0] <= 57) {
					num.push_back(boxList[j]);
					boxList[j] = "-1";
					continue;
				}
				if (!lexographical_Compare(sn, ss))
				{
					swap(boxList[i], boxList[j]);
					sn = ss;
				}
			}
		}
	}
	for (size_t i = 0; i < numberOfBoxes; i++)
	{
		if (boxList[i] == "-1")continue;
		else ret.push_back(boxList[i]);
	}
	for (size_t i = 0; i < num.size(); i++)
	{
		ret.push_back(num[i]);
	}
	return ret;
}

