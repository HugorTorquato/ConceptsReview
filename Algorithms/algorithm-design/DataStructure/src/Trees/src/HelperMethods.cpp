

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