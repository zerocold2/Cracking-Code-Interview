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
