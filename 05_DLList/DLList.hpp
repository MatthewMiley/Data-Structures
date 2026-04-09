#ifndef DLLIST_H
#define DLLIST_H

#include "DLLNode.hpp"

template <typename T>
class DLList{

    public:
        
        DLList();

        //SLList(const SLList<T>& otherlistclass);

        //&<T> operator=(const SLList<T>& otherlistclass);
        
        //~SLList();

        //unsigned    size() const; //returns the size of the list
        bool        empty() const; //returns true if list is empty
        void        push_front(const T& val); //Inserts the new node at the beginning
        void        print() const; //print the list
        
        
        //void        clear(); //will clear the list
        void        pop_back(); //remove the last element (node)
        void        pop_front();
        void        print_backwards() const;
        void        push_back(const T&);


    private:
        DLLNode<T>* head; //the pointer to the last node
        DLLNode<T>* tail; //the pointer to the first node
        unsigned list_size;


};


#endif