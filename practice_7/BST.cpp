#include "BST.hpp"
#include <iostream>

template <typename T>
BST<T>::BST() {
    root = nullptr;
}


template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::insert(const T& val) {
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }
    
    // Iterative approach
    BTNode<T>* cur = root;
    BTNode<T>* prev = root;
    while (cur) {
        prev = cur;
        if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    if (prev->data > val) {
        prev->left = new BTNode<T>(val);   
    }
    else {
        prev->right = new BTNode<T>(val);   
    }
}

template <typename T>
void BST<T>::insert_recursive(const T& val) {
    root = insert_recursive(root, val);
}

template <typename T>
BTNode<T>* BST<T>::insert_recursive(BTNode<T>* node, const T& val) {
    if (!node) {
        return new BTNode<T>(val);
    }
    if (val > node->data) {
        node->right = insert_recursive(node->right, val);
        return node;
    } 
    else {
        node->left = insert_recursive(node->left, val);
        return node;
    }
}


template <typename T>
void BST<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << "]\n";
}

template <typename T>
void BST<T>::inorder(BTNode<T>* node) const {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
}


template <typename T>
bool BST<T>::isFullTree() const {
    return isFullTree(root);
}

template <typename T>
bool BST<T>::isFullTree(BTNode<T>* node) const {
    if (!node) {
        return true;
    }
    if (node->hasOneChild()) {
        return false;
    }
    return isFullTree(node->left) && isFullTree(node->right);
}

