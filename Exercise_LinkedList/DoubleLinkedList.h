#pragma once

#include <assert.h>
#include <iostream>
#include <vector>

class Node
{
public:

	Node(int value)
	{
		data = value;
	}

	int data;
	Node* previous{ nullptr };
	Node* next{ nullptr };
};

class DoubleLinkedList
{
public:
	void pushFront(int value);
	void pushBack(int value);
	
	void insert(Node* node, int value);

	Node* begin() { return head; }
	Node* end() { return tail->next; }

	auto first() 
	{ 
		assert(head != nullptr);
		return head->data; 
	}

	auto last() 
	{
		assert(tail != nullptr);
		return tail->data;
	} 

	int count();

	void popBack();

	void popFront();

	void erase(Node* node);

	void remove(int value);

	bool empty();

	void clear();
	
	void sort();

	int getFirst();

	int getLast();

	int getDataAtIndex(int index);

	std::vector<int> getAllData();

private:

	Node* head{ nullptr };
	Node* tail{ nullptr };

};

