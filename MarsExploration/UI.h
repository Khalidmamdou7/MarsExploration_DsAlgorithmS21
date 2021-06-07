#pragma once

class MarsStation;

class UI
{
private:
	MarsStation* pS;
	int Mode;
public:
	UI();
	void ReadMode(MarsStation* pS);
};

