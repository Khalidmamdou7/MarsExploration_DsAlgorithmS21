#include "Rover.h"

Rover::Rover(char r_Type, int r_CheckupDuration, int r_Speed, int n_noMissionsBeforeCheckUp)
{
	Type = r_Type;
	CheckupDuration = r_CheckupDuration;
	Speed = r_Speed;
	noMissionsBeforeCheckUp = n_noMissionsBeforeCheckUp;
	MissionsCount = 0;
	AvailableDay = 0;
	/////
	isAssigned = false;
}

// Rover Type (E: Emergency, P: Polar, M: Mountainous)
char Rover::getType() const
{
	return Type;
}

// Rover Type (E: Emergency, P: Polar, M: Mountainous)
void Rover::setType(char r_t)
{
	Type = r_t;
}

int Rover::getCheckupDuration()
{
	return CheckupDuration;
}
int Rover::getSpeed()
{
	return Speed;
}

int Rover::getNoMissionsBeforeCheckUp() {
	return noMissionsBeforeCheckUp;
}


void Rover::setCheckupDuration(int D)
{
	this->CheckupDuration = D;
}
void Rover::setSpeed(int S)
{
	this->Speed = S;
}

void Rover::setNoMissionsBeforeCheckUp(int N) {
	this->noMissionsBeforeCheckUp = N;
}

int Rover::getMissionsCount() const
{
	return MissionsCount;
}

// Increment MissionsCount
void Rover::FinishedMission()
{
	MissionsCount++;
}

// Check if Rover finished Checkup
// Reset MissionsCount to zero
bool Rover::Checkuped(int currDay)
{
	if (AvailableDay == currDay) {
		MissionsCount = 0;
		AvailableDay = 0;
		return true;
	}
	else
		return false;
}

bool Rover::NeedsCheckup(int currDay)
{	
	if (MissionsCount >= noMissionsBeforeCheckUp) {
		AvailableDay = currDay + CheckupDuration;
		return true;
	}
	return false;
}

//bool Rover::isassigned()
//{
//	return isAssigned;
//}

Rover::~Rover() {}