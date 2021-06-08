#include "UI.h"
#include <iostream>
#include<chrono>
#include<thread>


#include "MarsStation.h"

using namespace std;
UI::UI()
{
	pS = NULL;
	Mode = 0;
	Printed = false;
}

void UI::Output(MarsStation* pS)
{
	ReadData(pS);
	switch (Mode)
	{
	case 1:
		InteractiveMode();
		break;
	case 2:
		StepByStepMode();
		break;
	case 3:
		SilentMode();
		break;
	case 4:
		exit(0);
	default:
		break;
	}
}

int UI::ReadMode()
{
	cout << "\n================== Welcome to Mars Exploration Simulator ==================\n";
	std::cout << "There's Three Modes: " << endl;
	std::cout << "Enter 1 For Interactive Mode" << endl;
	std::cout << "Enter 2 For Step-by-step mode" << endl;
	std::cout << "Enter 3 For Silent mode" << endl;
	std::cout << "Enter 4 For Exit" << endl;
	cin >> Mode;
	return Mode;
}

void UI::ReadData(MarsStation* pS)
{
	//Emergency Missions are in PriorityQueue
	//Other Missions are in LinkedQueue

	this->pS = pS;

	WEM = new PriorityQueue<Mission*>(*(pS->getWEMList()));
	WMM = new LinkedQueue<Mission*>(*(pS->getWMMList()));
	WPM = new LinkedQueue<Mission*>(*(pS->getWPMList()));

	InEx = new PriorityQueue<Mission*>(*(pS->getInEx()));

	AvailableER = new PriorityQueue<Rover*> (*(pS->getAvailableER()));
	AvailableMR = new PriorityQueue<Rover*> (*(pS->getAvailableMR()));
	AvailablePR = new PriorityQueue<Rover*> (*(pS->getAvailablePR()) );

	InCheckupER = new LinkedQueue<Rover*>(*(pS->getInCheckupER()));
	InCheckupMR = new LinkedQueue<Rover*>(*(pS->getInCheckupMR()));
	InCheckupPR = new LinkedQueue<Rover*>(*(pS->getInCheckupPR()));

	CompletedMissions = new LinkedQueue<Mission*>(*(pS->getCompletedMissions()));

	wem = 0;
	inex = 0;
	inexE = 0;
	inexP = 0;
	inexM = 0;
	avrovers = 0;
	incheck = 0;
	compE = 0;
	compM = 0;
	compP = 0;
	completedmissions = 0;
	z = 0;

	
	while (WEM->dequeue(M))
	{
		wem++;
	}
	while (WMM->dequeue(M))
	{
		wem++;
	}
	while (WPM->dequeue(M))
	{
		wem++;
	}
	while (AvailableER->dequeue(R))
	{
		avrovers++;
	}
	while (AvailableMR->dequeue(R))
	{
		avrovers++;
	}
	while (AvailablePR->dequeue(R))
	{
		avrovers++;
	}
	while (InCheckupER->dequeue(R))
	{
		incheck++;
	}
	while (InCheckupMR->dequeue(R))
	{
		incheck++;
	}
	while (InCheckupPR->dequeue(R))
	{
		incheck++;
	}
	while (InEx->dequeue(M))
	{
		inex++;
		if (M->getType() == 'E')
		{
			inexE++;
		}
		if (M->getType() == 'P')
		{
			inexP++;
		}
		if (M->getType() == 'M')
		{
			inexM++;
		}
	}
	while (CompletedMissions->dequeue(M))
	{
		completedmissions++;
		if (M->getType() == 'E')
		{
			compE++;
		}
		if (M->getType() == 'P')
		{
			compP++;
		}
		if (M->getType() == 'M')
		{
			compM++;
		}
	}


	delete 	WEM, WMM, WPM, InEx, AvailableER, AvailableMR, AvailablePR, InCheckupER, InCheckupMR, InCheckupPR, CompletedMissions;
	
	WEM = new PriorityQueue<Mission*>(*(pS->getWEMList()));
	WMM = new LinkedQueue<Mission*>(*(pS->getWMMList()));
	WPM = new LinkedQueue<Mission*>(*(pS->getWPMList()));

	InEx = new PriorityQueue<Mission*>(*(pS->getInEx()));

	AvailableER = new PriorityQueue<Rover*>(*(pS->getAvailableER()));
	AvailableMR = new PriorityQueue<Rover*>(*(pS->getAvailableMR()));
	AvailablePR = new PriorityQueue<Rover*>(*(pS->getAvailablePR()));

	InCheckupER = new LinkedQueue<Rover*>(*(pS->getInCheckupER()));
	InCheckupMR = new LinkedQueue<Rover*>(*(pS->getInCheckupMR()));
	InCheckupPR = new LinkedQueue<Rover*>(*(pS->getInCheckupPR()));

	CompletedMissions = new LinkedQueue<Mission*>(*(pS->getCompletedMissions()));

}

