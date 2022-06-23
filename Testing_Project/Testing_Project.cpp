#include "CppUnitTest.h"

#include "../Exercise_LinkedList/DoubleLinkedList.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingProject
{
	TEST_CLASS(TestingProject)
	{
	public:
		
		TEST_METHOD(PushBack_Test)
		{
			DoubleLinkedList list;

			list.pushBack(0);
			list.pushBack(20);
			list.pushBack(40);
			list.pushBack(60);

			Assert::AreEqual(60, list.getLast());
		}

		TEST_METHOD(PushFront_Test)
		{
			DoubleLinkedList list;
			list.pushFront(1);
			list.pushFront(1);
			list.pushFront(2);
			list.pushFront(3);
			list.pushFront(5);
			list.pushFront(8);

			Assert::AreEqual(8, list.getFirst());

		}
		TEST_METHOD(ListCount_Test)
		{
			DoubleLinkedList list;
			list.pushFront(6);
			list.pushBack(18);
			list.pushFront(68);
			list.pushBack(100);
			list.pushFront(2000);

			Assert::AreEqual(5, list.count());
		}
		TEST_METHOD(ListGetData_Test)
		{
			DoubleLinkedList list;

			std::vector<int> data;
			std::vector<int> listData;

			list.pushBack(5);
			list.pushBack(4);
			list.pushBack(3);
			list.pushBack(2);
			list.pushBack(1);
			list.pushBack(0);

			data.push_back(5);
			data.push_back(4);
			data.push_back(3);
			data.push_back(2);
			data.push_back(1);
			data.push_back(0);

			listData = list.getAllData();

			for (int i = 0; i < data.size(); i++)
			{
				Assert::AreEqual(data[i], listData[i]);
			}
		}

		TEST_METHOD(ListInsert_Test)
		{
			//Reminder: List insert function inserts data before the passed node;

			DoubleLinkedList list;

			list.pushBack(5);
			list.pushBack(4);
			list.pushBack(3);
			list.pushBack(2);
			list.pushBack(1);
			list.pushBack(0);

			list.insert(list.begin()->next->next->next, 60);

			Assert::AreEqual(60, list.getDataAtIndex(3));

		}
		TEST_METHOD(ListSort_Test)
		{
			DoubleLinkedList list;
			
			std::vector<int> data;
			std::vector<int> listData;

			list.pushFront(16);
			list.pushFront(800);
			list.pushFront(12);
			list.pushFront(642);
			list.pushFront(42);

			list.sort();

			data.push_back(12);
			data.push_back(16);
			data.push_back(42);
			data.push_back(642);
			data.push_back(800);

			listData = list.getAllData();

			for (int i = 0; i < data.size(); i++)
			{
				Assert::AreEqual(data[i], listData[i]);
			}

		}

	};
}