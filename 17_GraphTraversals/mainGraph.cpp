#include "Graph.hpp"
#include <string>

int main(void) {
    Graph<std::string> knowledge;

    knowledge.insertVertex("A");
    knowledge.insertVertex("B");
    knowledge.insertVertex("C");
    knowledge.insertVertex("D");
    knowledge.insertVertex("E");
    knowledge.insertVertex("F");
    knowledge.insertVertex("G");
    knowledge.insertVertex("H");
    knowledge.insertVertex("I");
    knowledge.insertVertex("S");
    



    knowledge.insertEdge("A", "B");
    knowledge.insertEdge("A", "S");
    knowledge.insertEdge("C", "S");
    knowledge.insertEdge("G", "S");
    knowledge.insertEdge("C", "F");
    knowledge.insertEdge("C", "E");
    knowledge.insertEdge("C", "D");
    knowledge.insertEdge("E", "H");
    knowledge.insertEdge("G", "H");
    knowledge.insertEdge("G", "F");

    knowledge.insertVertex("J"); //disconnected

    knowledge.print();
    knowledge.DFS();

    knowledge.BFS();

    std::cout<< "A, F"<<knowledge.shortestPath("A","F")<<std::endl;
    std::cout<< "A, D"<<knowledge.shortestPath("A","D")<<std::endl;

    //TODO
    //1. Create a disconnected graph
    //2. update dfs to traverse all the nodes of this graph

    return 0;
}