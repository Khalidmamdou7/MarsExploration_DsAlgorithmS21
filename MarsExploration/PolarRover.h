#pragma once
#include "Rover.h"
class PolarRover :
    public Rover
{

public:
    PolarRover(int r_CheckupDuration, int r_rSpeed);
};

PolarRover::PolarRover(int r_CheckupDuration, int r_rSpeed)
    : Rover(r_CheckupDuration, r_rSpeed) {
}