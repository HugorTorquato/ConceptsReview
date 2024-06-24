#include <iostream>
#include <string>

#include "Sortings.h"


/*
- The idea is to implement the transposition type of sorts and compare the execution time between them
    - Bubble sort
    - Selection Sort
    - Insertio Sort
- Start with VALUE-BASED and them implement the POITNER-BASED. 
- The idea is to compare the execution time between them
*/

using namespace std;


// Colocar isso dentro de uma classe!!!!!!!!!!!

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
    return 1;
}

int Sortings::defaultCollection1[] = { 6, 0, 5, 3 };
int Sortings::defaultCollection2[] = { 3, 6, 0, 5 };


