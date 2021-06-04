#pragma once
#include "Event.h"

#include "EmergencyMission.h"
#include "PolarMissions.h"
#include "MountainuousMission.h"

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

    EmergencyMission* pEM = NULL;
    PolarMissions* pPM = NULL;
    MountainuousMission* pMM = NULL;
    switch (mType) {
    case 'E':
        pEM = new EmergencyMission(FormulationDay, mTargetLocation, mDuration, mSignificance, 'W');
        break;
    case 'P':
        pPM = new PolarMissions(FormulationDay, mTargetLocation, mDuration, mSignificance, 'W');
        break;
    case 'M':
        pMM = new MountainuousMission(FormulationDay, mTargetLocation, mDuration, mSignificance, 'W', mAutoP);
        break;
    default:
        break;
    }

    

    if (pEM) {
        // Add to priority queue of waiting Emergency mission using MarsStation
        // pStation->get(pMission);
    }
    if (pPM) {
        // Add to queue of waiting Polar missions using MarStation
        // pStation->AddMission(pMission)
    }
    if (pMM) {
        // Add to queue of waiting Mountainuous missions using MarStation

    }

}

