#include "CP.h"

//O(E log(V))
pair<int, vector<edge> >Kruskal_MST(vector<edge> edgeList, int n) {
	UnionFind uf(n);
	vector<edge> edges;		// Save MST edges
	int mstCost = 0;
	priority_queue<edge> q;	// Sort Edges
	REP(i, n)q.push(edgeList[i]);
	while (!q.empty())
	{
		edge e = q.top();
		q.pop();

		if (uf.union_sets(e.from, e.to))
		{
			mstCost += e.w;
			edges.PB(e);
		}
	}
	if (sz(edges) != n - 1) return MP(EPS, vector<edge>());
	return MP(mstCost, edges);
}