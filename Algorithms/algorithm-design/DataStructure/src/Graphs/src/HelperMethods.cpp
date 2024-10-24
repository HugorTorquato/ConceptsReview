

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