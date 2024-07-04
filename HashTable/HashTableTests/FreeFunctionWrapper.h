#pragma once

#include "MockWrapper.h"
#include "../HashTable/HashTableFreeFunctions.h"

class FreeFunctionWrapper : public MockWrapper
{
public:
	int FreeFunction(int x) override {
		return ::FreeFunction(x);
	}
};

