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
	int inexE = 0;
	int inexP = 0;
	int inexM = 0;
	int avrovers = 0;
	int incheck = 0;
	int compE = 0;
	int compM = 0;
	int compP = 0;
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
	while (CompletedMissions_count.dequeue(M))
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

	std::cout << "There's Three Modes: " << endl;
	std::cout << "Enter 1 For Interactive Mode" << endl;
	std::cout << "Enter 2 For Step-by-step mode" << endl;
	std::cout << "Enter 3 For Silent mode" << endl;
	std::cout << "Enter 4 For Exit" << endl;
	cin >> Mode;

	switch (Mode)
	{
	case 1: {
		std::cout << "Current Day : " << pS->GetCurrentDay() << endl;
		std::cout << wem << "  Waiting Missions :" << " ";
		if (!WEM.isEmpty())
		{
			std::cout << "[" << " ";
			while (WEM.dequeue(M))
			{
				std::cout << M->getID();
				if (WEM.peek(M))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (!WPM.isEmpty())
		{
			std::cout << "(" << " ";
			while (WPM.dequeue(M))
			{
				std::cout << M->getID();
				if (WPM.peek(M))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (!WMM.isEmpty())
		{
			cout << "{" << " ";
			while (WMM.dequeue(M))
			{
				std::cout << M->getID();
				if (WMM.peek(M))
					std::cout << " , ";
			}
			std::cout << "}" << endl;
		}
		if (wem==0)
		{
			std::cout << endl;
		}
		std::cout << "------------------------------------------------------" << endl;
		std::cout << inex << "  In-Execution Missions/Rovers:" << " ";
		if (inexE != 0)
		{
			std::cout << "[" << " ";
			while (InEx.dequeue(M))
			{
				if (M->getType() == 'E')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (InEx.peek(M))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (inexP != 0)
		{
			std::cout << "(";
			while (InEx.dequeue(M))
			{
				if (M->getType() == 'P')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (InEx.peek(M))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (inexM != 0)
		{
			std::cout << "{";
			while (InEx.dequeue(M))
			{
				if (M->getType() == 'M')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (InEx.peek(M))
					std::cout << " , ";
			}
			std::cout << "}" << " " << endl;;
		}
		if (inex == 0)
		{
			std::cout << endl;
		}
		std::cout << "------------------------------------------------------" << endl;
		std::cout << avrovers << "  Available Rovers :" << "";
		if (!AvailableER.isEmpty())
		{
			std::cout << "[" << " ";
			while (AvailableER.dequeue(R))
			{
				std::cout << R->getID();
				if (AvailableER.peek(R))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (!AvailablePR.isEmpty())
		{
			std::cout << "(" << " ";
			while (AvailablePR.dequeue(R))
			{
				std::cout << R->getID();
				if (AvailablePR.peek(R))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (!AvailableMR.isEmpty())
		{
			std::cout << "{" << " ";
			while (AvailableMR.dequeue(R))
			{
				std::cout << R->getID();
				if (AvailableMR.peek(R))
					std::cout << " , ";
			}
			std::cout << "}" << " " << endl;
		}
		if (avrovers==0)
		{
			std::cout << endl;
		}
		std::cout << "------------------------------------------------------" << endl;
		std::cout << incheck << " In - Checkup Rovers :" << " ";
		if (!InCheckupER.isEmpty())
		{
			std::cout << "[" << " ";
			while (InCheckupER.dequeue(R))
			{
				std::cout << R->getID();
				if (InCheckupER.peek(R))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (!InCheckupPR.isEmpty())
		{
			std::cout << "(";
			while (InCheckupPR.dequeue(R))
			{
				std::cout << R->getID();
				if (InCheckupPR.peek(R))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (!InCheckupMR.isEmpty())
		{
			std::cout << "{";
			while (InCheckupMR.dequeue(R))
			{
				std::cout << R->getID();
				if (InCheckupMR.peek(R))
					std::cout << " , ";
			}
			std::cout << "}" << " " << endl;
		}
		if (incheck==0)
		{
			std::cout << endl;
		}
		std::cout << "------------------------------------------------------" << endl;
		std::cout << completedmissions << " Completed Missions:" << " ";
		if (compE != 0)
		{
			std::cout << "[" << " ";
			while (CompletedMissions.dequeue(M))
			{
				if (M->getType() == 'E')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (CompletedMissions.peek(M))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (compP != 0)
		{
			std::cout << "(";
			while (CompletedMissions.dequeue(M))
			{
				if (M->getType() == 'P')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (CompletedMissions.peek(M))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (compM != 0)
		{
			std::cout << "{";
			while (CompletedMissions.dequeue(M))
			{
				if (M->getType() == 'M')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (CompletedMissions.peek(M))
					std::cout << " , ";
			}
			std::cout << "}" << " " << endl;
		}
		pS->load();
		cout << " Enter any thing to continue: " << " " << endl;
		cin >> z;
		break;
	}
	case 2: {
		std::cout << "Current Day : " << pS->GetCurrentDay() << endl;
		std::cout << wem << "  Waiting Missions :" << " ";
		if (!WEM.isEmpty())
		{
			std::cout << "[" << " ";
			while (WEM.dequeue(M))
			{
				std::cout << M->getID();
				if (WEM.peek(M))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (!WPM.isEmpty())
		{
			std::cout << "(" << " ";
			while (WPM.dequeue(M))
			{
				std::cout << M->getID();
				if (WPM.peek(M))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (!WMM.isEmpty())
		{
			cout << "{" << " ";
			while (WMM.dequeue(M))
			{
				std::cout << M->getID();
				if (WMM.peek(M))
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
			std::cout << "[" << " ";
			while (InEx.dequeue(M))
			{
				if (M->getType() == 'E')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (InEx.peek(M))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (inexP != 0)
		{
			std::cout << "(";
			while (InEx.dequeue(M))
			{
				if (M->getType() == 'P')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (InEx.peek(M))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (inexM != 0)
		{
			std::cout << "{";
			while (InEx.dequeue(M))
			{
				if (M->getType() == 'M')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (InEx.peek(M))
					std::cout << " , ";
			}
			std::cout << "}" << " " << endl;;
		}
		if (inex == 0)
		{
			std::cout << endl;
		}
		std::cout << "------------------------------------------------------" << endl;
		std::cout << avrovers << "  Available Rovers :" << "";
		if (!AvailableER.isEmpty())
		{
			std::cout << "[" << " ";
			while (AvailableER.dequeue(R))
			{
				std::cout << R->getID();
				if (AvailableER.peek(R))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (!AvailablePR.isEmpty())
		{
			std::cout << "(" << " ";
			while (AvailablePR.dequeue(R))
			{
				std::cout << R->getID();
				if (AvailablePR.peek(R))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (!AvailableMR.isEmpty())
		{
			std::cout << "{" << " ";
			while (AvailableMR.dequeue(R))
			{
				std::cout << R->getID();
				if (AvailableMR.peek(R))
					std::cout << " , ";
			}
			std::cout << "}" << " " << endl;
		}
		if (avrovers == 0)
		{
			std::cout << endl;
		}
		std::cout << "------------------------------------------------------" << endl;
		std::cout << incheck << " In - Checkup Rovers :" << " ";
		if (!InCheckupER.isEmpty())
		{
			std::cout << "[" << " ";
			while (InCheckupER.dequeue(R))
			{
				std::cout << R->getID();
				if (InCheckupER.peek(R))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (!InCheckupPR.isEmpty())
		{
			std::cout << "(";
			while (InCheckupPR.dequeue(R))
			{
				std::cout << R->getID();
				if (InCheckupPR.peek(R))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (!InCheckupMR.isEmpty())
		{
			std::cout << "{";
			while (InCheckupMR.dequeue(R))
			{
				std::cout << R->getID();
				if (InCheckupMR.peek(R))
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
			while (CompletedMissions.dequeue(M))
			{
				if (M->getType() == 'E')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (CompletedMissions.peek(M))
					std::cout << " , ";
			}
			std::cout << "]" << " ";
		}
		if (compP != 0)
		{
			std::cout << "(";
			while (CompletedMissions.dequeue(M))
			{
				if (M->getType() == 'P')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (CompletedMissions.peek(M))
					std::cout << " , ";
			}
			std::cout << ")" << " ";
		}
		if (compM != 0)
		{
			std::cout << "{";
			while (CompletedMissions.dequeue(M))
			{
				if (M->getType() == 'M')
					std::cout << M->getID() << "/" << (M->getAssignedRover())->getID();
				if (CompletedMissions.peek(M))
					std::cout << " , ";
			}
			std::cout << "}" << " " << endl;
		}
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