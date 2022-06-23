/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>

using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	if (m_pRoot == nullptr)
	{
		m_pRoot = new TreeNode(a_nValue);
		return;
	}

	TreeNode* currentNode = m_pRoot;
	TreeNode* prevNode = nullptr;

	while (currentNode != nullptr)
	{
		prevNode = currentNode;

		if (a_nValue < currentNode->GetData())
		{
			currentNode = currentNode->GetLeft();
		}
		else if (a_nValue > currentNode->GetData())
		{
			currentNode = currentNode->GetRight();
		}
		else if (a_nValue == currentNode->GetData())
		{
			return;
		}
	}

	if (a_nValue < prevNode->GetData())
	{
		TreeNode* newNode = new TreeNode(a_nValue);
		prevNode->SetLeft(newNode);
	}
	else
	{
		TreeNode* newNode = new TreeNode(a_nValue);
		prevNode->SetRight(newNode);
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	TreeNode* currentNode = m_pRoot;
	TreeNode* prevNode = nullptr;

	while (currentNode != nullptr)
	{
		if (a_nSearchValue == currentNode->GetData())
		{
			ppOutNode = currentNode;
			ppOutParent = prevNode;
			return true;
		}
		else
		{
			if (a_nSearchValue < currentNode->GetData())
			{
				prevNode = currentNode;
				currentNode = currentNode->GetLeft();
			}
			else
			{
				prevNode = currentNode;
				currentNode = currentNode->GetRight();
			}
		}
	}
	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	TreeNode* currentNode = nullptr;
	TreeNode* parentNode = nullptr;
	TreeNode* foundParentNode = nullptr;
	TreeNode* foundNode = nullptr;

	if (!FindNode(a_nValue, foundNode, foundParentNode)) { return; }

	if (foundNode->HasRight())
	{
		currentNode = foundNode->GetRight();
		parentNode = foundNode;

		while (currentNode->HasLeft())
		{
			parentNode = currentNode;
			currentNode = currentNode->GetLeft();
		}

		foundNode->SetData(currentNode->GetData());

		if (currentNode == parentNode->GetLeft())
		{
			parentNode->SetLeft(currentNode->GetRight());
		}
		if (currentNode == parentNode->GetRight())
		{
			parentNode->SetRight(currentNode->GetRight());
		}
		
	}
	else
	{
		if (foundNode == foundParentNode->GetLeft())
		{
			foundParentNode->SetLeft(foundNode->GetLeft());
		}
		if (foundNode == foundParentNode->GetRight())
		{
			foundParentNode->SetRight(foundNode->GetLeft());
		}
		if (foundNode == m_pRoot)
		{
			m_pRoot = foundNode->GetLeft();
		}
	}

	

}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}