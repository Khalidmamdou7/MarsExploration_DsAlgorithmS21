#include "Event.h"
#include"PromoteEvent.h"


PromoteEvent::PromoteEvent() {}
PromoteEvent::PromoteEvent(int r_eventD, int r_mID) : Event(r_eventD, r_mID) {
}

void PromoteEvent::Execute()
{
    // TODO: should move a mountainous mission to the emergency list and
    // update the mission’s data(if foundand is waiting)


}