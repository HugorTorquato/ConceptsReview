

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

void initializeSourceNodeBFS(
    vector< pair<shared_ptr<Node>, vector<int>> > &graphToApplyBFS,
    queue<shared_ptr<Node>> &BFS_queue
){
    graphToApplyBFS.at(0).first->color= color::gray;
    graphToApplyBFS.at(0).first->distance= 0;
    graphToApplyBFS.at(0).first->parent= nullptr;

    BFS_queue.push(graphToApplyBFS.at(0).first);
}

void initializeSourceNodeDFS(
    vector< pair<shared_ptr<Node>, vector<int>> > &graphToApplyBFS,
    stack<shared_ptr<Node>> &BFS_queue
){
    graphToApplyBFS.at(0).first->color= color::gray;
    graphToApplyBFS.at(0).first->distance= 0;
    graphToApplyBFS.at(0).first->parent= nullptr;

    BFS_queue.push(graphToApplyBFS.at(0).first);
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

void initializeSingleSource(
    vector< pair<shared_ptr<Node>, vector<int>> >& graphDefinition,
    queue<shared_ptr<Node>>& _queue
){
    for(
        vector< pair<shared_ptr<Node>, vector<int>> >::iterator it=graphDefinition.begin();
        it != graphDefinition.end(); ++it
    ){
        if(it->first->getId() != 1){
            it->first->distance = infInt;
        } else {
            it->first->distance = 0;
        }

        it->first->parent = nullptr;
        _queue.push(it->first);
    }
}