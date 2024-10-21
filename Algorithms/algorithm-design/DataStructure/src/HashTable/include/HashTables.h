#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

class HashTablesClass {
    public:
        HashTablesClass();

        int return1ToTest();

        std::unordered_map<std::string,int> getHashTable();
        void insertElementsInTheHashTable(const std::string &key, const int &value);

        int retreveValueFromKey(const std::string &key);
        void removeElementBasedOnKey(const std::string &key);
        

    private:
        std::unordered_map<std::string,int> hashTable;
};

// --------------------------------------------------------
