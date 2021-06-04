#include "EmergencyMission.h"

EmergencyMission::EmergencyMission(int r_FD, int r_TargetLocation, int r_Duration, int r_Significance, char r_Status)
	: Mission(r_FD, r_TargetLocation, r_Duration, r_Significance, r_Status)
{
	// Calculates Priority equation
		// Priority = (Mission's significance*10) + Mission's Duration + Target Location - Formulation Day
	priority = (r_Significance * 10) + r_Duration + r_TargetLocation - r_FD;

}

int EmergencyMission::getPriority() const
{
	return priority;
}

void EmergencyMission::setPriority(int p)
{
	priority = p;
}
