#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

template <typename T>
class Graph {
public:
    void insertVertex(const T& value);
    void insertEdge(const T& v1, const T& v2);
    void print() const;

    void DFS() const;
    
    //breadth first search
    void BFS(int start=0) const;
    int shortestPath(const T& source, const T& destination) const;
    //todo:
    bool isConnected() const;


private:   
    std::vector<T> vertices;
    std::vector<std::vector<int>> edges;

    int getVertexIndex(const T& value) const;

    //helper dfs
    void DFS(int i, std::vector<bool>& visited) const;

    
};

#include "Graph.tpp"

#endif

