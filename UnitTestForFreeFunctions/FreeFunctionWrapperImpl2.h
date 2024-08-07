#pragma once

#include "FreeFunctionWraper.h"
#include "FreeFunction.h"

class FreeFunctionWrapperImpl : public FreeFunctionWrapper {
public:
	int add(const int a, const int b) const override {
		return ::add(a, b);
	}
};