template <typename T>
BTNode<T>* BST<T>::search(const T& val) const {
    BTNode<T>* cur = root;

    while (cur) {
        if (cur->data == val) { // Found the value
            return cur;
        }
        else if (cur->data > val) { // Value is less than current
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return nullptr;
}


/////------------////

template <typename T>
BTNode<T>* BST<T>::getMinNode() const {
    return getMinNode(root);
}

template <typename T>
BTNode<T>* BST<T>::getMinNode(BTNode<T>* node) const {
    if (!node) {
        return nullptr;
    }
    else if (!node->left) {
        return node;
    }
    return getMinNode(node->left);
}

template <typename T>
void BST<T>::deleteLeaf(BTNode<T>* child, BTNode<T>* parent) {
    if (!child) {
        return;
    }
    if (!parent) { // This is the root
        delete root;
        root = nullptr;
        return;
    }
    if (parent->left == child) { //left kid
        parent->left = nullptr;
    }
    else if (parent->right == child) { //right kid
        parent->right = nullptr;
    }

    delete child;
}


template <typename T>
void BST<T>::deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent) {
    if (child == root) {
        BTNode<T>* to_delete = root;
        root = (root->left) ? root->left : root->right;
        delete to_delete;
        return;
    }
    BTNode<T>* grand_kid = (child->right) ? child->right : child->left;
    if (parent->right == child) {
        parent->right = grand_kid;
    }
    if (parent->left == child) {
        parent->left = grand_kid;
    }

    //release the memory
    delete child;
}

template <typename T>
BTNode<T>* BST<T>::searchParent(const T& val) const {
    if(root->data == val) { // Root doesn't have a parent
        return nullptr;
    }
    
    BTNode<T>* node = root;
    BTNode<T>* prev = root;

    while (node) {
        if (node->data == val) {
            return prev;
        }
        prev = node;
        if (val < node->data) {
            node = node->left;
        }
        else if (val > node->data) {
            node = node->right;
        }
    }

    return nullptr;
}

template <typename T>
void BST<T>::print() const {
    std::cout << "===============================\n";
    print("", root, false);    
    std::cout << "===============================\n";
}

template <typename T>
void BST<T>::print(const std::string& prefix, BTNode<T>* node, bool isRight) const {
    if (!node) {
        return;
    }
    std::cout << prefix;
    if (node != root) {
        std::cout << (isRight ? "R----" : "L----");
    }
    else {
        std::cout << "---";
    }

    // Print the value of the node
    std::cout << '[' << node->data <<  ", " << getHeight(node) << ", " << getBalance(node) << ']' << std::endl;

    // Go to the next level of the tree
    print(prefix + "     ", node->right, true);
    print(prefix + "     ", node->left, false);

}

template <typename T>
void BST<T>::deleteNode(const T& val) {
    BTNode<T>* node = search(val);

    if (!node) {
        std::cout << "Delete: No value in the BST\n";
        return;
    }
    BTNode<T>* parent = searchParent(val);

    if (node->isLeaf()) {
        deleteLeaf(node, parent);
    }
    else if (node->hasOneChild()) {
        deleteNodeWithOneChild(node, parent);
    }
    else {  // The node has 2 children
        deleteNodeWithTwoChildren(node);
    }

}

template <typename T>
void BST<T>::deleteNodeWithTwoChildren(BTNode<T>* node) {
    BTNode<T>* min_right_node = getMinNode(node->right);
    T min_val = min_right_node->data;

    if (min_right_node->isLeaf()) {
        deleteLeaf(min_right_node, searchParent(min_val));
    }
    else if (min_right_node->hasOneChild()) {
        deleteNodeWithOneChild(min_right_node, searchParent(min_val));
    }
    node->data = min_val;
}

template <typename T>
int BST<T>::getHeight(const BTNode<T>* node) const {
    if (!node) {
        return 0;
    }
    int left_height = getHeight(node->left); 
    int right_height = getHeight(node->right);
    
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}


template <typename T>
int BST<T>::getBalance(const BTNode<T>* node) const {
    if (!node) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
void BST<T>::rotateRightAt(const T& val) {
    BTNode<T>* node = search(val);
    BTNode<T>* parent = searchParent(val);

    if (!node) {
        return;
    }
    else if (!parent) {
        root = rotateRight(root);
    }
    else if (parent->left == node) {
        parent->left = rotateRight(parent->left);
    }
    else {
        parent->right = rotateRight(parent->right);
    }
}

template <typename T>
BTNode<T>* BST<T>::rotateRight(BTNode<T>* node) {
    if (!node || !node->left) {
        return node;
    }
    BTNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;
    
    return left_kid;
}

template <typename T>
BTNode<T>*& BST<T>::searchRef(const T& val) {
    return searchRef(val, root);
}

template <typename T>
BTNode<T>*& BST<T>::searchRef(const T& val, BTNode<T>*& node) {
    if (!node || node->data == val) {
        return node;
    }
    else if (node->data > val) {
        return searchRef(val, node->left);
    }
    else {
        return searchRef(val, node->right);
    }
}

template <typename T>
void BST<T>::rotateRightRef(BTNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }
    BTNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;
    
    node = left_kid;
}

template <typename T>
void BST<T>::rotateLeftRef(BTNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }
    BTNode<T>* right_kid = node->right;
    node->right = right_kid->left;
    right_kid->left = node;
    
    node = right_kid;
}


template <typename T>
void BST<T>::rotateLeftDoubleRef(BTNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }
    rotateRightRef(node->right);
    rotateLeftRef(node);
}

template <typename T>
void BST<T>::rotateRightDoubleRef(BTNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }
    rotateLeftRef(node->left);
    rotateRightRef(node);
}


template <typename T>
void BST<T>::balance() {
    balance(root);
}

template <typename T>
void BST<T>::balance(BTNode<T>*& node) {
    if (!node) {
        return;
    }
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);
    if (left_height - right_height > 1) { //left unbalanced
        if(getHeight(node->left->left) >= getHeight(node->left->right)) {
            rotateRightRef(node);
        }
        else {
            rotateRightDoubleRef(node);
        }
    }
    if (right_height - left_height > 1) { //right unbalanced
        // FINISH THE CODE HERE
        if(getHeight(node->right->right) >= getHeight(node->right->left)) {
            rotateLeftRef(node);
        }
        else {
            rotateLeftDoubleRef(node);
        }
    }
    balance(node->left);
    balance(node->right);
}

//from quiz dont worry about implementing
// template <typename T>
// int BST<T>::count_leaves(BTNode<T>* node){
//     if(!node){
//         return 0;
//     }
//     else if(node->isLeaf()){
//         return 1;
//     }
//     int left_leaves=count_leaves(node->left);
//     int right_leaves=count_leaves(node->right);
    
//     return left_leaves+right_leaves;
// }