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

	PriorityQueue<Mission*> WEM_count(*(pS->getWEMList()));
	LinkedQueue<Mission*>   WMM_count(*(pS->getWMMList()));
	LinkedQueue<Mission*>   WPM_count(*(pS->getWPMList()));
	PriorityQueue<Mission*> InEx_count(*(pS->getInEx()));
	LinkedQueue<Rover*>   AvailableER_count(*(pS->getAvailableER()));
	LinkedQueue<Rover*>   AvailableMR_count(*(pS->getAvailableMR()));
	LinkedQueue<Rover*>   AvailablePR_count(*(pS->getAvailablePR()));
	LinkedQueue<Rover*>  InCheckupER_count(*(pS->getInCheckupER()));
	LinkedQueue<Rover*>   InCheckupMR_count(*(pS->getInCheckupMR()));
	LinkedQueue<Rover*>   InCheckupPR_count(*(pS->getInCheckupPR()));
	LinkedQueue<Mission*>   CompletedMissions_count(*(pS->getCompletedMissions()));
	int wem = 0;
	int inex = 0;
	int avrovers = 0;
	int incheck = 0;
	int completedmissions = 0;
	int z = 0;
	Mission* M;
	Rover* R;
	while (WEM_count.dequeue(M))
	{
		wem++;
	}
	while (WMM_count.dequeue(M))
	{
		wem++;
	}
	while (WPM_count.dequeue(M))
	{
		wem++;
	}
	while (AvailableER_count.dequeue(R))
	{
		avrovers++;
	}
	while (AvailableMR_count.dequeue(R))
	{
		avrovers++;
	}
	while (AvailablePR_count.dequeue(R))
	{
		avrovers++;
	}
	while (InCheckupER_count.dequeue(R))
	{
		incheck++;
	}
	while (InCheckupMR_count.dequeue(R))
	{
		incheck++;
	}
	while (InCheckupPR_count.dequeue(R))
	{
		incheck++;
	}
	while (InEx_count.dequeue(M))
	{
		inex++;
	}
	while (CompletedMissions_count.dequeue(M))
	{
		completedmissions++;
	}

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