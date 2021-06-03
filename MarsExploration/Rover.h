#pragma once
class Rover
{
private:
	int Duration;
	int Speed;
public:
	Rover();
	int getDuration();
	void setDuration(int D);
	int getSpeed() ;
	void setSpeed(int S) ;
	~Rover() ;
};

