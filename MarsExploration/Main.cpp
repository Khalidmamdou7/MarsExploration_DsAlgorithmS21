#include <iostream>

// Include ADTs
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"

// Include Node Class
#include "PNode.h"
#include "Node.h"

// Include Event Classes
#include "FormulationEvent.h"
#include "CancelEvent.h"
#include "PromoteEvent.h"
#include "Event.h"
// Include Mission Class
#include "Mission.h"
#include "MarsStation.h"
#include"UI.h"
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

	//Testing Event
	cout << "=============================================================================" << endl;
	MarsStation M1;
	//                 FD, ID Type  Loc Dur.Sig.AutoP
	FormulationEvent F1(5, 88, 'M', 200, 8 , 7, 0);
	FormulationEvent F2(6, 89, 'M', 210, 11, 3, 0);
	FormulationEvent F3(7, 90, 'M', 222, 12, 5, 0);
	FormulationEvent F4(8, 91, 'M', 223, 18, 5, 0);  //prio =323 
	FormulationEvent F5(9, 92, 'E', 224, 13, 8, 0);  //prio= 308
	FormulationEvent F6(14,95, 'P', 224, 17, 12, 0);
	F1.Execute(&M1);
	F2.Execute(&M1);
	F3.Execute(&M1);
	F4.Execute(&M1);
	F5.Execute(&M1);
	F6.Execute(&M1);
	
	CancelEvent C1(5, 91);
	PromoteEvent P1(7, 91);
	//C1.Execute(&M1);
	P1.Execute(&M1);
	M1.assign();
	M1.justfortest();
	/*
	LinkedQueue<Mission*>* Q1 = M1.getWMMList();
	PriorityQueue<Mission*>* Q2 = M1.getWEMList();
	
	while (!Q1->isEmpty()) {
		Mission* toprint;
		Q1->dequeue(toprint);
		cout << toprint->getID() << endl;
	}
	cout << "==Emergency==" << endl;
	while (!Q2->isEmpty()) {
		Mission* toprint;
		Q2->dequeue(toprint);
		cout << toprint->getID() << endl;
	}
	*/

	UI *Output= new UI();
	
	Output->ReadMode();
	return 0;
}