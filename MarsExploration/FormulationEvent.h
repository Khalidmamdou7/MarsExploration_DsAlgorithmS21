#pragma once
#include "Mission.h"
#include "Event.h"
using namespace std;


class FormulationEvent : public Event
{
private:
    char mType;             // mission Type (M: mountainous, P: polar, E: emergency, U: Unassigned)
    int mTargetLocation;    // missionís target location (in kilometers from the base station
    int mDuration;          // the number of days needed to fulfill the mission requirements at target location.
    int mSignificance;      // mission's significance
    int mAutoP;
public:
    FormulationEvent();
    FormulationEvent(int r_eventD, int r_mID, char r_mType, int r_mTargetLocation, int r_mDuration, int r_mSignificance, int mAutoP);
    virtual void Execute(MarsStation* pS);
};


