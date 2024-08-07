#include "FreeFunction.h"

#include "FreeFunctionWrapperImpl2.h"


int add(const int a, const int b) {
	return a + b;
}

int addTwoPlusTwo() {
	return add(2, 2);
}

FreeFunctionWrapperImpl wrapperImpl;

int addTwoPlusTwoRefactored() {
	return wrapperImpl.add(2, 2);
}