
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
    
    list.insert(list.begin()->next->next->next, 5);

    //list.clear();
    

    std::cout << list.count() << std::endl;

    std::cout << "Hello World!\n";
}
