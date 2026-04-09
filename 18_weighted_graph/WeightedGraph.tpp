#include "WeightedGraph.hpp"
#include <iostream>
#include <queue>
#include <climits>
#include "MinHeap.hpp"

//Thought exercise:
//build a graph of what cities youve visited and put distances and connected verticies



template <typename T>
void WeightedGraph<T>::insertVertex(const T& v) {
    if (getVertexIndex(v) != -1) {
        std::cout << "insertVertex: vertex already exist\n";
        return;
    }

    vertices.push_back(v);
    std::vector<Edge> tmp; // TODO
    edges.push_back(tmp); //insert empty vector to the edges
}





// TODO
template <typename T>
void WeightedGraph<T>::insertEdge(const T& v1, const T& v2, int weight) {
    int i1 = getVertexIndex(v1);
    int i2 = getVertexIndex(v2);
    if (i1 == -1 || i2 == -1) {
        std::cout << "insertEdge: incorrect vertices\n";
        return;
    }

    if (!hasEdge(i1, i2)) {
        edges[i1].push_back(Edge(i2, weight));
        if (i1 != i2) {
            edges[i2].push_back(Edge(i1, weight));
        }
    }
}   





template <typename T>
int WeightedGraph<T>::getVertexIndex(const T& ver) const {
    for(int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == ver) {
            return i;
        }
    }

    return -1;
}




template <typename T>
void WeightedGraph<T>::print() const {
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << "{ " << vertices[i] << ": ";
        for(int j = 0; j < edges[i].size(); j++) {
            std::cout << "("<<vertices[edges[i][j].neighbor] << ", "<< edges[i][j].weight<<") ";
        }
        std::cout << " }\n";
    }
}




template <typename T>
bool WeightedGraph<T>::hasEdge(int i1, int i2) const {
    if (i1 < 0 || i1 >= edges.size()) {
        return false;
    }

    for (const Edge& e : edges[i1]) {
        if (e.neighbor == i2) {
            return true;
        }
    }

    return false;
}



template <typename T>
void WeightedGraph<T>::DFS() const {
    if (vertices.empty()) {
        return;
    }
    // Create a record of which cities we have already visited
    std::vector<bool> visited(vertices.size(), false);
    // Start the recursive exploration from the first vertex (index 0)
    DFS(0, visited);
    std::cout << "DONE" << std::endl;
}




template <typename T>
bool WeightedGraph<T>::isConnected() const {
    if (vertices.empty()) {
        return true; // An empty graph is technically connected
    }

    std::vector<bool> visited(vertices.size(), false);
    
    // Perform a DFS starting from city 0
    DFS(0, visited);

    // After the DFS, check the "visited" list
    for (bool reached : visited) {
        // If any city is still 'false', it means it is an isolated island
        if (!reached) {
            return false;
        }
    }

    return true;
}


// TODO
template <typename T>
void WeightedGraph<T>::DFS(int i, std::vector<bool>& visited) const {
    visited[i] = true;
    std::cout << vertices[i] << " -> ";

    // Look through all the neighbours (which are Edge objects)
    for (const Edge& e : edges[i]) {
        // e.neighbor is the index of the city at the end of the road
        if (!visited[e.neighbor]) {
            DFS(e.neighbor, visited);
        }
    }
}

// TODO
template <typename T>
void WeightedGraph<T>::BFS(int start) const {
    // Check if the graph is empty or the starting ID is invalid
    if (vertices.empty() || start < 0 || start >= vertices.size()) {
        return;
    }

    std::vector<bool> discovered(vertices.size(), false);
    std::queue<int> where_to_go;

    // Mark the start city as discovered and put it in the queue
    where_to_go.push(start);
    discovered[start] = true;

    while (!where_to_go.empty()) {
        int cur = where_to_go.front();
        std::cout << vertices[cur] << " ";
        where_to_go.pop();

        // Explore the neighbors of the current city
        for (const Edge& e : edges[cur]) {
            // If we haven't seen this neighbor city yet, add it to the queue
            if (!discovered[e.neighbor]) {
                where_to_go.push(e.neighbor);
                discovered[e.neighbor] = true;
            }
        }
    }   
    std::cout << std::endl;
}

// TODO
template <typename T>
int WeightedGraph<T>::shortestPath(const T& src, const T& dest) const {
    // Find indices
    //i_src is the node you start at
    int i_src = getVertexIndex(src);
    //i_dest is the node you want to go to
    int i_dest = getVertexIndex(dest);

    // Check edge case
    //if the node you start at or end at is the -1st thats impossible
    if (i_src == -1 || i_dest == -1) {
        std::cout << "shortestPath: incorrect indices";
        return -1;
    }//if the start and end are the same node the distance is zero
    if (i_src == i_dest) {
        return 0;
    }

    // Create distances vector
    std::vector<int> distances(vertices.size(), INT_MAX); // distances from source to all other nodes
    //make a vector named "distances" with "verticies.size()" number of slots
    //we get the distance from the node we are at to "node #"
    //and then set all the distances equal to the max intiger value (our version of infinity)


    distances[i_src]=0;
    //set the distance from our origin node to our origin node equal to zero in the vector

    //create a heap that stores "Edge" objects
    //Edges are the things connecting nodes
    MinHeap<Edge> heap;

    //TODO (you will be fudged if you dont):
    //also make the weighted graph of cities youve visited

    //implement < operator in Edge (this makes sure that edge data structure can be used in < operations)
    heap.insert(Edge(i_src, 0));

        //Go through all unvisited neighbors of the smallest edge
    
        //Check the distance (if the distance is smaller update the distance)

        //Insert the edge into the heap

    //While the heap of edges isn't empty
    while (!heap.empty()) {
        // Get the smallest edge (best candidate) from the heap
        // deleteMin() returns the Edge with the lowest cumulative weight
        //heap will keep track of the paths taken
        Edge current = heap.deleteMin();

        // Optimization: If we found a better way to this node already, skip all the code below and repeat the deleteMin()
        if (current.weight > distances[current.neighbor]) {
            continue;
        }

        // If we reached our destination, we can return the distance immediately
        if (current.neighbor == i_dest) {
            return distances[i_dest];
        }

        // Go through all neighbors of the current node
        // We look inside our adjacency list: edges[current.neighbor]

        //For each Edge (which we will call e) in the list edges[current.neighbor] (which is the paths out of the current node)
        for (const Edge& e : edges[current.neighbor]) {
            
            // Calculate the "Tentative Distance" (Total distance from start to this neighbor)
            //new_dist = (total distance to reach current node) + (distance of the edge to the neighbor)
            int new_dist = distances[current.neighbor] + e.weight;

            //Relaxation: If this path is shorter than any we've seen before, record it
            if (new_dist < distances[e.neighbor]) {
                distances[e.neighbor] = new_dist; // Update the "sticky note" on the map
                
                // Insert this updated path into the heap to explore further
                heap.insert(Edge(e.neighbor, new_dist));
            }
        }
    }

    
    return -1; //no path exists
}