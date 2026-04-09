#include "SLLNode.hpp"
#include <iostream>

int main(void) {
    //create SLL Nodes
    SLLNode *n1= new SLLNode(1);
    SLLNode *n2= new SLLNode(2);
    SLLNode *n3= new SLLNode(3);
    SLLNode *n4= new SLLNode(4);


    //Alternative creation
    SLLNode* b = new SLLNode(10);
    b->next=new SLLNode(20);
    b->next->next=new SLLNode(30);

    //link the nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    

    //iterate through the nodes (linked list)
    SLLNode *cur=n1;

    while(cur != nullptr){
        std::cout<< cur->data << "->"; //access the data of the current node
        cur= cur->next; //go to the next node
    }


    //free the memory
    delete n1->next->next->next;


    return 0;
}