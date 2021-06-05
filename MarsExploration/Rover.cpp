#include "Rover.h"

Rover::Rover(char r_Type, int r_CheckupDuration, int r_Speed, int N_NoOfMissionsBeforeCheckup)
{
	Type = r_Type;
	CheckupDuration = r_CheckupDuration;
	Speed = r_Speed;
	NoOfMissionsBeforeCheckup = N_NoOfMissionsBeforeCheckup;

}
int Rover::getCheckupDuration()
{
	return CheckupDuration;
}
int Rover::getSpeed()
{
	return Speed;
}

int Rover::getNoOfMissionsBeforeCheckup()
{
	return NoOfMissionsBeforeCheckup;
}


void Rover::setCheckupDuration(int D)
{
	this->CheckupDuration = D;
}
void Rover::setSpeed(int S)
{
	this->Speed = S;
}

void Rover::setNoOfMissionsBeforeCheckup(int N) {
	NoOfMissionsBeforeCheckup = N;
}





Rover::~Rover(){}