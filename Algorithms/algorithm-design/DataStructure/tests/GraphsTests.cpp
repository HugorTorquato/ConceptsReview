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

TEST(GraphsTests, Dijkstra_ShortestPath_ReturnInitializedDistancesIfNoEdges){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    shared_ptr<Node> NodeObj_2 = make_shared<Node>();

    const vector<int> expectedDistanceResults = {0, infInt};

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 2);

    vector<std::shared_ptr<Node>> _result = GC.Dijkstra_ShortestPath();

    int count = 0;

    ASSERT_FALSE(_result.empty());
    ASSERT_EQ(_result.size(), expectedDistanceResults.size());
    for(auto it : _result){
        EXPECT_EQ(it->distance, expectedDistanceResults[count]);
        count++;
    }
}

TEST(GraphsTests, Dijkstra_ShortestPath_IncludeWeightedEdgeUsingHasMap){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    shared_ptr<Node> NodeObj_2 = make_shared<Node>();

    
    const int weightForEdgeFromNode1ToNode2 = 10;
    const vector<int> expectedDistanceResults = {0, weightForEdgeFromNode1ToNode2};

    NodeObj_1->includeWeightedEdge(2, weightForEdgeFromNode1ToNode2);

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 2);

    vector<std::shared_ptr<Node>> _result = GC.Dijkstra_ShortestPath();

    int count = 0;

    ASSERT_FALSE(_result.empty());
    ASSERT_EQ(_result.size(), expectedDistanceResults.size());
    for(auto it : _result){
        EXPECT_EQ(it->distance, expectedDistanceResults[count]);
        count++;
    }

    EXPECT_EQ(_result.at(0)->weightedEdges[2], weightForEdgeFromNode1ToNode2);
}

TEST(GraphsTests, Dijkstra_ShortestPath_3Nodes){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>();
    shared_ptr<Node> NodeObj_2 = make_shared<Node>();
    shared_ptr<Node> NodeObj_3 = make_shared<Node>();

    
    const int weightForEdgeFromNode1ToNode2 = 10;
    const int weightForEdgeFromNode1ToNode3 = 20;
    const vector<int> expectedDistanceResults = {
        0, 
        weightForEdgeFromNode1ToNode2, 
        weightForEdgeFromNode1ToNode3
    };

    NodeObj_1->includeWeightedEdge(2, weightForEdgeFromNode1ToNode2);
    NodeObj_1->includeWeightedEdge(3, weightForEdgeFromNode1ToNode3);

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);
    GC.includeNode(NodeObj_3);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 3);

    vector<std::shared_ptr<Node>> _result = GC.Dijkstra_ShortestPath();

    int count = 0;

    ASSERT_FALSE(_result.empty());
    ASSERT_EQ(_result.size(), expectedDistanceResults.size());
    for(auto it : _result){
        EXPECT_EQ(it->distance, expectedDistanceResults[count]);
        count++;
    }

    EXPECT_EQ(_result.at(0)->weightedEdges[2], weightForEdgeFromNode1ToNode2);
}

TEST(GraphsTests, Dijkstra_ShortestPath_Example_5_nodes){
    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>(); // A
    shared_ptr<Node> NodeObj_2 = make_shared<Node>(); // B
    shared_ptr<Node> NodeObj_3 = make_shared<Node>(); // C
    shared_ptr<Node> NodeObj_4 = make_shared<Node>(); // D
    shared_ptr<Node> NodeObj_5 = make_shared<Node>(); // E

    const int weightForEdgeFromNode1ToNode2 = 10; // A->B
    const int weightForEdgeFromNode1ToNode3 = 3;  // A->C
    const int weightForEdgeFromNode2ToNode3 = 1;  // B->C
    const int weightForEdgeFromNode2ToNode4 = 2;  // B->D
    const int weightForEdgeFromNode3ToNode2 = 4;  // C->B
    const int weightForEdgeFromNode3ToNode4 = 8;  // C->D
    const int weightForEdgeFromNode3ToNode5 = 2;  // C->E
    const int weightForEdgeFromNode4ToNode5 = 7;  // D->E
    const int weightForEdgeFromNode5ToNode4 = 9;  // E->D

    NodeObj_1->includeWeightedEdge(2, weightForEdgeFromNode1ToNode2);
    NodeObj_1->includeWeightedEdge(3, weightForEdgeFromNode1ToNode3);
    NodeObj_2->includeWeightedEdge(3, weightForEdgeFromNode2ToNode3);
    NodeObj_2->includeWeightedEdge(4, weightForEdgeFromNode2ToNode4);
    NodeObj_3->includeWeightedEdge(2, weightForEdgeFromNode3ToNode2);
    NodeObj_3->includeWeightedEdge(4, weightForEdgeFromNode3ToNode4);
    NodeObj_3->includeWeightedEdge(5, weightForEdgeFromNode3ToNode5);
    NodeObj_4->includeWeightedEdge(5, weightForEdgeFromNode4ToNode5);
    NodeObj_5->includeWeightedEdge(4, weightForEdgeFromNode5ToNode4);

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);
    GC.includeNode(NodeObj_3);
    GC.includeNode(NodeObj_4);
    GC.includeNode(NodeObj_5);

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 5);

    vector<std::shared_ptr<Node>> _result = GC.Dijkstra_ShortestPath();
    ASSERT_FALSE(_result.empty());

    const vector<int> expetedResultVectorIDsAscOrder = {1, 3, 5, 2, 4};

    int count = 0;
    for(auto res : _result){
        EXPECT_EQ(res->getId(), expetedResultVectorIDsAscOrder[count]);
        count++;
    }
}

