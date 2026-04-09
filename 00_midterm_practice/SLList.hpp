#ifndef SLLIST_H
#define SLLIST_H

#include "SLLNode.hpp"

template <typename T>
class SLList{

    public:
        //no-arg constructor
        SLList();

        //copy constructor (todo)
        SLList(const SLList<T>& otherlistclass);
        //used for creating a new SLList object but then does the same as assignment opperator



        //assignment operator(todo)
        SLList<T>& operator=(const SLList<T>& otherlistclass);
        //used for overwriting an exsisting object
        //copy one linked list onto another linked list by removing the list1 and deallocating the memory at list1
        //then make a new memory location for list 1
        //then copy each item from list 2 at the new location of list 1

        
        //go down for more todo


        //Destructor
        ~SLList();

        unsigned    size() const; //returns the size of the list
        bool        empty() const; //returns true if list is empty
        void        push_front(const T& val); //Inserts the new node at the beginning
        void        print() const; //print the list
        void        push_back(const T& val); //Insert new node at the end

        void        pop_front(); //remove the first element (node)

        void        clear(); //will clear the list
        void        pop_back(); //remove the last element (node)
        void        searchdelete(const T& val);


    private:
        SLLNode<T>* head; //the pointer to the last node
        SLLNode<T>* tail; //the pointer to the first node
        unsigned list_size;


};


#endif