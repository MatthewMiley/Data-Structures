#include "CLList.hpp"

#include <iostream>

template <typename T>
CLList<T>::CLList() {
    tail = nullptr;
    list_size = 0;
}

template <typename T>
bool CLList<T>::empty() const {
    return (list_size == 0);
}

template <typename T>
void CLList<T>::push_front(const T& val) { //insert node at beginning
    if (empty()) {
        tail = new DLLNode<T>(val);
        tail->prev = tail;
        tail->next = tail;
    }
    else {
        DLLNode<T>* newnode = new DLLNode<T>(val, tail, tail->next); //create a new node who's prev points to tail 
        // and next points to the tail's former next

        tail->next->prev=newnode; //update the old head prev variable to contain the new node
        tail->next = newnode; //set the tail next variable to equal the new node
    }
    
    list_size++;
}

template <typename T>
void CLList<T>::print() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail->next;
    do {
        std::cout << cur->data;
        if (cur != tail) { // not the last node
            std::cout << " -> ";
        }
        cur = cur->next;
    } while (cur != tail->next);
    
    std::cout << std::endl;
}

template <typename T>
void CLList<T>::print_backwards() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail;

    do {
        std::cout << cur->data;
        if (cur != tail->next) { // not the last node
            std::cout << " <- ";
        }
        cur = cur->prev;
    } while (cur != tail);
    
    std::cout << std::endl;
}




// Insert at the end
template <typename T>
void CLList<T>::push_back(const T& val){
    push_front(val);
    tail=tail->next;
}


// Remove the last element (node)
template <typename T>
void CLList<T>::pop_back(){
    if (empty()){
        return;
    }
    DLLNode<T>* to_delete=tail; //temp storage pointer holds the current last node
    if(list_size==1){
        tail=nullptr; //deleting last makes no items in list, therefore null
    }
    else{
        tail->prev->next=tail->next; //node before last node pointed to first node
        tail->next->prev=tail->prev; //point first node to node before last node 
        tail=tail->prev; //set tail(last node) equal to the node before the old last node
    }
    //delete the old last node
    delete to_delete;
    list_size--;
}

// Remove the first element (node)
template <typename T>
void CLList<T>::pop_front(){
    //repeat same beginning code from pop_back
    if (empty()){
        return;
    }
    DLLNode<T>* to_delete=tail->next; //temp storage pointer holds the current first node(head)
    if(list_size==1){
        tail=nullptr; //deleting last makes no items in list, therefore null
    }
    else{
        tail->next=to_delete->next; //set last node's next var equal to the node after the old first node
        to_delete->next->prev=tail; //set new first node prev var equal to the last node
    }
    //delete the old last node
    delete to_delete;
    list_size--;
}