TEST(GraphsTests, Bellman_Ford_ShortestPath_PassingEmptyGraph){

    GraphsClass GC;

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 0);

    vector<std::shared_ptr<Node>> _result = GC.Bellman_Ford_ShortestPath();
    ASSERT_TRUE(_result.empty());
}

TEST(GraphsTests, Bellman_Ford_ShortestPath_1EmptyNode){

    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>(); // A

    GC.includeNode(NodeObj_1);

    const vector<int> expetedResultVectorIDsAscOrder = {1};
    const vector<int> expetedResultDistances = {0};

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 1);

    vector<std::shared_ptr<Node>> _result = GC.Bellman_Ford_ShortestPath();
    ASSERT_FALSE(_result.empty());

    int count = 0;
    for(auto res : _result){
        EXPECT_EQ(res->getId(), expetedResultVectorIDsAscOrder[count]);
        EXPECT_EQ(res->distance, expetedResultDistances[count]);
        count++;
    }
}

TEST(GraphsTests, Bellman_Ford_ShortestPath_2Nodes_1Edge){

    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>(); // A
    shared_ptr<Node> NodeObj_2 = make_shared<Node>(); // B

    const int weightForEdgeFromNode1ToNode2 = 1; // A->B

    NodeObj_1->includeWeightedEdge(2, weightForEdgeFromNode1ToNode2);

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);

    const vector<int> expetedResultVectorIDsAscOrder = {1, 2};
    const vector<int> expetedResultDistances = {0, 1};

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 2);

    vector<std::shared_ptr<Node>> _result = GC.Bellman_Ford_ShortestPath();
    ASSERT_FALSE(_result.empty());

    int count = 0;
    for(auto res : _result){
        EXPECT_EQ(res->getId(), expetedResultVectorIDsAscOrder[count]);
        EXPECT_EQ(res->distance, expetedResultDistances[count]);
        count++;
    }
}


TEST(GraphsTests, Bellman_Ford_ShortestPath_NegativeCycle){

    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>(); // A
    shared_ptr<Node> NodeObj_2 = make_shared<Node>(); // B
    shared_ptr<Node> NodeObj_3 = make_shared<Node>(); // C
    shared_ptr<Node> NodeObj_4 = make_shared<Node>(); // D
    shared_ptr<Node> NodeObj_5 = make_shared<Node>(); // E
    shared_ptr<Node> NodeObj_6 = make_shared<Node>(); // F

    const int weightForEdgeFromNode1ToNode2 = 5;  // A->B
    const int weightForEdgeFromNode2ToNode3 = 1;  // B->C
    const int weightForEdgeFromNode2ToNode4 = 2;  // B->D
    const int weightForEdgeFromNode3ToNode5 = 1;  // C->E
    const int weightForEdgeFromNode4ToNode6 = 2;  // D->F
    const int weightForEdgeFromNode5ToNode4 = -1; // E->D
    const int weightForEdgeFromNode6ToNode5 = -3; // F->E

    NodeObj_1->includeWeightedEdge(2, weightForEdgeFromNode1ToNode2);
    NodeObj_2->includeWeightedEdge(3, weightForEdgeFromNode2ToNode3);
    NodeObj_2->includeWeightedEdge(4, weightForEdgeFromNode2ToNode4);
    NodeObj_3->includeWeightedEdge(5, weightForEdgeFromNode3ToNode5);
    NodeObj_4->includeWeightedEdge(6, weightForEdgeFromNode4ToNode6);
    NodeObj_5->includeWeightedEdge(4, weightForEdgeFromNode5ToNode4);
    NodeObj_6->includeWeightedEdge(5, weightForEdgeFromNode6ToNode5);

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);
    GC.includeNode(NodeObj_3);
    GC.includeNode(NodeObj_4);
    GC.includeNode(NodeObj_5);
    GC.includeNode(NodeObj_6);

    const vector<int> expetedResultVectorIDsAscOrder = {1, 2, 3, 4, 5, 6};
    const vector<int> expetedResultDistances = {0, 0, 0, 0, 0, 0};

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 6);

    vector<std::shared_ptr<Node>> _result = GC.Bellman_Ford_ShortestPath();
    ASSERT_TRUE(_result.empty());
}

