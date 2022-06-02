#pragma once

#include <assert.h>

class DoubleLinkedList
{
public:

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

	void pushFront(int value);
	void pushBack(int value);
	
	void insert(Node* node, int value);

	auto begin() { return head; }
	auto end() { return tail->next; }

	auto first() 
	{ 
		assert(head != nullptr);
		return *head; 
	} //assert if no elements?
	auto last() 
	{
		assert(tail != nullptr);
		return *tail;
	} //assert if no elements?

	int count();

	void popBack();

	void popFront();

	void erase(Node* node);

	void remove(int value);

	bool empty();

	void clear();
	


private:

	Node* head{ nullptr };
	Node* tail{ nullptr };

};

