#include <iostream>
#include <chrono>
#include <math.h>

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

int partition(int* const array, int p, int r)
{
    int x = array[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
    {
        if (array[j] <= x)
        {
            i = i + 1;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[r];
    array[r] = temp;

    return i + 1;
}

void quickSort(int* const array, int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

void merge(int* const array, int startIdx, int midIdx, int endIdx)
{
    int leftEnd = midIdx - startIdx + 1;
    int rightEnd = endIdx - midIdx;

    int* left = new int[leftEnd];
    int* right = new int[rightEnd];

    for (int i = 0; i < leftEnd; i++)
    {
        left[i] = array[startIdx + i];
    }
    for (int j = 0; j < rightEnd; j++)
    {
        right[j] = array[midIdx + j + 1];
    }

    int i = 0, j = 0, k = startIdx;

    while (i < leftEnd && j < rightEnd)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftEnd)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < rightEnd)
    {
        array[k] = right[j];
        j++;
        k++;
    }

    /*for (int k = startIdx; k < endIdx; k++)
    {
        if (j >= rightEnd || i < leftEnd && left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
    }*/
}

void mergeSort(int* const array, int startIdx, int endIdx)
{
    if (startIdx < endIdx)
    {
        int q = (startIdx + endIdx) / 2;
        mergeSort(array, startIdx, q);
        mergeSort(array, q + 1, endIdx);
        merge(array, startIdx, q, endIdx);
    }
}



int main()
{
    const int size = 1000;

    //create a large array
    int* values = new int[size];
    int* valuesToSort = new int[size];
    int* valuesToToSort = new int[size];
    int* valuesToToToSort = new int[size];

    srand(time(nullptr));
    //and fill it with some ordered data
    for (int i = 0; i < size; i++)
    {
        values[i] = rand() % size;
    }

    high_resolution_clock::time_point t1, t2;

    memcpy(valuesToSort, values, sizeof(int) * size);
    memcpy(valuesToToSort, values, sizeof(int) * size);
    memcpy(valuesToToToSort, values, sizeof(int) * size);

    t1 = high_resolution_clock::now();
    bubbleSort(values, size);
    t2 = high_resolution_clock::now();

    for (int i = 0; i < size; i++)
    {
        std::cout << values[i] << ", ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "BubbleSort took = " << (t2 - t1).count() << "nanoseconds" << std::endl;
    std::cout << "BubbleSort actually took = " << (long long int)(t2 - t1).count() / 3.154e+16 << " calendar years" << std::endl;
    std::cout << "BubbleSort REALLYYYY took = " << std::chrono::duration<double, std::chrono::years::period>(t2-t1).count() << " chrono years" << std::endl;
    std::cout << "BubbleSort REALLYYYY took = " << std::chrono::duration<double, std::chrono::seconds::period>(t2 - t1).count() << " seconds" << std::endl;

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
    std::cout << "InsertionSort REALLYYYY took = " << std::chrono::duration<double, std::chrono::seconds::period>(t2 - t1).count() << " seconds" << std::endl;

    std::cin.ignore(std::cin.rdbuf()->in_avail());

    //pause
    std::cout << "Press any key to profile QuickSort" << std::endl;
    std::cin.get();
    std::cout << std::endl;

    //Profile QuickSort
    t1 = high_resolution_clock::now();
    quickSort(valuesToToSort, 0, size - 1);
    t2 = high_resolution_clock::now();

    for (int i = 0; i < size; i++)
    {
        std::cout << valuesToToSort[i] << ", ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "QuickSort took = " << (t2 - t1).count() << "nanoseconds" << std::endl;
    std::cout << "QuickSort REALLYYYY took = " << std::chrono::duration<double, std::chrono::seconds::period>(t2 - t1).count() << " seconds" << std::endl;

    std::cin.ignore(std::cin.rdbuf()->in_avail());

    //pause
    std::cout << "Press any key to profile MergeSort" << std::endl;
    std::cin.get();
    std::cout << std::endl;

    //Profile MergeSort
    t1 = high_resolution_clock::now();
    mergeSort(valuesToToToSort, 0, size - 1);
    t2 = high_resolution_clock::now();

    for (int i = 0; i < size; i++)
    {
        std::cout << valuesToToToSort[i] << ", ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "MergeSort took = " << (t2 - t1).count() << "nanoseconds" << std::endl;
    std::cout << "MergeSort REALLYYYY took = " << std::chrono::duration<double, std::chrono::seconds::period>(t2 - t1).count() << " seconds" << std::endl;

    delete[] values;
    delete[] valuesToSort;
    delete[] valuesToToSort;
    delete[] valuesToToToSort;

    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
    return 0;
}

