#include "CP.h"

class Graph
{
public:
	enum TraverseType {
		DFS,
		BFS
	};

	VII list;
	VVI mat;
	VI vis;
	int size;
	Graph();
	~Graph();

#pragma region TrajanDeclarations
	VVI adjList;
	int* ids, * low, id, unvisited = -1, gSize, SCC = 0;
	bool* onStack;
	stack<int> tStack;
	void TrajanStronglyConnectedComponent();
	void TrajanDfs(int n);
#pragma endregion

	void addEdge(int v, int w)
	{
		mat[v].push_back(w);
	}

	void Traverse(VVI& adjList, TraverseType gType) {
		//adjList = mat;
		size = adjList.size();
		MEM(visited, false);
		mat = adjList;
		//copy(adjList.begin(), adjList.end(), back_inserter(list)); // to copy adjList into list
		switch (gType)
		{
		case DFS:
			DFS_Traverse(0);
			break;
		case BFS:
			BFS_Traverse(0);
			break;
		default:
			break;
		}
	}

	int dfs(int n) {
		int res = 0;
		try
		{
			for (int i = 0; n < size && i < mat[n].size(); ++i) {
				if (vis[mat[n][i]] == 0) {
					vis[mat[n][i]] = 1;
					res = 1;
					dfs(mat[n][i]);
				}
			}
		}
		catch (const std::exception&)
		{

		}

		return res;
	}

	int numOfConnectedComponent() {
		/*
		mat representaion as
			1 -> 2, 3
			2 -> 4 ,5 ,6
			4 -> 5 , 6
		*/
		size = mat.size();
		vis.assign(size * size, 0);
		int res = 0;
		REP(i, size) {
			res += dfs(i);
		}
		return res;
	}
private:
	int visited[MAX];
	bool valid(int x) { return (x < size * size) ? true : false; }
	void DFS_Traverse(int x) {
		//if (!valid(x))return;
		REP(j, size) {
			if (!visited[x] && mat[x][j] == 1) {
				visited[x] = true;
				DFS_Traverse(j);
				list.PB(MP(x, j));
			}
		}
	}
	void BFS_Traverse(int n) {
		map<int, int> dist;
		dist[0] = 0;
		priority_queue<int> pq;
		pq.push(n);
		while (!pq.empty())
		{
			int curr = pq.top();
			pq.pop();
			REP(i, (int)mat[curr].size()) {
				if (dist.find(mat[curr][i]) == dist.end())
				{
					dist[mat[curr][i]] = dist[curr] + 1;
					pq.push(mat[curr][i]);
				}
			}
		}
		REP(i, (int)mat.size()) {
			REP(j, (int)mat[i].size())
				cout << "node " << mat[i][j] << " distance " << dist[mat[i][j]] << endl;
		}
	}
};

inline Graph::Graph()
{
}

inline Graph::~Graph() {
	delete[] ids, delete[] onStack, delete[] low;
}

inline void Graph::TrajanStronglyConnectedComponent()
{
	gSize = adjList.size();
	ids = new int[gSize + 1], low = new int[gSize + 1], onStack = new bool[gSize + 1];
	memset(ids, unvisited, sizeof(ids));
	memset(low, 0, sizeof(low));
	memset(onStack, false, sizeof(onStack));

	REP(i, (int)gSize) {
		TrajanDfs(i);
	}
}

inline void Graph::TrajanDfs(int at)
{
	tStack.push(at);
	ids[at] = low[at] = id++;
	onStack[at] = true;


	REP(i, (int)adjList[at].size()) {
		int to = adjList[at][i];
		if (ids[to] == unvisited)TrajanDfs(to);
		if (onStack[to])low[at] = min(low[at], low[to]);
	}

	//	On recursive call back,
	//	Empty stack if we are on SCC root
	if (low[at] = ids[at]) {
		for (;;) {
			int node = tStack.top(); tStack.pop();
			low[at] = ids[at];
			onStack = false;
			if (node == at) break;
		}
		SCC++;
	}
}





