#include "gmock/gmock.h"
#include "../Graphs/Graph.h"

#include "../Graphs/Source.cpp"

using namespace std;

TEST(SimpleTest, simpleSumTest) {
	EXPECT_EQ(sum(2, 2), 4);
}


TEST(GraphTests, retrieveEmptyGraphwithSizeEquals5) {

	const int size = 5;
	Graph graphTest(size);

	EXPECT_EQ(graphTest.getSize(), size);
}

TEST(GraphTests, defineSimpleEmptyGraphWithSize5) {

	const int size = 5;
	Graph graphTest(size);

	EXPECT_EQ(graphTest.getGraph().size(), 0);
}

TEST(GraphTests, defineSimpleGraphWithSize6) {

	const int size = 6;
	Graph graphTest(size);

	graphTest.addEdgeFromTo(0, 1);
	graphTest.addEdgeFromTo(0, 2);
	graphTest.addEdgeFromTo(1, 3);
	graphTest.addEdgeFromTo(1, 4);
	graphTest.addEdgeFromTo(2, 5);
	graphTest.addEdgeFromTo(5, 6);

	EXPECT_TRUE(graphTest.hasEdge(0, 1));
	EXPECT_TRUE(graphTest.hasEdge(1, 3));
	EXPECT_TRUE(graphTest.hasEdge(5, 6));
}

TEST(GraphTests, peformBFS) {

	const int size = 7;
	Graph graphTest(size);

	graphTest.addEdgeFromTo(0, 1);
	graphTest.addEdgeFromTo(0, 2);
	graphTest.addEdgeFromTo(1, 3);
	graphTest.addEdgeFromTo(1, 4);
	graphTest.addEdgeFromTo(2, 5);
	graphTest.addEdgeFromTo(5, 6);

	int bfsExpectLedfRight[] = { 0, 1, 2, 3, 4, 5, 6 };

	auto bfsOrder = graphTest.BFSorderLeftToRight(0);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(bfsOrder[i], bfsExpectLedfRight[i]);
	}
}

TEST(GraphTests, peformDFS) {

	const int size = 7;
	Graph graphTest(size);

	//TO DO: The order we enter the vertix should not metter
	graphTest.addEdgeFromTo(0, 1);
	graphTest.addEdgeFromTo(0, 2);
	graphTest.addEdgeFromTo(1, 3);
	graphTest.addEdgeFromTo(1, 4);
	graphTest.addEdgeFromTo(2, 5);
	graphTest.addEdgeFromTo(5, 6);

	int bfsExpectLedfRight[] = { 0, 1, 3, 4, 2, 5, 6 };

	auto bfsOrder = graphTest.DFSorderLeftToRight(0);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(bfsOrder[i], bfsExpectLedfRight[i]);
	}
}

TEST(GraphTests, validateIfPosition0HasConectionToPosition5BFS) {

	const int size = 7;
	Graph graphTest(size);

	//TO DO: The order we enter the vertix should not metter
	graphTest.addEdgeFromTo(0, 1);
	graphTest.addEdgeFromTo(0, 2);
	graphTest.addEdgeFromTo(1, 3);
	graphTest.addEdgeFromTo(1, 4);
	graphTest.addEdgeFromTo(2, 5);
	graphTest.addEdgeFromTo(5, 6);

	EXPECT_TRUE(graphTest.BFSorderHasConnection(0, 5));
	EXPECT_TRUE(graphTest.BFSorderHasConnection(2, 5));
}

TEST(GraphTests, validateIfPosition0HasNoConectionToPosition5BFS) {

	const int size = 7;
	Graph graphTest(size);

	//TO DO: The order we enter the vertix should not metter
	graphTest.addEdgeFromTo(0, 1);
	graphTest.addEdgeFromTo(0, 2);
	//graphTest.addEdgeFromTo(1, 3);
	graphTest.addEdgeFromTo(1, 4);
	graphTest.addEdgeFromTo(2, 5);
	graphTest.addEdgeFromTo(5, 6);

	EXPECT_FALSE(graphTest.BFSorderHasConnection(0, 8));
}

TEST(GraphTests, validateIfPosition0HasConectionToPosition5DFS) {

	const int size = 7;
	Graph graphTest(size);

	//TO DO: The order we enter the vertix should not metter
	graphTest.addEdgeFromTo(0, 1);
	graphTest.addEdgeFromTo(0, 2);
	graphTest.addEdgeFromTo(1, 3);
	graphTest.addEdgeFromTo(1, 4);
	graphTest.addEdgeFromTo(2, 5);
	graphTest.addEdgeFromTo(5, 6);

	EXPECT_TRUE(graphTest.DFSorderHasConnection(0, 5));
	EXPECT_TRUE(graphTest.DFSorderHasConnection(2, 5));
}

TEST(GraphTests, validateIfPosition0HasNoConectionToPosition5DFS) {

	const int size = 7;
	Graph graphTest(size);

	//TO DO: The order we enter the vertix should not metter
	graphTest.addEdgeFromTo(0, 1);
	graphTest.addEdgeFromTo(0, 2);
	//graphTest.addEdgeFromTo(1, 3);
	graphTest.addEdgeFromTo(1, 4);
	graphTest.addEdgeFromTo(2, 5);
	graphTest.addEdgeFromTo(5, 6);

	EXPECT_FALSE(graphTest.DFSorderHasConnection(0, 8));
}


