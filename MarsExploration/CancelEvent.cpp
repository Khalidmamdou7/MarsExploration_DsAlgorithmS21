#include "CancelEvent.h"
CancelEvent::CancelEvent() {}
CancelEvent::CancelEvent(int r_eventD, int r_mID) : Event(r_eventD, r_mID) {
}

void CancelEvent::Execute(MarsStation* pS)
{
    // TODO: should cancel the requested mountainous mission (if found and is waiting)

}