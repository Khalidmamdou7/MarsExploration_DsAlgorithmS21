#pragma once
#include"MarsStation.h"
class UI
{
private:
	int Mode;
	MarsStation* h;

public:
	UI(MarsStation* g);
	void ReadMode();
};

