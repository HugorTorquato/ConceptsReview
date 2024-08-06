#include "gmock/gmock.h"

#include "../FreeFunction.h"

TEST(IndependentTests, firstSimpleTestToSeeIfItIsWorking) {
	EXPECT_EQ(1, 1);
}

TEST(IndependentTests, testFreeFunctionWithoutMock) {

	int result = add(2, 2);
	EXPECT_EQ(result, 4);
}

TEST(IndependentTests, testFreeFunctionInvokingAnotherFreeFunctionWithoutMock) {

	int result = addTwoPlusTwo();
	EXPECT_EQ(result, 4);
}