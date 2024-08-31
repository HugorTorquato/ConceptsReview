#pragma once

#include <list>
#include <vector>
#include <stack>
#include <queue>


struct NodesDist {
	int node;
	int dist;
	int previousNode;
};

class Graph
{
public:
	Graph(const int size);
	~Graph();

	int getSize();
	std::list<int> getGraph();
	
	void addEdgeFromTo(const int from, const int to);

	bool hasEdge(const int u, const int v);

	std::vector<int> BFSorderLeftToRight(const int startingNode);
	std::vector<int> DFSorderLeftToRight(const int startingNode);

	bool BFSorderHasConnection(const int startingNode, const int endingNode);

	bool DFSorderHasConnection(const int startingNode, const int endingNode);

	std::vector<int> BFSDistaceBetween2Nodes(const int startingNode, const int endingNode);

private:
	int graphSize;

	std::list<int> *adjList;
};

bool alraedyVisited(const std::vector<int> adjNodeFrom, const int current);
