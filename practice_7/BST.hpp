#ifndef BST_HPP
#define BST_HPP
#include "BTNode.hpp"
#include <string>


template <typename T>
class BST {
public:
    BST();
    
    bool empty() const;
    void inorder() const; // Inorder traversal of the tree
    
    bool isFullTree() const; // Check if the tree is full tree
    
    void print() const;
    
    void insert(const T& val);
    void insert_recursive(const T& val);

    void deleteNode(const T& val);

    // Searching
    BTNode<T>* search(const T& val) const;
    BTNode<T>* searchParent(const T& val) const;
    BTNode<T>*& searchRef(const T& val);
    BTNode<T>* getMinNode() const;
    

    int getHeight(const BTNode<T>* node) const;
    int getBalance(const BTNode<T>* node) const;

    // Tree rotations
    void rotateRightAt(const T& val);
    void rotateRightRef(BTNode<T>*& node);
    void rotateLeftRef(BTNode<T>*& node); // TODO
    
    void rotateLeftDoubleRef(BTNode<T>*& node);
    void rotateRightDoubleRef(BTNode<T>*& node); // TODO
     
    void balance(); 
    
private:
    BTNode<T>* root;
    void inorder(BTNode<T>* node) const;
    bool isFullTree(BTNode<T>* node) const;
    BTNode<T>* insert_recursive(BTNode<T>* node, const T& val);
    BTNode<T>* getMinNode(BTNode<T>* node) const;
    
    void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithTwoChildren(BTNode<T>* node);
    
    void print(const std::string& prefix, BTNode<T>* node, bool isRight) const;
    
    BTNode<T>*& searchRef(const T& val, BTNode<T>*& node);
    BTNode<T>* rotateRight(BTNode<T>* node);
    
    void balance(BTNode<T>*& node);  // TODO
};

#endif