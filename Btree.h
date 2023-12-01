//
// Created by Jacqueline Edoro on 11/24/23.

//**B-Tree**

//- ensure at least `insert` & `search` methods are correct
//- `search` must also return/print the count
//
//- generate a DOT file for visualization
//
//        **_Store the words of an input text file_**
//
//- for the word ($node$) in the tree, a count with the number of repeats must also be stored

#pragma once
#include <vector>


class Node{
private:
        // Keys stored in a vector as integers
        int* keys;

        //minimum number of keys each node requires
        int min_key;

        //stores vector of child pointers
        std::vector<Node*> children;

        //current number of keys
        int num_keys;

        //checks if the node is a leaf, True if leaf, false if not
        bool isLeaf;

        //splits nodes if too big
        void split_child(int index, Node* child);

        //preorder, post order, in order (probably needed so we generate dot file)
        void traverse();

        //inserts into a non full node
        void insert_non_full(int key);

public:
        //constructor that takes in minimum number of keys and isLeaf
        Node(int min_key, bool isLeaf);

        //searches the tree finding repeats, returns count(see above guidelines)
        Node* search(int key);

        friend class Btree;

};

class Btree{

private:
        Node* root;

        //Minimum degree of Btree
        int min_key;

        //Repeated numbers found in the search method
        int repeated_num;

public:
        //constructor of the B tree class takes in degree
        Btree(int min_key);

        //Public method to call private insert method
        void insert(int key);

        //Public method to call private search method
        Node* search(int key);

        //Public method to call private traverse method
        void traverse();

        // Prints the structure of the B-tree for visualization and debugging purposes
        void printTree();
};
