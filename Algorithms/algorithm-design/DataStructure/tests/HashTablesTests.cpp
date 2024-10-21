#include <gtest/gtest.h>

#include "HashTables.h"

TEST(HashTableTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(HashTableTests, simpleMethodReturning1){

    HashTablesClass HTT;

    EXPECT_EQ(HTT.return1ToTest(), 1);
}

// --------------------------------------------------------