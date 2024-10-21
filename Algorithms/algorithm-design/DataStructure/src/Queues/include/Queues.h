#pragma once

#include <queue>


class QueueClass {

    public:
        QueueClass();

        int return1ToTest();

        std::queue<int> getQueue();
        void addElement(const int elementToAdd);
        void removeElement(const int position = 0);

        void updateFrontElementTo(const int updatedValue);
        void updateBackElementTo(const int updatedValue);

    private:
        std::queue<int> hugoQueue;

};