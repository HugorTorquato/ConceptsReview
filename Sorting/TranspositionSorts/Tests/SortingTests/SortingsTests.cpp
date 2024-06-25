#include "gtest/gtest.h"
#include "../../Sortings.h"

TEST(FirstTests, compareNumberWithFirstGreater) {
    int num1 = 2;
    int num2 = 1;

   EXPECT_EQ(Sortings::compareNumbers(num1, num2), 1);
}

TEST(FirstTests, compareNumberWithSecondGreater) {
    int num1 = 1;
    int num2 = 2;

    EXPECT_EQ(Sortings::compareNumbers(num1, num2), -1);
}
TEST(FirstTests, compareEqualNumber) {
    int num1 = 2;
    int num2 = 2;

    EXPECT_EQ(Sortings::compareNumbers(num1, num2), 0);
}


TEST(FirstTests, swapTwoNumberOnIntegerListPointer) {

    int integerListToSwap[] = { 0, 1, 3, 2 };
    int integerListToAssert[] = { 0, 1, 2, 3 };

    // It returns a pointer to the modified integerListToSwap.
    Sortings::swapValuesPointer(integerListToSwap, 2, 3);

    int size = sizeof(integerListToSwap) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSwap[i], integerListToAssert[i]);
    }
}

TEST(FirstTests, swapTwoNumberOnIntegerListReference) {

    int integerListToSwap[] = { 0, 1, 3, 2 };
    int integerListToAssert[] = { 0, 1, 2, 3 };

    // It returns a pointer to the modified integerListToSwap.
    Sortings::swapValuesReference(integerListToSwap, 2, 3);

    int size = sizeof(integerListToSwap) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSwap[i], integerListToAssert[i]);
    }
}

TEST(FirstTests, bubbleSort) {
    int integerListToSort[] = { 0, 1, 3, 2 };
    int integerListToAssert[] = { 0, 1, 2, 3 };

    int size = std::size(integerListToSort);
    EXPECT_EQ(size, 4);

    Sortings::doBubbleSort(integerListToSort, size);

    for (int i = 0; i < size; i++)
    {
       EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}

TEST(FirstTests, bubbleSortWithBigAray) {
    int integerListToSort[] = { 92, 10, 36, 49, 8, 64, 31, 28, 76, 59,
                                38, 50, 66, 19, 74, 15, 83, 57, 65, 42,
                                12, 41, 29, 22, 6, 48, 60, 75, 89, 82,
                                4, 67, 81, 40, 37, 91, 24, 17, 25, 72,
                                34, 54, 98, 2, 56, 11, 43, 61, 47, 53,
                                27, 46, 18, 68, 95, 85, 93, 16, 3, 9,
                                71, 1, 73, 94, 52, 99, 13, 20, 35, 23,
                                86, 26, 84, 5, 30, 58, 63, 79, 14, 69,
                                90, 0, 97, 62, 45, 88, 21, 70, 78, 87,
                                51, 33, 7, 80, 55, 96, 32, 39, 77, 44 };

    int integerListToAssert[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                                  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                                  20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
                                  30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                                  40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
                                  50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
                                  60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
                                  70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
                                  80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
                                  90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };

    int size = std::size(integerListToSort);

    EXPECT_EQ(std::size(integerListToSort), std::size(integerListToAssert));

    Sortings::doBubbleSort(integerListToSort, size);

    for (int i = 0; i < size; i++)
    {
        //EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}






int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}