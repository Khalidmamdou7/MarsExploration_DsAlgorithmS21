#pragma once
#include "Event.h"
class CancelEvent :
    public Event
{
public:
    CancelEvent();
    CancelEvent(int r_eventD, int r_mID);
    virtual void Execute();
};

CancelEvent::CancelEvent() {
}
CancelEvent::CancelEvent(int r_eventD, int r_mID) {
    FormulationDay = r_eventD;
    mID = r_mID;

}

inline void CancelEvent::Execute()
{
    // TODO: should cancel the requested mountainous mission (if found and is waiting)

}

