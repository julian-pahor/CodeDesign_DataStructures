#include "DoubleLinkedList.h"

void DoubleLinkedList::pushFront(int value)
{
	Node* node = new Node(value);

	if (head != nullptr)
	{
		head->previous = node;
		node->next = head;
	}

	if (tail == nullptr)
	{
		tail = node;
	}

	head = node;
}

void DoubleLinkedList::pushBack(int value)
{
	Node* node = new Node(value);

	if (tail != nullptr)
	{
		tail->next = node;
		node->previous = tail;
	}

	if (head == nullptr)
	{
		head = node;
	}

	tail = node;

}

void DoubleLinkedList::insert(Node* node, int value)
{
	// this is inserting the new node before the passed node;
	if (node == nullptr)
	{
		pushBack(value);
		return;
	}

	Node* newNode = new Node(value);
	
	if (node == head)
	{
		head = newNode;
	}

	newNode->next = node;
	newNode->previous = node->previous;

	if (node->previous != nullptr)
	{
		node->previous->next = newNode;

	}

	node->previous = newNode;
}

int DoubleLinkedList::count()
{
	int counter = 0;
	Node* currentNode;
	
	if (head != nullptr)
	{
		currentNode = head;
		counter++;
	}
	else
	{
		return counter;
	}

	bool counting = true;

	while (counting)
	{
		counting = false;

		if (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
			counter++;
			counting = true;
		}
	}

	return counter;
}

void DoubleLinkedList::popBack()
{
	if (tail != nullptr)
	{
		Node* temp = tail;

		if (tail->previous != nullptr)
		{
			tail->previous->next = nullptr;
		}

		tail = tail->previous;

		delete temp;
	}
}

void DoubleLinkedList::popFront()
{

	if (head != nullptr)
	{
		Node* temp = head;

		if (head->next != nullptr)
		{
			head->next->previous = nullptr;
		}

		head = head->next;

		delete temp;
	}
}

void DoubleLinkedList::erase(Node* node)
{

	if (node == tail)
	{
		popBack();

		return;
	}

	if (node == head)
	{
		popFront();

		return;
	}

	
	node->next->previous = node->previous;
	node->previous->next = node->next;

	delete node;
}

void DoubleLinkedList::remove(int value)
{
	
	bool removing = true;
	Node* currentNode = nullptr;
	Node* nextNode = nullptr;

	if (head != nullptr)
	{
		currentNode = head;

		while (removing)
		{
			removing = false;

			if (currentNode != tail)
			{
				if (currentNode->data = value)
				{
					nextNode = currentNode->next;
					erase(currentNode);
				}

				removing = true;
			}
			else
			{
				if (currentNode->data = value)
				{
					erase(currentNode);
				}
			}
		}
	}
}

bool DoubleLinkedList::empty()
{
	if (head == nullptr && tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DoubleLinkedList::clear()
{

}

