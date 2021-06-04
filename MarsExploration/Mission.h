#pragma once
class Mission
{
private:
	// char Type;			// Mission types (E: Emergency, M: Mountainuous, P: Polar, U: Unassigned (just for check))
	int FD;				// Formulation Day: the day when the mission formulation is finalized and the mission becomes ready to be assigned to a rover.
	int TargetLocation; // The distance (in kilometers) from the base station to the target location of the mission.
	int Duration;		// The number of days needed to fulfill the mission requirements at the target location(assumed constant regardless of rover type)
	int Significance;	// A number representing the importance of the mission and how beneficial it is (the higher the number, the more significant it is).
	char Status;		// Status of the mission ( W: Waiting, E: In-execution, C: Completed, U: Unassigned (just for check)). Not sure if needed yet.
	// Rover* assignedRover;
public:
	Mission(int r_FD = -1, int r_TargetLocation = -1 , int r_Duration = -1, int r_Significance = -1, char r_Status = 'U');
	
	// char getType() const;
	// void setType(char r_Type);

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

};

Mission::Mission(int r_FD, int r_TargetLocation, int r_Duration, int r_Significance, char r_Status) {
	FD = r_FD;
	// Type = r_Type;
	TargetLocation = r_TargetLocation;
	Duration = r_Duration;
	Significance = r_Significance;
	Status = r_Status;
}

//inline char Mission::getType() const
//{
//	return Type;
//}
//
//inline void Mission::setType(char r_Type)
//{
//	Type = r_Type;
//}

inline int Mission::getFD() const
{
	return FD;
}

inline int Mission::getTargetLocation() const
{
	return TargetLocation;
}

inline int Mission::getDuration() const
{
	return Duration;
}

inline int Mission::getSignificance() const
{
	return Significance;
}

inline char Mission::getStatus() const
{
	return Status;
}

inline void Mission::setFD(int r_FD)
{
	FD = r_FD;
}

inline void Mission::setTargetLocation(int r_TargetLocation)
{
	TargetLocation = r_TargetLocation;
}

inline void Mission::setDuration(int r_Duration)
{
	Duration = r_Duration;
}

inline void Mission::setSignificance(int r_Significance)
{
	Significance = r_Significance;
}

inline void Mission::setStatus(char r_Status)
{
	Status = r_Status;
}

