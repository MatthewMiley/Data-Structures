#include <iostream>
#include <string>
#include "BTNode.hpp"
#include "BST.cpp"
#include "BST.hpp"

int main(void){

    //todo make it work
    BST<int> tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);

    tree.print();

    //todo it didnt work with search
    //check with search as an argument
    //will be how to get quiz code
    BTNode<int>* t =tree.search(2);
    tree.rotateRight(t);
    tree.print();

    
    

    return 0;
}