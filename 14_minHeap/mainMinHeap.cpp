#include "MinHeap.hpp"
#include "MinHeap.cpp"
#include <cstdlib>
#include <vector>


template<typename T>
void heapSort(std::vector<T>& v){
    MinHeap<T> heap(v);

    for(int i=0; i<v.size(); i++){
        v[i] = heap.deleteMin();
    }
}



int main(void){
    MinHeap<int> heap;
    std::vector<int> v;

    for(int i=0; i<10; i++){
        int num = rand()%1000;
        heap.insert(rand() % 1000);
        heap.insert(num);
        v.push_back(num);
    }



    

    // std::cout<<"\n";
    // for(int i=0; i<10; i++){
    //     heap.deleteMin();
    //     heap.print();
    //     std::cout<<"\n----------\n";
    // }

    MinHeap<int> heap2(v);

    heap.print();
    heap2.print();

    return 0;
}