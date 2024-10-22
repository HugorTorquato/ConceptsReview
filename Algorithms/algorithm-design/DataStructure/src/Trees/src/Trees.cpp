#include "Trees.h"

BTreesClass::BTreesClass(){

}

int BTreesClass::return1ToTest(){
    return 1;
}

// --------------------------------------------------------

BTreeVertice::BTreeVertice(){
    value = 0;
    root = nullptr;
    rightChild = nullptr;
    leftChild = nullptr;
}

int BTreeVertice::getValue(){
    return value;
}

BTreeVertice* BTreeVertice::getRoot(){
    return root;
}

BTreeVertice* BTreeVertice::getRightChild(){
    return rightChild;
}

BTreeVertice* BTreeVertice::getLeftChild(){
    return leftChild;
}

void BTreeVertice::setValue(const int &_value){
    value = _value;
}

void BTreeVertice::setRoot(BTreeVertice* _root){
    root = _root;
}

void BTreeVertice::setRightChild(BTreeVertice* _rightChield){
    rightChild = _rightChield;
}

void BTreeVertice::setLeftChild(BTreeVertice* _leftChield){
    leftChild = _leftChield;
}

// --------------------------------------------------------

void BTreesClass::includeVerticeInBTree(const std::string &key, const int &value, const std::string &root){
    //Verify if this key already exists in the map
    if(BTree.find(key) != BTree.end()){
        //If Yes, Update Value
        BTree[key]->setValue(value);
        
    } else {
        //If No , Include vertice

        //Declare a new vertice
        BTreeVertice* vertice = new BTreeVertice();
        //Populate the values for the new vertice
        vertice->setValue(value);
        //Include the new vertice in the map
        BTree[key] = vertice;

    }
}

BTreeVertice* BTreesClass::getBTreeVerticeFromKey(const std::string &key){
    if(BTree.find(key) != BTree.end()){
        return BTree[key]; 
    }
    return nullptr;
}
