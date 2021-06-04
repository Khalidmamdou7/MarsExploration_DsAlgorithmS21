#include "MountainuousMission.h"

MountainuousMission::MountainuousMission()
{
	AutoP = -1;
}

MountainuousMission::MountainuousMission(int r_FD, int r_TargetLocation, int r_Duration, int r_Significance, char r_Status, int r_AutoP)
	: Mission(r_FD, r_TargetLocation, r_Duration, r_Significance, r_Status)
{
	AutoP = r_AutoP;
}

int MountainuousMission::getAutoP() const
{
	return AutoP;
}

void MountainuousMission::setAutoP(int r_AutoP)
{
	AutoP = r_AutoP;
}
