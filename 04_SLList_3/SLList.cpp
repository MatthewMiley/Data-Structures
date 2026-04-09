#include "SLList.hpp"
#include <iostream>

template<typename T>
SLList<T>::SLList(){
    head=nullptr;
    tail=nullptr;
    list_size=0;
}

//im not sure the function of ::?


//copy one linked list onto another new linked list 
//copy each item from list 2 at the new location of list 1
template<typename T>
SLList<T>::SLList(const SLList<T>& otherlistclass){
    head=nullptr;
    tail=nullptr;
    list_size=0;

    SLLNode<T>* cur= otherlistclass.head;
    //cur only exsists in the code when the copy constructor is run, stores the memory address of the 
    //head variable from the SLList class we put into the input of the copy constructor
    //head is the first node in the linked list, therefor cur is the address of the first item in the other list

    while(cur!=nullptr){
        push_back(cur->data); //adds new node to the end of the new list it has the address of the node and the ->data takes 
        //the data from the cur node and puts that data in the new node 
        //(data is in the SLLNode class, which is stored in the SLList class)
        cur=cur->next; //sets cur equal to the next address in the previous list 
    }
}

//I need help understanding the layout of the 34th line (is the defining line of a function a header?)
template<typename T>
SLList<T>& SLList<T>::operator=(const SLList<T>& otherlistclass){
    if(this==&otherlistclass){//I get that the "this" value is the address of the current list but Ive never used it before
        return *this;
    }
    clear();
    SLLNode<T>* cur= otherlistclass.head;
    while(cur!=nullptr){
        push_back(cur->data);
        cur=cur->next; 
    }
    return *this; //returns the new overwritten list
}

template<typename T>
SLList<T>::~SLList(){
    clear();
}

template<typename T>
unsigned SLList<T>::size() const{
    return list_size;
}

template<typename T>
bool SLList<T>::empty() const{
    return (size()==0);

}


template<typename T>
void SLList<T>::push_front(const T& val){
    // add new node at the beginning
    //SLLNode* new_node = new SLLNode(val);
    //new_node->next=head;
    //head=new_node;

    //alternate way
    head=new SLLNode<T>(val, head);
    list_size++;
    if (size()==1){
        tail=head;
    }
}

template<typename T>
void SLList<T>::print() const{
    std::cout<<"[";
    
    SLLNode* cur=head;
    while(cur){
        std::cout<<cur->data;
        if(cur->next){
            std::cout<<" -> ";
        }
        cur=cur->next; //goes to next node
    }
    std::cout<<"}\n";
}

template<typename T>
void SLList<T>::push_back(const T& val){
    //check to make sure that there is a first node
    if (empty()) {
        push_front(val);
        return;
    } 
    tail->next=new SLLNode<T>(val);//add the node to the end
    tail=tail->next; //move the tail
    list_size++;
}

template<typename T>
void SLList<T>::pop_front(){
    if (!empty()) {
        SLLNode<T>* old_head=head;
        head=head->next; //need to understand the head->next being assigned to current head
                                                //What ^ means?
        delete old_head;//free memory
        list_size--;
        if(empty()){
            tail=head;
        }
    }
}

template<typename T>
void SLList<T>::clear(){
    while(!empty()){
        pop_front();
    }
}

//delete the last node
template<typename T>
void SLList<T>::pop_back(){
    
    if(empty()){//first check if list is empty
        return;
    }
    
    SLLNode<T>* cur= head;

    if(head==tail){//second check if there is only one item in the list 
        delete head;
        head = nullptr;
        tail = nullptr;
        list_size = 0;
    }
    else{ //if multiple nodes
        while(cur->next!=tail){
            //if the data value "next" of the current node points to a node who's "next" value points at the tail node 
            //which is already assigned to mark the last node then cease loop
            cur=cur->next; //if not then the current node should be set equal to the node pointed to in the current
            //"next" variable
        }
        delete tail;
        tail=cur;
        tail->next=nullptr; 
        list_size--;
    }
}