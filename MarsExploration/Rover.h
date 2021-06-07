#pragma once
class Rover
{
private:
	char Type;				// Rover Type (E: Emergency, P: Polar, M: Mountainous)
	int CheckupDuration;	// The duration (in days) of checkups that a rover needs to perform after completing N missions.
	int Speed;
	int noMissionsBeforeCheckUp;
	int MissionsCount;		// Number of missions done before checkup - reset with each checkup
	int AvailableDay;		// The Day which the rover will finish checkup
	////
	bool isAssigned;
	////
public:
	Rover(char r_Type, int r_CheckupDuration = 0, int r_Speed = 0, int noMissionsBeforeCheckUp = 0);

	char getType() const;
	void setType(char);

	int getCheckupDuration();
	void setCheckupDuration(int D);

	int getSpeed();
	void setSpeed(int S);

	int getNoMissionsBeforeCheckUp();
	void setNoMissionsBeforeCheckUp(int);

	int getMissionsCount() const;
	void FinishedMission();			// Increment MissionsCount
	bool Checkuped(int currDay);	// Reset MissionsCount to zero
	bool NeedsCheckup(int currDay);

	/////
	//bool isassigned();
	~Rover();
};

