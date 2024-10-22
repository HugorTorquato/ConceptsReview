#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

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

class HashTableImpClass {

    //TO DO: 
    // 1- Implement the hashTable using other data structure than unordered_map<>

    public:
        HashTableImpClass();

        //Insert
        //Get
        //Remove
        //Display

    private:

        int hashFunction();

        int size;
        std::vector< std::list< std::pair< std::string, int > > > hashTableImp;

};