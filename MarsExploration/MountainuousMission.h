#pragma once
#include "Mission.h"
class MountainuousMission :
    public Mission
{
private:
    int AutoP;
public:
    MountainuousMission();

    int getAutoP() const;
    void setAutoP(int r_AutoP);
};

