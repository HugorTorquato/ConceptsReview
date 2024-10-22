#include <gtest/gtest.h>

#include "Trees.h"

TEST(TreesTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(TreesTests, simpleMethodReturning1){
    TreesClass TT;

    EXPECT_EQ(TT.return1ToTest(), 1);
}

// --------------------------------------------------------
