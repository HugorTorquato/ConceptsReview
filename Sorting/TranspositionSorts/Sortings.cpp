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