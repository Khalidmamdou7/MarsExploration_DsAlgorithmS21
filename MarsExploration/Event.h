#pragma once
#include <iostream>
#include <fstream>
#include <string>
//#include "MarsStation.h"   //DO NOT INCLUDE
#include "Rover.h"
#include "Mission.h"
#include "QueueADT.h"
#include "PNode.h"
#include "ListADT.h"
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"

class MarsStation;

class Event
{
protected:
	MarsStation* pStation;
	int FormulationDay;
	int mID;
public:
	Event(int ED = 0, int mID = 0);
	int getFormulationDay() const;
	void setFormulationDay(const int& ED);
	int getmID() const;
	void setmID(const int& mID);
	virtual void Execute(MarsStation *pS) = 0;

};





