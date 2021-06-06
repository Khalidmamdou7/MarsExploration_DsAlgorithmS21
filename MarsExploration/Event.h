#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MarsStation.h"
#include "Rover.h"
#include "Mission.h"
#include "QueueADT.h"
#include "PNode.h"
#include "ListADT.h"
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"

class Event
{
public:
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

inline Event::Event(int r_ED, int r_mID)
{
	pStation = NULL;
	FormulationDay = r_ED;
	mID = r_mID;
}

int Event::getFormulationDay() const {
	return FormulationDay;
}

 void Event::setFormulationDay(const int& r_ED)
{
	if (r_ED > 0)
		FormulationDay = r_ED;
}

 int Event::getmID() const
{
	return mID;
}

 void Event::setmID(const int& r_mID)
{
	mID = r_mID;
}




