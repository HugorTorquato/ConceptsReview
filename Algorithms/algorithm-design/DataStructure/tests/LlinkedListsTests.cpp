#include <gtest/gtest.h>

#include "LlinkedLists.h"

TEST(LinkedListsTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(LinkedListsTests, simpleMethodReturning1){

    LinkedListsClass LLT;

    EXPECT_EQ(LLT.return1ToTest(), 1);
}

