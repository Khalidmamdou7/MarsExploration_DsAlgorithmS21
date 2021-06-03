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
Rover::~Rover(){}