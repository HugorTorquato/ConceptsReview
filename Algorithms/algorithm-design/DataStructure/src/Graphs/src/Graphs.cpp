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
    queue<shared_ptr<Node>> _queue;

    initializeSingleSource(graphDefinition, _queue);

    while (!_queue.empty())
    {
        shared_ptr<Node> nodeUnderValidation = _queue.front();
        _queue.pop();

        //Avaliar a distancia com base no que foi a entrada do edge
        cout << "[GraphsClass::Dijkstra_ShortestPath] Node : " << nodeUnderValidation->getId()<< endl;

        for(auto node : nodeUnderValidation->getEdges()){
            cout << "       Edge To : " << node << " Weight : " << nodeUnderValidation->weightedEdges[node] << endl; 
        }

        // Implement the relax








    }
    





    // Output

    for(auto node : graphDefinition){
        cout << "[GraphsClass::Dijkstra_ShortestPath] Node Distance - Initialization - : " << node.first->distance << endl;
        _result.push_back(node.first);
    }

    //Return Initialized distances if no path
    return _result;



}
