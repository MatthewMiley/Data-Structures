#include "QueueDLL.hpp"
#include "QueueDLL.cpp"

#include <stdexcept>

int main(void){
    QueueDLL<int> q;


    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.print();

    std::cout<< q.dequeue()<<std::endl;
    std::cout<< q.dequeue()<<std::endl;
    std::cout<< q.dequeue()<<std::endl;


//segmentation fault, somthing goes wrong in the

    try{
        q.dequeue();
    }
    catch(std::out_of_range& ex){
        std::cout<<ex.what()<<std::endl;
    }
    return 0;
}



