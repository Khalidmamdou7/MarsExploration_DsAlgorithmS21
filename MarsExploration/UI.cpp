#include "UI.h"
#include <iostream>
#include<chrono>
#include<thread>
#include"Mission.h"
#include"Rover.h"

#include "MarsStation.h"

using namespace std;
UI::UI()
{
	pS = NULL;
	Mode = 0;
}
void UI::ReadMode(MarsStation* pS)
{
	//Emergency Missions are in PriorityQueue
	//Other Missions are in LinkedQueue

	PriorityQueue<Mission*> WEM(*(pS->getWEMList()));
	LinkedQueue<Mission*>   WMM(*(pS->getWMMList()));
	LinkedQueue<Mission*>   WPM(*(pS->getWPMList()));
	PriorityQueue<Mission*> InEx(*(pS->getInEx()));
	LinkedQueue<Rover*>   AvailableER(*(pS->getAvailableER()));
	LinkedQueue<Rover*>   AvailableMR(*(pS->getAvailableMR()));
	LinkedQueue<Rover*>   AvailablePR(*(pS->getAvailablePR()));
	LinkedQueue<Rover*>  InCheckupER(*(pS->getInCheckupER()));
	LinkedQueue<Rover*>   InCheckupMR(*(pS->getInCheckupMR()));
	LinkedQueue<Rover*>   InCheckupPR(*(pS->getInCheckupPR()));
	LinkedQueue<Mission*>   CompletedMissions(*(pS->getCompletedMissions()));
	int wem = 0;
	int inex = 0;
	int avrovers = 0;
	int incheck = 0;
	int completedmissions = 0;
	int z = 0;
	Mission* M;
	Rover* R;
	while (WEM.dequeue(M))
	{
		wem++;
	}
	while (WMM.dequeue(M))
	{
		wem++;
	}
	while (WPM.dequeue(M))
	{
		wem++;
	}
	while (AvailableER.dequeue(R))
	{
		avrovers++;
	}
	while (AvailableMR.dequeue(R))
	{
		avrovers++;
	}
	while (AvailablePR.dequeue(R))
	{
		avrovers++;
	}
	while (InCheckupER.dequeue(R))
	{
		incheck++;
	}
	while (InCheckupMR.dequeue(R))
	{
		incheck++;
	}
	while (InCheckupPR.dequeue(R))
	{
		incheck++;
	}
	while (InEx.dequeue(M))
	{
		inex++;
	}
	while (CompletedMissions.dequeue(M))
	{
		completedmissions++;
	}
	std::cout << "There's three modes: " << endl;
	std::cout << "enter 1 for interactive Mode" << endl;
	std::cout << " 2 for step-by-step mode" << endl;
	std::cout << "3 for silent mode" << endl;
	std::cout << "4 for Exit" << endl;
	cin >> Mode;

	switch (Mode)
	{
	case 1: {
		std::cout << "Current Day : " << pS->GetCurrentDay() << endl;
		std::cout << wem << "  Waiting Missions :" << "[" << "";
		while (WEM.dequeue(M))
		{
			std::cout << M->getID();
			if (WEM.peek(M))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(" << " ";
		while (WPM.dequeue(M))
		{
			std::cout << M->getID();
			if (WPM.peek(M))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{" << " ";
		while (WMM.dequeue(M))
		{
			std::cout << M->getID();
			if (WMM.peek(M))
				std::cout << " , ";
		}
		std::cout << "}";
		std::cout << "------------------------------------------------------" << endl;
		std::cout << inex << "  In-Execution Missions/Rovers:" << "[" << " ";
		while (InEx.dequeue(M))
		{
			if(M->getType()=='E')
			std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
			if (InEx.peek(M))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(";
		while (InEx.dequeue(M))
		{
			if (M->getType() == 'P')
				std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
			if (InEx.peek(M))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{";
		while (InEx.dequeue(M))
		{
			if (M->getType() == 'M')
				std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
			if (InEx.peek(M))
				std::cout << " , ";
		}
		std::cout << "}" << " ";
		std::cout << "------------------------------------------------------" << endl;
		std::cout << avrovers << "  Available Rovers :" << "[" << " ";
		while (AvailableER.dequeue(R))
		{
			std::cout << R->getID();
			if (AvailableER.peek(R))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(" << " ";
		while (AvailablePR.dequeue(R))
		{
			std::cout << R->getID();
			if (AvailablePR.peek(R))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{" << " ";
		while (AvailableMR.dequeue(R))
		{
			std::cout << R->getID();
			if (AvailableMR.peek(R))
				std::cout << " , ";
		}
		std::cout << "}" << " ";
		std::cout << "------------------------------------------------------" << endl;
		std::cout << incheck << " In - Checkup Rovers :" << "[" << " ";
		while (InCheckupER.dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupER.peek(R))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(";
		while (InCheckupPR.dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupPR.peek(R))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{";
		while (InCheckupMR.dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupMR.peek(R))
				std::cout << " , ";
		}
		std::cout << "}" << " ";
		std::cout << "------------------------------------------------------" << endl;
		std::cout << completedmissions << " Completed Missions:" << "[" << " ";
		while (CompletedMissions.dequeue(M))
		{
			std::cout << M->getID();
			if (CompletedMissions.peek(M))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(" << " ";
		while (CompletedMissions.dequeue(M))
		{
			std::cout << M->getID();
			if (CompletedMissions.peek(M))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{" << " ";
		while (CompletedMissions.dequeue(M))
		{
			std::cout << M->getID();
			if (CompletedMissions.peek(M))
				std::cout << " , ";
		}
		std::cout << "}";
		pS->load();
		cout << " Enter any thing to continue: " << " ";
		cin >> z;
		break;
	}
	case 2: {
		std::cout << "Current Day : " << pS->GetCurrentDay() << endl;
		std::cout << wem << "  Waiting Missions :" << "[" << "";
		while (WEM.dequeue(M))
		{
			std::cout << M->getID();
			if (WEM.peek(M))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(" << " ";
		while (WPM.dequeue(M))
		{
			std::cout << M->getID();
			if (WPM.peek(M))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{" << " ";
		while (WMM.dequeue(M))
		{
			std::cout << M->getID();
			if (WMM.peek(M))
				std::cout << " , ";
		}
		std::cout << "}";
		std::cout << "------------------------------------------------------" << endl;
		std::cout << inex << "  In-Execution Missions/Rovers:" << "[" << " ";
		while (InEx.dequeue(M))
		{
			if (M->getType() == 'E')
				std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
			if (InEx.peek(M))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(";
		while (InEx.dequeue(M))
		{
			if (M->getType() == 'P')
				std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
			if (InEx.peek(M))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{";
		while (InEx.dequeue(M))
		{
			if (M->getType() == 'M')
				std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
			if (InEx.peek(M))
				std::cout << " , ";
		}
		std::cout << "}" << " ";
		std::cout << "------------------------------------------------------" << endl;
		std::cout << avrovers << "  Available Rovers :" << "[" << " ";
		while (AvailableER.dequeue(R))
		{
			std::cout << R->getID();
			if (AvailableER.peek(R))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(" << " ";
		while (AvailablePR.dequeue(R))
		{
			std::cout << R->getID();
			if (AvailablePR.peek(R))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{" << " ";
		while (AvailableMR.dequeue(R))
		{
			std::cout << R->getID();
			if (AvailableMR.peek(R))
				std::cout << " , ";
		}
		std::cout << "}" << " ";
		std::cout << "------------------------------------------------------" << endl;
		std::cout << incheck << " In - Checkup Rovers :" << "[" << " ";
		while (InCheckupER.dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupER.peek(R))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(";
		while (InCheckupPR.dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupPR.peek(R))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{";
		while (InCheckupMR.dequeue(R))
		{
			std::cout << R->getID();
			if (InCheckupMR.peek(R))
				std::cout << " , ";
		}
		std::cout << "}" << " ";
		std::cout << "------------------------------------------------------" << endl;
		std::cout << completedmissions << " Completed Missions:" << "[" << " ";
		while (CompletedMissions.dequeue(M))
		{
			std::cout << M->getID();
			if (CompletedMissions.peek(M))
				std::cout << " , ";
		}
		std::cout << "]" << " " << "(" << " ";
		while (CompletedMissions.dequeue(M))
		{
			std::cout << M->getID();
			if (CompletedMissions.peek(M))
				std::cout << " , ";
		}
		std::cout << ")" << " " << "{" << " ";
		while (CompletedMissions.dequeue(M))
		{
			std::cout << M->getID();
			if (CompletedMissions.peek(M))
				std::cout << " , ";
		}
		std::cout << "}";
		std::cout.flush();
		this_thread::sleep_for(chrono::milliseconds(10000));
		pS->load();
		break;
	}
	case 3: {
		std::cout << "Silent Mode" << endl;
		std::cout << "Simulation Starts..." << endl;
		std::cout << "Simulation ends, Output file created" << endl;
		pS->load();
		break;
	}
	case 4: {
		exit(0);
	}
	}while (Mode != 4);

}