#pragma once
#include "Amazon.h"


int Amazon::getMinimumCostToConstruct(int numTotalAvailableCities, int numTotalAvailableRoads, int** roadsAvailable, int numNewRoadsConstruct, int** costNewRoadsConstruct)
{
	int mstCost = 0, sz = numTotalAvailableRoads, totalEdges = numTotalAvailableRoads + numNewRoadsConstruct;
	vector<edge> edges;
	UnionFind uf(totalEdges + 1);
	REP(i, numTotalAvailableRoads) {
		edges.PB(edge(roadsAvailable[i][0], roadsAvailable[i][1], 0));
		uf.union_sets(roadsAvailable[i][0], roadsAvailable[i][1]);
	}
	REP(i, numNewRoadsConstruct) {
		edges.PB(edge(costNewRoadsConstruct[i][0], costNewRoadsConstruct[i][1], costNewRoadsConstruct[i][2]));
	}
	priority_queue<edge> q;
	REP(i, totalEdges)q.push(edges[i]);

	while (!q.empty())
	{
		edge e = q.top();
		q.pop();
		if (uf.union_sets(e.from, e.to))
		{
			mstCost += e.w;
			sz++;
		}
	}
	if (sz == numTotalAvailableCities - 1)return mstCost;
	return -1;
}

void Amazon::Driver_getMinimumCostToConstruct()
{
	int r[4][2] = { { 1, 2 }, { 2,3 }, { 4,5 }, { 3,5 } },
		rr[2][3] = { { 1,6,410 },{ 2,4,800 } };
	int* rx[4] = { r[0],r[1],r[2],r[3] }, * rrx[2] = { rr[0],rr[1] };
	cout << getMinimumCostToConstruct(6, 4, rx, 2, rrx);
}

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

vector<string> Amazon::orderedJunctionBoxes(int numberOfBoxes, vector<string> boxList)

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