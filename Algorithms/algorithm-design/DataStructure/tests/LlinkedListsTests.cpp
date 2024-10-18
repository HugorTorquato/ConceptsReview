#include <gtest/gtest.h>

#include "LlinkedLists.h"

TEST(LinkedListsTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(LinkedListsTests, simpleMethodReturning1){

    LinkedListsClass LLT;

    EXPECT_EQ(LLT.return1ToTest(), 1);
}

// --------------------------------------------------------

TEST(LinkedListsTests, retrieveInitializedHeaderNodeWithNoInformation){

    LinkedListsClass llc;

    Node* _node = llc.retrieveHeadNode();

    EXPECT_EQ(_node->data, NULL);
    EXPECT_EQ(_node->next, nullptr);

}

TEST(LinkedListsTests, createNewNodeAndPlaceThisValueAtTheHeader){

    LinkedListsClass llc;

    llc.inculdeNewNodeAtTheEndOfTheList(1);
    Node* _node = llc.retrieveHeadNode();

    EXPECT_EQ(_node->data, 1);
}

TEST(LinkedListsTests, retrieveNodeBasedOnGivenPosition_EmptyList){
    LinkedListsClass llc;

    Node* _node = llc.retrieveNodeBasedOnGivenPosition(1);

    EXPECT_EQ(_node, nullptr);
}

TEST(LinkedListsTests, retrieveNodeBasedOnGivenPosition_OutsideTheListSize){
    LinkedListsClass llc;

    llc.inculdeNewNodeAtTheEndOfTheList(1); 
    Node* _node = llc.retrieveNodeBasedOnGivenPosition(5);

    EXPECT_EQ(_node, nullptr);
}

TEST(LinkedListsTests, retrieveNodeBasedOnGivenPosition_FirstPosition){
    LinkedListsClass llc;

    llc.inculdeNewNodeAtTheEndOfTheList(1);
    Node* _node = llc.retrieveNodeBasedOnGivenPosition(1);

    EXPECT_EQ(_node->data, 1);
}

TEST(LinkedListsTests, createNewNodeAndPlaceThisValueAtTheSecondNode){

    LinkedListsClass llc;

    llc.inculdeNewNodeAtTheEndOfTheList(1);
    llc.inculdeNewNodeAtTheEndOfTheList(10);

    EXPECT_EQ(llc.retrieveNodeBasedOnGivenPosition(2)->data, 10);
}

TEST(LinkedListsTests, asserLinkedListValues_WithSizeAs3){
    LinkedListsClass llc;

    std::vector<int> expectLLValues = {10, 20, 30};

    llc.inculdeNewNodeAtTheEndOfTheList(10);
    llc.inculdeNewNodeAtTheEndOfTheList(20);
    llc.inculdeNewNodeAtTheEndOfTheList(30);

    EXPECT_EQ(llc.retrieveLLValuesAsIntegerVactor(), expectLLValues);
}

TEST(LinkedListsTests, createFiveNewNodesAndAssertTheValues){

    LinkedListsClass llc;

    llc.inculdeNewNodeAtTheEndOfTheList(10);
    llc.inculdeNewNodeAtTheEndOfTheList(20);
    llc.inculdeNewNodeAtTheEndOfTheList(30);
    llc.inculdeNewNodeAtTheEndOfTheList(40);
    llc.inculdeNewNodeAtTheEndOfTheList(50);

    ASSERT_EQ(llc.retrieveNodeBasedOnGivenPosition(1)->data, 10);
    ASSERT_EQ(llc.retrieveNodeBasedOnGivenPosition(2)->data, 20);
    ASSERT_EQ(llc.retrieveNodeBasedOnGivenPosition(3)->data, 30);
    ASSERT_EQ(llc.retrieveNodeBasedOnGivenPosition(4)->data, 40);
    ASSERT_EQ(llc.retrieveNodeBasedOnGivenPosition(5)->data, 50);
}