void UI::EveryDayOutput() {
	cout << "=================" << endl;
	std::cout << "Current Day : " << pS->GetCurrentDay() << endl;
	cout << "=================" << endl;
	std::cout << wem << "  Waiting Missions :" << " ";
	if (!WEM->isEmpty())
	{
		std::cout << "[" << " ";
		while (WEM->dequeue(M))
		{
			std::cout << M->getID();
			if (WEM->peek(M))
				std::cout << " , ";
		}
		std::cout << "]" << " ";
	}
	if (!WPM->isEmpty())
	{
		std::cout << "(" << " ";
		while (WPM->dequeue(M))
		{
			std::cout << M->getID();
			if (WPM->peek(M))
				std::cout << " , ";
		}
		std::cout << ")" << " ";
	}
	if (!WMM->isEmpty())
	{
		cout << "{" << " ";
		while (WMM->dequeue(M))
		{
			std::cout << M->getID();
			if (WMM->peek(M))
				std::cout << " , ";
		}
		std::cout << "}" << endl;
	}
	if (wem == 0)
	{
		std::cout << endl;
	}
	std::cout << "------------------------------------------------------" << endl;
	std::cout << inex << "  In-Execution Missions/Rovers:" << " ";
	if (inexE != 0)
	{
		PriorityQueue<Mission*> InExCopy(*InEx);
		std::cout << "[" << " ";
		while (InExCopy.dequeue(M))
		{
			if (M->getType() == 'E') {
				std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				inexE--;
				if (inexE > 0)
					std::cout << " , ";
			}
		}
		std::cout << "]" << " ";
	}

	if (inexP != 0)
	{
		PriorityQueue<Mission*> InExCopy(*InEx);
		std::cout << "(";
		while (InExCopy.dequeue(M))
		{
			if (M->getType() == 'P') {
				std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				inexP--;
				if (inexP > 0)
					std::cout << " , ";
			}
		}
		std::cout << ")" << " ";
	}
	if (inexM != 0)
	{
		PriorityQueue<Mission*> InExCopy(*InEx);
		std::cout << "{";
		while (InExCopy.dequeue(M))
		{
			if (M->getType() == 'M') {
				std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				inexM--;
				if (inexM > 0)
					std::cout << " , ";
			}
		}
		std::cout << "}" << " " << endl;;
	}
	if (inex == 0)
	{
		std::cout << endl;
	}
	std::cout << "------------------------------------------------------" << endl;
	std::cout << avrovers << "  Available Rovers :" << "";
	if (!AvailableER->isEmpty())
	{
		std::cout << "[" << " ";
		while (AvailableER->dequeue(R))
		{
			std::cout << R->getID();
			if (AvailableER->peek(R))
				std::cout << " , ";
		}
		std::cout << "]" << " ";
	}
	if (!AvailablePR->isEmpty())
	{
		std::cout << "(" << " ";
		while (AvailablePR->dequeue(R))
		{
			std::cout << R->getID();
			if (AvailablePR->peek(R))
				std::cout << " , ";
		}
		std::cout << ")" << " ";
	}
	if (!AvailableMR->isEmpty())
	{
		std::cout << "{" << " ";
		while (AvailableMR->dequeue(R))
		{
			std::cout << R->getID();
			if (AvailableMR->peek(R))
				std::cout << " , ";
		}
		std::cout << "}" << " ";
	}
	std::cout << endl;
	if (avrovers == 0)
	{
		std::cout << endl;
	}
	std::cout << "------------------------------------------------------" << endl;
	std::cout << incheck << " In - Checkup Rovers :" << " ";
	if (!InCheckupER->isEmpty())
	{
		std::cout << "[" << " ";
		while (InCheckupER->dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupER->peek(R))
				std::cout << " , ";
		}
		std::cout << "]" << " ";
	}
	if (!InCheckupPR->isEmpty())
	{
		std::cout << "(";
		while (InCheckupPR->dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupPR->peek(R))
				std::cout << " , ";
		}
		std::cout << ")" << " ";
	}
	if (!InCheckupMR->isEmpty())
	{
		std::cout << "{";
		while (InCheckupMR->dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupMR->peek(R))
				std::cout << " , ";
		}
		std::cout << "}" << " " << endl;
	}
	if (incheck == 0)
	{
		std::cout << endl;
	}
	std::cout << "------------------------------------------------------" << endl;
	std::cout << completedmissions << " Completed Missions:" << " ";
	if (compE != 0)
	{
		std::cout << "[" << " ";
		LinkedQueue<Mission*> CMCopy(*CompletedMissions);
		while (CMCopy.dequeue(M))
		{
			if (M->getType() == 'E') {
				std::cout << M->getID();
				compE--;
				if (compE > 0)
					std::cout << " , ";
			}
		}
		std::cout << "]" << " ";
	}
	if (compP != 0)
	{
		LinkedQueue<Mission*> CMCopy(*CompletedMissions);
		std::cout << "(";
		while (CMCopy.dequeue(M))
		{
			if (M->getType() == 'P') {
				std::cout << M->getID();
				compP--;
				if (compP > 0)
					std::cout << " , ";
			}
		}
		std::cout << ")" << " ";
	}
	if (compM != 0)
	{
		LinkedQueue<Mission*> CMCopy(*CompletedMissions);
		std::cout << "{";
		while (CMCopy.dequeue(M))
		{
			if (M->getType() == 'M') {
				std::cout << M->getID();
				compM--;
				if (compM > 0)
					std::cout << " , ";
			}
		}
		std::cout << "}" << " " << endl;
	}
}

void UI::InteractiveMode()
{
	EveryDayOutput();
	cout << "\nEnter any thing to continue...\n" << endl;
	cin >> z;
}
void UI::StepByStepMode()
{
	EveryDayOutput();
	std::cout.flush();
	this_thread::sleep_for(chrono::milliseconds(1000));
}
void UI::SilentMode()
{
	if (!Printed) {
		std::cout << "Silent Mode" << endl;
		std::cout << "Simulation Starts..." << endl;
		std::cout << "Simulation ends, Output file created" << endl;
		Printed = true;
	}
	

}
bool UI::getPrinted() const
{
	return Printed;
}
UI::~UI()
{
	delete 	WEM, WMM, WPM, InEx, AvailableER, AvailableMR, AvailablePR, InCheckupER, InCheckupMR, InCheckupPR, CompletedMissions;
}
