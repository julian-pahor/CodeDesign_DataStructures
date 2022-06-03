#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(int* const array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (array[j] < array[j - 1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }

}

void insertionSort(int* const array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
            array[j + 1] = key;
        }
    }
}


int main()
{
    const int size = 100;

    //create a large array
    int* values = new int[size];
    int* valuesToSort = new int[size];

    srand(time(nullptr));
    //and fill it with some ordered data
    for (int i = 0; i < size; i++)
    {
        values[i] = rand() % size;
    }

    high_resolution_clock::time_point t1, t2;

    memcpy(valuesToSort, values, sizeof(int) * size);

    t1 = high_resolution_clock::now();
    bubbleSort(values, size);
    t2 = high_resolution_clock::now();

    for (int i = 0; i < size; i++)
    {
        std::cout << values[i] << ", ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "BubbleSort took = " << (t2 - t1).count() << "nanoseconds" << std::endl;

    //pause
    std::cout << "Press any key to profile InsertionSort" << std::endl;
    std::cin.get();
    std::cout << std::endl;

    //Profile Insertion Sort
    t1 = high_resolution_clock::now();
    insertionSort(valuesToSort, size);
    t2 = high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        std::cout << valuesToSort[i] << ", ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "InsertionSort took = " << (t2 - t1).count() << "nanoseconds" << std::endl;


    delete[] values;
    delete[] valuesToSort;

    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
    return 0;
}

