#pragma once
class Event
{
private:
	int eventDay;
	int missionID;
public:
	int getEventDay() const;
	void setEventDay(const int& ED);
	int getMissionID() const;
	void setMissionID(const int& mID);
	virtual void Execute() = 0;
};

int Event::getEventDay() const {
	return eventDay;
}

inline void Event::setEventDay(const int& ED)
{
	if (ED > 0)
		eventDay = ED;
}

inline int Event::getMissionID() const
{
	return missionID;
}

inline void Event::setMissionID(const int& mID)
{
	missionID = mID;
}



