#include "MarsStation.h"
#include <string>
#include"UI.h"
MarsStation::MarsStation(){

	WaitingEmergency = new PriorityQueue<Mission*>();
	WaitingPolar = new LinkedQueue<Mission*>();
	WaitingMount = new LinkedQueue<Mission*>();


	InEx = new PriorityQueue<Mission*>();
	CompletedMissions = new LinkedQueue<Mission*>();

	Events = new LinkedQueue<Event*>;
	AvailableER = new LinkedQueue<Rover*>();
	AvailableMR = new LinkedQueue<Rover*>();
	AvailablePR = new LinkedQueue<Rover*>();
	InCheckupER = new LinkedQueue<Rover*>();
	InCheckupMR = new LinkedQueue<Rover*>();
	InCheckupPR = new LinkedQueue<Rover*>();


	numof_mount_rovers = 0, numof_emer_rovers = 0, numof_polar_rovers = 0;
	speed_mount_rovers = 0, speed_emer_rovers = 0, speed_polar_rovers = 0;

	numof_missions_before_checkup = 0;
	mount_rovers_checkup_duration = 0, polar_rovers_checkup_duration = 0, emer_rovers_checkup_duration = 0;

	mount_rovers_autoP = 0;

	num_events = 0;

	event_type = 0, misson_type = 0;
	event_day = 0, misson_id = 0, target_loc = 0, days_needed_for_mission = 0, misson_significance = 0;

	// Data Statistics
	sumED = 0, sumWD = 0, AutoPcount = 0;

}


void MarsStation::assign()
{
	if (AvailableER->isEmpty() && AvailableMR->isEmpty() && AvailablePR->isEmpty())
		return;

	Mission* M;
	Rover* R;
	int ED; // Execution Days
	while (!WaitingEmergency->isEmpty())
	{
		if (AvailableER->dequeue(R))
		{
			WaitingEmergency->dequeue(M);

		}
		else if (AvailableMR->dequeue(R))
		{
			WaitingEmergency->dequeue(M);
		}
		else if (AvailablePR->dequeue(R))
		{
			WaitingEmergency->dequeue(M);
		}
		else
			break;

		ED = ceil(M->getTargetLocation() / (R->getSpeed() * 25)) + M->getDuration();
		M->setAssignedRover(R);
		M->setStatus('E');
		M->setWD(current_day - M->getFD());
		M->setED(ED);
		M->setCD(current_day + ED);
		InEx->enqueue(M, current_day+ ED);
	}

	while (!WaitingPolar->isEmpty())
	{
		if (AvailablePR->dequeue(R))
		{
			WaitingPolar->dequeue(M);
			M->setAssignedRover(R);
			M->setStatus('E');
			ED = ceil(M->getTargetLocation() / (R->getSpeed() * 25)) + M->getDuration();
			InEx->enqueue(M, current_day + ED);
			M->setWD(current_day - M->getFD());
			M->setED(ED);
			M->setCD(current_day + ED);
		}
		else
			break;

	}

	while (!WaitingMount->isEmpty())
	{
		if (AvailableMR->dequeue(R))
		{
			WaitingMount->dequeue(M);
		}
		else if (AvailableER->dequeue(R))
		{
			WaitingMount->dequeue(M);
		}
		else
			break;

		ED = ceil(M->getTargetLocation() / (R->getSpeed() * 25)) + M->getDuration();
		M->setAssignedRover(R);
		M->setStatus('E');
		InEx->enqueue(M, current_day + ED);
		M->setWD(current_day - M->getFD());
		M->setED(ED);
		M->setCD(current_day + ED);
	}

}

 PriorityQueue<Mission*>* MarsStation::getWEMList()
{
	return WaitingEmergency;
}

 LinkedQueue<Mission*>* MarsStation::getWPMList()
{
	return WaitingPolar;
}

 LinkedQueue<Mission*>* MarsStation::getWMMList()
 {
	 return WaitingMount;
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

			Event* E1 = NULL;
			if (event_type == 'F') {
				//This is formulation event
				inputfile >> misson_type;
				inputfile >> event_day;
				inputfile >> misson_id;
				inputfile >> target_loc;
				inputfile >> days_needed_for_mission;
				inputfile >> misson_significance;
				E1 = new FormulationEvent(event_day, misson_id, misson_type, target_loc, days_needed_for_mission, misson_significance, mount_rovers_autoP);
			}
			else if (event_type == 'P') {
				//This is promotion event
				inputfile >> event_day;
				inputfile >> misson_id;
				E1 = new PromoteEvent(event_day, misson_id);
			}
			else if (event_type == 'X') {
				//This is cancelltion event
				inputfile >> event_day;
				inputfile >> misson_id;
				E1 = new CancelEvent(event_day, misson_id);
			}
			if(E1)
				Events->enqueue(E1);
		}


		//Adding MountRovers to MountRovers Queue
		for (int i = 0; i < numof_mount_rovers; i++) {
			Rover* rover_To_add = new Rover('M', mount_rovers_checkup_duration, speed_mount_rovers, numof_missions_before_checkup);
			AvailableMR->enqueue(rover_To_add);
		}

		//Adding PolarRovers to PolarRovers Queue
		for (int i = 0; i < numof_polar_rovers; i++) {
			Rover* rover_To_add = new Rover('P', polar_rovers_checkup_duration, speed_polar_rovers, numof_missions_before_checkup);
			AvailablePR->enqueue(rover_To_add);
		}

		//Adding EmergencyRovers to EmergencyRovers Queue
		for (int i = 0; i < numof_emer_rovers; i++) {
			Rover* rover_To_add = new Rover('E', emer_rovers_checkup_duration, speed_emer_rovers, numof_missions_before_checkup);
			AvailableER->enqueue(rover_To_add);
		}
	}
}

