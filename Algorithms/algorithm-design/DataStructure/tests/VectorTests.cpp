#include <gtest/gtest.h>

#include "Vectors.h"

TEST(VectorTest, SimlpleAssertion2222) {
  EXPECT_EQ(1, 1);
}


/*
Create a class called DynamicStack that implements a
 stack data structure using an std::vector. A stack follows 
 the Last-In-First-Out (LIFO) principle, meaning the last 
 element added is the first one to be removed.

 */
TEST(VectorTest, getFifoStackInitializedEmpty) {

    DynamicStack vectorToTest;

    std::vector<int> emptyVector = std::vector<int>();

    EXPECT_EQ(vectorToTest.getFifoStack(), emptyVector);

}

TEST(VectorTest, verifyIfTheVectorIsEmpty) {

    DynamicStack vectorToTest;

    EXPECT_TRUE(vectorToTest.isVectorEmty());

}

TEST(VectorTest, verifyIfTheVectorIsNotEmpty) {

    DynamicStack vectorToTest;

    const int elementoToIncludeAndExclude = 0;
    vectorToTest.IncludeElementIntoTheStack(elementoToIncludeAndExclude);


    EXPECT_FALSE(vectorToTest.isVectorEmty());

}

TEST(VectorTest, assertAnElementWithinTheVector) {

    DynamicStack vectorToTest;

    vectorToTest.IncludeElementIntoTheStack(10);
    vectorToTest.IncludeElementIntoTheStack(11);
    vectorToTest.IncludeElementIntoTheStack(12);

    std::vector<int> vectorUnderTest = vectorToTest.getFifoStack();

    EXPECT_EQ(vectorUnderTest[1], 11);

}

TEST(VectorTest, IncludeElementZeroToTheStack) {

    DynamicStack vectorToTest;

    const int elementoToInclude = 0;

    std::vector<int> vectorWithOnElementZero = {elementoToInclude};

    vectorToTest.IncludeElementIntoTheStack(elementoToInclude);

    EXPECT_EQ(vectorToTest.getFifoStack(), vectorWithOnElementZero);

}

TEST(VectorTest, IncludeAndRemoveElementZeroToTheStackWithPopBack) {

    DynamicStack vectorToTest;

    const int elementoToIncludeAndExclude = 0;

    std::vector<int> vectorWithOnElementZero = {elementoToIncludeAndExclude};
    std::vector<int> emptyVector = std::vector<int>();

    vectorToTest.IncludeElementIntoTheStack(elementoToIncludeAndExclude);

    EXPECT_EQ(vectorToTest.getFifoStack(), vectorWithOnElementZero);

    vectorToTest.ElementFromTheStackWithPopBack();

    EXPECT_EQ(vectorToTest.getFifoStack(), emptyVector);

}

TEST(VectorTest, IncludeAndRemoveElementZeroToTheStackWithErase) {

    DynamicStack vectorToTest;

    const int elementoToIncludeAndExclude = 0;

    std::vector<int> vectorWithOnElementZero = {elementoToIncludeAndExclude};
    std::vector<int> emptyVector = std::vector<int>();

    vectorToTest.IncludeElementIntoTheStack(elementoToIncludeAndExclude);

    EXPECT_EQ(vectorToTest.getFifoStack(), vectorWithOnElementZero);

    vectorToTest.ElementFromTheStackWithErase();

    EXPECT_EQ(vectorToTest.getFifoStack(), emptyVector);

}