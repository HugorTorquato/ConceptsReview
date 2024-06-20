#include <iostream>
#include <string>


/*
- The idea is to implement the transposition type of sorts and compare the execution time between them
    - Bubble sort
    - Selection Sort
    - Insertio Sort
- Start with VALUE-BASED and them implement the POITNER-BASED. 
- The idea is to compare the execution time between them
*/

using namespace std;

void displayCollection(int collection[], int size) {
    for (int i = 0; i < size; i++) {
        cout << collection[i] << " ";
    }
    cout << endl;
}

int compareNumbers(int num1, int num2) {
    if (num1 == num2) {
        return 0;
    }
    else if (num1 > num2) {
        return -1;
    }
    else {
        return 1;
    }
}

int doBubbleSort(int collection[], int size) {
    cout << "Start sort : ";
    displayCollection(collection, size);


    for (int i = 0; i < size; i++) {
        // First loop
        for (int j = 0; j < size; j++) {
            if (compareNumbers(collection[i], collection[j]) == 1) {
                // if number 1 is greater tan number 2, swap
                int tempNum = collection[i];
                collection[i] = collection[j];
                collection[j] = tempNum;
            }
        }
    }


    cout << "End sort   : ";
    displayCollection(collection, size);
    return 1;
}

int main()
{
    int defaultCollection[] = { 10, 21, 34, 9 };
    int size = sizeof(defaultCollection) / sizeof(int);

    doBubbleSort(defaultCollection, size);


}
