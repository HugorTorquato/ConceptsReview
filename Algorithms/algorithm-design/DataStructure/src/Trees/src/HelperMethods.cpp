#include <queue>

void includeVertice(
    const int &value, 
    std::unordered_map<std::string, std::shared_ptr<BTreeVertice>> &BTree,
    const std::string &key,
    const std::string &rootKey ){

        /*
            //Declare a new vertice -- NEED TO FREE THIS MEMORY
            std::shared_ptr<BTreeVertice> vertice = new BTreeVertice();
        */
       
        // If it does not exist, create a new BTreeVertice and manage it with shared_ptr
        std::shared_ptr<BTreeVertice> vertice = std::make_shared<BTreeVertice>();

        //Populate the values for the new vertice
        vertice->setValue(value);

        //Set the root if valid
        if(!rootKey.empty() && BTree.find(rootKey) != BTree.end()){
            vertice->setRoot(BTree[rootKey]);
        }

        //Include the new vertice in the map
        BTree[key] = vertice;   

}

bool includeElementInTheRootPositionOfTheTreeIfEmpty(
    const std::shared_ptr<BTreeVertice> BTV,
    std::shared_ptr<BTreeVertice> &rootVertice){

    if(rootVertice == nullptr){
        rootVertice = BTV;
        return true;
    }

    return false;
}

void includeElementInTheTreeLeftToRight(
    const std::shared_ptr<BTreeVertice> BTV,
    std::shared_ptr<BTreeVertice> &rootVertice    
){
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

int retrieveNumberOfNodesInTree(
    std::shared_ptr<BTreeVertice> &rootVertice
){
    int count = 0;

    if(rootVertice == nullptr){
        return count;
    }

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

