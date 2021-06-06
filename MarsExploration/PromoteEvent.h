#pragma once
#include "Event.h"
class PromoteEvent :
    public Event
{
public:
    PromoteEvent(int r_eventD, int r_mID);
    PromoteEvent();
    virtual void Execute(MarsStation* pS);
};


