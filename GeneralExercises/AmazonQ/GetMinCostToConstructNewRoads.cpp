#pragma once
#include "../CP.h"


int Core_getMinimumCostToConstruct(int numTotalAvailableCities,
	int numTotalAvailableRoads,
	int** roadsAvailable,
	int numNewRoadsConstruct,
	int** costNewRoadsConstruct) {

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

void Core_Driver_getMinimumCostToConstruct() {
	int r[4][2] = { { 1, 2 }, { 2,3 }, { 4,5 }, { 3,5 } },
		rr[2][3] = { { 1,6,410 },{ 2,4,800 } };
	int* rx[4] = { r[0],r[1],r[2],r[3] }, * rrx[2] = { rr[0],rr[1] };
	cout << Core_getMinimumCostToConstruct(6, 4, rx, 2, rrx);
}

