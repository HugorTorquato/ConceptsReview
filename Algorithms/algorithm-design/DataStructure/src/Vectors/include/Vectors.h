#pragma once

#include <vector>

class DynamicStack {
    public:
        void vectors();
        std::vector<int> getFifoStack();
        void IncludeElementIntoTheStack(const int& elementToInclude);
        void ElementFromTheStackWithPopBack();
        void ElementFromTheStackWithErase();
        bool isVectorEmty();

    private:
        std::vector<int> FIFOStack;
};