#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class LinkedList
{
	friend ostream& operator<<(ostream &sout, const LinkedList &list)
	{
		if (list.isEmpty())
		{
			sout << "List is empty";
			return sout;
		}
		Node *pNode = list.pHead;

		while (pNode != NULL)
		{
			sout << *pNode->pData;
			pNode = pNode->pNext;
		}
		return sout;
	}

public:
	struct Node;
	LinkedList();
	LinkedList(const LinkedList &source);
	~LinkedList();

	bool BuildList(string FileName);
	bool Insert(T *obj);
	bool Remove(T target, T &result);
	bool Peek(const T target, T &result) const;
	bool isEmpty() const;
	void DeleteList();
	bool Merge(LinkedList &list1);

	LinkedList operator+(const LinkedList &other) const;
	LinkedList& operator+=(const LinkedList &other);

	bool operator==(const LinkedList &other) const;
	bool operator!=(const LinkedList &other) const;

	LinkedList& operator=(const LinkedList &other);

private:
	struct Node
	{
		Node *pNext;
		T *pData;
		Node(T* datum, Node * n) 
		{ 
			pData = new T; 
			(*pData) = (*datum);
			pNext = n; 
		}
	};

	Node* pHead;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	pHead = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &source)
{
	pHead = NULL;
	*this = source;
}


template <typename T>
LinkedList<T>::~LinkedList()
{
	DeleteList();
}



template <typename T>
bool LinkedList<T>::BuildList(string FileName)
{
	ifstream readFile(FileName);
	//DeleteList(); //make sure the list is empty

	if (!readFile || FileName.empty())
	{
		return false;
	}

	T dantum;
	while (!readFile.eof())
	{
		readFile >> dantum;
		Insert(&dantum);
	}

	readFile.close();
	return true;
}

template <typename T>
bool LinkedList<T>::Insert(T *obj)
{
	if (obj == NULL) //if passed object is NULL, then
	{
		return false;
	}

	if (isEmpty()) 
	{
		Node *newNode = new Node(obj, pHead);
		pHead = newNode;
		return true;
	}
	else 
	{
		Node* pNode = pHead;

		while ((pNode->pNext) != NULL)
		{
			pNode = pNode->pNext;
		}

		Node *newNode = new Node(obj, pNode->pNext);
		pNode->pNext = newNode;
		return true;
	}
}

template <typename T>
bool LinkedList<T>::Remove(T target, T &result)
{
	if (isEmpty())
	{
		throw runtime_error("Empty list");
		return false;
	}

	if (&target == NULL)
	{
		return false;
	}


	Node *current = pHead;
	Node *previous = pHead;

	while (current != NULL)
	{
		if (target == *(current->pData))
		{
			result = *(current->pData);

			if (current != pHead)
			{
				previous->pNext = current->pNext;
			}
			else
			{
				pHead = current->pNext;
			}

			delete current->pData;
			current->pData = NULL;
			delete current;
			current = NULL;

			return true;
		}

		previous = current;
		current = current->pNext;
	}

	return false;
}

template <typename T>
bool LinkedList<T>::Peek(const T target, T &result) const
{
	if (isEmpty())
	{
		//throw runtime_error("Empty list");
		return false;
	}

	if (&target == NULL)
	{
		return false;
	}

	Node *current = pHead;

	while (current != NULL)
	{
		if (target == *(current->pData))
		{
			result = *(current->pData);
			return true;
		}
		current = current->pNext;
	}

	return false;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	if (pHead == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void LinkedList<T>::DeleteList()
{
	if (isEmpty())
	{
		return;
	}

	Node *temp;
	while (!isEmpty())
	{
		temp = pHead;
		pHead = pHead->pNext;
		delete temp->pData;
		temp->pData = NULL;
		delete temp;
		temp = NULL;
	}
	pHead = NULL;
	return;
}

template <typename T>
bool LinkedList<T>::Merge(LinkedList &list1)
{
	if ((this == &list1) || (list1.isEmpty()))
	{
		return true;  // original list is same with passed list OR passed list is empty, nothing to do.
	}

	if (isEmpty()) // original list is empty, second list is good
	{
		this->pHead = list1.pHead;
		list1.pHead = NULL;
		return true;
	}

	//both have data
	Node *pThis = pHead;
	Node *pOther = list1.pHead;
	Node *pOther2 = list1.pHead;

	if (*(pThis->pData) > *(pOther->pData)) //compare first data for both list
	{
		pOther = pOther->pNext;
		list1.pHead = pOther;
		pOther2->pNext = pThis;
		pHead = pOther2;
		pOther2 = pOther;
		pThis = pHead;
	}
	while (pOther != NULL)
	{
		while (((pThis->pNext) != NULL) && (*((pThis->pNext)->pData) <= *(pOther->pData)))
		{
			pThis = pThis->pNext;
		}

		if (*(pThis->pData) == *(pOther->pData))
		{
			pOther = pOther->pNext;
			list1.pHead = pOther;
			delete pOther2->pData;
			pOther2 = pOther;

		}
		else
		{
			pOther = pOther->pNext;
			list1.pHead = pOther;
			pOther2->pNext = pThis->pNext;
			pThis->pNext = pOther2;
			pOther2 = pOther;
		}
	}

	return true;
}

template <typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList &other) const
{
	LinkedList<T> result = *this;
	result += other;
	return result;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator+=(const LinkedList &other)
{
	/*
	List342<T> temp(other);
	this->Merge(temp);
	return *this;
	*/

	if ((this == &other) || (other.isEmpty()))
	{
		return *this;  // original list is same with passed list OR passed list is empty, nothing to do.
	}

	if (isEmpty()) // original list is empty, second list is good
	{
		this->pHead = other.pHead;
		return *this;
	}

	//both have data
	Node *pThis = pHead;
	Node *pOther = other.pHead;

	if (*(pThis->pData) > *(pOther->pData)) //compare first data for both list
	{
		Node *newNode = new Node((pOther->pData), pHead);
		pHead = newNode;
		pOther = pOther->pNext;
		pThis = pHead;
	}
	while (pOther != NULL)
	{
		while (((pThis->pNext) != NULL) && (*((pThis->pNext)->pData) <= *(pOther->pData)))
		{
			pThis = pThis->pNext;
		}

		if (*(pThis->pData) == *(pOther->pData))
		{
			pOther = pOther->pNext;
		}
		else
		{
			Node *newNode = new Node((pOther->pData), (pThis->pNext));
			pThis->pNext = newNode;
			pOther = pOther->pNext;
		}
	}
	return *this;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList &other) const
{
	Node *left = this->pHead;
	Node *right = other.pHead;

	if (left == NULL && right == NULL)
	{
		return true;
	}

	if (left == NULL || right == NULL)
	{
		return false;
	}

	while (left != NULL && right != NULL)
	{
		if (*(left->pData) != *(right->pData))
		{
			return false;
		}

		left = left->pNext;
		right = right->pNext;
	}

	if (left == NULL && right == NULL)
	{
		return true;
	}
	return false;
}

template <typename T>
bool LinkedList<T>::operator!=(const LinkedList &other) const
{
	return !(*this == other);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &other)
{
	if (this == &other)
	{
		return *this;
	}

	DeleteList();

	if (other.isEmpty())
	{
		return *this;
	}

	Node *pOther = other.pHead;
	pHead = new Node((pOther->pData), NULL);
	Node *pThis = pHead;
	
	while (pOther->pNext != NULL)
	{
		pOther = pOther->pNext;
		pThis->pNext = new Node((pOther->pData), NULL);
		pThis = pThis->pNext;
	}
	return *this;
}
#endif