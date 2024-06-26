#include "Sortings.h"
#include <iostream>

using namespace std;

void Sortings::displayColletion(const int collection[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << collection[i] << " ";
	}
	cout << endl;
}

int Sortings::compareNumbers(const int num1, const int num2) {

	if (num1 > num2)
	{
		return(1);
	}
	else if (num1 < num2) {
		return(-1);
	}
	else {
		return(0);
	}
}

void Sortings::swapValuesPointer(int* listToSwap, const int position1, const int position2) {

	int temp = listToSwap[position2];

	listToSwap[position2] = listToSwap[position1];
	listToSwap[position1] = temp;

}

// Must define the size of the array :( when using array by reference
void Sortings::swapValuesReference(int (&listToSwap)[4], const int position1, const int position2) {

	int temp = listToSwap[position2];

	listToSwap[position2] = listToSwap[position1];
	listToSwap[position1] = temp;

}

void Sortings::doBubbleSort(int* defaultCollection, const int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			if ( Sortings::compareNumbers(defaultCollection[i], defaultCollection[j]) == -1)
			{
				Sortings::swapValuesPointer(defaultCollection, i, j);
			}
		}
	}
}

// If no two elements swaped in the inner loop... means the sort is completed
void Sortings::doBubbleSortWithBreak(int* defaultCollection, const int size)
{
	for (int i = 0; i < size; i++)
	{
		bool swapped = false;
		for (int j = 0; j < size; j++)
		{
			if (Sortings::compareNumbers(defaultCollection[i], defaultCollection[j]) == -1)
			{
				Sortings::swapValuesPointer(defaultCollection, i, j);
				swapped = true;
			}
		}

		if (swapped = false) {
			break;
		}
	}
}

/*---------------------------------------------------------------------------------------------- */

int Sortings::identifyPivotLastElement(const int size)
{
	return size - 1;
}

int Sortings::identifyPivotRandom(const int size)
{
	return rand() % size;
}

void printArray(int* defaultCollection, const int size) {

	for (int i = 0; i < size; i++)
	{
		cout << defaultCollection[i] << " ";
	}
	cout << endl;
}

int Sortings::getSortedPivotIndex(int* defaultCollection, int low, const int size) {

	cout << "Init ";
	printArray(defaultCollection, size);
	int pivot = Sortings::identifyPivotLastElement(size);

	int lowerIndex = (low - 1);

	// Need to start with the lower because it covers the "higher sub array" as well
	for (int i = low; i < size; i++) {
		cout << "defaultCollection[i] " << defaultCollection[i] << " pivot " << defaultCollection[pivot] << endl;
		if (defaultCollection[i] < defaultCollection[pivot])
		{
			lowerIndex++;
			swapValuesPointer(defaultCollection, i, lowerIndex);
		}
	}

	// swap pivot with first of the higher values
	cout << "lowerIndex " << lowerIndex << " pivot " << pivot << endl;
	swapValuesPointer(defaultCollection, lowerIndex + 1, pivot);

	cout << "End ";
	printArray(defaultCollection, size);
	return lowerIndex + 1;
}

void Sortings::doQuickSort(int* defaultCollection, int low, const int size)
{
	// If array has more than one element
	if(low < size) {
		int mid = getSortedPivotIndex(defaultCollection, low, size);

		// Do quck sort for lower subarrays
		Sortings::doQuickSort(defaultCollection, low, mid);

		// Do quick sort for higher subarrays
		Sortings::doQuickSort(defaultCollection, mid+1, size);

	}
}

int Sortings::getSortedRandomPivotIndex(int* defaultCollection, int low, const int size) {

	cout << "Init ";
	printArray(defaultCollection, size);
	int pivot = Sortings::identifyPivotRandom(size);

	int lowerIndex = (low - 1);

	// Need to start with the lower because it covers the "higher sub array" as well
	for (int i = low; i < size; i++) {
		cout << "defaultCollection[i] " << defaultCollection[i] << " pivot " << defaultCollection[pivot] << endl;
		if (defaultCollection[i] < defaultCollection[pivot])
		{
			lowerIndex++;
			swapValuesPointer(defaultCollection, i, lowerIndex);
		}
	}

	// swap pivot with first of the higher values
	cout << "lowerIndex " << lowerIndex << " pivot " << pivot << endl;
	swapValuesPointer(defaultCollection, lowerIndex + 1, pivot);

	cout << "End ";
	printArray(defaultCollection, size);
	return lowerIndex + 1;
}

void Sortings::doQuickSortRandomPivot(int* defaultCollection, int low, const int size)
{
	// If array has more than one element
	if (low < size) {
		int mid = getSortedPivotIndex(defaultCollection, low, size);

		// Do quck sort for lower subarrays
		Sortings::doQuickSort(defaultCollection, low, mid);

		// Do quick sort for higher subarrays
		Sortings::doQuickSort(defaultCollection, mid + 1, size);

	}
}

/*---------------------------------------------------------------------------------------------- */

int Sortings::identifyMaxValueInArray(int* defaultCollection, const int size)
{
	int maxValue = 0;

	for (int i = 0; i < size; i++)
	{
		if (defaultCollection[i] > maxValue)
		{
			maxValue = defaultCollection[i];
		}
	}

	return maxValue;
}

int* Sortings::populateCountArray(int* defaultCollection, const int size, const int maxValueInArray) {

	int* countArray = new int[maxValueInArray] {0};

	for (int i = size - 1; i >= 0; i--) {
		countArray[defaultCollection[i]]++;
	}

	for (size_t i = 1; i < maxValueInArray; i++)
	{
		countArray[i] += countArray[i - 1];
	}

	return countArray;
}

int* Sortings::doCountSort(int* defaultCollection, const int size)
{
	// Identify the max integer number in the array
	const int maxValueInArray = Sortings::identifyMaxValueInArray(defaultCollection, size) + 1;

	// Create the countArray and fill it with how many times each number ocurred
	int* countArray = Sortings::populateCountArray(defaultCollection, size, maxValueInArray);
	printArray(countArray, maxValueInArray);

	// Start to populate the output array
	int* outputArray = new int[size] {0};

	for (int i = size - 1; i >= 0; i--)
	{
		outputArray[countArray[defaultCollection[i]] - 1] = defaultCollection[i];
		countArray[defaultCollection[i]]--;
	}
	printArray(outputArray, size);

	return outputArray;
}

/*---------------------------------------------------------------------------------------------- */

















