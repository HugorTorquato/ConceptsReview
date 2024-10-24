#include <gtest/gtest.h>

#include "Graphs.h"

TEST(GraphsTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(GraphsTests, simpleMethodReturning1){
    GraphsClass GC;

    EXPECT_EQ(GC.return1ToTest(), 1);
}
