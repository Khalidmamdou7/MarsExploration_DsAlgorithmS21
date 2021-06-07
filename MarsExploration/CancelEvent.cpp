#include "CancelEvent.h"
#include "MarsStation.h"
CancelEvent::CancelEvent() {}
CancelEvent::CancelEvent(int r_eventD, int r_mID) : Event(r_eventD, r_mID) {
}

void CancelEvent::Execute(MarsStation* pS)
{
    // TODO: Create a new mission and add it to the appropriate list

    pStation = pS;

    //Cancellation is always for mountinuios missions only 

    LinkedQueue<Mission*>* pML = pStation->getWMMList();
    if (pML->isEmpty()) return;

    Mission* saveFirstMisson;

    Mission* traversal;
    pML->dequeue(saveFirstMisson);
    //Case 1: We are cancelling the first mission in the list 
    if (getmID() == saveFirstMisson->getID()) {
        delete saveFirstMisson;
        saveFirstMisson = NULL;
    }
    //Case 2: We are cancelling ANY mission in the list
    else {
        traversal = saveFirstMisson;
        pML->enqueue(traversal);
        //pML->dequeue(traversal);
        //Now traversal pointer looks at the second entry in the queue
        do {
            //being in this loop means that the queue has not come to a complete round yet

            pML->dequeue(traversal);
            if (getmID() == traversal->getID()) {

            }
            else {
                pML->enqueue(traversal);
                // pML->dequeue(traversal);
            }
            pML->peek(traversal);
        } while (traversal->getID() != saveFirstMisson->getID());
    }

}