void MarsStation::Simulate() {

	ExecuteEvents();
	FinishedExecution();
	FinishedCheckup();
	assign();

}

// Execute the events that should be executed at that day
void MarsStation::ExecuteEvents()
{
	Event* pE = NULL;
	while (Events->peek(pE)) {
		if (pE->getFormulationDay() == current_day) {
			Events->dequeue(pE);
			pE->Execute(this);
		}
		else
			break;
	}
}

void MarsStation::AutoP(){


}

// Check every day if missions finished Execution
void MarsStation::FinishedExecution()
{
	PriorityQueue<Mission*> Q1;
	Mission* pM = NULL;

	while (InEx->peek(pM) && pM->getCD() == current_day) {

		InEx->dequeue(pM);
		pM->setStatus('C');
		Q1.enqueue(pM, pM->getED());

		Rover* rover = pM->getAssignedRover();
		pM->setAssignedRover(NULL);
		rover->FinishedMission();
		if (rover->NeedsCheckup(current_day)) {
			// Enqueue Rover to inCheckup
			switch (rover->getType()) {
			case 'E':
				InCheckupER->enqueue(rover);
				break;
			case 'M':
				InCheckupMR->enqueue(rover);
				break;
			case 'P':
				InCheckupPR->enqueue(rover);
				break;
			default:
				break;
			}
		}
		else {
			switch (rover->getType()) {
			case 'E':
				AvailableER->enqueue(rover);
				break;
			case 'M':
				AvailableMR->enqueue(rover);
				break;
			case 'P':
				AvailablePR->enqueue(rover);
				break;
			default:
				break;
			}
		}
	}

	while (Q1.dequeue(pM)) {
		CompletedMissions->enqueue(pM);
	}

}

// Check every day if rovers finished in checkup
void MarsStation::FinishedCheckup()
{
	Rover* pR = NULL;
	while (InCheckupER->peek(pR)) {
		if (pR->Checkuped(current_day)) {
			InCheckupER->dequeue(pR);
			AvailableER->enqueue(pR);
		}
		else
			break;
	}
	
	while (InCheckupPR->peek(pR)) {
		if (pR->Checkuped(current_day)) {
			InCheckupPR->dequeue(pR);
			AvailablePR->enqueue(pR);
		}
		else
			break;
	}

	while (InCheckupMR->peek(pR)) {
		if (pR->Checkuped(current_day)) {
			InCheckupMR->dequeue(pR);
			AvailableMR->enqueue(pR);
		}
		else
			break;
	}
}

void MarsStation::Interface() {
	pUI->ReadMode(this);

	
 }



