#pragma once

// Include Data structures
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "LinkedQueue.h"

// Include Events, Missions, Rovers
#include "Event.h"
#include "Mission.h"
#include "Rover.h"


class MarsStation;

class UI
{
private:
	MarsStation* pS;
	int Mode;
	bool Printed;
	// Variables needed for output
	PriorityQueue<Mission*>* WEM;
	LinkedQueue<Mission*>*   WMM;
	LinkedQueue<Mission*>*   WPM;
	PriorityQueue<Mission*>* InEx;
	PriorityQueue<Rover*>*   AvailableER;
	PriorityQueue<Rover*>*   AvailableMR;
	PriorityQueue<Rover*>*   AvailablePR;
	LinkedQueue<Rover*>*  InCheckupER;
	LinkedQueue<Rover*>*   InCheckupMR;
	LinkedQueue<Rover*>*   InCheckupPR;
	LinkedQueue<Mission*>*   CompletedMissions;
	Mission* M;
	Rover* R;
	int wem = 0, inex = 0, inexE = 0, inexP = 0, inexM = 0, avrovers = 0, incheck = 0, compE = 0, compM = 0, compP = 0, completedmissions = 0, z = 0;


public:
	UI();
	void Output(MarsStation*);
	int ReadMode();
	void ReadData(MarsStation* pS);
	void EveryDayOutput();
	void InteractiveMode();
	void StepByStepMode();
	void SilentMode();
	bool getPrinted() const;
	~UI();
};

