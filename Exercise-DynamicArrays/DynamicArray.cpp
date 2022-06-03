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
	delete[] data;
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

void DynamicArray::AddAtIndex(int value, int index)
{
	if (count >= capacity || index > count)
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

	for (int i = count; i >= index - 1; i--)
	{
		data[i + 1] = data[i];
	}

	data[index - 1] = value;
	count++;

	
}

void DynamicArray::RemoveOrdered(int index)
{
	for (int i = index - 1; i <= count; i++)
	{
		data[i] = data[i + 1];
	}

	count--;
}

void DynamicArray::RemoveUnordered(int index)
{
	data[index - 1] = data[count - 1];
	count--;
}

void DynamicArray::FormatSpace()
{
	int* newData = new int[count];

	for (int i = 0; i < count; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = count;
}

void DynamicArray::Clear()
{
	for (int i = 0; i <= count; i++)
	{
		data[i] = 0;
	}
}

void DynamicArray::RemoveAtEnd()
{
	count--;
}

void DynamicArray::Print()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << "Data at index: " << i << " = " << data[i] << std::endl;
	}

	std::cout << "Current Count = " << count << std::endl;
	std::cout << "Current Capacity = " << capacity << std::endl;
}
