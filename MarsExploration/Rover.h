#pragma once
class Rover
{
private:
	int Duration;
	int Speed;
	char *Emergency;
	char* Mountainous;
	char *Polar;
public:
	Rover();
	int getDuration();
	void setDuration(int D);
	int getSpeed() ;
	void setSpeed(int S) ;
	void setEmergency(char* E);
	char* getEmergency();
	void setMountainous(char* M);
	char* getMountainous();
	void setPolar(char* P);
	char* getPolar();
	~Rover() ;
};

