#include "MarsStation.h"
#include <string>

MarsStation::MarsStation(){
	Events=NULL;
	EmergencyRovers=NULL;
	MountRovers=NULL;
	PolarRovers = NULL;
	numof_mount_rovers = 0, numof_emer_rovers = 0, numof_polar_rovers = 0;
	speed_mount_rovers = 0, speed_emer_rovers = 0, speed_polar_rovers = 0;

	numof_missions_before_checkup = 0;
	mount_rovers_checkup_duration = 0, polar_rovers_checkup_duration = 0, emer_rovers_checkup_duration = 0;

	mount_rovers_autoP = 0;

	num_events = 0;

	event_type = 0, misson_type = 0;
	event_day = 0, misson_id = 0, target_loc = 0, days_needed_for_mission = 0, misson_significance = 0;

}

 PriorityQueue<Mission>* MarsStation::getWEMList()
{
	return WaitingEmergency;
}

 LinkedQueue<Mission>* MarsStation::getWPMList()
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
				FormulationEvent* E1 = new FormulationEvent(event_day, misson_id, misson_type, target_loc, days_needed_for_mission, misson_significance, mount_rovers_autoP);
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
			Rover* rover_To_add = new Rover('M', mount_rovers_checkup_duration, speed_mount_rovers, numof_missions_before_checkup);
			MountRovers->enqueue(rover_To_add);
		}

		//Adding PolarRovers to PolarRovers Queue
		for (int i = 0; i < numof_polar_rovers; i++) {
			Rover* rover_To_add = new Rover('P', polar_rovers_checkup_duration, speed_polar_rovers, numof_missions_before_checkup);
			PolarRovers->enqueue(rover_To_add);
		}

		//Adding EmergencyRovers to EmergencyRovers Queue
		for (int i = 0; i < numof_emer_rovers; i++) {
			Rover* rover_To_add = new Rover('E', emer_rovers_checkup_duration, speed_emer_rovers, numof_missions_before_checkup);
			EmergencyRovers->enqueue(rover_To_add);
		}
	}
}

void MarsStation::Simulate() {

}