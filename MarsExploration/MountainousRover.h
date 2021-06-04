#pragma once
#include "Rover.h"
class MountainousRover :
    public Rover
{

public:
    MountainousRover(int r_CheckupDuration, int r_rSpeed);
};

MountainousRover::MountainousRover(int r_CheckupDuration, int r_rSpeed)
    : Rover(r_CheckupDuration, r_rSpeed) 
{
}