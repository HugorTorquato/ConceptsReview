#include "Array.h"
#include <gtest/gtest.h>


TEST(ArrayTest, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}

TEST(ArrayTest, SimlpleAssertion2) {
  EXPECT_EQ(1, 1);
}

TEST(ArrayTest, SimpleAddToVerifyIfCanAccessTheLib) {
  Calculations calc;
  EXPECT_EQ(calc.add(2,2), 4);
}
