#include "Trees.h"
#include "HelperMethods.cpp"

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

std::shared_ptr<BTreeVertice> BTreeVertice::getRoot(){
    return root;
}

std::shared_ptr<BTreeVertice> BTreeVertice::getRightChild(){
    return rightChild;
}

std::shared_ptr<BTreeVertice> BTreeVertice::getLeftChild(){
    return leftChild;
}

void BTreeVertice::setValue(const int &_value){
    value = _value;
}

void BTreeVertice::setRoot(std::shared_ptr<BTreeVertice> _root){
    root = _root;
}

void BTreeVertice::setRightChild(std::shared_ptr<BTreeVertice> _rightChield){
    rightChild = _rightChield;
}

void BTreeVertice::setLeftChild(std::shared_ptr<BTreeVertice> _leftChield){
    leftChild = _leftChield;
}

// --------------------------------------------------------

void BTreesClass::includeVerticeInBTree(const std::string &key, const int &value, const std::string &rootKey){
    //Verify if this key already exists in the map
    if(BTree.find(key) != BTree.end()){
        //If Yes, Update Value
        BTree[key]->setValue(value);
        
    } else {
        //If No , Include vertice
        includeVertice(value, BTree, key, rootKey);
    }
}

std::shared_ptr<BTreeVertice> BTreesClass::getBTreeVerticeFromKey(const std::string &key){
    if(BTree.find(key) == BTree.end()){
        return nullptr;
    }
    return BTree[key]; 
}
