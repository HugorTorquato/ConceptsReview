#pragma once


class MockWrapper
{
public:
	virtual ~MockWrapper() = default;
	virtual int FreeFunction(int x) = 0;
};