#include "Graph.h"



Graph::Graph(const int size)
{
	this->graphSize = size;
	adjList = new std::list<int>[size];
}

Graph::~Graph()
{
}

int Graph::getSize()
{
	return this->graphSize;
}

std::list<int> Graph::getGraph()
{
	return *adjList;
}

void Graph::addEdgeFromTo(const int from, const int to)
{
	adjList[from].push_back(to);
}


std::vector<int> Graph::BFSorderLeftToRight(const int startingNode)
{
	int currentNode;
	// Define the visited vector
	std::vector<int> output;
	// Define the Queue/Stack to store the output
	std::queue<int> bfsqueued;

	//std::stack<int> dfsOutput;

	bfsqueued.push(startingNode);

	while (!bfsqueued.empty()) {
		// Define the starting node as the current node
		currentNode = bfsqueued.front();
		//Salve the visited node in the output vector
		output.push_back(currentNode);
		//Populate the queue with the new neighbors
		bfsqueued.pop();
		for (const int& neighbors : adjList[currentNode]) {
				bfsqueued.push(neighbors);
		}
	}
	return output;
}

std::vector<int> Graph::DFSorderLeftToRight(const int startingNode)
{
	int currentNode;
	// Define the visited vector
	std::vector<int> output;
	// Define the Queue/Stack to store the output
	std::stack<int> bfsstack;

	//std::stack<int> dfsOutput;

	bfsstack.push(startingNode);

	while (!bfsstack.empty()) {
		// Define the starting node as the current node
		currentNode = bfsstack.top();


		//Salve the visited node in the output vector
		output.push_back(currentNode);
		
		bfsstack.pop();
		//Populate the queue with the new neighbors
		//for (const int& neighbors : adjList[currentNode]) {
		//	bfsstack.push(neighbors);
		//}

		for (std::list<int>::reverse_iterator it_neighbors = adjList[currentNode].rbegin();
			it_neighbors != adjList[currentNode].rend();
			++it_neighbors) {
			bfsstack.push(*it_neighbors);
		}

	}
	return output;
}

bool Graph::BFSorderHasConnection(const int startingNode, const int endingNode)
{
	int currentNode;
	// Define the visited vector
	std::vector<int> output;
	// Define the Queue/Stack to store the output
	std::queue<int> bfsqueued;

	//std::stack<int> dfsOutput;

	bfsqueued.push(startingNode);

	while (!bfsqueued.empty()) {
		// Define the starting node as the current node
		currentNode = bfsqueued.front();
		if (currentNode == endingNode) {
			return true;
		}
		//Salve the visited node in the output vector
		output.push_back(currentNode);
		//Populate the queue with the new neighbors
		bfsqueued.pop();
		for (const int& neighbors : adjList[currentNode]) {
			bfsqueued.push(neighbors);
		}


	}


	return false;
}

bool Graph::DFSorderHasConnection(const int startingNode, const int endingNode)
{
	int currentNode;
	// Define the visited vector
	std::vector<int> output;
	// Define the Queue/Stack to store the output
	std::stack<int> bfsstack;

	//std::stack<int> dfsOutput;

	bfsstack.push(startingNode);

	while (!bfsstack.empty()) {
		// Define the starting node as the current node
		currentNode = bfsstack.top();

		if (currentNode == endingNode) {
			return true;
		}

		//Salve the visited node in the output vector
		output.push_back(currentNode);

		bfsstack.pop();
		//Populate the queue with the new neighbors
		//for (const int& neighbors : adjList[currentNode]) {
		//	bfsstack.push(neighbors);
		//}

		for (std::list<int>::reverse_iterator it_neighbors = adjList[currentNode].rbegin();
			it_neighbors != adjList[currentNode].rend();
			++it_neighbors) {
			bfsstack.push(*it_neighbors);
		}
	}
	return false;
}





/* Helpers */
bool Graph::hasEdge(const int from, const int to)
{
	std::list<int> adjNodeFrom = adjList[from];

	/*
	Reference Avoids Copying: auto& means you're iterating over elements by reference rather than by value. 
		This avoids making copies of elements, which can be important if the elements are large objects or if copying is expensive.
	Performance: For large data structures, especially those that contain complex or large objects, 
		using auto& can significantly improve performance by preventing unnecessary copies.
	*/
	for (const int& neighbor : adjNodeFrom)
	{
		if (neighbor == to) {
			return true;
		}
	}

	return false;
}

bool alraedyVisited(const std::vector<int> adjNodeFrom, const int current) {
	for (const int& neighbor : adjNodeFrom)
	{
		if (neighbor == current) {
			return true;
		}
	}
	return false;
}