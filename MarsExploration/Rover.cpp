#include "Rover.h"

Rover::Rover(char r_Type, int r_CheckupDuration, int r_Speed)
{
	Type = r_Type;
	CheckupDuration = r_CheckupDuration;
	Speed = r_Speed;
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



Rover::~Rover(){}