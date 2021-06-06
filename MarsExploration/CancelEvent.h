#pragma once
#include "Event.h"

class CancelEvent :
    public Event
{
public:
    CancelEvent(int r_eventD, int r_mID);
    CancelEvent();
    virtual void Execute();
};



