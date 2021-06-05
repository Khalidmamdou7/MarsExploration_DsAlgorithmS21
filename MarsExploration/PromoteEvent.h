#pragma once
#include "Event.h"
class PromoteEvent :
    public Event
{
public:
    PromoteEvent(int r_eventD, int r_mID);
    PromoteEvent();
    virtual void Execute();
};

PromoteEvent::PromoteEvent() {}
PromoteEvent::PromoteEvent(int r_eventD, int r_mID) : Event(r_eventD, r_mID) {
}

inline void PromoteEvent::Execute()
{
    // TODO: should move a mountainous mission to the emergency list and
    // update the mission’s data(if foundand is waiting)


}



