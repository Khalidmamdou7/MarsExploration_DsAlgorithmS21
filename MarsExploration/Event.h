#pragma once
class Event
{
protected:
	//MarsStation* pStation;
	int FormulationDay;
	int mID;
public:
	Event(int ED = 0, int mID = 0);
	int getFormulationDay() const;
	void setFormulationDay(const int& ED);
	int getmID() const;
	void setmID(const int& mID);
	virtual void Execute() = 0;
};

inline Event::Event(int r_ED, int r_mID)
{
	FormulationDay = r_ED;
	mID = r_mID;
}

int Event::getFormulationDay() const {
	return FormulationDay;
}

inline void Event::setFormulationDay(const int& r_ED)
{
	if (r_ED > 0)
		FormulationDay = r_ED;
}

inline int Event::getmID() const
{
	return mID;
}

inline void Event::setmID(const int& r_mID)
{
	mID = r_mID;
}




