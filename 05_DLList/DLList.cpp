#include "DLList.hpp"
#include <iostream>

template <typename T>
DLList<T>::DLList(){
    head = new DLLNode<T>; //sentinal head node
    tail = new DLLNode<T>; //sentinal head node
    head->next=tail;
    tail->prev=head;
    list_size=0;

}

template <typename T>
void DLList<T>::push_front(const T& val){
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev=head->next; //head=tail

    list_size++;
}

template <typename T>
void DLList<T>::print() const{
    DLLNode<T>* cur=head->next;

    while(cur!=tail){
        std::cout<<cur->data;
        if(cur->next != tail){
            std::cout<<"->";
        }
        cur=cur->next;
    }
    std::cout<<std::endl;
}

template <typename T>
void DLList<T>::pop_back(){
    if(!empty()){
        DLLNode<T>* to_delete=tail->prev;
        tail->prev=to_delete->prev;
        tail->prev->next=tail;

        list_size--;
        delete to_delete;
    }
}

template <typename T>
bool DLList<T>::empty() const{
    return 0;
}
//removes the first node from the list.
template <typename T>
void DLList<T>::pop_front(){
    if (!empty()) {
        DLLNode<T>* temp_node=head->next; //create a new node pointing to the first node after head (since head is empty)
        head->next=temp_node->next; //set the head node's next variable equal to the temp node's next value
        temp_node->next->prev=head; //Set the prev variable of the node "after-after" our head equal to the head
        delete temp_node; 
        //^clear the memory of the temp node now that the new first node has its
        //next and prev values connected to the next node and head
        list_size--;
    }
}


//prints the content of the list from tail to head. (end to beginning)
template <typename T>
void DLList<T>::print_backwards() const{
    if (!empty()){
        DLLNode<T>* current_node=tail->prev; //create a node that points to the last real node (the node before the tail)
        
        while(current_node!=head){
            std::cout<<current_node->data; //print data at the current node
            if(current_node->prev!=head){
                std::cout<<" -> ";//arrow pointing to next previous item
            }
            current_node=current_node->prev;//change current node to next previous node
        }
        std::cout<<"\n";//end
    }
}


//inserts the new node at the end of the list.
template <typename T>
void DLList<T>::push_back(const T& val){
    
    tail->prev = new DLLNode<T>(val, tail->prev, tail); //create new node assigning val to data, node formerly previous to tail 
    // to new node prev, and send new node's next pointing to tail node
    //then set tail's prev variable equal to the new node
    tail->prev->prev->next = tail->prev; //set the old previous node of tail's next value equal to the new node
    list_size++;
    
}