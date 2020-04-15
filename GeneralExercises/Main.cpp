//#include "MaxSum.cpp"
//#include "Road.cpp"
#include "CP.h"
//#include <algorithm>    // std::lexicographical_compare
#include "Graph.cpp"
#include "UnionFindDisjointSets.cpp"
//#include "AmazonQ/Amazon.h"

using namespace std;

int main() {
	/*
	MaxSum maxsum;
	int arr[4] = { -2,3,2,-1 };
	cout << maxsum.Kadane1DArray(arr,4) << endl;
	maxsum.SetColumns();
	maxsum.SetRows();
	maxsum.SetMatrix();
	maxsum.ComputeMaxSumOnMatrix();
	maxsum.PrintComputedMaxSumMatrix();
	cout << maxsum.SolveMaxSumOnMatrix() << endl;
*/

#pragma region AmazonQ
	//Amazon am;
	//am.Driver_getMinimumCostToConstruct();
#pragma endregion


#pragma region UnionFindDisjointSets_Driver
	
	UnionFindDisjointSets ufds(5);
	ufds.UnionSet(0, 1);
	ufds.UnionSet(1, 2);
	ufds.UnionSet(3, 2);
	ufds.UnionSet(4, 3);
	cout << ufds.findSet(3) << endl;

#pragma endregion

	
#pragma region Graph_Driver
	VVI g;
	VI t;
	int j;
	g = {{0,1,1,0,0},
		{0,0,1,1,1},
		{0,0,0,1,0},
		{0,0,0,0,1},
		{0,0,0,0,0}
	};
	Graph p;
	p.Traverse(g, p.DFS);

	REP(i, p.list.size()) {
		cout << p.list[i].first << " " << p.list[i].second << endl;
		REP(j, 5) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}

#pragma endregion
	

	//vector<string> ret = orderedJunctionBoxes(4, { "mi2 jog mid pet","wz3 34 54 398","a1 alps cow bar","x4 45 21 7" });
	//vector<string> ret = orderedJunctionBoxes(6, { "t2 13 121 98","r1 box ape bit","b4 xi me nu","br8 eat nim did","w1 has uni gry","f3 52 54 31" });
	/*for (size_t i = 0; i < 4; i++)
	{
		cout << ret[i] << endl;
	}*/
	cout << endl;
	system("PAUSE");
	return 0;
}