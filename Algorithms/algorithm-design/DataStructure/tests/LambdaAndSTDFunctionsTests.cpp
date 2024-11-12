#include <gtest/gtest.h>

#include "LambdaAndSTDFunctions.h"

TEST(LambdaAndSTDFunctionsTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(LambdaAndSTDFunctionsTests, simpleMethodReturning1){

    LambdaAndSTDFunctionsClass LSTDF;

    EXPECT_EQ(LSTDF.return1ToTest(), 1);
}

// --------------------------------------------------------

TEST(LambdaAndSTDFunctionsTests, incrementDataByOne){
    LambdaAndSTDFunctionsClass LSTDF;

    LSTDF.data = 1;

    // Overengineering
    LSTDF.incrementData(1);

    EXPECT_EQ(LSTDF.data, 2);

}

TEST(LambdaAndSTDFunctionsTests, useLambdaInAStdFunctionMethod_AddOperator){

    LambdaAndSTDFunctionsClass LSTDF;

    auto add_operator = [] (const int &a, const int &b) {
        return a + b;
    };

    const int result = LSTDF.operationBetweenTwoIntegers(2, 3, add_operator);

    EXPECT_EQ(result, 5);
}

TEST(LambdaAndSTDFunctionsTests, useLambdaInAStdFunctionMethod_SubOperator){

    LambdaAndSTDFunctionsClass LSTDF;

    auto sub_operator = [] (const int &a, const int &b) {
        return a - b;
    };

    const int result = LSTDF.operationBetweenTwoIntegers(3, 2, sub_operator);

    EXPECT_EQ(result, 1);
}

TEST(LambdaAndSTDFunctionsTests, useLambdaInAStdFunctionMethod_TimesOperator){

    LambdaAndSTDFunctionsClass LSTDF;

    auto times_operator = [] (const int &a, const int &b) {
        return a * b;
    };

    const int result = LSTDF.operationBetweenTwoIntegers(3, 2, times_operator);

    EXPECT_EQ(result, 6);
}

TEST(LambdaAndSTDFunctionsTests, useLambdaInAStdFunctionMethod_DependingOnAnObjectProperty_AddOperator){

    LambdaAndSTDFunctionsClass LSTDF;

    LSTDF.data = 1;

    auto add_operator = [LSTDF] (const int &b) {
        return LSTDF.data + b;
    };

    const int result = LSTDF.operationBetweenObjPropAndOneIntegers(2, add_operator);

    EXPECT_EQ(result, 3);
}

TEST(LambdaAndSTDFunctionsTests, useLambdaInAStdFunctionMethod_DependingOnAnObjectPropertyByRef_AddOperator){

    LambdaAndSTDFunctionsClass LSTDF;

    LSTDF.data = 1;

    auto add_operator = [&LSTDF] (const int &b) {
        return LSTDF.data += b;
    };

    const int result = LSTDF.operationBetweenObjPropAndOneIntegers(2, add_operator);

    EXPECT_EQ(LSTDF.data, 3);
}