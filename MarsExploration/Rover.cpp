#include "Rover.h"

Rover::Rover(char r_Type, int r_CheckupDuration, int r_Speed, int n_noMissionsBeforeCheckUp)
{
	Type = r_Type;
	CheckupDuration = r_CheckupDuration;
	Speed = r_Speed;
	noMissionsBeforeCheckUp = n_noMissionsBeforeCheckUp;
	MissionsCount = 0;
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

// Reset MissionsCount to zero
void Rover::Checkuped()
{
	MissionsCount = 0;
}

bool Rover::NeedsCheckup()
{
	return MissionsCount >= noMissionsBeforeCheckUp;
}

//bool Rover::isassigned()
//{
//	return isAssigned;
//}

Rover::~Rover() {}