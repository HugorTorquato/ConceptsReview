#pragma once

#include <Vector>
#include <memory>
#include <queue>

using namespace std;

enum color {
    white,
    gray,
    black
};

class Node {

    public:
        void setData(const int &_data);
        int getData();

        void setId(const int &_id);
        int getId();

        void includeEdge(const int &_edge);
        vector<int> getEdges();

        //TODO: move to private
        int color = color::white;
        int distance;
        shared_ptr<Node> parent;

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

        vector<shared_ptr<Node>> BFS_Search();

    private:
        vector< pair<shared_ptr<Node>, vector<int>> > graphDefinition;

        int sizeOfTheGraph;

};