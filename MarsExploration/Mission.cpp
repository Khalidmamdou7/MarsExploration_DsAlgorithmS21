#include "Mission.h"


Mission::Mission(char r_Type, int r_FD, int r_TargetLocation, int r_Duration, int r_Significance, char r_Status, Rover* r_assignedRover) {
	FD = r_FD;
	Type = r_Type;
	TargetLocation = r_TargetLocation;
	Duration = r_Duration;
	Significance = r_Significance;
	Status = r_Status;
	assignedRover = r_assignedRover;
}

char Mission::getType() const
{
	return Type;
}

void Mission::setType(char r_Type)
{
	Type = r_Type;
}

int Mission::getFD() const
{
	return FD;
}

int Mission::getTargetLocation() const
{
	return TargetLocation;
}

int Mission::getDuration() const
{
	return Duration;
}

int Mission::getSignificance() const
{
	return Significance;
}

char Mission::getStatus() const
{
	return Status;
}

void Mission::setFD(int r_FD)
{
	FD = r_FD;
}

void Mission::setTargetLocation(int r_TargetLocation)
{
	TargetLocation = r_TargetLocation;
}

void Mission::setDuration(int r_Duration)
{
	Duration = r_Duration;
}

void Mission::setSignificance(int r_Significance)
{
	Significance = r_Significance;
}

void Mission::setStatus(char r_Status)
{
	Status = r_Status;
}

Rover* Mission::getAssignedRover() const
 {
	 return assignedRover;
 }

void Mission::setAssignedRover(Rover* r)
 {
	 assignedRover = r;
 }
