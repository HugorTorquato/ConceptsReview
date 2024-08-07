#include "FreeFunction.h"

#include "FreeFunctionWrapperImpl2.h"


// Initializa the pointer with the actuall function we expect it to call
int (*add_ptr)(const int, const int) = add;


int add(const int a, const int b) {
	return a + b;
}

// Since the pointer is referencing the correct funtion, we can update it here and still acess the add logic
int addTwoPlusTwo() {
	return add_ptr(2, 2);
}

int addTwoPlusTwoOriginal() {
	return add(2, 2);
}
