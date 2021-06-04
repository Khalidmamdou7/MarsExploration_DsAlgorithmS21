#pragma once
#include "Event.h"
class FormulationEvent :
    public Event
{
private:
    char mType;             // mission Type (M: mountainous, P: polar, E: emergency, U: Unassigned)
    int mTargetLocation;    // mission’s target location (in kilometers from the base station
    int mDuration;          // the number of days needed to fulfill the mission requirements at target location.
    int mSignificance;      // mission's significance
public:
    FormulationEvent();
    FormulationEvent(int r_eventD, int r_mID, char r_mType, int r_mTargetLocation, int r_mDuration, int r_mSignificance);
    virtual void Execute();
};


inline FormulationEvent::FormulationEvent()
{
    mType = 'U';    // UnAssigned
    mTargetLocation = -1;
    mDuration = -1;
    mSignificance = -1;
}

inline FormulationEvent::FormulationEvent(int r_eventD, int r_mID, char r_mType, int r_mTargetLocation, int r_mDuration, int r_mSignificance):
    Event(r_eventD, r_mID)
{
    mType = r_mType;
    mTargetLocation = r_mTargetLocation;
    mDuration = r_mDuration;
    mSignificance = r_mSignificance;
}

void FormulationEvent::Execute() {
    // TODO: Create a new mission and add it to the appropriate list

}
