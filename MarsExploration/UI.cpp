#include "UI.h"
#include <iostream>;
#include<chrono>;
#include<thread>;
#include"Mission.h";
#include"Rover.h";
using namespace std;
void UI::ReadMode()
{
	cout << "There's three modes: " << endl;
	cout << "enter 1 for interactive Mode" << endl;
	cout << " 2 for step-by-step mode" << endl;
	cout << "3 for silent mode" << endl;
	cout << "4 for Exit" << endl;
	cin >> Mode;
	switch (Mode)
	{
	case 1:
		Mission g;
		cout << "Current Day :" << g.getFD() << endl;
		cout << " " << "Waiting Missions :" << "["<<" " <<","<<" "<<"]" <<"  "<<"{" <<" "<<"}"<<endl;
		cout << "------------------------------------------------------" << endl;
		cout << "" << "ahmed" << "In-Execution Missions/Rovers:" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" << endl;;
		cout << "------------------------------------------------------" << endl;
		cout << " " << "Available Rovers :" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" << endl;;
		cout << "------------------------------------------------------" << endl;
		cout << " " << " In - Checkup Rovers :" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" << endl;;
		cout << "------------------------------------------------------" << endl;
		cout << " " << "Completed Missions:" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" <<endl;
		break;
	case 2:
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(10000));
		Mission g;
		cout << "Current Day :" << g.getFD() << endl;
		cout << " " << "Waiting Missions :" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "" << "ahmed" << "In-Execution Missions/Rovers:" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" << endl;;
		cout << "------------------------------------------------------" << endl;
		cout << " " << "Available Rovers :" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" << endl;;
		cout << "------------------------------------------------------" << endl;
		cout << " " << " In - Checkup Rovers :" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" << endl;;
		cout << "------------------------------------------------------" << endl;
		cout << " " << "Completed Missions:" << "[" << " " << "," << " " << "]" << "  " << "{" << " " << "}" << endl;
		break;
	case 3:
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
		break;
	case 4:
		exit(0);
	}while (Mode != 4);
}