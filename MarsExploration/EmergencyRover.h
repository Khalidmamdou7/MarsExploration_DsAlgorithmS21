#pragma once
#include "Rover.h"
class EmergencyRover :
    public Rover
{

public:
    EmergencyRover(int r_CheckupDuration, int r_rSpeed , int n_no_Mission_before_checkUp);
};

EmergencyRover::EmergencyRover(int r_CheckupDuration, int r_rSpeed , int n_no_Mission_before_checkUp)
    : Rover(r_CheckupDuration, r_rSpeed) {
    }