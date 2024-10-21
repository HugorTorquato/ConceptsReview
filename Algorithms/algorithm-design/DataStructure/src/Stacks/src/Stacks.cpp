#include "Stacks.h"

StackClass::StackClass(){

}

int StackClass::return1ToTest(){
    return 1;
}

// --------------------------------------------------------

std::stack<int> StackClass::getStack(){
    return hugoStack;
}

void StackClass::pushElementToTheStack(const int elementToPush){
    hugoStack.push(elementToPush);
}

void StackClass::popElementOfTheStack(){

    if(hugoStack.empty()){
        return;
    }

    hugoStack.pop();
}