

void includeNodeInGraph(
    shared_ptr<Node> nodeToInclude,
    vector< pair<shared_ptr<Node>, vector<int>> > &graphDefinition    
){
    // Include a pair in the graphDefinition vector
        //Define the pair
        // No need to populate vector with child because the graph is empty

    pair<shared_ptr<Node>, vector<int>> nodePairToInclude = make_pair(
        nodeToInclude, nodeToInclude->getEdges()
    );

    graphDefinition.push_back(nodePairToInclude);
}

void initializeSourceNode(
    vector< pair<shared_ptr<Node>, vector<int>> > &graphToApplyBFS,
    queue<shared_ptr<Node>> &BFS_queue
){
    for (
        vector< pair<shared_ptr<Node>, vector<int>> >::iterator it=graphToApplyBFS.begin();
        it != graphToApplyBFS.end(); ++it
    )
    {
        if(it->first->getId() == 1){
            it->first->color = color::gray;
            it->first->distance = 0;
            it->first->parent = nullptr;

            BFS_queue.push(it->first);
            return;
        }
    }
}

shared_ptr<Node> retrieveNodePonterFromGraph(
    const int &desiredNodeId,
    vector< pair<shared_ptr<Node>, vector<int>> > &graphDefinition
){
    for (
        vector< pair<shared_ptr<Node>, vector<int>> >::iterator it=graphDefinition.begin();
        it != graphDefinition.end(); ++it
    )
    {
        if(it->first->getId() == desiredNodeId){
            return it->first;
        }
    }

    return nullptr;
}