#include "gtest/gtest.h"
#include <random>
#include "../../Sortings.h"

TEST(BubbleSortTests, compareNumberWithFirstGreater) {
    int num1 = 2;
    int num2 = 1;

   EXPECT_EQ(Sortings::compareNumbers(num1, num2), 1);
}

TEST(BubbleSortTests, compareNumberWithSecondGreater) {
    int num1 = 1;
    int num2 = 2;

    EXPECT_EQ(Sortings::compareNumbers(num1, num2), -1);
}
TEST(BubbleSortTests, compareEqualNumber) {
    int num1 = 2;
    int num2 = 2;

    EXPECT_EQ(Sortings::compareNumbers(num1, num2), 0);
}


TEST(BubbleSortTests, swapTwoNumberOnIntegerListPointer) {

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

TEST(BubbleSortTests, swapTwoNumberOnIntegerListReference) {

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

TEST(BubbleSortTests, bubbleSort) {
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

TEST(BubbleSortTests, bubbleSortWithBigAray) {

    const int sizeOftheArray = 100;
    int integerListToSort[sizeOftheArray];
    int integerListToAssert[sizeOftheArray];

    for (int i = 0; i < sizeOftheArray; i++) {
        integerListToSort[i] = i;
        integerListToAssert[i] = i;
    }

    std::random_shuffle(integerListToSort, integerListToSort + sizeOftheArray);

    int size = std::size(integerListToSort);

    EXPECT_EQ(std::size(integerListToSort), std::size(integerListToAssert));

    Sortings::doBubbleSort(integerListToSort, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}

TEST(BubbleSortTests, bubbleSortWithBigArayAndBreak) {

    const int sizeOftheArray = 100;
    int integerListToSort[sizeOftheArray];
    int integerListToAssert[sizeOftheArray];

    for (int i = 0; i < sizeOftheArray; i++) {
        integerListToSort[i] = i;
        integerListToAssert[i] = i;
    }

    std::random_shuffle(integerListToSort, integerListToSort + sizeOftheArray);

    int size = std::size(integerListToSort);

    EXPECT_EQ(std::size(integerListToSort), std::size(integerListToAssert));

    Sortings::doBubbleSortWithBreak(integerListToSort, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}

/*---------------------------------------------------------------------------------------------- */

TEST(QuickSortTests, IdentifyPivotInArrayLastElement) {

    int integerListToSwap[] = { 0, 1, 3, 2 };
    int size = std::size(integerListToSwap);

    int pivotIndex = Sortings::identifyPivotLastElement(size);

    EXPECT_EQ(pivotIndex, 3);
}

TEST(QuickSortTests, IdentifyPivotInArrayRandomElement) {

    int integerListToSwap[] = { 0, 1, 3, 2 };
    int size = std::size(integerListToSwap);

    int pivotIndex = Sortings::identifyPivotRandom(size);

    EXPECT_TRUE(pivotIndex < size);
}

TEST(QuickSortTests, quickSortWithPivotAsLasElementOneIteraton) {

    int integerListToSort[] = { 0, 3, 2 };
    int integerListToAssert[] = { 0, 2, 3 };
    int size = std::size(integerListToSort);

    Sortings::doQuickSort(integerListToSort, 0, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}

TEST(QuickSortTests, quickSortWithPivotAsLasElementTwoIterations) {

    int integerListToSort[] = { 0, 2, 3, 1 };
    int integerListToAssert[] = { 0, 1, 2, 3 };
    int size = std::size(integerListToSort);

    Sortings::doQuickSort(integerListToSort, 0, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}

TEST(QuickSortTests, quickSortWithPivotAsLasElementTwoIterations2) {

    int integerListToSort[] = { 4, 0, 2, 3, 1, 44, 5 };
    int integerListToAssert[] = { 0, 1, 2, 3, 4, 5, 44 };
    int size = std::size(integerListToSort);

    Sortings::doQuickSort(integerListToSort, 0, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}

TEST(QuickSortTests, quickSortWithBigAray) {

    const int sizeOftheArray = 100;
    int integerListToSort[sizeOftheArray];
    int integerListToAssert[sizeOftheArray];

    for (int i = 0; i < sizeOftheArray; i++) {
        integerListToSort[i] = i;
        integerListToAssert[i] = i;
    }

    std::random_shuffle(integerListToSort, integerListToSort + sizeOftheArray);


    int size = std::size(integerListToSort);

    EXPECT_EQ(std::size(integerListToSort), std::size(integerListToAssert));

    Sortings::doQuickSort(integerListToSort, 0, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}

TEST(QuickSortTests, quickSortWithBigArayAndRandomPivot) {

    const int sizeOftheArray = 100;
    int integerListToSort[sizeOftheArray];
    int integerListToAssert[sizeOftheArray];

    for (int i = 0; i < sizeOftheArray; i++) {
        integerListToSort[i] = i;
        integerListToAssert[i] = i;
    }

    std::random_shuffle(integerListToSort, integerListToSort + sizeOftheArray);

    int size = std::size(integerListToSort);

    EXPECT_EQ(std::size(integerListToSort), std::size(integerListToAssert));

    Sortings::doQuickSortRandomPivot(integerListToSort, 0, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}


/*---------------------------------------------------------------------------------------------- */

TEST(CountiSortTests, identifyMaxValueInArray) {

    int integerListToAssert[] = { 0, 1, 2, 3 };

    int size = std::size(integerListToAssert);
    
    int maxValueInArray = Sortings::identifyMaxValueInArray(integerListToAssert, size);

    EXPECT_EQ(maxValueInArray, 3);
}

TEST(CountiSortTests, createAnArrayWithSizeEqualToMaxValue) {

    int integerListToSort[] = { 0, 1, 2, 2, 3 };
    int integerListToAssert[] = { 1, 2, 4, 5 };

    int sizeSort = std::size(integerListToSort);

    const int maxValueInArray = Sortings::identifyMaxValueInArray(integerListToSort, sizeSort) + 1;

    int* countArray = Sortings::populateCountArray(integerListToSort, sizeSort, maxValueInArray);

    for (int i = 0; i < maxValueInArray; i++)
    {
        EXPECT_EQ(countArray[i], integerListToAssert[i]);
    }
}

TEST(CountiSortTests, countSortWithSmallArray) {

    int integerListToSort[] = { 0, 2, 3, 1, 2 };
    int integerListToAssert[] = { 0, 1, 2, 2, 3 };

    int size = std::size(integerListToAssert);

    int* outputSort = Sortings::doCountSort(integerListToSort, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(outputSort[i], integerListToAssert[i]);
    }
}

TEST(CountiSortTests, countSortWithSmallArrayAndBigNumbers) {

    int integerListToSort[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int integerListToAssert[] = { 2, 24, 45, 66, 75, 90, 170, 802};

    int size = std::size(integerListToAssert);

    int* outputSort = Sortings::doCountSort(integerListToSort, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(outputSort[i], integerListToAssert[i]);
    }
}

TEST(CountiSortTests, countSortWithBigArray) {

    const int sizeOftheArray = 100;
    int integerListToSort[sizeOftheArray];
    int integerListToAssert[sizeOftheArray];

    for (int i = 0; i < sizeOftheArray; i++) {
        integerListToSort[i] = i;
        integerListToAssert[i] = i;
    }

    std::random_shuffle(integerListToSort, integerListToSort + sizeOftheArray);

    int size = std::size(integerListToAssert);

    int* outputSort = Sortings::doCountSort(integerListToSort, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(outputSort[i], integerListToAssert[i]);
    }
}

/*---------------------------------------------------------------------------------------------- */


TEST(RadixSortTests, identifyNumberOfDigitsFromMaxValue) {
    int integerListToSort[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int sizeSort = std::size(integerListToSort);

    const int maxValueInArray = Sortings::identifyMaxValueInArray(integerListToSort, sizeSort) + 1;


    int maxNumberOfDigits = Sortings::identifyNumberOfDigits(maxValueInArray);

    EXPECT_EQ(maxNumberOfDigits, 3);
}

TEST(RadixSortTests, retrieveDigitFromNumber) {

    int numberToSearate = 802;

    EXPECT_EQ(Sortings::returnDigitAsSignificance(numberToSearate, 0), 8);
    EXPECT_EQ(Sortings::returnDigitAsSignificance(numberToSearate, 1), 0);
    EXPECT_EQ(Sortings::returnDigitAsSignificance(numberToSearate, 2), 2);
}

TEST(RadixSortTests, radixSortWithSmallArray) {
    int integerListToSort[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int integerListToAssert[] = { 2, 24, 45, 66, 75, 90, 170, 802 };

    int sizeSort = std::size(integerListToSort);

    Sortings::doRadixSort2(integerListToSort, sizeSort);

    for (int i = 0; i < sizeSort; i++)
    {
        EXPECT_EQ(integerListToSort[i], integerListToAssert[i]);
    }
}





int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}