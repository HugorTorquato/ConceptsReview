#include "LambdaAndSTDFunctions.h"

LambdaAndSTDFunctionsClass::LambdaAndSTDFunctionsClass(){

}

int LambdaAndSTDFunctionsClass::return1ToTest(){
    return 1;
}

void LambdaAndSTDFunctionsClass::incrementData(const int &valueToIncrement){
    //data += valueToIncrement;

    auto lambda = [this] (const int &valueToIncrement) -> int {
        return this->data += valueToIncrement;
    };

    data = lambda(valueToIncrement);

}

int LambdaAndSTDFunctionsClass::operationBetweenTwoIntegers(
    const int &a, const int &b,
    std::function<int(int, int)> operation)
{
    return operation(a, b);
}

int LambdaAndSTDFunctionsClass::operationBetweenObjPropAndOneIntegers(
    const int &b,
    std::function<int(int)> operation)
{
    return operation(b);
}
