#include "Rover.h"

Rover::Rover()
{
	Duration = 0;
	Speed = 0;
}
int Rover::getDuration()
{
	return Duration;
}
int Rover::getSpeed()
{
	return Speed;
}
void Rover::setDuration(int D)
{
	this->Duration = D;
}
void Rover::setSpeed(int S)
{
	this->Speed = S;
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