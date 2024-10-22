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
    BTreeVertice BTV2;

    //Remember to use reference here &

    BTV.setValue(1);
    BTV.setRoot(&BTV2);
    BTV.setRightChild(&BTV2);
    BTV.setLeftChild(&BTV2);

    ASSERT_EQ(BTV.getValue(), 1);
    ASSERT_EQ(BTV.getRoot(), &BTV2);
    ASSERT_EQ(BTV.getRightChild(), &BTV2);
    ASSERT_EQ(BTV.getLeftChild(), &BTV2);
}


TEST(BTreesClassTests, retrieveVrticeFromEmptyBTree){
    BTreesClass BTClass;

    EXPECT_EQ(BTClass.getBTreeVerticeFromKey("A"), nullptr);
}

TEST(BTreesClassTests, insertVrticeInEmptyBTreeAndRetreaveItsValue){
    BTreesClass BTClass;

    const int valueToAddInNode = 1;
    const std::string keyToAddInNode = "A";
    
    // Vou ter de pedir os dados de root, e 
    // root is an optional value here

    BTClass.includeVerticeInBTree(keyToAddInNode, valueToAddInNode);

    BTreeVertice* vertice = BTClass.getBTreeVerticeFromKey(keyToAddInNode);

    ASSERT_TRUE(vertice != nullptr);
    EXPECT_EQ(vertice->getValue(), valueToAddInNode);

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
