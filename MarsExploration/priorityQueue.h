#pragma once

#include "QueueADT.h"
#include "PNode.h"

using namespace std;

template <typename T>
class PriorityQueue :public QueueADT<T>
{
private:
	PNode<T>* backPtr;
	PNode<T>* frontPtr;
	int count;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, const int& priority);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	void PrintList();
	~PriorityQueue();

	// Copy constructor
	PriorityQueue(const PriorityQueue<T>& PQ);
};

//------------------------------------------------------------IMPLEMENTAION--------------------------------------------------------//
template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
	count = 0;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T>
bool PriorityQueue<T>::enqueue(const T& newEntry,const int& priority)
{
	count++;
	PNode<T>* newPNptr = new PNode<T>(newEntry, priority);

	if (isEmpty()) {
		frontPtr = newPNptr;
		backPtr = frontPtr;
		return true;
	}
	else {
		PNode<T>* prev = frontPtr;
		PNode<T>* curr = frontPtr;

		while (curr) {
			if (newPNptr->getPriority() > curr->getPriority()) {
				if (curr == frontPtr) {
					frontPtr = newPNptr;
					newPNptr->setNext(curr);
					return true;
				}
				else {
					newPNptr->setNext(curr);
					prev->setNext(newPNptr);
					return true;
				}
			}
			else {
				if (curr == backPtr) {
					backPtr->setNext(newPNptr);
					backPtr = newPNptr;
					return true;
				}
				prev = curr;
				curr = curr->getNext();
			}
		}
	}

	return false;

}

template <typename T>
bool PriorityQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	PNode<T>* PNodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (PNodeToDeletePtr == backPtr)
		backPtr = nullptr;
	delete PNodeToDeletePtr;

	count--;
	return true;

}

template <typename T>
bool PriorityQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;
}

template<typename T>
inline void PriorityQueue<T>::PrintList()
{
	PNode<T>* p = frontPtr;
	while (p)
	{
		cout << p->getItem() << " ";
		p = p->getNext();
	}
	cout << endl;
	
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	T temp;
	while (dequeue(temp));
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& PQ)
{
	count = PQ.count;
	PNode<T>* PNodePtr = PQ.frontPtr;
	if (!PNodePtr)
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	PNode<T>* ptr = new PNode<T>(PNodePtr->getItem());
	frontPtr = backPtr = ptr;
	PNodePtr = PNodePtr->getNext();
	while (PNodePtr)
	{
		PNode<T>* ptr = new PNode<T>(PNodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		PNodePtr = PNodePtr->getNext();
	}
}
