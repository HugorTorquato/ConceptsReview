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

void Sortings::doBubbleSort(int* defaultCollection, const int size)
{
	cout << "defaultCollection : ";
	displayColletion(defaultCollection, size);

	Sortings::compareNumbers(1, 1);

	cout << "doBubbleSort : ";
	displayColletion(defaultCollection, size);
}
