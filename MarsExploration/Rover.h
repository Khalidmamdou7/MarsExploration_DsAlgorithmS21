#pragma once
class Rover
{
protected:
	int CheckupDuration;
	int rSpeed;
	int noMissionsBeforeCheckUp;
public:
	Rover(int r_CheckupDuration = 0, int r_rSpeed = 0, int no_Mission_before_checkUp=0);
	int getCheckupDuration();
	void setCheckupDuration(int D);
	
	int getrSpeed() ;
	void setrSpeed(int S) ;

	int getNoMissionsBeforeCheckUp();
	void setNoMissionsBeforeCheckUp(int N);
	
	
	~Rover() ;
};

