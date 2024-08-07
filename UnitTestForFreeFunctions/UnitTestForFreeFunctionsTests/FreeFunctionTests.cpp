#include "gmock/gmock.h"

#include "../FreeFunction.h"
#include "MockFreeFunctionWrapper.h"

using ::testing::Return;

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

TEST(UsingWrappersToMockFreeFunctions, applyMockToAddFreeFunction) {
	
	MockFreeFunctionWrapper mockWrapper;

	EXPECT_CALL(mockWrapper, add(2, 2))
		.WillOnce(Return(5));

	FreeFunctionWrapperImpl wrapper;

	EXPECT_EQ(wrapper.add(2, 2), 5);
}

TEST(UsingWrappersToMockFreeFunctions, testFreeFunctionInvokingAnotherFreeFunctionWithoutMock) {

	// There is no way to use wrappers or virtual functions without modifying the legacy code :( 
	MockFreeFunctionWrapper mockWrapper;

	EXPECT_CALL(mockWrapper, add(2, 2))
		.WillOnce(Return(5));

	// The method reference the free add() function isntead of the mocked one. So, when the test run... the mocked add()
	// is never called and the end result is 4
	EXPECT_EQ(mockWrapper.addTwoPlusTwo(), 5);
}