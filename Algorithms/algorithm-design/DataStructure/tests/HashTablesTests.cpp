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

TEST(HashTableTests, initializingAnEmptyHashTable) {
  HashTablesClass HTT;

  EXPECT_TRUE(HTT.getHashTable().empty());
}

TEST(HashTableTests, initializingTheHashTableWithOneValue) {
  HashTablesClass HTT;

  HTT.insertElementsInTheHashTable("hugo", 27);

  EXPECT_FALSE(HTT.getHashTable().empty());
}

TEST(HashTableTests, retrieveAValueFromHashTableBasedOnTheKey){
    HashTablesClass HTT;

    HTT.insertElementsInTheHashTable("hugo", 27);
    HTT.insertElementsInTheHashTable("Tay", 28);

    EXPECT_EQ(HTT.retreveValueFromKey("hugo"), 27);
    EXPECT_EQ(HTT.retreveValueFromKey("Tay"), 28);
}

TEST(HashTableTests, retrieveAValueFromHashTableBasedOnInvalidKey){
    HashTablesClass HTT;

    HTT.insertElementsInTheHashTable("hugo", 27);
    HTT.insertElementsInTheHashTable("Tay", 28);

    ASSERT_EQ(HTT.retreveValueFromKey("hugoO"), 0);
}

TEST(HashTableTests, removeElementFromHashTable){
    HashTablesClass HTT;

    HTT.insertElementsInTheHashTable("hugo", 27);
    HTT.insertElementsInTheHashTable("Tay", 28);

    HTT.removeElementBasedOnKey("hugo");

    EXPECT_EQ(HTT.retreveValueFromKey("hugo"), 0);
    EXPECT_EQ(HTT.retreveValueFromKey("Tay"), 28);
}

// --------------------------------------------------------
