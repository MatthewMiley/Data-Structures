#include "SLList.hpp"
#include <iostream>

SLList::SLList(){
    head=nullptr;
    list_size=0;
}

unsigned SLList::size() const{
    return list_size;

}


bool SLList::empty() const{
    return (size()==0);

}

void SLList::push_front(int val){
    // add new node at the beginning
    //SLLNode* new_node = new SLLNode(val);
    //new_node->next=head;
    //head=new_node;

    //alternate way
    head=new SLLNode(val, head);

    list_size++;
}


void SLList::print() const{
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

void SLList::push_back(int val){
    
    
    SLLNode* newNode= new SLLNode(val, nullptr); //Need to understand this line look at SLLNode.hpp
    
    //check to make sure that there is a first node
    if (head == nullptr) {
        head = newNode;
    } 
    else {
        SLLNode* cur=head;

        while(cur->next != nullptr){ //loop until the next value equals nullptr
            cur= cur->next; //go to the next node
        }
        cur->next=newNode;
    }
    list_size++;

}