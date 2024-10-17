#include "Vectors.h"

void DynamicStack::vectors() {
    FIFOStack = {};
}

std::vector<int> DynamicStack::getFifoStack(){
    return FIFOStack;
}

void DynamicStack::IncludeElementIntoTheStack(const int& elementToInclude){
    FIFOStack.push_back(elementToInclude);
}

void DynamicStack::ElementFromTheStackWithPopBack(){
    FIFOStack.pop_back();
}

void DynamicStack::ElementFromTheStackWithErase(){
    // Don't like this + 1 and -1
    // BUt it is very usefull to erase elements or group of elements 
    // in the middle of hte vector
    FIFOStack.erase(FIFOStack.end() - 1);
}

bool DynamicStack::isVectorEmty(){
    if(FIFOStack.size() == 0) {
        return true;
    }

    return false;
}