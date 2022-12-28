//
// Created by Utilizador on 26-Dec-22.
//

#include "Graph.h"

Graph::Graph(){

}

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(string src, string dest, string comp, int weight) {
    int srcIndex=0, destIndex=0;
    for(int i=1; i<nodes.size(); i++){
        if(nodes[i].airport.getCode()==src)
            srcIndex = i;
        if(nodes[i].airport.getCode()==dest)
            destIndex=i;
        if(srcIndex!=0 && destIndex!=0)
            break;
    }

    if (srcIndex<1 || srcIndex>n || destIndex<1 || destIndex>n) return;
    for(auto it=nodes[srcIndex].adj.begin(); it!=nodes[srcIndex].adj.end(); it++)
        if(it->dest==destIndex) {
            it->Airlines.push_back(comp);
            return;
        }
    nodes[srcIndex].adj.push_back({destIndex, weight});
    nodes[srcIndex].adj.back().Airlines.push_back(comp);
    if (!hasDir) nodes[destIndex].adj.push_back({srcIndex, weight});
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

void Graph::bfs(int v) {
    for (int i = 1; i <= n; i++){ nodes[i].visited = false; nodes[i].distance = -1;}
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        // show node order
        //cout << u << " ";
        for (auto e: nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance+1;
            }
        }
    }
}

int Graph::maxbfs(int v) {
    int max = 0;
    for (int i = 1; i <= n; i++){ nodes[i].visited = false; nodes[i].distance = -1;}
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        // show node order
        //cout << u << " ";
        for (auto e: nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance+1;
                if(nodes[w].distance == -1){
                    return -1;
                }
                else if(nodes[w].distance > max) max = nodes[w].distance;
            }
        }
    }
    return max;
}

int Graph::distance(string a, string b) {
    int srcIndex=0, destIndex=0;
    for(int i=0; i<nodes.size(); i++){
        if(nodes[i].airport.getCode()==a)
            srcIndex = i;
        if(nodes[i].airport.getCode()==b)
            destIndex=i;
        if(srcIndex!=0 && destIndex!=0)
            break;
    }

    bfs(srcIndex);
    return nodes[destIndex].distance;
}

int Graph::diameter() {
    int max = 0;
    for(int i = 0; i<nodes.size(); i++){
        if(!nodes[i].visited && i>1) return -1;
        int res = maxbfs(i);
        if(res == -1) return -1;
        else if(res> max) max = res;
    }
    return max;
}

bool Graph::bfsPath(int src, int dest, destination *pred, Airport *airports) {
    for (int i = 1; i <= n; i++){ nodes[i].visited = false; nodes[i].distance = -1; pred[i].src = -1;}
    queue<int> q;
    q.push(src);
    nodes[src].visited = true;
    nodes[src].distance = 0;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        for (auto e: nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance + 1;
                pred[w].src = u;
                pred[w].Airlines = e.Airlines;
                airports[w] = nodes[u].airport;
                if(w==dest)
                    return true;
            }
        }
    }
    return false;
}

vector<vector<string>> Graph::Path(string src, string dest) {
    int srcIndex=0, destIndex=0;
    for(int i=0; i<nodes.size(); i++){
        if(nodes[i].airport.getCode()==src)
            srcIndex = i;
        if(nodes[i].airport.getCode()==dest)
            destIndex=i;
        if(srcIndex!=0 && destIndex!=0)
            break;
    }
    vector<vector<string>> path;
    Airport airports[nodes.size()];
    destination pred[nodes.size()];
    if(bfsPath(srcIndex, destIndex, pred, airports)){
        vector<string> tmp;
        int crawl = destIndex;
        tmp.push_back(nodes[crawl].airport.getCode());
        for(int i=0; i<pred[crawl].Airlines.size(); i++){
            tmp.push_back(pred[crawl].Airlines[i]);
        }
        path.push_back(tmp);
        crawl = pred[crawl].src;
        while (pred[crawl].src != -1) {
            tmp.clear();
            tmp.push_back(nodes[crawl].airport.getCode());
            for(int i=0; i<pred[crawl].Airlines.size(); i++){
                tmp.push_back(pred[crawl].Airlines[i]);
            }
            path.push_back(tmp);
            crawl = pred[crawl].src;
        }
        tmp.clear();
        tmp.push_back(nodes[crawl].airport.getCode());
        path.push_back(tmp);
    }
    return path;
}

void Graph::bfstest(vector<int> *parent, int src) {
    vector<int> dist(nodes.size(), 1000000000);
    queue<int> q;
    q.push(src);
    parent[src] = {-1};
    nodes[src].visited = true;
    dist[src] = 0;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        for (auto e: nodes[u].adj) {
            int w = e.dest;
            if (dist[w] > dist[u] + 1){

                // A shorter distance is found
                // So erase all the previous parents
                // and insert new parent u in parent[v]
                dist[w] = dist[u] + 1;
                q.push(w);
                parent[w].clear();
                parent[w].push_back(u);
            }
            else if(dist[w]==dist[u]){
                parent[w].push_back(u);
            }
        }
    }
}

void Graph::find_paths(vector<vector<string>> &paths, vector<string> &path, vector<int> *parent, int dest) {
    if(dest == -1) {
        paths.push_back(path);
        return;
    }

    for(int par : parent[dest]){
        path.push_back(nodes[dest].airport.getCode());
        find_paths(paths, path, parent, par);
        path.erase(path.begin()+1, path.end());
    }
}


