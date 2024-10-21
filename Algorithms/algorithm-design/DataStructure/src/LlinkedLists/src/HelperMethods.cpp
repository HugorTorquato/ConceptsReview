#include "NodeStructure.h"

bool isHeadEmpty(const Node* node){
    return node->data == 0 && node->next == nullptr;
}

int getLinkedListLength(Node* head) {
    int length = 0;
    Node* current = head;

    while (current != nullptr) {
        length++;
        current = current->next;
    }

    return length;
}

bool isPositionWithinLinkedListLength(Node* head, const int &position){
    return position > getLinkedListLength(head);
}

void includeNodeAtHeader(Node* &head, const int data){
    head->data = data;
}

void includeNodeAtTheEnd(Node* head, const int data){
    Node* nodeToInclude = new Node();
    Node* headNode = head;

    // Get to the latest node before include the new node
    while (head->next != nullptr) {
        head = head->next;
    }

    nodeToInclude->data = data;

    head->next = nodeToInclude;

    head = headNode;
}

void includeNodeAtTheBeggining(Node* &head, const int data){

    Node* nodeToInclude = new Node();

    nodeToInclude->data = data;
    nodeToInclude->next = head;

    //Important to change the head of the List, otherwise the changes won't affect it
    head = nodeToInclude;
}

void includeNodeAtTheMiddle(Node* &head, const int data, const int position){

    Node* headNode = head;
    Node* nodeToInclude = new Node();

    int currentPosition = 1;
    Node* currentNode = head;

    if(isPositionWithinLinkedListLength(head, position)){
        return;
    }

    while(currentNode->next != nullptr && currentPosition < position){
        currentNode = currentNode->next;
        currentPosition++;
    }

    // nodeToInclude receives the data to the next Node on the list
    nodeToInclude->data = data;
    if(currentNode->next != nullptr){
        nodeToInclude->next = currentNode->next;
    }

    //currentNode receives the data to the new node included
    currentNode->next = nodeToInclude;

    head = headNode;
}

void remveNodeFromTheEndOfTheList(Node* &current){
    Node* previousNode;
    Node* headNode = current;

    while(current->next != nullptr){
        previousNode = current;
        current = current->next;
    }

    // At this point we already have both previous and current node
    // Need to remove the pointer from the next node and the current node point it to nullptr

    current = previousNode;
    current->next = nullptr;

    current = headNode;
}