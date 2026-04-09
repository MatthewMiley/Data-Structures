#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

template <typename T, int size = 100>
class QueueArray {
public:
    QueueArray();
    
    int     length() const;//todo
    bool    empty() const;
    bool    full() const;
    void    print() const;
    void    clear(); //todo
    
    void        enqueue(const T& val);
    //throws std::out_of_range exception
    const T&    dequeue();
    const T&    front();//return the first element in the queue (todo)
    
private:
    T data[size]; // An array of 100 elements
    int queue_size;
    int front_idx;
    int back_idx;
};

#endif