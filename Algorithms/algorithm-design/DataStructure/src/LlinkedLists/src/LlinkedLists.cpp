#include "LlinkedLists.h"

int LinkedListsClass::return1ToTest(){
    return 1;
}

LinkedListsClass::LinkedListsClass(){
    head = new Node();
}

Node* LinkedListsClass::retrieveHeadNode(){
    return head;
}

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

Node* LinkedListsClass::retrieveNodeBasedOnGivenPosition(const int position){

    int currentPosition = 0;
    Node* node = retrieveHeadNode();

    if(isHeadEmpty(node) || isPositionWithinLinkedListLength(node, position)){
        return nullptr;
    }

    while(node != nullptr && currentPosition < position) {

        if(node->next != nullptr){
            node = node->next;  
        }
        currentPosition++;
    }

    return node;
}

void includeNodeAtHeader(Node* &head, const int data){
    head->data = data;
}

void includeNodeAtTheEnd(Node* &head, const int data){
    Node* nodeToInclude = new Node();

    nodeToInclude->data = data;

    head->next = nodeToInclude;
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