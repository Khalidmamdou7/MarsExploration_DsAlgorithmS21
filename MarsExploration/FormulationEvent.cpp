#include "FormulationEvent.h"
#include "MarsStation.h"

#include "PriorityQueue.h"
#include "LinkedQueue.h"

FormulationEvent::FormulationEvent()
{
    mType = 'U';    // UnAssigned
    mTargetLocation = -1;
    mDuration = -1;
    mSignificance = -1;
    mAutoP = -1;
}

FormulationEvent::FormulationEvent(int r_eventD, int r_mID, char r_mType, int r_mTargetLocation, int r_mDuration, int r_mSignificance, int r_mAutoP)
    :Event(r_eventD, r_mID)
{
    mType = r_mType;
    mTargetLocation = r_mTargetLocation;
    mDuration = r_mDuration;
    mSignificance = r_mSignificance;
    mAutoP = r_mAutoP;
}

void FormulationEvent::Execute(MarsStation* pS) {
    // TODO: Create a new mission and add it to the appropriate list
    
   pStation = pS;
    
    Mission* pM = new Mission(mID, mType, FormulationDay, mTargetLocation, mDuration, mSignificance, 'W');
    pM->setWD(pS->GetCurrentDay());
    switch (mType) {
    case 'E': {
        // Add to priority queue of waiting Emergency mission using MarsStation
        PriorityQueue<Mission*>* pEL = pStation->getWEMList();
        pEL->enqueue(pM, pM->getPriority());
        break;
    }
    case 'P': {
        // Add to queue of waiting Polar missions using MarStation
        LinkedQueue<Mission*>* pPL = pStation->getWPMList();
        pPL->enqueue(pM);
        break;
    }
    case 'M': {
        // Add to queue of waiting Mountainuous missions using MarStation
        LinkedQueue<Mission*>* pML = pStation->getWMMList();
        pML->enqueue(pM);
        break;
    }
    default:
        break;
    }
}