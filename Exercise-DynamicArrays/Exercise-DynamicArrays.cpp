
#include <iostream>
#include "DynamicArray.h"



int main()
{
    DynamicArray array = DynamicArray(5);

    array.AddToEnd(1);
    array.AddToEnd(42);
    array.AddToEnd(43);
    array.AddToEnd(600);
    array.AddToEnd(22);
    array.AddToEnd(23);
    array.Print();


    std::cout << "Hello World!\n";

}

