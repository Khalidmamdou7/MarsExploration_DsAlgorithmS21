#pragma once
#include "Rover.h"
class PolarRover :
    public Rover
{

public:
    PolarRover(int r_CheckupDuration, int r_rSpeed, int n_no_Mission_before_checkUp);
};

PolarRover::PolarRover(int r_CheckupDuration, int r_rSpeed, int n_no_Mission_before_checkUp)
    : Rover(r_CheckupDuration, r_rSpeed ,n_no_Mission_before_checkUp) {
}