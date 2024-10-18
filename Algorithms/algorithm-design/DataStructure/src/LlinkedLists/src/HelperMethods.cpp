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

    // Get to the latest node before include the new node
    while (head->next != nullptr) {
        head = head->next;
    }

    nodeToInclude->data = data;

    head->next = nodeToInclude;
}

void includeNodeAtTheBeggining(Node* &head, const int data){

    Node* nodeToInclude = new Node();

    nodeToInclude->data = data;
    nodeToInclude->next = head;

    //Important to change the head of the List, otherwise the changes won't affect it
    head = nodeToInclude;
}
