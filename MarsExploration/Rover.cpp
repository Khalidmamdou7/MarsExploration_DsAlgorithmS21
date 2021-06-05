#include "Rover.h"

Rover::Rover(int r_CheckupDuration, int r_rSpeed, int n_no_Mission_before_checkUp)
{
	CheckupDuration = r_CheckupDuration;
	rSpeed = r_rSpeed;
	noMissionsBeforeCheckUp = n_no_Mission_before_checkUp;
}

int Rover::getCheckupDuration()
{
	return CheckupDuration;
}
int Rover::getrSpeed()
{
	return rSpeed;
}

int Rover::getNoMissionsBeforeCheckUp() {
	return noMissionsBeforeCheckUp;
}


void Rover::setCheckupDuration(int D)
{
	this->CheckupDuration = D;
}

void Rover::setrSpeed(int S)
{
	this->rSpeed = S;
}

void Rover::setNoMissionsBeforeCheckUp(int N) {
	this->noMissionsBeforeCheckUp = N;
}



Rover::~Rover(){}