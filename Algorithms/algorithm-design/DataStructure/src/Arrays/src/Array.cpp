#include "../include/Array.h"

int ArrayClass::add (const int a, const int b){
    return a + b;
}

int ArrayClass::returnSizeOfTheArray(const std::array<int, 4>& arrayToEvluate){
    return static_cast<int>(arrayToEvluate.size());
}

int ArrayClass::returThePointerUsingeData(const std::array<int, 4>& arrayToEvluate, const int position){

    const int* ptr = arrayToEvluate.data();

    return ptr[position];
}

std::array<int, 4> ArrayClass::invertTheArray(std::array<int, 4>& arrayToEvluate){

    std::array<int, 4> arrayInv = {0};

    //Populate the entire array with 1, cool
    arrayInv.fill(1);

    int position = 0;

    // Here is the trick of the function
    // Needs to do a rever loop, based on a reverse_iterator ( which is a pointer, so needs to use the * to access the value)
    // The rbegin() and rend() also do the trick here, but for a normal loop throug an array, use begin() end() and the ::iterator
    for(std::array<int,4>::reverse_iterator it = arrayToEvluate.rbegin(); it != arrayToEvluate.rend(); ++it){
        arrayInv[position++] = *it;
    }

    return arrayInv;

}

std::array<int, 4> ArrayClass::SwapTwoArrays(std::array<int, 4> arrayToEvluateTo, std::array<int, 4> arrayToEvluateFrom){

    arrayToEvluateTo.swap(arrayToEvluateFrom);

    return arrayToEvluateTo;

}