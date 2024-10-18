#pragma once

#include <iostream>
#include <vector>

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
        std::vector<int> retrieveLLValuesAsIntegerVactor();
        Node* retrieveNodeBasedOnGivenPosition(const int position);
        void inculdeNewNodeAtTheEndOfTheList(const int data);

    private:
        Node* head;
};