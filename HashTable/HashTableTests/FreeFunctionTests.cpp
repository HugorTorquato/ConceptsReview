#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "MockWrapper.h"
#include "FreeFunctionWrapper.h"
#include "../HashTable/HashTableFreeFunctions.h"

using ::testing::Return;
using ::testing::_;

class MockWrapperImp : public MockWrapper {
public:
    MOCK_METHOD(int, FreeFunction, (int x), (override));
};

TEST(FreeFunctiontTests, TestFreeFunction) {
    EXPECT_EQ(FreeFunction(10), 20);
}

TEST(FreeFunctiontTests, TestFreeFunctionWithWrapper) {
    MockWrapperImp mockWrapper;

    EXPECT_CALL(mockWrapper, FreeFunction(10))
        .Times(1)
        .WillOnce(Return(30));

    EXPECT_EQ(mockWrapper.FreeFunction(10), 30);
}
