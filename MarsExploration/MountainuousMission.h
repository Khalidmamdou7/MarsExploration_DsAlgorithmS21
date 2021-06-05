#pragma once
#include "Mission.h"
class MountainuousMission :
    public Mission
{
private:
    int AutoP;
public:
    MountainuousMission();
    MountainuousMission(int r_FD, int r_TargetLocation, int r_Duration, int r_Significance, char r_Status, int r_AutoP);


    int getAutoP() const;
    void setAutoP(int r_AutoP);
};

  