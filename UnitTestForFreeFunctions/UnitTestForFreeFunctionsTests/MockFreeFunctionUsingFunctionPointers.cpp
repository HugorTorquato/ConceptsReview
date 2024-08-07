
#include "gmock/gmock.h"
#include "../FreeFunction.h"

using ::testing::Return;

int mock_add(const int a, const int b) {
	return 5;
}

TEST(MockUsingPointerFunctions, updateTheFunctionPointerToUseMock) {

	// Save the original value in the pointer to rollback the change in the end of the test
	int (*original_add_ptr)(const int, const int) = add_ptr;

	// Here is where we change the pointers... now it is pointing to the new function defined in this file
	add_ptr = mock_add;

	// It's possible to call the function that uses te pointer... and it'll have the "mocked" behavior
	EXPECT_EQ(addTwoPlusTwo(), 5);

	// It's possible to call the function that DOESN'T use te pointer... and it'll have the original behavior
	EXPECT_EQ(addTwoPlusTwoOriginal(), 4);

	add_ptr = original_add_ptr;

	EXPECT_EQ(addTwoPlusTwo(), 4);

}

TEST(MockUsingPointerFunctions, updateFunctionPointerToAffectOtherUnitTest) {
	add_ptr = mock_add;

	EXPECT_EQ(addTwoPlusTwo(), 5);
	EXPECT_EQ(addTwoPlusTwoOriginal(), 4);
}

TEST(MockUsingPointerFunctions, affectedTestWhenNotRollingBackOriginalFunctionPointer) {
	add_ptr = mock_add;

	EXPECT_EQ(addTwoPlusTwo(), 5);
	EXPECT_EQ(addTwoPlusTwoOriginal(), 4);
}

const int loopLimit = 1000000000;
TEST(MockUsingPointerFunctions, performanceTestUsingTheFunctionPointerIndirectCall) {

	int (*original_add_ptr)(const int, const int) = add_ptr;
	add_ptr = mock_add;

	for (int i = 0; i < loopLimit; i++)
	{
		EXPECT_EQ(addTwoPlusTwo(), 5);
	}

	add_ptr = original_add_ptr;
}

TEST(MockUsingPointerFunctions, performanceTestUsingTheFunctionPointerDindirectCall) {

	for (int i = 0; i < loopLimit; i++)
	{
		EXPECT_EQ(addTwoPlusTwoOriginal(), 4);
	}
}
