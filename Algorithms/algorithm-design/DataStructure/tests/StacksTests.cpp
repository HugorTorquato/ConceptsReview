#include <gtest/gtest.h>

#include "Stacks.h"

TEST(StacksTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(StacksTests, simpleMethodReturning1){

    StackClass ST;

    EXPECT_EQ(ST.return1ToTest(), 1);
}

// --------------------------------------------------------