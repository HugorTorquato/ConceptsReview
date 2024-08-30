#include "gmock/gmock.h"
#include "../Graphs/Graph.h"

#include "../Graphs/Source.cpp"

TEST(SimpleTest, simpleSumTest) {
	EXPECT_EQ(sum(2, 2), 4);
}

