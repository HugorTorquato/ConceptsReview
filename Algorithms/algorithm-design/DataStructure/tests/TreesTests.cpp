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
