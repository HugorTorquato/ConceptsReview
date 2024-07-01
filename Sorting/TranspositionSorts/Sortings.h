#pragma once

class Sortings
{
public:

	static int defaultCollection1[];
	static int defaultCollection2[];

	static void displayColletion(const int collection[], int size);
	static int compareNumbers(const int num1, const int num2);
	static void swapValuesPointer(int* listToSwap, const int position1, const int position2);
	static void swapValuesReference(int (&listToSwap)[4], const int position1, const int position2);

	static void doBubbleSort(int* defaultCollection, const int size);
	static void doBubbleSortWithBreak(int* defaultCollection, const int size);




	static int identifyPivotLastElement(const int size);
	static int identifyPivotRandom(const int size);

	static int getSortedPivotIndex(int* defaultCollection, int pivot, const int size);
	static int getSortedRandomPivotIndex(int* defaultCollection, int pivot, const int size);
	static void doQuickSort(int* defaultCollection, int pivot, const int size);
	static void doQuickSortRandomPivot(int* defaultCollection, int pivot, const int size);


	static int identifyMaxValueInArray(int* defaultCollection, const int size);
	static int* populateCountArray(int* defaultCollection, const int size, const int maxValueInArray);
	static int* populateCountArray2(int* defaultCollection, const int size, const int maxValueInArray, const int exp);
	static int* doCountSort(int* defaultCollection, const int size);
	static int* doCountSort2(int* defaultCollection, const int size, const int exp);


	static int identifyNumberOfDigits(const int number);
	static int returnDigitAsSignificance(const int number, const int digit);
	static void doRadixSort(int* defaultCollection, const int size);
	static void doRadixSort2(int* defaultCollection, const int size);
};

