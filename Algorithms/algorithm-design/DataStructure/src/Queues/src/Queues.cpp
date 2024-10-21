#include "Queues.h"

QueueClass::QueueClass(){

}

int QueueClass::return1ToTest(){
    return 1;
}

// --------------------------------------------------------
// HELPERS

bool isEmptyQueue(const std::queue<int> queue){
    return queue.empty();
}

void removeElementBasedOnPosition(std::queue<int> &hugoQueue, const int &position){
    std::queue<int> secundaryQueue;

    int index = 1;
    // Can't be defined within the loop, because it get re-evaluated 
    // over and over
    int queuesize = hugoQueue.size();

    while(index <= queuesize){
        if(index != position){
            secundaryQueue.push(hugoQueue.front());
        }
        hugoQueue.pop();
        index++;
    }


    hugoQueue = secundaryQueue;
}
// --------------------------------------------------------
std::queue<int> QueueClass::getQueue(){
    return hugoQueue;
}

void QueueClass::addElement(const int elementToAdd){
    hugoQueue.push(elementToAdd);
}

void QueueClass::removeElement(const int position){
    if(isEmptyQueue(hugoQueue)){
        return;
    }

    if(position == 0){
        hugoQueue.pop();
    } else {
        removeElementBasedOnPosition(hugoQueue, position);
    }
}

void QueueClass::updateFrontElementTo(const int updatedValue){
    if(isEmptyQueue(hugoQueue)){
        return;
    }

    hugoQueue.front() = updatedValue;
}

void QueueClass::updateBackElementTo(const int updatedValue){
    if(isEmptyQueue(hugoQueue)){
        return;
    }

    hugoQueue.back() = updatedValue;
}