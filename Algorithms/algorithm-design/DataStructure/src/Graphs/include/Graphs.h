#pragma once

#include <Vector>
#include <memory>

using namespace std;

class Node {

    public:
        void setData(const int &_data);
        int getData();

        void setId(const int &_id);
        int getId();

        void includeEdge(const int &_edge);
        vector<int> getEdges();

    private:
        int data;
        int id;
        vector<int> edgesIds;
};

class GraphsClass {
    public:

        GraphsClass();
        int return1ToTest();

        vector< pair<shared_ptr<Node>, vector<int>> > getGraphAsVector();
        void includeNode(shared_ptr<Node> nodeToInclude);
        void includeEdgeFromTo(const int &fromNode, const int &toNode);

    private:
        vector< pair<shared_ptr<Node>, vector<int>> > graphDefinition;

        int sizeOfTheGraph;

};