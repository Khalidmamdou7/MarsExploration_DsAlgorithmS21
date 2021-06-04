#pragma once
class Event
{
private:
	int eventDay;
	int mID;
public:
	Event(int ED = 0, int mID = 0);
	int getEventDay() const;
	void setEventDay(const int& ED);
	int getmID() const;
	void setmID(const int& mID);
	virtual void Execute() = 0;
};

inline Event::Event(int r_ED, int r_mID)
{
	eventDay = r_ED;
	mID = r_mID;
}

int Event::getEventDay() const {
	return eventDay;
}

inline void Event::setEventDay(const int& r_ED)
{
	if (r_ED > 0)
		eventDay = r_ED;
}

inline int Event::getmID() const
{
	return mID;
}

inline void Event::setmID(const int& r_mID)
{
	mID = r_mID;
}



