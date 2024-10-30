#include "Graphs.h"
#include "HelperMethods.cpp"

GraphsClass::GraphsClass(){

}

int GraphsClass::return1ToTest(){
    return 1;
}

// --------------------------------------------------------
// Node Methods
// --------------------------------------------------------

void Node::setData(const int &_data){
    data = _data;
}

int Node::getData(){
    return data;
}

void Node::setId(const int &_id){
    id = _id;
}

int Node::getId(){
    return id;
}

void Node::includeEdge(const int &_edge){
    edgesIds.push_back(_edge);
}

void Node::includeWeightedEdge(const int& _edge, const int& _weight){
    weightedEdges[_edge] = _weight;
    includeEdge(_edge);
}

vector<int> Node::getEdges(){
    return edgesIds;
}

// --------------------------------------------------------
// Graph Methods
// --------------------------------------------------------
vector< pair<shared_ptr<Node>, vector<int>> > GraphsClass::getGraphAsVector(){
    return graphDefinition;
}

void GraphsClass::includeEdgeFromTo(const int &fromNode, const int &toNode){

    if(graphDefinition.empty()){
        return;
    }

    for (
        vector< pair<shared_ptr<Node>, vector<int>> >::iterator it=graphDefinition.begin();
         it < graphDefinition.end(); it++)
    {
        if(it->first->getId() == fromNode){
            it->first->includeEdge(toNode);
            it->second.push_back(toNode);
            break;
        }
    } 
}

void GraphsClass::includeNode(shared_ptr<Node> nodeToInclude){

    // When including a new node, add the id as the length of the graph + 1;
    //TODO: Add a try here to rollback the counter if include feils
    nodeToInclude->setId(++sizeOfTheGraph);

    cout<< "[GraphsClass::includeNode] nodeToEvaluate id: " << nodeToInclude->getId() << endl;

    includeNodeInGraph(nodeToInclude, graphDefinition);
}

vector<shared_ptr<Node>> GraphsClass::BFS_Search(){

    vector<shared_ptr<Node>> BFS_result;
    queue<shared_ptr<Node>> BFS_queue;
    vector< pair<shared_ptr<Node>, vector<int>> > graphToApplyBFS = graphDefinition;
    
    if(graphDefinition.empty()){
        return BFS_result;
    }

    initializeSourceNodeBFS(graphToApplyBFS, BFS_queue);

    while (!BFS_queue.empty())
    {
        shared_ptr<Node> nodeToEvaluate = BFS_queue.front();
        BFS_queue.pop();

        cout<< "[GraphsClass::BFS_Search] nodeToEvaluate ID: " << nodeToEvaluate->getId() << endl;

        vector<int> childNodes = nodeToEvaluate->getEdges();

        //for(vector<int>::iterator it=childNodes.begin(); it != childNodes.end(); ++it){
        for(int it : childNodes){
            cout<< "[GraphsClass::BFS_Search] Node ID: " << it << endl;
            shared_ptr<Node> node = retrieveNodePonterFromGraph(it, graphToApplyBFS);
            if(node && node->color == color::white){
                node->color = color::gray;
                node->distance = nodeToEvaluate->distance + 1;
                node->parent = nodeToEvaluate;
                BFS_queue.push(node);
            }
        }
        nodeToEvaluate->color = color::black;
        BFS_result.push_back(nodeToEvaluate);
    }

    return BFS_result;
}

