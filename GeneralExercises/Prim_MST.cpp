#include "CP.h"



//Find MST value & edges, adjMax is initialized by OO
pair<int, vector<edge> >Prim_MST1(VVI adjMax) { //O(n^2)
	int curNode = 0, n = sz(adjMax), mini;
	int mind, mstCost = 0;

	VI vis(n, 0), prev(n);
	VI dist(n, INF);  //1- dist[i]= Minimum value to connect i to current tree
	vector<edge> edges;	//Save MST edges

	REP(k, n - 1) {
		vis[curNode] = 1, mind = INF, mini = -1;
		REP(i, n) {
			if (!vis[i])
			{
				if (adjMax[curNode][i] < dist[i]) //2- Update if i can reach the tree with a new minimum value
					dist[i] = adjMax[curNode][i], prev[i] = curNode;

				if (dist[i] < mind)
					mind = dist[i], mini = i; //3- Select minimum Edge value
			}
		}
		if (mini == -1)break; //4- check if graph is disconnected
		//5- update edges and cost of MST
		edges.PB(edge(prev[mini], mini, adjMax[prev[mini]][mini]));
		curNode = mini, mstCost += dist[curNode];
	}
	if (sz(edges) != n - 1)return MP(INF, vector<edge>());
	return MP(mstCost, edges);
}

//O(E logV)
pair<int, vector<edge> > Prim_MST2(vector<vector<edge> > adjList) {
	int n = sz(adjList), mstCost = 0;
	VI vis(n, 0);
	vector<edge> edges;	//Save MST Edges

	priority_queue<edge> q;	//1- priority_queue to sort edges
	q.push(edge(-1, 0, 0));

	while (!q.empty())
	{
		edge e = q.top();
		if (vis[e.to]) continue;
		vis[e.to] = 1;
		mstCost += e.w;
		if (e.to)edges.PB(e); //2- Remove min element & update cost/list
		
		REP(k, sz(adjList[e.to])) {
			// 3- Iterate on adjacent edges & add new edges, using e.to as src
			edge ne = adjList[e.to][k];
			if (!vis[ne.to])q.push(ne);
		}
	}
	if (sz(edges) != n - 1)return MP(EPS, vector<edge>());
	return MP(mstCost, edges);
}