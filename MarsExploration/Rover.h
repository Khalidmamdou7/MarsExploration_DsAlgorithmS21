#pragma once
class Rover
{
private:
	char Type;				// Rover Type (E: Emergency, P: Polar, M: Mountainous)
	int CheckupDuration;
	int Speed;
	int NoOfMissionsBeforeCheckup;
public:
	Rover(char r_Type, int r_CheckupDuration = 0, int r_Speed = 0 , int N_NoOfMissionsBeforeCheckup=0);
	int getCheckupDuration();
	void setCheckupDuration(int D);
	
	int getSpeed() ;
	void setSpeed(int S) ;

	int getNoOfMissionsBeforeCheckup();
	void setNoOfMissionsBeforeCheckup(int);

	
	~Rover() ;
};

