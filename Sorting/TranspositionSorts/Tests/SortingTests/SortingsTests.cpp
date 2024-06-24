#include "gtest/gtest.h"
#include "../../Sortings.h"


TEST(FirstTest, Test1) {
    EXPECT_EQ(1, 1);
}

TEST(FirstTest, Test2) {
   EXPECT_EQ(Sortings::compareNumbers(2,2), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}