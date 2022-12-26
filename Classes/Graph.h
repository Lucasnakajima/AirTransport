//
// Created by Utilizador on 26-Dec-22.
//

#ifndef AIRTRANSPORT_GRAPH_H
#define AIRTRANSPORT_GRAPH_H

#include <list>
#include <vector>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;// As the node been visited on a search?
        int color;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // Depth-First Search: example implementation
    void dfs(int v);
    void dfsTopo(int v, list<int>& order);
    // ----- Functions to implement in this class -----
    int outDegree(int v);
    int weightedOutDegree(int v);
    int connectedComponents();
    int giantComponent();
    list<int> topologicalSorting();
    bool hasCycle();

    int dfsGC(int v);
    void dfsCycle(int v, int& count);
};


#endif //AIRTRANSPORT_GRAPH_H
