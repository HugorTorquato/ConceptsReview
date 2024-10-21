#pragma once

#include <stack>


class StackClass {

    public:
        StackClass();

        int return1ToTest();
        std::stack<int> getStack();

        void pushElementToTheStack(const int elementToPush);
        void popElementOfTheStack();

    private:
        std::stack<int> hugoStack;

};