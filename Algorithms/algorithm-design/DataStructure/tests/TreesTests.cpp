#include <gtest/gtest.h>

#include "Trees.h"

TEST(TreesTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(TreesTests, simpleMethodReturning1){
    BTreesClass TT;

    EXPECT_EQ(TT.return1ToTest(), 1);
}

// --------------------------------------------------------



// ----- Representation of a Binary Tree
// Nodes have at most two children (left and right).
TEST(BTreeVerticeTests, retrieveEmptyBTreeVerticeAfterInitialization){
    BTreeVertice BTV;
    
    ASSERT_EQ(BTV.getValue(), 0);
    ASSERT_EQ(BTV.getRoot(), nullptr);
    ASSERT_EQ(BTV.getRightChild(), nullptr);
    ASSERT_EQ(BTV.getLeftChild(), nullptr);
}

TEST(BTreeVerticeTests, setValuesForBTreeVerticeAfterInitialization){

    BTreeVertice BTV;

    //Remember to use reference here &

    BTV.setValue(1);

    ASSERT_EQ(BTV.getValue(), 1);
}


TEST(BTreesClassTests, retrieveVrticeFromEmptyBTree){
    BTreesClass BTClass;

    EXPECT_EQ(BTClass.getBTreeVerticeFromKey("A"), nullptr);
}

TEST(BTreesClassTests, insertVrticeInEmptyBTreeAndRetreaveItsValue){
    BTreesClass BTClass;

    const int valueToAddInNode = 1;
    const std::string keyToAddInNode = "A";

    BTClass.includeVerticeInBTree(keyToAddInNode, valueToAddInNode);

    std::shared_ptr<BTreeVertice> vertice = BTClass.getBTreeVerticeFromKey(keyToAddInNode);

    ASSERT_TRUE(vertice != nullptr);
    EXPECT_EQ(vertice->getValue(), valueToAddInNode);

}

TEST(BTreesClassTests, updateValueInVrticeInEmptyBTreeAndRetreaveItsValue){
    BTreesClass BTClass;

    const int valueToAddInNode = 1;
    const int valueToAddInNode2 = 3;
    const std::string keyToAddInNode = "A";

    BTClass.includeVerticeInBTree(keyToAddInNode, valueToAddInNode);
    BTClass.includeVerticeInBTree(keyToAddInNode, valueToAddInNode2);

    std::shared_ptr<BTreeVertice> vertice = BTClass.getBTreeVerticeFromKey(keyToAddInNode);

    ASSERT_TRUE(vertice != nullptr);
    EXPECT_EQ(vertice->getValue(), valueToAddInNode2);

}

// Find a way to populate the rightChild and leftChild


        //I can populate it with the Vertice itself and not parameter by parameter

TEST(BTreesClassTests, initializeVerticeUsingConstructor) {
    //BTreeVertice* BTC = new BTreeVertice(5);
    std::shared_ptr<BTreeVertice> BTC = std::make_shared<BTreeVertice>(5);
    ASSERT_TRUE(BTC->getValue() == 5);
}

TEST(BTreesClassTests, includeVerticeInEmptuTree_AllocateAtRootPosition) {

    const int rootDataToStore = 5;

    //BTreeVertice* BTC = new BTreeVertice(5);
    std::shared_ptr<BTreeVertice> BTV = std::make_shared<BTreeVertice>(rootDataToStore);
    BTreesClass BTC; 

    ASSERT_TRUE(BTV->getValue() == rootDataToStore);
    ASSERT_TRUE(BTV->getRightChild() == nullptr);
    ASSERT_TRUE(BTV->getLeftChild() == nullptr);
    
    BTC.includeVerticeAtTree(BTV);
    
    ASSERT_TRUE(BTC.getNumberOfNodes() == 1);
    EXPECT_EQ(BTC.getRootVertice()->getValue(), rootDataToStore);    
    EXPECT_EQ(BTC.getRootVertice()->getLeftChild(), nullptr);    
    EXPECT_EQ(BTC.getRootVertice()->getRightChild(), nullptr);    
}


TEST(BTreesClassTests, introduceTheBTreeVerticeAsParameters_3NewVertices) {

    std::shared_ptr<BTreeVertice> BTV1 = std::make_shared<BTreeVertice>(10);
    std::shared_ptr<BTreeVertice> BTV2 = std::make_shared<BTreeVertice>(11);
    std::shared_ptr<BTreeVertice> BTV3 = std::make_shared<BTreeVertice>(12);

    BTreesClass BTC;
    
    //If i want to specify the tree.... not right now
    //BTV1->setLeftChild(BTV3);
    //BTV1->setRightChild(BTV2);

    /*
        BTC1
        /  \
    BTC3   BTC2
    */


    BTC.includeVerticeAtTree(BTV1);
    BTC.includeVerticeAtTree(BTV2);
    BTC.includeVerticeAtTree(BTV3);

    EXPECT_EQ(BTC.getRootVertice()->getValue(), BTV1->getValue());  
    EXPECT_EQ(BTC.getNumberOfNodes(), 3);
    EXPECT_EQ(BTC.getRootVertice()->getLeftChild()->getValue(),  BTV2->getValue());  
    EXPECT_EQ(BTC.getRootVertice()->getRightChild()->getValue(), BTV3->getValue());  

}

TEST(BTreesClassTests, introduceTheBTreeVerticeAsParameters_4NewVertices) {

    std::shared_ptr<BTreeVertice> BTV1 = std::make_shared<BTreeVertice>(10);
    std::shared_ptr<BTreeVertice> BTV2 = std::make_shared<BTreeVertice>(11);
    std::shared_ptr<BTreeVertice> BTV3 = std::make_shared<BTreeVertice>(12);
    std::shared_ptr<BTreeVertice> BTV4 = std::make_shared<BTreeVertice>(13);

    BTreesClass BTC;
    
    //If i want to specify the tree.... not right now
    //BTV1->setLeftChild(BTV3);
    //BTV1->setRightChild(BTV2);

    /*
            BTC1
            /  \
        BTC3   BTC2
        /
    BTC4
    */


    BTC.includeVerticeAtTree(BTV1);
    BTC.includeVerticeAtTree(BTV2);
    BTC.includeVerticeAtTree(BTV3);
    BTC.includeVerticeAtTree(BTV4);

    EXPECT_EQ(BTC.getRootVertice()->getValue(), BTV1->getValue());  
    EXPECT_EQ(BTC.getNumberOfNodes(), 4);

    std::shared_ptr<BTreeVertice> rootVertice = BTC.getRootVertice();

    EXPECT_EQ(rootVertice->getLeftChild()->getValue(),  BTV2->getValue());  
    EXPECT_EQ(rootVertice->getRightChild()->getValue(), BTV3->getValue());  
    EXPECT_EQ(rootVertice->getLeftChild()->getLeftChild()->getValue(),  BTV4->getValue());  
}

TEST(BTreesClassTests, deleteNodeFromEmptyTree) {
    BTreesClass BTC; 

    const int verticeValueToDelete = 1;

    BTC.deleteVerticeAtTree(verticeValueToDelete);

    ASSERT_TRUE(BTC.getNumberOfNodes() == 0);
}

TEST(BTreesClassTests, deleteOnlyNodeFromATreeBasedOnItsValue) {

    const int rootDataToStore = 5;

    //BTreeVertice* BTC = new BTreeVertice(5);
    std::shared_ptr<BTreeVertice> BTV = std::make_shared<BTreeVertice>(rootDataToStore);
    BTreesClass BTC; 

    ASSERT_TRUE(BTV->getValue() == rootDataToStore);
    
    BTC.includeVerticeAtTree(BTV);
    
    ASSERT_TRUE(BTC.getNumberOfNodes() == 1);
    ASSERT_EQ(BTC.getRootVertice()->getValue(), rootDataToStore);  

    BTC.deleteVerticeAtTree(rootDataToStore);
    
    ASSERT_TRUE(BTC.getNumberOfNodes() == 0);
    ASSERT_EQ(BTC.getRootVertice(), nullptr);  
}


// ----- Representation of a N-ary Tree
/*
Each node can have up to N children, 
and we often use vectors to store the children.
*/



// ----- Representation of a Binary Search Tree (BST)

/*
A specialized binary tree where the left 
subtree contains values less than the root,
and the right subtree contains values greater 
than the root.
*/
