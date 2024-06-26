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



};