vector<shared_ptr<Node>> GraphsClass::DFS_Search(){

    vector<shared_ptr<Node>> BFS_result;
    stack<shared_ptr<Node>> BFS_stack;
    vector< pair<shared_ptr<Node>, vector<int>> > graphToApplyBFS = graphDefinition;
    
    if(graphDefinition.empty()){
        return BFS_result;
    }

    initializeSourceNodeDFS(graphToApplyBFS, BFS_stack);

    while (!BFS_stack.empty())
    {
        shared_ptr<Node> nodeToEvaluate = BFS_stack.top();
        BFS_stack.pop();

        cout<< "[GraphsClass::BFS_Search] nodeToEvaluate ID: " << nodeToEvaluate->getId() << endl;

        vector<int> childNodes = nodeToEvaluate->getEdges();

        //for(vector<int>::iterator it=childNodes.begin(); it != childNodes.end(); ++it){
        for(int it : childNodes){
            cout<< "[GraphsClass::BFS_Search] Node ID: " << it << endl;
            shared_ptr<Node> node = retrieveNodePonterFromGraph(it, graphToApplyBFS);
            if(node && node->color == color::white){
                node->color = color::gray;
                node->distance = nodeToEvaluate->distance + 1;
                node->parent = nodeToEvaluate;
                BFS_stack.push(node);
            }
        }
        nodeToEvaluate->color = color::black;
        BFS_result.push_back(nodeToEvaluate);
    }

    return BFS_result;
}



vector<shared_ptr<Node>> GraphsClass::Dijkstra_ShortestPath(){

    vector<shared_ptr<Node>> _result;
    vector<shared_ptr<Node>> _unvisitedNodes;
    vector< pair<shared_ptr<Node>, vector<int>> > graphToApplyDijkstra = graphDefinition;

    initializeSingleSource(graphToApplyDijkstra, _unvisitedNodes);

    while (hasNodeToVisit(_unvisitedNodes))
    {
        shared_ptr<Node> nodeUnderValidation = returnNodeWithSmallestValidWeight(_unvisitedNodes);
        nodeUnderValidation->color = gray;
        _result.push_back(nodeUnderValidation);

        printResultVectorID(_result);

        cout << "[GraphsClass::Dijkstra_ShortestPath] Node : " << nodeUnderValidation->getId()<< endl;

        for(int node : nodeUnderValidation->getEdges()){
            cout << "       Edge To : " << node << " Weight : " << nodeUnderValidation->weightedEdges[node] << endl; 
        
            shared_ptr<Node> adjNodeFromEvaluated = retrieveNodePonterFromGraph(node, graphToApplyDijkstra);

            cout<< "[GraphsClass::Dijkstra_ShortestPath] Adj node ID: " << adjNodeFromEvaluated->getId() << endl;

            relaxNodeData(nodeUnderValidation, adjNodeFromEvaluated);

            cout<< "[GraphsClass::Dijkstra_ShortestPath] parent ID: " << adjNodeFromEvaluated->parent->getId() << endl;
        
        }  
    }

    return _result;
}

vector<shared_ptr<Node>> GraphsClass::Bellman_Ford_ShortestPath(){

    vector<shared_ptr<Node>> _result;
    vector< pair<shared_ptr<Node>, vector<int>> > graphToApplyBellman = graphDefinition;

    vector<shared_ptr<Edge>> _edgesToVerify;



    initializeSingleSource(graphToApplyBellman);

    //Loop trought all vertices
    for(pair<shared_ptr<Node>, vector<int>> vertice : graphToApplyBellman){
        //Loop trought all adj nodes
        cout << "Vertice, ID, under evaluation : " << vertice.first->getId() << endl;

        for(int edge : vertice.first->getEdges()){
            // Get the adj node
            // compare with the current node

            shared_ptr<Node> adjNodeFromEvaluated = retrieveNodePonterFromGraph(edge, graphToApplyBellman);
            cout << "Adj vertice, ID, under evaluation : " << adjNodeFromEvaluated->getId() << endl;

            // Compare the node under evaluation ( vertice ->first ), with the adj one
            // if weight values are smaller, update it
            //relaxNodeData(vertice.first, adjNodeFromEvaluated);

            //Create another vector to store the edges. It'll be used in the end to loop and relax them
            _edgesToVerify.push_back(
                make_shared<Edge>(
                    vertice.first,
                    adjNodeFromEvaluated,
                    vertice.first->weightedEdges[adjNodeFromEvaluated->getId()]
                )
            );

        }

        peformRelaxingInAllEdges(_edgesToVerify, _result);

        _result.push_back(vertice.first);
        printResultVectorID(_result);
        printResultVectorDistance(_result);
    }

    peformRelaxingInAllEdgesCheck(_edgesToVerify, _result);

    return _result;
}
