#include "Rover.h"

Rover::Rover(int r_CheckupDuration, int r_rSpeed)
{
	CheckupDuration = r_CheckupDuration;
	rSpeed = r_rSpeed;
}
int Rover::getCheckupDuration()
{
	return CheckupDuration;
}
int Rover::getrSpeed()
{
	return rSpeed;
}
void Rover::setCheckupDuration(int D)
{
	this->CheckupDuration = D;
}
void Rover::setrSpeed(int S)
{
	this->rSpeed = S;
}




Rover::~Rover(){}