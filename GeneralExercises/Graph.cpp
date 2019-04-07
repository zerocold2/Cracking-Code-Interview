#include "CP.h"
enum TraverseType {
	DFS,
	BFS
};
class Graph
{
public:

	Graph();
	~Graph();
	void Traverse(VI &adjList,TraverseType gType) {
		vis.clear();
	}
private:
	vector< bool > vis;
	void DFS_Traverse(VI &adjList) {
		

	}
};

Graph::Graph()
{
}

Graph::~Graph()
{
}