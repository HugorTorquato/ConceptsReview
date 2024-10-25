#include <gtest/gtest.h>

#include "Graphs.h"

TEST(GraphsTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(GraphsTests, simpleMethodReturning1){
    GraphsClass GC;

    EXPECT_EQ(GC.return1ToTest(), 1);
}

// --------------------------------------------------------

TEST(GraphsTests, setAndGetDataForSpecificNode){
    Node NodeObj;
    const int valueToAssociateToTheNode = 1;

    NodeObj.setData(valueToAssociateToTheNode);

    EXPECT_EQ(NodeObj.getData(), valueToAssociateToTheNode);
}

TEST(GraphsTests, includeAndGetEdgesForSpecificNode){
    Node NodeObj;
    const int valueToAssociateToTheNode = 1;
    const vector<int> expectedEdges = {2, 3};

    NodeObj.setData(valueToAssociateToTheNode);
    NodeObj.includeEdge(2);
    NodeObj.includeEdge(3);

    EXPECT_EQ(NodeObj.getData(), valueToAssociateToTheNode);
    EXPECT_EQ(NodeObj.getEdges(), expectedEdges);
}


// --------------------------------------------------------

TEST(GraphsTests, retrieveEmptyGraph){
    GraphsClass GC;

    ASSERT_TRUE(GC.getGraphAsVector().empty());
}

TEST(GraphsTests, includeElementInEmptyGraph){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    const int valueToAssociateToTheNode = 100;

    NodeObj_1->setData(valueToAssociateToTheNode);

    GC.includeNode(NodeObj_1);

    ASSERT_FALSE(GC.getGraphAsVector().empty());
    ASSERT_TRUE(GC.getGraphAsVector().size() == 1);
}

TEST(GraphsTests, includeEdgeInWhenFromNodeDoesntExist_GraphAndEdgesCoundRemainZero){
    GraphsClass GC;

    GC.includeEdgeFromTo(1, 2);

    ASSERT_TRUE(GC.getGraphAsVector().empty());
}


TEST(GraphsTests, includeNodeInGraphWithEdge_1Nodes){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    const vector<int> expectedEdgesFromNode1 = {2};

    NodeObj_1->includeEdge(2);

    GC.includeNode(NodeObj_1);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();

    ASSERT_TRUE(graph.size() == 1);

    EXPECT_EQ(graph.at(0).second, expectedEdgesFromNode1);

}

// Include 2 elements and edge between them
TEST(GraphsTests, includeNodeInGraphWithEdge_2Nodes){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    shared_ptr<Node> NodeObj_2 = make_shared<Node>();

    const vector<int> expectedEdgesFromNodeObj_1 = {2, 3};
    const vector<int> expectedEdgesFromNodeObj_2 = {4};

    NodeObj_1->includeEdge(2);
    NodeObj_1->includeEdge(3);

    NodeObj_2->includeEdge(4);

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();

    ASSERT_TRUE(graph.size() == 2);

    EXPECT_EQ(graph.at(0).second, expectedEdgesFromNodeObj_1);
    EXPECT_EQ(graph.at(1).second, expectedEdgesFromNodeObj_2);

    /*
    () - just declared the edges
            1
           / \ 
         2    (3)
        /
      (4)
    */
}

TEST(GraphsTests, applyBFSToAnEmptyGraph_ReturnEmptyVector){
    GraphsClass GC;

    ASSERT_TRUE(GC.BFS_Search().empty());
}

TEST(GraphsTests, applyBFSToGraph_1NodeAnd0Edges){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    const vector<int> expectedEdgesFromNode1 = {2};
    const vector<int> expectedBFSResultIDs = {1};

    NodeObj_1->includeEdge(2);

    GC.includeNode(NodeObj_1);

    vector<std::shared_ptr<Node>> BFS_result = GC.BFS_Search();

    ASSERT_FALSE(BFS_result.empty());
}


TEST(GraphsTests, applyBFSToGraph_2NodeAnd3Edges){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    shared_ptr<Node> NodeObj_2 = make_shared<Node>();

    const vector<int> expectedBFSResultIDs = {1, 2};

    NodeObj_1->includeEdge(2);

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 2);

    vector<std::shared_ptr<Node>> BFS_result = GC.BFS_Search();

    ASSERT_FALSE(BFS_result.empty());
}


// include 3 elements and edges between them

// 