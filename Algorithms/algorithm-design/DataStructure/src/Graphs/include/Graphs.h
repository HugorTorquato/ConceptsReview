#pragma once

#include <Vector>
#include <memory>
#include <queue>
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

const int infInt = 1000000;

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
        void includeWeightedEdge(const int& _edge, const int& _weight);
        vector<int> getEdges();

        //TODO: move to private
        int color = color::white;
        int distance;
        int edgeWeight;
        shared_ptr<Node> parent;

        // Uma forma de incluir edges com pesos....
        // map, sendo o int1 -> node para qual vai e int2 o peso do edge
        unordered_map<int, int> weightedEdges;

    private:
        int data;
        int id;
        vector<int> edgesIds;

        
};

class Edge{
    public:
        shared_ptr<Node> source_U;
        shared_ptr<Node> destination_V;
        int weight;

        Edge(shared_ptr<Node> u, shared_ptr<Node> v, int w) 
            : source_U(u), destination_V(v), weight(w) {}
};


class GraphsClass {
    public:

        GraphsClass();
        int return1ToTest();

        vector< pair<shared_ptr<Node>, vector<int>> > getGraphAsVector();
        void includeNode(shared_ptr<Node> nodeToInclude);
        void includeEdgeFromTo(const int &fromNode, const int &toNode);

        vector<shared_ptr<Node>> BFS_Search();
        vector<shared_ptr<Node>> DFS_Search();


        vector<shared_ptr<Node>> Dijkstra_ShortestPath();
        vector<shared_ptr<Node>> Bellman_Ford_ShortestPath();

    private:
        vector< pair<shared_ptr<Node>, vector<int>> > graphDefinition;

        int sizeOfTheGraph = 0;

};