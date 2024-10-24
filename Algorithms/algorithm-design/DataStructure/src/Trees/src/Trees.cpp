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

BTreeVertice::BTreeVertice(int _value){
    value = _value;
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

// Find a way to populate the rightChild and leftChild

std::shared_ptr<BTreeVertice> BTreesClass::getRootVertice(){
    return rootVertice;
}

int BTreesClass::getNumberOfNodes(){
    return retrieveNumberOfNodesInTree(rootVertice);
}

void BTreesClass::includeVerticeAtTree(const std::shared_ptr<BTreeVertice> BTV){
    // At this moment, the Vertice is already initialized and connected to the respected child
    
    if(includeElementInTheRootPositionOfTheTreeIfEmpty(BTV, rootVertice)){
        return;
    }

    includeElementInTheTreeLeftToRight(BTV, rootVertice);
}

std::queue<int> BTreesClass::retrieveVerticesDataInorderTransversal(){

    std::queue<int> inordertTransversalData;

    if(rootVertice != nullptr){
        
    }

    return inordertTransversalData;
}



// Faz o delete com base no valor do vertice... hummm

void BTreesClass::deleteVerticeAtTree(const int value){

    // If empty, return
    if(rootVertice == nullptr){
        return;
    }

    // If rootNode to be deleted, return
    if(rootVertice->getValue() == value){
        rootVertice = nullptr;
        return;
    }

    std::queue<std::shared_ptr<BTreeVertice>> treeQueue;
    treeQueue.push(rootVertice);

    while (!treeQueue.empty())
    {
        std::shared_ptr<BTreeVertice> verticeToEvaluate = treeQueue.front();
        treeQueue.pop();

        if(verticeToEvaluate->getValue() == value){
            verticeToEvaluate = nullptr;
        }

        // Achar o pai e apontar ele para os filhos desse vertice (se tiver)
        // achar os filhos e
    }
    


}