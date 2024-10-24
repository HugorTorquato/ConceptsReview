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

vector<int> Node::getEdges(){
    return edgesIds;
}

// --------------------------------------------------------
// Graph Methods
// --------------------------------------------------------
vector< pair<shared_ptr<Node>, vector<int>> > GraphsClass::getGraphAsVector(){
    return graphDefinition;
}

void GraphsClass::includeNode(shared_ptr<Node> nodeToInclude){

    // When including a new node, add the id as the length of the graph + 1;
    //TODO: Add a try here to rollback the counter if include feils
    nodeToInclude->setId(sizeOfTheGraph++);

    includeNodeInGraph(nodeToInclude, graphDefinition);
}

vector<shared_ptr<Node>> GraphsClass::BFS_Search(){

    vector<shared_ptr<Node>> BFS_result;
    
    if(graphDefinition.empty()){
        return BFS_result;
    }

    queue<shared_ptr<Node>> BFS_queue;
    vector< pair<shared_ptr<Node>, vector<int>> > graphToApplyBFS = graphDefinition;

    initializeSourceNode(graphToApplyBFS, BFS_queue);

    while (!BFS_queue.empty())
    {
        shared_ptr<Node> nodeToEvaluate = BFS_queue.front();
        BFS_queue.pop();

        vector<int> childNodes = nodeToEvaluate->getEdges();

        for(int it : childNodes){

            shared_ptr<Node> node = retrieveNodePonterFromGraph(it, graphToApplyBFS);
            if(node->color == color::white){
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




