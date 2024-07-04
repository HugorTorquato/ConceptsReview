#include "HashTableFunctions.h"

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
