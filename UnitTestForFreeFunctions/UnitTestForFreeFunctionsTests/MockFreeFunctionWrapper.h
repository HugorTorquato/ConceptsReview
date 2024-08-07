#pragma once

#include "gmock/gmock.h"
#include "../FreeFunctionWrapperImpl2.h"
//#include "../FreeFunctionWraper.h"

class MockFreeFunctionWrapper :
    public FreeFunctionWrapper
{
public:
    MOCK_METHOD(int, add, (int a, int b), (const, override));
};

