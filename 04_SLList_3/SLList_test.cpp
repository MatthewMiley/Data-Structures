#include "SLList.hpp"
#include "SLList.cpp"
#include <string>

int main(void){
    SLList<std::string> list;

    list.push_front("a");
    list.push_front("b");
    list.push_front("c");
    list.push_front("d");

    list.print();

    return 0;
}