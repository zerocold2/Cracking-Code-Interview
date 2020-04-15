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

	Graph() {};
	~Graph() {};

	void Traverse(VVI& adjList, TraverseType gType) {
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
			BFS_Traverse(0, 0);
			break;
		default:
			break;
		}
	}

	int dfs(int n) {
		int res=0;
		for (int i = 0; i < mat[n].size(); ++i) {
			if (vis[mat[n][i]] == 0) {
				vis[mat[n][i]] = 1;
				res = 1;
				dfs(i);
			}
		}
	}

	int numOfConnectedComponent() {
		/*
		mat representaion as
			1 -> 2, 3
			2 -> 4 ,5 ,6
			4 -> 5 , 6
		*/
		//fill(vis, vis, 0);
		size = mat.size();
		int res = 0;
		REP(i, size) {
			res+=dfs(i);
		}
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
	void BFS_Traverse(int x, int y) {

	}
};
