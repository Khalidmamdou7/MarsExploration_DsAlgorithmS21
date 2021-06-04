#include <iostream>
#include <fstream>
using namespace std;

#pragma once
#include "EmergencyMission.h"
#include "PolarMissions.h"
#include "MountainuousMission.h"
#include "QueueADT.h"
#include "PNode.h"
#include "Event.h"
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
	LinkedList<Event>** Events;   //list of event pointers // is it queue?
	LinkedQueue<Rover> ** Rovers;

	int numof_mount_rovers , numof_emer_rovers , numof_polar_rovers;
	int speed_mount_rovers, speed_emer_rovers, speed_polar_rovers;

	int  numof_missions_before_checkup;
	int  mount_rovers_checkup_duration , polar_rovers_checkup_duration , emer_rovers_checkup_duration;

public:
	MarsStation() 
	{
		//Rovers = new * LinkedQueue <Rover>(number here); //to start assigning data

		ifstream inputfile("Input_File", ios::in);
		while (!inputfile.eof())
		{

			inputfile >> numof_mount_rovers ;
			inputfile >> numof_polar_rovers ;
			inputfile >> numof_emer_rovers ;

			inputfile >> speed_mount_rovers;
			inputfile >> speed_polar_rovers;
			inputfile >> speed_emer_rovers;

			inputfile >> numof_missions_before_checkup;
			inputfile >> mount_rovers_checkup_duration;
			inputfile >> polar_rovers_checkup_duration;
			inputfile >> emer_rovers_checkup_duration;
		
		}
		
		//assign data after read



	}


	//ON EACH DAY FUNS
	





};