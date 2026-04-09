#include "BST.hpp"

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
void BST<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << " ]\n";
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

// template <typename T>
// bool BST<T>::isFullTree() const{
//     return isFullTree(root);
// }

template <typename T>
bool BST<T>::isFullTree() const {
    return isFullTree(root);
}

template <typename T>
bool BST<T>::isFullTree(BTNode<T>* node) const{
    if(!node){
        return true;
    }
    if(node.hasOneChild()){
        return false;
    }
    return isFullTree(node->left) && isFullTree(node->right);
}

//fix this
template <typename T>
BTNode<T>* BST<T>::search(const T& val) const{
    BTNode<T>* cur=root;

    while(cur){
        if (cur->data==val){ //found the value
            return cur;
        }
        else if(cur->data>val){ //value is less than current
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
    return nullptr;
}

template <typename T>
BTNode<T>* BST<T>::getMinNode(BTNode<T>* node) const {
    if (!node) return nullptr;
    BTNode<T>* cur = node;
    while (cur->left) {
        cur = cur->left;
    }
    return cur;
}

template <typename T>
BTNode<T>* BST<T>::searchParent(const T& val) const {
    if (!root || root->data == val) return nullptr;

    BTNode<T>* cur = root;
    while (cur) {
        if ((cur->left && cur->left->data == val) || (cur->right && cur->right->data == val)) {
            return cur;
        }
        if (val < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}

template <typename T>
void BST<T>::deleteLeaf(BTNode<T>* child, BTNode<T>* parent){
    BTNode<T>* cur = root;
    
    //if(cur->right==nullptr&&cur->left==nullptr){
    //    return nullptr;
    //}
    if(parent->left==child){
        parent->left=nullptr;
    }
    else{
        parent->right=nullptr;
    }
    delete child;

}

template<typename T>
void BST<T>::deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent)
{
    if(child == root)
    {
        child = nullptr;
        delete child;
    }

    BTNode<T>* to_replace = (child->left == nullptr) ? child->right : child->left;

    if(parent->left == child)
    {
        parent->left = to_replace;
        delete child;
    }
    else
    {
        parent->right = to_replace;
        delete child;
    }
}

template<typename T>
void BST<T>::print() const{
    std::cout<<"===========================\n";
    print("", root, false);
    std::cout<<"===========================\n";
}


template<typename T>
void BST<T>::print(const std::string& prefix, BTNode<T>* node, bool isRight) const {
    if (!node) return;
    
    std::cout << prefix;
    if (node != root) {
        std::cout << (isRight ? "R--" : "L--");
    } else {
        std::cout << "---";
    }

    std::cout << "[" << node->data <<  ", "<< getHeight(node)<< ", "<<getBalance(node)<<"]"<< std::endl;

    // Use a temporary string for the next recursion level
    print(prefix + "    ", node->right, true);
    print(prefix + "    ", node->left, false);
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
        if (node == root) root = nullptr; // Handle deleting root leaf
        else deleteLeaf(node, parent);
    }
    else if (node->hasOneChild()) { // Fixed typo here
        deleteNodeWithOneChild(node, parent);
    }
    else { 
        deleteNodeWithTwoChildren(node);
    }
}

template <typename T>
void BST<T>::deleteNodeWithTwoChildren(BTNode<T>* node) {
    BTNode<T>* successor = getMinNode(node->right);
    T min_val = successor->data;
    
    // Perform deletion on the successor first
    deleteNode(min_val); 
    
    // Then replace the current node's value
    node->data = min_val;
}

template <typename T>
int BST<T>::getHeight(const BTNode<T>* node) const{
    if(!node){
        return 0;
    }
    int left_height= getHeight(node->left);
    int right_height= getHeight(node->right);

    return(left_height>right_height) ? left_height+1 : right_height+1;
}

template <typename T>
int BST<T>::getBalance(const BTNode<T>* node) const{
    if(!node){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}


template <typename T>
void BST<T>::rotateRight(BTNode<T>* & node){
    if(!node || !node->left){
        return;
    }
    BTNode<T>* left_kid=node->left;
    node->left=left_kid->right;
    left_kid->right=node;
    node=left_kid; //because we pass by the reference of the pointer
}