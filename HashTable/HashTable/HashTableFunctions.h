#pragma once



#include <iostream>
#include <list>
#include <vector>
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
	vector<list<pair<int, string>>> getHashTable();
	int hashFunction(int key);
	void insert(const int key, const string& value);
	string search(const int key);
	void remove(const int key);




	

};

