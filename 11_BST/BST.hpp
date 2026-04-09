#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <string>
#include "BTNode.hpp"


//binary search tree 
template <typename T>
class BST {
    public:
        BST();
        bool empty() const;
        void insert(const T& val);
        // Traversals of the tree
        void inorder() const;
        //todo
        void preorder() const;
        void postorder() const;

        bool isFullTree() const;

        BTNode<T>* getMinNode() const;
        BTNode<T>* searchParent(const T& val) const;
        BTNode<T>* search(const T& val) const;

        void print() const;


    private:
        BTNode<T>* root;
        void inorder(BTNode<T>* node) const;
        bool isFullTree(BTNode<T>* node) const;
        void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
        void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent);

        void print(std::string& prefix, BTNode<T>* node, bool isRight) const;
};

#endif