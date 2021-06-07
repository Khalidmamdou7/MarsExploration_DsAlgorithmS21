#include "PromoteEvent.h"
#include "MarsStation.h"

PromoteEvent::PromoteEvent() {}

PromoteEvent::PromoteEvent(int r_eventD, int r_mID) : Event(r_eventD, r_mID) {
}

void PromoteEvent:: Execute(MarsStation* pS)
{
    // TODO: Create a new mission and add it to the appropriate list

    pStation = pS;

    //Cancellation is always for mountinuios missions only 

    LinkedQueue<Mission*>* pML = pStation->getWMMList();
    PriorityQueue<Mission*>* pEL = pStation->getWEMList();

    if (pML->isEmpty()) return;

    Mission* saveFirstMisson;

    Mission* traversal;
    pML->dequeue(saveFirstMisson);
    //Case 1: We are promoting the first mission in the list 
    if (getmID() == saveFirstMisson->getID()) {
        saveFirstMisson->setType('E');
        pEL->enqueue(saveFirstMisson, saveFirstMisson->getPriority());
    }

    //Case 2: We are promoting ANY mission in the list
    else {
        traversal = saveFirstMisson;
        pML->enqueue(traversal);
        //pML->dequeue(traversal);
        //Now traversal pointer looks at the second entry in the queue
        do {
            //being in this loop means that the queue has not come to a complete round yet

            pML->dequeue(traversal);
            if (getmID() == traversal->getID()) {

                traversal->setType('E');
                pEL->enqueue(traversal, traversal->getPriority());
            }
            else {
                pML->enqueue(traversal);
                // pML->dequeue(traversal);
            }
            pML->peek(traversal);
        } while (traversal->getID() != saveFirstMisson->getID());
    }

}



