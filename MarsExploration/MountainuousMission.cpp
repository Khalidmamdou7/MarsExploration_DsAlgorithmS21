#include "MountainuousMission.h"

MountainuousMission::MountainuousMission()
{
	AutoP = -1;
}

int MountainuousMission::getAutoP() const
{
	return AutoP;
}

void MountainuousMission::setAutoP(int r_AutoP)
{
	AutoP = r_AutoP;
}
