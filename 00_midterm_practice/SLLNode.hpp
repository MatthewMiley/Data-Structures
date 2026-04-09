#ifndef SLLNODE_H
#define SLLNODE_H

template <typename T>
class SLLNode {
    //T()-default template value
    public:

        SLLNode(const T& d=T(), SLLNode<T> *n = nullptr){
            data = d;
            next = n;
        }

        T data;
        SLLNode<T> *next; //pointer to the next node



};

#endif