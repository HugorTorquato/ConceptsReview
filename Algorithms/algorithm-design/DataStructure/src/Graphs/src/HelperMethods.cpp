

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
    vector<shared_ptr<Node>>& _unvisitedNodes
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
        _unvisitedNodes.push_back(it->first);
        cout << "[initializeSingleSource] Node included in _unvisitedNodes vector : " << it->first->getId() << endl;
    }
}

void relaxNodeData(
    shared_ptr<Node>& nodeUnderEvaluation,
    shared_ptr<Node>& adjNodeFromEvaluated
){
    const int CurrentNodeDistancePlusWeight = 
        nodeUnderEvaluation->distance + nodeUnderEvaluation->weightedEdges[adjNodeFromEvaluated->getId()];

    if(nodeUnderEvaluation != nullptr && adjNodeFromEvaluated->distance > CurrentNodeDistancePlusWeight){
        cout << "[relaxNodeData] Update Distance from : " << adjNodeFromEvaluated->distance << " To " << CurrentNodeDistancePlusWeight << endl;
        adjNodeFromEvaluated->distance = CurrentNodeDistancePlusWeight;
        adjNodeFromEvaluated->parent = nodeUnderEvaluation;
    }
}

shared_ptr<Node> returnNodeWithSmallestValidWeight(
   const vector<shared_ptr<Node>>& _unvisitedNodes
){
    int minimum = infInt;
    shared_ptr<Node> nodeToReturn;

    for(auto node : _unvisitedNodes){
        if(node->color == white && node->distance <= minimum){
            cout << "[returnNodeWithSmallestValidWeight] Evaluating Node : " << node->getId() << endl;
            minimum = node->distance;
            nodeToReturn = node;
        }
    }

    return nodeToReturn;
}

bool hasNodeToVisit(const vector<shared_ptr<Node>>& _unvisitedNodes){

    for(auto node : _unvisitedNodes){
        if(node->color == white){
            return true;
        }
    }

    return false;
}

void printResultVectorID(const vector<shared_ptr<Node>>& _result){
    cout << " result vector = { ";

    for(auto x : _result){
        cout << x->getId() << " ";
    }

    cout << "}" << endl;
}