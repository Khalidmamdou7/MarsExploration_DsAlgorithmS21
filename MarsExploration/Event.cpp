#include "Event.h"

Event::Event(int r_ED, int r_mID)
{
	pStation = NULL;
	FormulationDay = r_ED;
	mID = r_mID;
}

int Event::getFormulationDay() const {
	return FormulationDay;
}

void Event::setFormulationDay(const int& r_ED)
{
	if (r_ED > 0)
		FormulationDay = r_ED;
}

int Event::getmID() const
{
	return mID;
}

void Event::setmID(const int& r_mID)
{
	mID = r_mID;
}
