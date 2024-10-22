#pragma once

#include <unordered_map>
#include <string>
#include <memory>

class BTreeVertice {
    public:

        BTreeVertice();

        int getValue();
        std::shared_ptr<BTreeVertice> getRoot();
        std::shared_ptr<BTreeVertice> getRightChild();
        std::shared_ptr<BTreeVertice> getLeftChild();

        void setValue(const int &_value);
        void setRoot(std::shared_ptr<BTreeVertice> _root);
        void setRightChild(std::shared_ptr<BTreeVertice> _rightChild);
        void setLeftChild(std::shared_ptr<BTreeVertice> _leftChild);


    private:

        int value;
        std::shared_ptr<BTreeVertice> root;
        std::shared_ptr<BTreeVertice> rightChild;
        std::shared_ptr<BTreeVertice> leftChild;
};

class BTreesClass {

    public:
        BTreesClass();
        int return1ToTest();

        void includeVerticeInBTree(const std::string &key, const int &value, const std::string &root = "");
        std::shared_ptr<BTreeVertice> getBTreeVerticeFromKey(const std::string &key);

    private:
        std::unordered_map<std::string, std::shared_ptr<BTreeVertice>> BTree;

};