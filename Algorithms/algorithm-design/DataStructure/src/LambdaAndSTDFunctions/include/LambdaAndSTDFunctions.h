#pragma once

#include <iostream>
#include <functional>


class LambdaAndSTDFunctionsClass {
    public:
        LambdaAndSTDFunctionsClass();

        int return1ToTest();

        //------------

        void incrementData(const int &valueToIncrement);

        int operationBetweenTwoIntegers(const int &a, const int &b, 
            std::function<int(int, int)> operation);
        int operationBetweenObjPropAndOneIntegers(const int &b, 
            std::function<int(int)> operation);



    public:
        int data;

};

// --------------------------------------------------------
