//
// Created by Utilizador on 26-Dec-22.
//

#ifndef AIRTRANSPORT_GRAPH_H
#define AIRTRANSPORT_GRAPH_H

#include <list>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include "Airport.h"
#include "Airline.h"
#include <iostream>

using namespace std;

class Graph {
    struct destination{
        int src;
        vector<string> Airlines;
    };
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        vector<string> Airlines;
    };

    struct Node {
        unordered_map<int,Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;// As the node been visited on a search?
        int color;
        int distance;
        Airport airport;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed

public:
    vector<Node> nodes; // The list of nodes being represented
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);



    Graph();

    // Add edge from source to destination with a certain weight
    void addEdge(string src, string dest, string comp, int weight = 1);

    // Depth-First Search: example implementation
    void dfs(int v);
    void dfsTopo(int v, list<int>& order);
    int outDegree(int v);
    int weightedOutDegree(int v);
    int connectedComponents();
    int giantComponent();
    list<int> topologicalSorting();
    bool hasCycle();

    int dfsGC(int v);
    void dfsCycle(int v, int& count);
    void bfs(int v);
    int maxbfs(int v);
    int distance(string a, string b);
    int diameter();
    void bfsPath(vector<int> parent[], int src);
    void find_paths(vector<vector<string>>& paths, vector<string>& path, vector<int> parent[], int dest);
};


#endif //AIRTRANSPORT_GRAPH_H
