
#include <iostream>

#include "DoubleLinkedList.h"

int main()
{
    DoubleLinkedList list;
    
    list.pushFront(4);
    list.pushFront(3);
    list.pushFront(2);
    list.pushBack(5);
    list.pushBack(6);
    
    list.popFront();

    list.popBack();

    std::cout << list.count() << std::endl;

    std::cout << "Hello World!\n";
}
