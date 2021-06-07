
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#pragma once
#include "QueueADT.h"
#include "PNode.h"
#include "Event.h"
#include "FormulationEvent.h"
#include "CancelEvent.h"
#include "PromoteEvent.h"
#include "LinkedList.h"
#include "ListADT.h"
#include "LinkedQueue.h"
#include "Rover.h"


/*
MarsStation Class
It should have an appropriate list of Event pointers to store all events loaded from the file at
system startup.
This class is the maestro class that manages the system. It should have member functions to:
1- At program startup, open the input file and load rovers data to fill rovers list(s) and to load
the events list.
2- One each day,
		a. Execute the events that should be executed at that day
		b. Check waiting mission to assign them to available rovers
		c. Move missions from waiting to in-execution to completed
		d. Move rovers from available to in-execution to checkup to available again
		e. Collect statistics that are needed to create output file
		f. Calls UI class functions to print day details on the output screen
3- Produce the output file at the end of simulation
*/


class MarsStation
{
private:
	////////////////////////////////////////////// DECLERATION//////////////////////////////////////////
	
	LinkedQueue<Event*>* Events;

	// Missions Lists
	PriorityQueue<Mission*>* WaitingEmergency;
	LinkedQueue<Mission*>* WaitingPolar;
	LinkedQueue<Mission*>* WaitingMount;

	PriorityQueue<Mission*>* InEx;
	LinkedQueue<Mission*>* CompletedMissions;

	
	// Rovers Lists
	LinkedQueue<Rover*>* AvailableER;
	LinkedQueue<Rover*>* AvailableMR;
	LinkedQueue<Rover*>* AvailablePR;
	LinkedQueue<Rover*>* InCheckupER;
	LinkedQueue<Rover*>* InCheckupMR;
	LinkedQueue<Rover*>* InCheckupPR;


	int current_day = 1;

	int numof_mount_rovers=0, numof_emer_rovers = 0, numof_polar_rovers = 0;
	int speed_mount_rovers=0, speed_emer_rovers = 0, speed_polar_rovers = 0;

	int  numof_missions_before_checkup = 0;
	int  mount_rovers_checkup_duration = 0, polar_rovers_checkup_duration = 0, emer_rovers_checkup_duration = 0;

	int mount_rovers_autoP = 0;

	int num_events = 0;

	char event_type = 0, misson_type = 0;
	int event_day = 0, misson_id = 0, target_loc = 0, days_needed_for_mission = 0, misson_significance = 0;

	// Used for Statistics
	int sumED, sumWD;			// sum of the Execution and  the waiting days of the missions
	int AutoPcount;				// numbers of mountainuous mission which has been auto promoted

	////////////////////////////////////////////END DECLERATION//////////////////////////////////////////


public:
	MarsStation();

	void load();
	void Simulate();
	void FinishExecution(); // Checks if missions finished execution
	void FinishedCheckup(); // Checks if rovers finished checkup and move it to available rovers

	PriorityQueue<Mission*>* getWEMList();
	LinkedQueue<Mission*>* getWPMList();
	LinkedQueue<Mission*>* getWMMList();

	MarsStation(string = "Input_File")
	{
		//Import From File to Create a Rovers,Missions,Events lists (or queues)..
		load();
	}
	void assign();
	//utility
	float calcpriority();
};








