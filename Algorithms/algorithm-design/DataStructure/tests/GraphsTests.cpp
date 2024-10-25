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

    int count = 0;

    ASSERT_FALSE(BFS_result.empty());
    ASSERT_EQ(BFS_result.size(), expectedBFSResultIDs.size());
    for(auto it : BFS_result){
        EXPECT_EQ(it->getId(), expectedBFSResultIDs[count]);
        count++;
    }
}

TEST(GraphsTests, applyBFSToGraph_11NodeAnd14Edges){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    shared_ptr<Node> NodeObj_2 = make_shared<Node>();
    shared_ptr<Node> NodeObj_3 = make_shared<Node>();
    shared_ptr<Node> NodeObj_4 = make_shared<Node>();
    shared_ptr<Node> NodeObj_5 = make_shared<Node>();
    shared_ptr<Node> NodeObj_6 = make_shared<Node>();
    shared_ptr<Node> NodeObj_7 = make_shared<Node>();
    shared_ptr<Node> NodeObj_8 = make_shared<Node>();
    shared_ptr<Node> NodeObj_9 = make_shared<Node>();
    shared_ptr<Node> NodeObj_10 = make_shared<Node>();
    shared_ptr<Node> NodeObj_11 = make_shared<Node>();

    const vector<int> expectedBFSResultIDs = {1, 3, 2, 4, 6, 5, 7, 8, 10, 9, 11};

    NodeObj_1->includeEdge(3);
    NodeObj_1->includeEdge(2);
    NodeObj_1->includeEdge(4);
    NodeObj_2->includeEdge(3);
    NodeObj_2->includeEdge(6);
    NodeObj_3->includeEdge(6);
    NodeObj_4->includeEdge(5);
    NodeObj_6->includeEdge(7);
    NodeObj_6->includeEdge(8);
    NodeObj_7->includeEdge(10);
    NodeObj_8->includeEdge(6);
    NodeObj_8->includeEdge(9);
    NodeObj_9->includeEdge(10);
    NodeObj_10->includeEdge(11);


    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);
    GC.includeNode(NodeObj_3);
    GC.includeNode(NodeObj_4);
    GC.includeNode(NodeObj_5);
    GC.includeNode(NodeObj_6);
    GC.includeNode(NodeObj_7);
    GC.includeNode(NodeObj_8);
    GC.includeNode(NodeObj_9);
    GC.includeNode(NodeObj_10);
    GC.includeNode(NodeObj_11);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 11);

    vector<std::shared_ptr<Node>> BFS_result = GC.BFS_Search();

    int count = 0;

    ASSERT_FALSE(BFS_result.empty());
    ASSERT_EQ(BFS_result.size(), expectedBFSResultIDs.size());

    //The order may change based on the way the graph is defined. 
    //TODO: Find another way to peform this verification
    for(auto it : BFS_result){
        EXPECT_EQ(it->getId(), expectedBFSResultIDs[count]);
        count++;
    }
}

TEST(GraphsTests, applyDFSToGraph_11NodeAnd14Edges){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    shared_ptr<Node> NodeObj_2 = make_shared<Node>();
    shared_ptr<Node> NodeObj_3 = make_shared<Node>();
    shared_ptr<Node> NodeObj_4 = make_shared<Node>();
    shared_ptr<Node> NodeObj_5 = make_shared<Node>();
    shared_ptr<Node> NodeObj_6 = make_shared<Node>();
    shared_ptr<Node> NodeObj_7 = make_shared<Node>();
    shared_ptr<Node> NodeObj_8 = make_shared<Node>();
    shared_ptr<Node> NodeObj_9 = make_shared<Node>();
    shared_ptr<Node> NodeObj_10 = make_shared<Node>();
    shared_ptr<Node> NodeObj_11 = make_shared<Node>();

    const vector<int> expectedBFSResultIDs = {1, 4, 5, 2, 6, 8, 9, 10, 11, 7, 3};

    NodeObj_1->includeEdge(3);
    NodeObj_1->includeEdge(2);
    NodeObj_1->includeEdge(4);
    NodeObj_2->includeEdge(3);
    NodeObj_2->includeEdge(6);
    NodeObj_3->includeEdge(6);
    NodeObj_4->includeEdge(5);
    NodeObj_6->includeEdge(7);
    NodeObj_6->includeEdge(8);
    NodeObj_7->includeEdge(10);
    NodeObj_8->includeEdge(6);
    NodeObj_8->includeEdge(9);
    NodeObj_9->includeEdge(10);
    NodeObj_10->includeEdge(11);


    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);
    GC.includeNode(NodeObj_3);
    GC.includeNode(NodeObj_4);
    GC.includeNode(NodeObj_5);
    GC.includeNode(NodeObj_6);
    GC.includeNode(NodeObj_7);
    GC.includeNode(NodeObj_8);
    GC.includeNode(NodeObj_9);
    GC.includeNode(NodeObj_10);
    GC.includeNode(NodeObj_11);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 11);

    vector<std::shared_ptr<Node>> BFS_result = GC.DFS_Search();

    int count = 0;

    ASSERT_FALSE(BFS_result.empty());
    ASSERT_EQ(BFS_result.size(), expectedBFSResultIDs.size());

    //The order may change based on the way the graph is defined. 
    //TODO: Find another way to peform this verification
    for(auto it : BFS_result){
        EXPECT_EQ(it->getId(), expectedBFSResultIDs[count]);
        count++;
    }
}

// include 3 elements and edges between them

// 