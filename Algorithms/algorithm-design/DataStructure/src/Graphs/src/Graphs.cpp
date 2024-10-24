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




