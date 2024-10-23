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
    int count = 0;

    std::queue<std::shared_ptr<BTreeVertice>> treeQueue;
    treeQueue.push(rootVertice);

    while(!treeQueue.empty()){
        std::shared_ptr<BTreeVertice> verticeToEvaluate = treeQueue.front();
        treeQueue.pop();

        std::shared_ptr<BTreeVertice>leftChild = verticeToEvaluate->getLeftChild();
        std::shared_ptr<BTreeVertice>rightChild = verticeToEvaluate->getRightChild();

        if(leftChild != nullptr) {treeQueue.push(leftChild);};
        if(rightChild != nullptr) {treeQueue.push(rightChild);};
        
        count++;
    }

    return count;
}

void BTreesClass::includeVerticeAtTree(const std::shared_ptr<BTreeVertice> BTV){
    // At this moment, the Vertice is already initialized and connected to the respected child
    
    // Verify if the tree is empty
    if(rootVertice == nullptr){
        rootVertice = BTV;
        return;
    }

    std::queue<std::shared_ptr<BTreeVertice>> treeQueue;
    treeQueue.push(rootVertice);

    while(!treeQueue.empty()){
        std::shared_ptr<BTreeVertice> verticeToEvaluate = treeQueue.front();
        treeQueue.pop();

        std::shared_ptr<BTreeVertice>leftChild = verticeToEvaluate->getLeftChild();
        std::shared_ptr<BTreeVertice>rightChild = verticeToEvaluate->getRightChild();

        //If the dequeued node’s left child is NULL:
        if(leftChild == nullptr){            
            //    Insert the new node as the left child of the dequeued node.
            //    Break the loop.
            verticeToEvaluate->setLeftChild(BTV);
            break;
        }

        //If the dequeued node’s right child is NULL:
        if(rightChild == nullptr){            
            //    Insert the new node as the left child of the dequeued node.
            //    Break the loop.
            verticeToEvaluate->setRightChild(BTV);
            break;
        }

        treeQueue.push(leftChild);
        treeQueue.push(rightChild);

        
    }



}