#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#pragma once
#include "Mission.h"
#include "QueueADT.h"
#include "PNode.h"
#include "Event.h"
#include "FormulationEvent.h"
#include "CancelEvent.h"
#include "PromoteEvent.h"

#include "ListADT.h"
#include "Rover.h"

// Add Data Structures
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"

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
	LinkedQueue<Rover*>* EmergencyRovers; 
	LinkedQueue<Rover*>* MountRovers;
	LinkedQueue<Rover*>* PolarRovers;

	PriorityQueue<Mission>* WaitingEmergency = new PriorityQueue<Mission>();
	LinkedQueue<Mission>* WaitingPolar = new LinkedQueue<Mission>();

	int current_day = 1;

	int numof_mount_rovers , numof_emer_rovers , numof_polar_rovers;
	int speed_mount_rovers, speed_emer_rovers, speed_polar_rovers;

	int  numof_missions_before_checkup;
	int  mount_rovers_checkup_duration , polar_rovers_checkup_duration , emer_rovers_checkup_duration;

	int mount_rovers_autoP;

	int num_events;

	char event_type , misson_type;
	int event_day, misson_id, target_loc, days_needed_for_mission, misson_significance;
	
	////////////////////////////////////////////END DECLERATION//////////////////////////////////////////


public:

	MarsStation();

	PriorityQueue<Mission>* getWEMList();
	LinkedQueue<Mission>* getWPMList();

	void load();
	void Simulate();
	

	MarsStation(string = "Input_File")
	{
		//Import From File to Create a Rovers,Missions,Events lists (or queues)..
		load();
		
		
	}
};


inline MarsStation::MarsStation()
{
}

inline PriorityQueue<Mission>* MarsStation::getWEMList()
{
	return WaitingEmergency;
}

inline LinkedQueue<Mission>* MarsStation::getWPMList()
{
	return WaitingPolar;
}

void MarsStation::load() {
		ifstream inputfile("Input_File", ios::in);
		while (!inputfile.eof())
		{
			//Reading rovers and their properties to add them to the rovers queue
			inputfile >> numof_mount_rovers;
			inputfile >> numof_polar_rovers;
			inputfile >> numof_emer_rovers;

			inputfile >> speed_mount_rovers;
			inputfile >> speed_polar_rovers;
			inputfile >> speed_emer_rovers;

			inputfile >> numof_missions_before_checkup;
			inputfile >> mount_rovers_checkup_duration;
			inputfile >> polar_rovers_checkup_duration;
			inputfile >> emer_rovers_checkup_duration;

			//Reading AutoPromotion Limit
			inputfile >> mount_rovers_autoP;

			//Reading Number Of Events
			inputfile >> num_events;

			//Reading the events itself & adding them to Events 
			for (int i = 0; i < num_events; i++) {
				inputfile >> event_type;

				if (event_type == 'F') {
					//This is formulation event
					inputfile >> misson_type;
					inputfile >> event_day;
					inputfile >> misson_id;
					inputfile >> target_loc;
					inputfile >> days_needed_for_mission;
					inputfile >> misson_significance;
					FormulationEvent* E1 = new FormulationEvent(event_day, misson_id, misson_type, target_loc, days_needed_for_mission, misson_significance);
					Events->enqueue(E1);
				}
				else if (event_type == 'P') {
					//This is promotion event
					inputfile >> event_day;
					inputfile >> misson_id;
					PromoteEvent* E1 = new PromoteEvent(event_day, misson_id);
				}

				else if (event_type == 'X') {
					//This is cancelltion event
					inputfile >> event_day;
					inputfile >> misson_id;
					CancelEvent* E1 = new CancelEvent(event_day, misson_id);
				}

			}

			//Adding MountRovers to MountRovers Queue
			for (int i = 0; i < numof_mount_rovers; i++) {
				Rover* rover_To_add = new Rover('M',mount_rovers_checkup_duration, speed_mount_rovers, numof_missions_before_checkup);
				MountRovers->enqueue(rover_To_add);
			}

			//Adding PolarRovers to PolarRovers Queue
			for (int i = 0; i < numof_polar_rovers; i++) {
				Rover* rover_To_add = new Rover('P',polar_rovers_checkup_duration, speed_polar_rovers, numof_missions_before_checkup);
				PolarRovers->enqueue(rover_To_add);
			}

			//Adding EmergencyRovers to EmergencyRovers Queue
			for (int i = 0; i < numof_emer_rovers; i++) {
				Rover* rover_To_add = new Rover('E',emer_rovers_checkup_duration, speed_emer_rovers, numof_missions_before_checkup);
				EmergencyRovers->enqueue(rover_To_add);
			}
		}
	}

	void MarsStation::Simulate() {

	}
	





