//
// Created by Jacqueline Edoro on 11/24/23.
#pragma once
#include <vector>
Class Node{
    private:
        std::vector<KeyType> keys;
        // Keys stored in the node
        std::vector<ValueType> values;
        // Corresponding values for the keys (if the B-tree is used as a map)
        std::vector<Node*> children;
        // Pointers to child nodes
        bool isLeaf;
        // Indicates whether the node is a leaf or internal node
        friend class Btree;
    public:
        Node();

};

Class Btree{

    private:

    public:
};