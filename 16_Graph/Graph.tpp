#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>

template <typename T>
int Graph<T>::getVertexIndex(const T& value) const {
    int i = 0;
    for (const auto& v : vertices) {
        if (v == value) {
            return i;
        }
        i++;
    }

    return -1; // No element
}

template <typename T>
void Graph<T>::insertVertex(const T& value) {
    if (getVertexIndex(value) != -1) {
        std::cout << "insertVertex: vertex already exists\n";
        return;
    }
    vertices.push_back(value);  // Add the new vertex
    std::vector<int> tmp;
    edges.push_back(tmp);       // Empty list of neighbours for the new vertex
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2) {
    int i1 = getVertexIndex(v1);
    int i2 = getVertexIndex(v2);
    if (i1 == -1 || i2 == -1) {
        std::cout << "insertEdge: incorrect vertices\n";
        return;
    }
    edges[i1].push_back(i2);
    if (i1 != i2) {
        edges[i2].push_back(i1);
    }
}

 


template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << "{ " << vertices[i] << ": ";
        for (int j = 0; j < edges[i].size(); j++) {
            std::cout << vertices[edges[i][j]] << " ";
        }
        std::cout << "}\n";
    }
}

template<typename T>
void Graph<T>::DFS() const {
    if (vertices.empty()) {
        return;
    }
    
    //track visited status for all vertices 
    std::vector<bool> visited(vertices.size(), false);

    //sterate through all vertices to handle disconnected components
    for (int i = 0; i < vertices.size(); i++) {
        if (!visited[i]) {
            //start a DFS traversal for each unvisited component
            DFS(i, visited);
            std::cout << " (Component End)" << std::endl;
        }
    }
}

template<typename T>
void Graph<T>::DFS(int i, std::vector<bool>& visited) const{
    visited[i]=true;
    std::cout<<vertices[i]<<" -> ";

    //Look through all the neighbors
    for(int j:edges[i]){
        if(!visited[j]){
            DFS(j, visited);
        }
    }
}

template<typename T>
void Graph<T>::BFS(int start) const{
    if(vertices.empty()){
        return;
    }

    std::vector<bool> discovered(vertices.size(), false);
    std::queue<int> where_to_go;

    where_to_go.push(start);
    discovered[start]=true;

    while(!where_to_go.empty()){
        int cur=where_to_go.front();
        std::cout<<vertices[cur]<<" -> ";
        where_to_go.pop();

        //explore the neighbors
        for(int j:edges[cur]){
            if(!discovered[j]){
                where_to_go.push(j);
                discovered[j]=true;
            }
        }
    }

}