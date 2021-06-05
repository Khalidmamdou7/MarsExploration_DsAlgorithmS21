#pragma once
#include "Event.h"

#include "Mission.h"

class FormulationEvent :
    public Event
{
private:
    char mType;             // mission Type (M: mountainous, P: polar, E: emergency, U: Unassigned)
    int mTargetLocation;    // mission’s target location (in kilometers from the base station
    int mDuration;          // the number of days needed to fulfill the mission requirements at target location.
    int mSignificance;      // mission's significance
    int mAutoP;
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

    Mission* pM = new Mission(mType, FormulationDay, mTargetLocation, mDuration, mSignificance, 'W');
    switch (mType) {
    case 'E': {
        // Calculates Priority equation
        // Priority = (Mission's significance*10) + Mission's Duration + Target Location - Formulation Day
        int priority = (mSignificance * 10) + mDuration + mTargetLocation - FormulationDay;

        // Add to priority queue of waiting Emergency mission using MarsStation
        // pStation->get(pMission);

        break;
    }
    case 'P':
        // Add to queue of waiting Polar missions using MarStation
        // pStation->AddMission(pMission)

        break;
    case 'M':
        // Add to queue of waiting Mountainuous missions using MarStation

        break;
    default:

        break;
    }



}

