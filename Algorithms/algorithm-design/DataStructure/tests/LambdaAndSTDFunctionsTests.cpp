#include <gtest/gtest.h>

#include "LambdaAndSTDFunctions.h"

TEST(LambdaAndSTDFunctionsTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(LambdaAndSTDFunctionsTests, simpleMethodReturning1){

    HLambdaAndSTDFunctionsClass LSTDF;

    EXPECT_EQ(LSTDF.return1ToTest(), 1);
}

// --------------------------------------------------------