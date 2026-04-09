#ifndef SLLIST_H
#define SLLIST_H

#include "SLLNode.hpp"


class SLList{

    public:
        //no-arg constructor
        SLList();

        unsigned    size() const; //returns the size of the list
        bool        empty() const; //returns true if list is empty
        void        push_front(int val); //Inserts the new node at the beginning
        void        print() const; //print the list
        
        //todo below
        void        push_back(int val); //Insert new node at the end



    private:
        SLLNode* head;
        unsigned list_size;


};


#endif