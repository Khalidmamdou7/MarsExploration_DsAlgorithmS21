#pragma once
#include "Event.h"
class CancelEvent :
    public Event
{
public:
    CancelEvent();
    virtual void Execute();
};

CancelEvent::CancelEvent() {

}

inline void CancelEvent::Execute()
{
    // TODO: should cancel the requested mountainous mission (if found and is waiting)

}

