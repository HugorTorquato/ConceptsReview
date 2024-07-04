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

TEST_F(HashTableTests, initializeHashTableWithSizeOfTen)
{
	HashTable htLocal(10);

	EXPECT_EQ(htLocal.getSize(), 10);
}

TEST_F(HashTableTests, initializeHashTableWithTenBuckets)
{
	HashTable htLocal(10);

	EXPECT_EQ(htLocal.getHashTable().size(), 10);
}

TEST_F(HashTableTests, validadeHashFunctionCalculation)
{
	HashTable htLocal(5);

	EXPECT_EQ(htLocal.hashFunction(5), 0);
	EXPECT_EQ(htLocal.hashFunction(9), 4);
	EXPECT_EQ(htLocal.hashFunction(1), 1);
}

TEST_F(HashTableTests, insertingUniqueEntryInHashTable)
{
	HashTable htGlobal10(10);

	int key = 5;
	string value = "Hugo";
	int index = htGlobal10.hashFunction(key);

	htGlobal10.insert(key, value);

	vector<list<pair<int, string>>> hashTable = htGlobal10.getHashTable();
	
	for (auto& pair : hashTable[index])
	{
		EXPECT_EQ(pair.first, key);
		EXPECT_EQ(pair.second, value);
	}
}

TEST_F(HashTableTests, searchElementNotIncludedInTheHashTable)
{
	HashTable htGlobal10(10);

	int key = 5;
	string value = "Hugo";
	int index = htGlobal10.hashFunction(key);

	htGlobal10.insert(key, value);

	EXPECT_EQ(htGlobal10.search(4), "key not found");
}

TEST_F(HashTableTests, searchElementIncludedInTheHashTable)
{
	HashTable htGlobal10(10);

	int key = 5;
	string value = "Hugo";
	int index = htGlobal10.hashFunction(key);

	htGlobal10.insert(key, value);

	EXPECT_EQ(htGlobal10.search(5), value);
}

TEST_F(HashTableTests, removeElementNotIncludedInTheHashTable)
{
	HashTable htGlobal10(10);
	int keyToRemove = 6;

	htGlobal10.remove(keyToRemove);

	EXPECT_EQ(htGlobal10.search(keyToRemove), "key not found");
}

TEST_F(HashTableTests, removeElementIncludedInTheHashTable)
{
	HashTable htGlobal10(10);

	int key = 5;
	string value = "Hugo";
	int index = htGlobal10.hashFunction(key);

	htGlobal10.insert(key, value);

	EXPECT_EQ(htGlobal10.search(key), value);

	htGlobal10.remove(key);

	EXPECT_EQ(htGlobal10.search(5), "key not found");
}
