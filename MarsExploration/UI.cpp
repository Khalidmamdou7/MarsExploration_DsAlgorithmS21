#include "UI.h"
#include <iostream>;
#include<chrono>;
using namespace std;
void UI::ReadMode()
{
	cout << "There's three modes: enter 1 for interactive, 2 for step-by-step, and 3 for silent mode" << endl;
	cin >> Mode;
	switch (Mode)
	{
	case 1:
		break;
	case 2:
		_sleep(1000);

		break;
	case 3:
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
		break;
	default:
		cout << " Wrong number" << endl;
		break;
	}
}