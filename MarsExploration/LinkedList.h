#pragma once
#include "ListADT.h"
#include "Node.h"
using namespace std;

template <typename T>
class LinkedList : public listADT<T>
{
private:
	Node<T>* Head;

public:
	LinkedList();
	void PrintList() const;
	void ReadList();
	void InsertEnd(const T&);
	void InsertBegin(const T&);
	void DeleteAll();
	bool DeleteNode(const T&);
	bool traverselist_search(const T&);
	T& traverselist_position(const T&);
	~LinkedList();
};

//-------------------------------------------------------IMPLEMENTAION--------------------------------------------------------//
template <typename T>
LinkedList<T>::LinkedList()
{
	Head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
		DeleteAll();
}


template <typename T>
void LinkedList<T>:: PrintList() const
{
	Node<T>* p = Head;
	while (p)
	{
		cout << p->getItem() << " ";
		p = p->getNext();
	}
	cout << endl;
}


template <typename T>
void LinkedList<T>::ReadList()	 
{
	int val;
	cin >> val;
	while (val != -1)
	{
		this->InsertEnd(val);
		cin >> val;
	}
}



template <typename T>
void LinkedList<T>::InsertEnd(const T& data)
{
	Node<T>* R = new Node<T>(data);
	if (!Head)
	{
		Head = R;
		return;
	}
	Node<T>* p = Head;
	while (p->getNext())
		p = p->getNext();
	p->setNext(R);
}



template <typename T>
void LinkedList<T>::InsertBegin(const T& data)
{
	Node<T>* P = new Node<T>(data);
	if (!Head)
	{
		Head = P;
		return;
	}
	P->setNext(Head);
	Head = P;
}


template <typename T>
void LinkedList<T>::DeleteAll()
{
	Node<T>* P = Head;
	while (Head)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
}



template <typename T>
bool LinkedList<T>::DeleteNode(const T& value)
{
	Node<T>* P = Head;
	Node<T>* temp = Head;
	while (P)
	{
		if (P->getItem() == value)
		{
			if (Head == NULL)
			{
				return NULL;
			}
			P = P->getNext();
		}
		delete temp;
	}
}


template <typename T>
bool LinkedList<T>::traverselist_search(const T& value)
{
	int c = 0;
	if (!Head)
		return;
	Node<T>* temp = Head;
	while (!temp)
	{
		c++;
		if (temp->getItem() == value)
			return c;
		temp = temp->getNext();
	}
	return false;
}


template <typename T>
T& LinkedList<T>::traverselist_position(const T& pos)
{
	int c = 0;
	if (!Head)
		return;
	Node<T> t = Head;
	while (!t)
	{
		c++;
		if (c == pos)
		{
			return t->getItem();
		}
	}
}


