#pragma once

#include <iostream>

class DynamicArray
{
public:

	//DynamicArray() = default;
	DynamicArray(int initialSize);
	~DynamicArray();
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator= (const DynamicArray& other);

	int Count()
	{
		return count;
	}

	int Capacity()
	{
		return capacity;
	}

	void AddToEnd(int value);
	void RemoveAtEnd();
	void Print();

	//void AddAtIndex(int value, int index);

private:

	int count = 0;
	int capacity = 0;
	int* data;

protected:


};

