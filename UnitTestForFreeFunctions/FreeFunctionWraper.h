#pragma once
#include "FreeFunction.h"

class FreeFunctionWrapper
{
public:
	virtual ~FreeFunctionWrapper() = default;
	virtual int add(const int a, const int b) const = 0;
	virtual int addTwoPlusTwo() { return ::addTwoPlusTwo(); };
};


