#include "HashTables.h"

HashTablesClass::HashTablesClass(){

}

int HashTablesClass::return1ToTest(){
    return 1;
}

std::unordered_map<std::string,int> HashTablesClass::getHashTable(){
    return hashTable;
}

void HashTablesClass::insertElementsInTheHashTable(const std::string &key, const int &value){
    hashTable[key] = value;
}

int HashTablesClass::retreveValueFromKey(const std::string &key){
    if(hashTable.find(key) != hashTable.end()){
        return hashTable[key];
    }
    return 0;
}

void HashTablesClass::removeElementBasedOnKey(const std::string &key){
    hashTable.erase(key);
}

// --------------------------------------------------------

HashTableImpClass::HashTableImpClass(){

}

