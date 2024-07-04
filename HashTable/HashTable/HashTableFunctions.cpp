#include "HashTableFunctions.h"

int HashTable::hashFunction(int key)
{
	return key % size;
}

HashTable::HashTable(int s) : size(s)
{
	table.resize(s);
}

HashTable::~HashTable()
{
}

int HashTable::getSize()
{
	return size;
}

vector<list<pair<int, string>>> HashTable::getHashTable()
{
	return table;
}

void HashTable::insert(const int key, const string& value)
{
	int index = hashFunction(key);
	table[index].emplace_back(key, value);
}

string HashTable::search(const int key)
{
	const int index = hashFunction(key);

	if (!table[index].empty()) {
		for (auto& pair : table[index]) {
			if (pair.first == key) {
				return pair.second;
			}
		}
	}

	return "key not found";
}

void HashTable::remove(const int key)
{
	int index = hashFunction(key);
	if (!table[index].empty()) {
		for (auto pair = table[index].begin(); pair != table[index].end(); pair++)
		{
			if (pair->first = key)
			{
				table[index].erase(pair);
			}
		}
	}
}



