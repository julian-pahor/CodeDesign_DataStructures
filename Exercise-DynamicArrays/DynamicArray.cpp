#include "DynamicArray.h"


DynamicArray::DynamicArray(int initialSize)
{
	capacity = initialSize;
	data = new int[capacity];
}


DynamicArray::DynamicArray(const DynamicArray& other)
{
	count = other.count;
	capacity = other.capacity;
	//data = other.data;

	data = new int(*other.data);
}


DynamicArray& DynamicArray::operator= (const DynamicArray& other)
{
	for (int i = 0; i < capacity; i++)
	{
		data[i] = other.data[i];
	}

	count = other.count;
	return *this;
}


DynamicArray::~DynamicArray()
{
	delete data;
}


void DynamicArray::AddToEnd(int value)
{
	
	if (count >= capacity)
	{
		int* newData = new int[capacity * 2];

		for (int i = 0; i < count; i++)
		{
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
		capacity *= 2;

	}

	data[count] = value;
	count++;
	
}

void DynamicArray::RemoveAtEnd()
{
	count--;
}

void DynamicArray::Print()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << "Data:" << data[i] << std::endl;
	}
}
