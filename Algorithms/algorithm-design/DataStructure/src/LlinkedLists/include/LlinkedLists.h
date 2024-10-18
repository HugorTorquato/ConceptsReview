#pragma once

#include <iostream>


struct Node
{
    int data;
    Node* next;
};



class LinkedListsClass {

    public:
        LinkedListsClass();

        int return1ToTest();
        Node* retrieveHeadNode();
        Node* retrieveNodeBasedOnGivenPosition(const int position);
        void inculdeNewNodeAtTheEndOfTheList(const int data);

    private:
        Node* head;
};