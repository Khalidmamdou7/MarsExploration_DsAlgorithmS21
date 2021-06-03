#include <iostream>

// Include ADTs
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"

// Include Node Class
#include "PNode.h"
#include "Node.h"


using namespace std;

int main() {

	// Test Linked List

	// Test Linked Queue

	// Test Priority Queue
	cout << "\n=================== Testing Priority Queue ==================\n";
	PriorityQueue<char>* PQ1 = new PriorityQueue<char>();

	PQ1->enqueue('A', 30);
	PQ1->enqueue('B', 30);
	PQ1->enqueue('C', 31);
	PQ1->enqueue('D', 32);
	PQ1->enqueue('E', 15);
	PQ1->enqueue('F', 0);
	PQ1->enqueue('G', -1);

	PQ1->PrintList();

	char c;
	PQ1->dequeue(c);
	PQ1->PrintList();

	PriorityQueue<char>* PQ2 = new PriorityQueue<char>(*PQ1);
	PQ2->PrintList();



	// Test PNode
	cout << "\n=================== Testing PNode ==================\n";
	PNode<int>* node1 = new PNode<int>(1);
	PNode<int>* node2 = new PNode<int>();
	
	cout << "Priority: " << node1->getPriority() << endl
		<< "Item: " << node1->getItem() << endl
		<< "Nextptr: " << node1->getNext() << endl;

	node1->setItem(5);	
	node1->setPriority(2);
	node1->setNext(node2);

	cout << "Priority: " << node1->getPriority() << endl
		<< "Item: " << node1->getItem() << endl
		<< "Nextptr: " << node1->getNext() << endl;





	return 0;
}