TEST(GraphsTests, Bellman_Ford_ShortestPath_AnotherNegativeExample){

    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>(); // A
    shared_ptr<Node> NodeObj_2 = make_shared<Node>(); // B
    shared_ptr<Node> NodeObj_3 = make_shared<Node>(); // C
    shared_ptr<Node> NodeObj_4 = make_shared<Node>(); // D
    shared_ptr<Node> NodeObj_5 = make_shared<Node>(); // E

    const int weightForEdgeFromNode1ToNode2 = 2;  // A->B
    const int weightForEdgeFromNode2ToNode3 = 2;  // B->C
    const int weightForEdgeFromNode2ToNode4 = 1;  // B->D
    const int weightForEdgeFromNode3ToNode4 = -4; // C->D
    const int weightForEdgeFromNode4ToNode2 = 1;  // D->B
    const int weightForEdgeFromNode4ToNode5 = 3;  // D->E

    NodeObj_1->includeWeightedEdge(2, weightForEdgeFromNode1ToNode2);
    NodeObj_2->includeWeightedEdge(3, weightForEdgeFromNode2ToNode3);
    NodeObj_2->includeWeightedEdge(4, weightForEdgeFromNode2ToNode4);
    NodeObj_3->includeWeightedEdge(4, weightForEdgeFromNode3ToNode4);
    NodeObj_4->includeWeightedEdge(2, weightForEdgeFromNode4ToNode2);
    NodeObj_5->includeWeightedEdge(5, weightForEdgeFromNode4ToNode5);

    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);
    GC.includeNode(NodeObj_3);
    GC.includeNode(NodeObj_4);
    GC.includeNode(NodeObj_5);

    const vector<int> expetedResultVectorIDsAscOrder = {1, 2, 3, 4, 5};
    const vector<int> expetedResultDistances = {0, 3, 2, 1, 6};

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 5);

    vector<std::shared_ptr<Node>> _result = GC.Bellman_Ford_ShortestPath();
    ASSERT_TRUE(_result.empty());
}

TEST(GraphsTests, Bellman_Ford_ShortestPath_WorkingExample){

    GraphsClass GC;
    shared_ptr<Node> NodeObj_1 = make_shared<Node>(); // A
    shared_ptr<Node> NodeObj_2 = make_shared<Node>(); // B
    shared_ptr<Node> NodeObj_3 = make_shared<Node>(); // C
    shared_ptr<Node> NodeObj_4 = make_shared<Node>(); // D
    shared_ptr<Node> NodeObj_5 = make_shared<Node>(); // E

    const int weightForEdgeFromNode1ToNode2 = 4;  // A->B
    const int weightForEdgeFromNode1ToNode3 = 2;  // A->C
    const int weightForEdgeFromNode2ToNode3 = 3;  // B->C
    const int weightForEdgeFromNode2ToNode4 = 2;  // B->D
    const int weightForEdgeFromNode2ToNode5 = 3;  // B->E
    const int weightForEdgeFromNode3ToNode2 = 1;  // C->B
    const int weightForEdgeFromNode3ToNode4 = 4;  // C->D
    const int weightForEdgeFromNode3ToNode5 = 5;  // C->E
    const int weightForEdgeFromNode5ToNode4 = -5; // E->D

    NodeObj_1->includeWeightedEdge(2, weightForEdgeFromNode1ToNode2);
    NodeObj_1->includeWeightedEdge(3, weightForEdgeFromNode1ToNode3);
    NodeObj_2->includeWeightedEdge(3, weightForEdgeFromNode2ToNode3);
    NodeObj_2->includeWeightedEdge(4, weightForEdgeFromNode2ToNode4);
    NodeObj_2->includeWeightedEdge(5, weightForEdgeFromNode2ToNode5);
    NodeObj_3->includeWeightedEdge(2, weightForEdgeFromNode3ToNode2);
    NodeObj_3->includeWeightedEdge(4, weightForEdgeFromNode3ToNode4);
    NodeObj_3->includeWeightedEdge(5, weightForEdgeFromNode3ToNode5);
    NodeObj_5->includeWeightedEdge(4, weightForEdgeFromNode5ToNode4);


    GC.includeNode(NodeObj_1);
    GC.includeNode(NodeObj_2);
    GC.includeNode(NodeObj_3);
    GC.includeNode(NodeObj_4);
    GC.includeNode(NodeObj_5);

    const vector<int> expetedResultVectorIDsAscOrder = {1, 2, 3, 4, 5};
    const vector<int> expetedResultDistances = {0, 3, 2, 1, 6};

    std::vector<std::pair<std::shared_ptr<Node>, std::vector<int>>> graph = GC.getGraphAsVector();
    ASSERT_EQ(graph.size(), 5);

    vector<std::shared_ptr<Node>> _result = GC.Bellman_Ford_ShortestPath();
    ASSERT_FALSE(_result.empty());

    int count = 0;
    for(auto res : _result){
        EXPECT_EQ(res->getId(), expetedResultVectorIDsAscOrder[count]);
        EXPECT_EQ(res->distance, expetedResultDistances[count]);
        count++;
    }
}


//