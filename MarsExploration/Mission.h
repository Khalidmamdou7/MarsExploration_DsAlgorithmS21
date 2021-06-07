#pragma once

#include "Rover.h"

class Mission
{
private:
	char Type;			// Mission types (E: Emergency, M: Mountainuous, P: Polar, U: Unassigned (just for check))
	int FD;				// Formulation Day: the day when the mission formulation is finalized and the mission becomes ready to be assigned to a rover.
	int TargetLocation; // The distance (in kilometers) from the base station to the target location of the mission.
	int Duration;		// The number of days needed to fulfill the mission requirements at the target location(assumed constant regardless of rover type)
	int Significance;	// A number representing the importance of the mission and how beneficial it is (the higher the number, the more significant it is).
	char Status;		// Status of the mission ( W: Waiting, E: In-execution, C: Completed, U: Unassigned (just for check)). Not sure if needed yet.
	Rover* assignedRover;
	int priority;
	// int AutoP;			// the number of days after which a mountainous mission is automatically promoted to an emergency mission (Not sure if needed)
	int WD;					// Waiting Days
	int ED;					// Execution Days
public:
	Mission(char r_Type = 'U', int r_FD = -1, int r_TargetLocation = -1, int r_Duration = -1, int r_Significance = -1, char r_Status = 'U', Rover* r_ass = nullptr);

	char getType() const;
	void setType(char r_Type);

	int getFD() const;
	void setFD(int r_FD);

	int getTargetLocation() const;
	void setTargetLocation(int r_TargetLocation);

	int getDuration() const;
	void setDuration(int r_Duration);

	int getSignificance() const;
	void setSignificance(int r_Significance);

	char getStatus() const;
	void setStatus(char r_Status);

	int getPriority() const;
	void setPriority(int p);

	int getWD() const;
	void setWD(int r_WD);
	
	int getED() const;
	void setED(int r_ED);

	Rover* getAssignedRover() const;
	void setAssignedRover(Rover* r);

};
