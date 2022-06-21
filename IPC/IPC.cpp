// IPC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>




int main()
{

    struct MyData
    {
        int i;
        float f;
        char c;
        bool b;
        double d;
    };

    HANDLE fileHandle = CreateFileMapping
    (
        INVALID_HANDLE_VALUE,
        nullptr,
        PAGE_READWRITE,
        0, sizeof(MyData),
        L"MySharedMemory"
    );

    HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");

    CloseHandle(fileHandle);

    MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));

    // write to the memory block 
    
    // write out what is in the memory block 
    std::cout << "MyData = { ";
    std::cout << data->i << ", ";
    std::cout << data->f << ", ";
    std::cout << data->c << ", ";
    std::cout << data->b << ", ";
    std::cout << data->d << ", ";
    std::cout << " };" << std::endl;
    
}
