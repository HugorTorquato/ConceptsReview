#pragma once



#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class HashTable
{
private:
	vector<list<pair<int, string>>> table;
	int size;
	
public:
	HashTable(int s);
	~HashTable();
	int getSize();

};

