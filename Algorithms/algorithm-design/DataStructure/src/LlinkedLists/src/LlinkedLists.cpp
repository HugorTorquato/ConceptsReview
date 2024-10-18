#include "LlinkedLists.h"
#include "HelperMethods.cpp"

int LinkedListsClass::return1ToTest(){
    return 1;
}

LinkedListsClass::LinkedListsClass(){
    head = new Node();
}

Node* LinkedListsClass::retrieveHeadNode(){
    return head;
}

std::vector<int> LinkedListsClass::retrieveLLValuesAsIntegerVactor(){

    std::vector<int> llValues;

    Node* current = retrieveHeadNode();

    while (current != nullptr) {
        llValues.push_back(current->data);
        current = current->next;
    }

    return llValues;
}

Node* LinkedListsClass::retrieveNodeBasedOnGivenPosition(const int position){

    int currentPosition = 1;
    Node* node = retrieveHeadNode();

    if(isHeadEmpty(node) || isPositionWithinLinkedListLength(node, position)){
        return nullptr;
    }

    while(node->next != nullptr && currentPosition < position){
        node = node->next;
        currentPosition++;
    }

    return node;
}

void LinkedListsClass::inculdeNewNodeAtTheEndOfTheList(const int data){
    // Criar nova structure
    // Se não tiver valor no header adiciona ali mesmo
    // se não adiciona uma nova structure (Node)

    if(isHeadEmpty(head)){
        includeNodeAtHeader(head, data);
    } else {
        includeNodeAtTheEnd(head, data);
    }
}

void LinkedListsClass::inculdeNewNodeAtTheBegginningOfTheList(const int data){

    if(isHeadEmpty(head)){
        includeNodeAtHeader(head, data);
    } else {
        includeNodeAtTheBeggining(head, data);
    }
}