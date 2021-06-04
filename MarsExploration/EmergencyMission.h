#pragma once
#include "Mission.h"
class EmergencyMission :
    public Mission
{
private:
    int priority;
public:
    EmergencyMission(int r_FD, int r_TargetLocation, int r_Duration, int r_Significance, char r_Status);

    int getPriority() const;
    void setPriority(int p);
};

