#pragma once

#include <iostream>
#include <vector>

#include "NodeStructure.h"



class LinkedListsClass {

    public:
        LinkedListsClass();

        int return1ToTest();
        Node* retrieveHeadNode();
        std::vector<int> retrieveLLValuesAsIntegerVactor();
        Node* retrieveNodeBasedOnGivenPosition(const int position);
        void inculdeNewNodeAtTheEndOfTheList(const int data);
        void inculdeNewNodeAtTheBegginningOfTheList(const int data);
        void inculdeNewNodeAtTheMiddleOfTheList(const int data, const int position);
        void removeNodeFromEndOfTheLinkedList(int position = 0);

    private:
        Node* head;
};