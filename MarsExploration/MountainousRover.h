#pragma once
#include "Rover.h"
class MountainousRover :
    public Rover
{

public:
    MountainousRover(int r_CheckupDuration, int r_rSpeed, int n_no_Mission_before_checkUp);
};

MountainousRover::MountainousRover(int r_CheckupDuration, int r_rSpeed, int n_no_Mission_before_checkUp)
    : Rover(r_CheckupDuration, r_rSpeed,  n_no_Mission_before_checkUp)
{
}