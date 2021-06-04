#pragma once
#include "Rover.h"
class EmergencyRover :
    public Rover
{

public:
    EmergencyRover(int r_CheckupDuration, int r_rSpeed);
};

EmergencyRover::EmergencyRover(int r_CheckupDuration, int r_rSpeed)
    : Rover(r_CheckupDuration, r_rSpeed) {
    }