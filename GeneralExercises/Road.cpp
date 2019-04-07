//
//#include "CP.h"
//
///*
//	6
//	4
//	[ [1,2], [2,3], [4,5], [3,5] ]
//	2
//	[ [1,6,410], [2,4,800] ]
//
//*/
//int getMinimumCostToConstruct(int numTotalAvailableCities,
//	int numTotalAvailableRoads,
//	int** roadsAvailable,
//	int numNewRoadsConstruct,
//	int** costNewRoadsConstruct) {
//
//	int mstCost = 0, sz = numTotalAvailableRoads;
//	vector<edge> edges;
//	UnionFind uf(numTotalAvailableCities);
//	REP(i, numTotalAvailableRoads) {
//		edges.PB(edge(roadsAvailable[i][0], roadsAvailable[i][1], 0));
//		uf.union_sets(roadsAvailable[i][0], roadsAvailable[i][1]);
//	}
//	REP(i, numNewRoadsConstruct) {
//		edges.PB(edge(costNewRoadsConstruct[i][0], costNewRoadsConstruct[i][1], costNewRoadsConstruct[i][2]));
//	}
//	priority_queue<edge> q;
//	REP(i, numTotalAvailableCities)q.push(edges[i]);
//
//	while (!q.empty())
//	{
//		edge e = q.top();
//		q.pop();
//		if (uf.union_sets(e.from, e.to))
//		{
//			mstCost += e.w;
//			sz++;
//		}
//	}
//	if (sz == numTotalAvailableCities - 1)return mstCost;
//	return -1;
//}