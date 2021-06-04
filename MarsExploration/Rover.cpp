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
void Rover::setEmergency(char* E)
{
	this->Emergency = E;
}
char* Rover::getEmergency()
{
	return Emergency;
}
void Rover::setMountainous(char* M)
{
	this->Mountainous = M;
}
char* Rover::getMountainous()
{
	return Mountainous;
}
void Rover::setPolar(char* P)
{
	this->Polar = P;
}
char* Rover::getPolar()
{
	return Polar;
}




Rover::~Rover(){}