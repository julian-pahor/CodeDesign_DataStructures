
#include <iostream>

#include "DoubleLinkedList.h"

int main()
{
    DoubleLinkedList list;
    
    list.pushFront(4);
    list.pushFront(4);
    list.pushFront(4);
    list.pushBack(5);
    list.pushBack(6);
    
    
    //list.remove(4);
    

    std::cout << list.count() << std::endl;

    std::cout << "Hello World!\n";
}
