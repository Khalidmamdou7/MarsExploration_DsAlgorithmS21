#pragma once
#include "Event.h"
class PromoteEvent :
    public Event
{
public:
    PromoteEvent();
    virtual void Execute();
};

PromoteEvent::PromoteEvent() {}

inline void PromoteEvent::Execute()
{
    // TODO: should move a mountainous mission to the emergency list and
    // update the mission’s data(if foundand is waiting)


}



