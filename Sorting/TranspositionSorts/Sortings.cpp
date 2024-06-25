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
