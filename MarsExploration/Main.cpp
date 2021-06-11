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
	MarsStation M;
	M.load();
	M.Simulate();
	return 0;
}