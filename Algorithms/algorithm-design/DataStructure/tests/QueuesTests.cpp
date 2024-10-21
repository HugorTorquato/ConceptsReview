#include <gtest/gtest.h>

#include "Queues.h"

TEST(QueuesTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(QueuesTests, simpleMethodReturning1){

    QueueClass QT;

    EXPECT_EQ(QT.return1ToTest(), 1);
}

// --------------------------------------------------------

// Verify empty queue
TEST(QueuesTests, verfyEmptyQueue){
    QueueClass QC;

    EXPECT_TRUE(QC.getQueue().empty());
}

TEST(QueuesTests, verfyEmptyQueueSizeEqualsZero){
    QueueClass QC;

    EXPECT_EQ(QC.getQueue().size(), 0);
}

TEST(QueuesTests, verfyQueueSizeEqualsTwo){
    QueueClass QC;

    QC.addElement(10);
    QC.addElement(20);

    EXPECT_EQ(QC.getQueue().size(), 2);
}

// Add element to queue
TEST(QueuesTests, addElemenToQueue){
    QueueClass QC;
    const int elementToAddTotQueue = 10;

    QC.addElement(elementToAddTotQueue);

    EXPECT_EQ(QC.getQueue().front(), elementToAddTotQueue);

}

// Remove element from empty queue
TEST(QueuesTests, removeElementFromEmptyQueue){
    QueueClass QC;

    QC.removeElement(); 
    // Queue only remove elements from the front
    // DQueue allows the developer to remove from the back as well

    EXPECT_TRUE(QC.getQueue().empty());

}

// Remove element from queue
TEST(QueuesTests, removeElementFromQueue){
    QueueClass QC;
    std::queue<int> expectedOutput;

    expectedOutput.push(20);
    expectedOutput.push(30);

    QC.addElement(10); // Element that will be removed
    QC.addElement(20);
    QC.addElement(30);

    QC.removeElement(); 
    // Queue only remove elements from the front
    // DQueue allows the developer to remove from the back as well

    ASSERT_EQ(QC.getQueue().size(), expectedOutput.size());
    ASSERT_EQ(QC.getQueue().front(), expectedOutput.front());
    ASSERT_EQ(QC.getQueue().back(), expectedOutput.back());
}

// Get the Front // back element of a queue
TEST(QueuesTests, retrieveTheFrontAndBackElementOfAQueue){
    QueueClass QC;

    QC.addElement(10); // Front element
    QC.addElement(20);
    QC.addElement(30); // Back element

    ASSERT_EQ(QC.getQueue().front(), 10);
    ASSERT_EQ(QC.getQueue().back(), 30);

}

// Change value of the front // back element of a queue
TEST(QueuesTests, updateTheFrontAndBackElementOfAQueue){
    QueueClass QC;
    const int elementToUpdateTheFrontElementTo = 11;
    const int elementToUpdateTheBackElementTo = 33;

    QC.addElement(10); // Front element
    QC.addElement(20);
    QC.addElement(30); // Back element

    QC.updateFrontElementTo(elementToUpdateTheFrontElementTo);
    QC.updateBackElementTo(elementToUpdateTheBackElementTo);

    ASSERT_EQ(QC.getQueue().front(), 11);
    ASSERT_EQ(QC.getQueue().back(), 33);

}

// Remove any element of a queue and come back with the same order

TEST(QueuesTests, removeElementInTheMiddleOfAQueue){

    QueueClass QC;

    const int elementIndexToRemove = 2;

    QC.addElement(10); // Front
    QC.addElement(20);
    QC.addElement(30);
    QC.addElement(40); // Back

    QC.removeElement(2);

    ASSERT_EQ(QC.getQueue().front(), 10);
    ASSERT_EQ(QC.getQueue().back(), 40);
    ASSERT_EQ(QC.getQueue().size(), 3);  

}