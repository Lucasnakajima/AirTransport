//
// Created by Utilizador on 26-Dec-22.
//

#include "Graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}


// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
//
int Graph::outDegree(int v) {
    if(nodes.size() == 0)
        return -1;
    if(v >= nodes.size() || v <= 0)
        return -1;
    return nodes[v].adj.size();
}

// ..............................
// b) Devolvendo o grau... pesado
//
int Graph::weightedOutDegree(int v) {
    if(nodes.size() == 0)
        return -1;
    if(v >= nodes.size() || v <= 0)
        return -1;
    int sum = 0;
    for(auto i : nodes[v].adj)
        sum = sum + i.weight;
    return sum;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
//
int Graph::connectedComponents() {
    int sum=0;
    for(int i = 1; i < nodes.size(); i++){
        if(!nodes[i].visited) {
            sum++;
            dfs(i);
        }

    }
    return sum;
}

int Graph::dfsGC(int v){
    int count = 1;
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            count += dfsGC(w);
    }
    return count;
}

// ..............................
// b) Componente gigante
//
int Graph::giantComponent() {
    int sum=0, res=0;
    for(int i = 1; i < nodes.size(); i++){
        if(!nodes[i].visited) {
            sum = dfsGC(i);
        }
        if(res<sum)
            res = sum;

    }
    return res;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
//

void Graph::dfsTopo(int v, list<int> &order) {
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfsTopo(w, order);
    }
    order.push_front(v);
}
list<int> Graph::topologicalSorting() {
    list<int> order;
    for(int i = 1; i < nodes.size(); i++) {
        if (!nodes[i].visited) {
            dfsTopo(i, order);
        }
    }
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
//

void Graph::dfsCycle(int v, int& count) {
    nodes[v].color=1;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (nodes[w].color == 1) count++;
        else if(nodes[w].color == 0) dfsCycle(w, count);

    }
    nodes[v].color = 2;
}

bool Graph::hasCycle() {
    for(int i = 1; i < nodes.size(); i++) nodes[i].color = 0;
    int count = 0;
    for(int i = 1; i < nodes.size(); i++){
        if(nodes[i].color == 0) dfsCycle(i, count);
    }
    return (count>0);
}