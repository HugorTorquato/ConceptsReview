#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <queue>

class BTreeVertice {
    public:

        BTreeVertice();
        BTreeVertice(int _value);

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

        void includeVerticeInBTree(const std::string &key, const int &value, const std::string &rootKey = "");
        std::shared_ptr<BTreeVertice> getBTreeVerticeFromKey(const std::string &key);

        std::shared_ptr<BTreeVertice> getRootVertice();
        int getNumberOfNodes();

        void includeVerticeAtTree(const std::shared_ptr<BTreeVertice> BTV);
        void deleteVerticeAtTree(const int value);

    private:
        std::shared_ptr<BTreeVertice> rootVertice;

        // This map can increase memory usage ( bad )
        std::unordered_map<std::string, std::shared_ptr<BTreeVertice>> BTree;

};