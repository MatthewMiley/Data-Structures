#include "AVLTree.hpp"
#include "AVLTree.cpp"

#include <iostream>
#include <string>

int main(void) {
    AVLTree<int> tree;
    for(int i=1; i<30;i++ ){
        tree.insert(i);
        tree.print();
    }
    
    std::cout<<"Deletion\n";
    for(int i=29; i>=1; i++){
        std::cout<<"Remove "<<i<<std::endl;
        tree.remove(i);
        tree.print();
    }

    
    return 0;
}


