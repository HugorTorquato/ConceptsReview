#pragma once

#include <unordered_map>
#include <string>

class BTreeVertice {
    public:

        BTreeVertice();

        int getValue();
        BTreeVertice* getRoot();
        BTreeVertice* getRightChild();
        BTreeVertice* getLeftChild();

        void setValue(const int &_value);
        void setRoot(BTreeVertice* _root);
        void setRightChild(BTreeVertice* _rightChild);
        void setLeftChild(BTreeVertice* _leftChild);


    private:

        int value;
        BTreeVertice* root;
        BTreeVertice* rightChild;
        BTreeVertice* leftChild;
};

class BTreesClass {

    public:
        BTreesClass();
        int return1ToTest();

        void includeVerticeInBTree(const std::string &key, const int &value, const std::string &root = "");
        BTreeVertice* getBTreeVerticeFromKey(const std::string &key);

    private:
        std::unordered_map<std::string, BTreeVertice*> BTree;

};