#pragma once

#include "gtest/gtest.h"
#include "../HashTable/HashTableFunctions.h"

class HashTableTests : public testing::Test
{

};


TEST_F(HashTableTests, initializeEmptyHashTable) {

	HashTable htLocal(0);

	EXPECT_EQ(htLocal.getSize(), 0);
}

TEST_F(HashTableTests, initializeHashTableWithTenBuckets)
{
	HashTable htLocal(10);

	EXPECT_EQ(htLocal.getSize(), 10);
}

TEST_F(HashTableTests, initializeHashTableWithTenBuckets)
{
	HashTable htLocal(10);

	EXPECT_EQ(htLocal.getSize(), 10);
}