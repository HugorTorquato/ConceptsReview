#pragma once

#include <iostream>
#include <array>
class ArrayClass {
    public:
        int add (const int a, const int b);
        int returnSizeOfTheArray(const std::array<int, 4>& arrayToEvluate);
        int returThePointerUsingeData(const std::array<int, 4>& arrayToEvluate, const int position);
        std::array<int, 4> invertTheArray(std::array<int, 4>& arrayToEvluate);
        std::array<int, 4> SwapTwoArrays(std::array<int, 4> arrayToEvluateTo, std::array<int, 4> arrayToEvluateFrom);


    private:
        int count;
};