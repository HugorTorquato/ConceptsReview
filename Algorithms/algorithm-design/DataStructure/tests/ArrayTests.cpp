#include <gtest/gtest.h>

#include "Array.h"


TEST(ArrayTest, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}

TEST(ArrayTest, SimlpleAssertion2) {
  EXPECT_EQ(1, 1);
}

TEST(ArrayTest, SimpleAddToVerifyIfCanAccessTheLib) {
  ArrayClass arrayClass;
  EXPECT_EQ(arrayClass.add(2,2), 4);
}

TEST(ArrayTest, ArrayMemberFunctionsSize){
    ArrayClass arrayClass;

    std::array<int, 4> arr = {1, 2, 3, 4};

    EXPECT_EQ(arrayClass.returnSizeOfTheArray(arr), 4);

}

TEST(ArrayTest, ArrayMemberFunctionsData){
    ArrayClass arrayClass;

    std::array<int, 4> arr = {1, 2, 3, 4};
    int position = 2;

    EXPECT_EQ(arrayClass.returThePointerUsingeData(arr, position), 3);

}

TEST(ArrayTest, InvertAnArrayTest){

    ArrayClass arrayClass;

    std::array<int, 4> arr = {1, 2, 3, 4};
    std::array<int, 4> arrInv = {4, 3, 2, 1};

    EXPECT_EQ(arrayClass.invertTheArray(arr), arrInv);

}

TEST(ArrayTest, SwapTwoArraysTest){

    ArrayClass arrayClass;

    std::array<int, 4> arr1 = {1, 2, 3, 4};
    std::array<int, 4> arr2 = {4, 3, 2, 1};

    EXPECT_EQ(arrayClass.SwapTwoArrays(arr2, arr1), arr1);

}