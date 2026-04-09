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
BTNode<T>* BST<T>::getMinNode() const{
    BTNode<T>* cur = root;
    if(cur->right==nullptr&&cur->left==nullptr){
        return cur;
    }
    while(cur->right!=nullptr&&cur->left!=nullptr){
        cur=cur->left;
    }
}

template <typename T>
BTNode<T>* BST<T>::searchParent(const T& val) const{
    BTNode<T>* cur = root;
    
    if(cur->right==nullptr&&cur->left==nullptr){
        return nullptr;
    }
    while (cur) {
        if (cur->left->data == val ||cur->right->data == val) { // Found the value
            return cur;
        }
        else if(cur->right==nullptr&&cur->left==nullptr){
            return nullptr;
        }
        else if (cur->data > val) { // Value is less than current
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
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
void BST<T>::print(std::string& prefix, BTNode<T>* node, bool isRight) const{
    if(!node){
        return;
    }
    if(node!=root){
        std::cout<<(isRight?"R--":"L--");
    }
    else{
        std::cout<<"---";
    }

    //Print the value of the node
    std::cout<<node->data<<std::endl;

    //Go the next level of the tree
    print(prefix + "  ", node->right, true);
    print(prefix + "  ", node->left, false);

}