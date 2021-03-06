#include "DoubleLinkedList.h"
#include <vector>

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

void DoubleLinkedList::insert(Node* node, int value) // this is inserting the new node before the passed node;
{
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

	if (head == nullptr)
	{
		return counter;
	}

	Node* currentNode;

	currentNode = head;

	while (currentNode != nullptr)
	{
		counter++;
		currentNode = currentNode->next;
		
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
			tail = tail->previous;
		}
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
			head = head->next;
		}
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
	if (head == nullptr)
	{
		return;
	}

	Node* currentNode;
	Node* nextNode;

	currentNode = head;

	while (currentNode != nullptr)
	{
		if (currentNode->data == value)
		{
			nextNode = currentNode->next;

			erase(currentNode);

			currentNode = nextNode;
		}
		else
		{
			currentNode = currentNode->next;
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
	if (head == nullptr)
	{
		return;
	}

	Node* currentNode;
	Node* nextNode;

	currentNode = head;

	while (currentNode != nullptr)
	{
		nextNode = currentNode->next;

		erase(currentNode);

		currentNode = nextNode;
	}

	head = nullptr;
	tail = nullptr;
}

void DoubleLinkedList::sort()
{
	Node* currentNode;
	Node* nextNode;
	int temp;
	bool sorted = false;

	currentNode = head;

	if (currentNode == nullptr) { return; }
	if (currentNode == tail) { return; }
	
	while (!sorted)
	{
		sorted = true;

		for (currentNode = head; currentNode != nullptr;)
		{
			nextNode = currentNode->next;

			if (nextNode != nullptr)
			{
				if (currentNode->data > nextNode->data)
				{
					temp = currentNode->data;
					currentNode->data = nextNode->data;
					nextNode->data = temp;
					sorted = false;
				}
			}
			currentNode = currentNode->next;
		}
	}

	
}

int DoubleLinkedList::getFirst()
{
	Node* currentNode = head;

	if (currentNode == nullptr) return NULL;

	return currentNode->data;
}

int DoubleLinkedList::getLast()
{
	Node* currentNode = tail;

	if (currentNode == nullptr) return NULL;

	return currentNode->data;
}

int DoubleLinkedList::getDataAtIndex(int index)
{
	int data;
	Node* currentNode = head;

	if (currentNode == nullptr) return NULL;

	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;

		if (currentNode == nullptr) return NULL;
	}

	data = currentNode->data;


	return data;
}

std::vector<int> DoubleLinkedList::getAllData()
{
	std::vector<int> allData; 

	Node* currentNode = head;

	if (currentNode == nullptr) return allData;

	for (currentNode = head; currentNode != nullptr;)
	{
		allData.push_back(currentNode->data);
		currentNode = currentNode->next;
	}

	return allData;
}





