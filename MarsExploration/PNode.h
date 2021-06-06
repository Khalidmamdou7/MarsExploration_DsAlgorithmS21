#pragma once
#include "Node.h"

// A node that has a priority

template <typename T>
class PNode :
	public Node<T>
{
private:
	T item;
	int priority;
	PNode<T>* next;
public:
	PNode();
	PNode(const T& r_Item);
	PNode(const T& r_Item, int p, PNode<T>* nextNodePtr = NULL);
	virtual void setNext(PNode<T>* nextNodePtr);
	virtual PNode<T>* getNext() const;
	void setPriority(int r_priority);
	int getPriority();

	T getItem() const;
	void setItem(T in);
	friend std::ostream& operator<<(std::ostream&, const PNode<T>&);

};

template <typename T>
PNode<T>::PNode()
{
	priority = -1;
	next = NULL;
}

template<typename T>
PNode<T>::PNode(const T& r_Item) : Node<T>(r_Item)
{
	priority = -1;
	next = NULL;
}

template<typename T>
PNode<T>::PNode(const T& r_Item, int p, PNode<T>* nextNodePtr) : Node<T>(r_Item)
{
	priority = p;
	next = nextNodePtr;
}

template<typename T>
inline void PNode<T>::setPriority(int r_priority)
{
	priority = r_priority;
}

template <typename T>
inline int PNode<T>::getPriority()
{
	return priority;
}

template<typename T>
inline void PNode<T>::setNext(PNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template<typename T>
inline PNode<T>* PNode<T>::getNext() const
{
	return next;
}

template<typename T>
inline void PNode<T>::setItem(T input)
{
	item = input;
}

template<typename T>
inline T PNode<T>::getItem() const
{
	return item;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const PNode<T>& myNode) {
	0 << myNode.getItem();
}