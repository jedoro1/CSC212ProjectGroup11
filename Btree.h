//
// Created by Jacqueline Edoro on 11/24/23.
// Edited by Ryan Jensen on 11/29/23.

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
        std::vector<int> keys;

        //minimum number of keys each node requires
        int min_key;

        //stores vector of child pointers
        std::vector<Node*> child;

        //current number of keys
        int num_keys;

        //checks if the node is a leaf, True if leaf, false if not
        bool isLeaf;

        friend class Btree;

        public:
        //constructor that takes in minimum number of keys and isLeaf
        Node(int min_key, bool leaf);

};

class Btree{

        private:
        Node* root;

        //Minimum degree of Btree
        int min;

        //Repeated numbers found in the search method
        int repeated_num;

        //Main insert, directs to methods like split_child/insert_non_full
        Node* insert(int data, Node* root);

        //searches the tree finding repeats, returns count(see above guidelines)
        Node* search(int data, Node* root);

        //preorder, post order, in order (probably needed so we generate dot file)
        void traverse(Node* node);

        //inserts into a non full node
        void insert_non_full(Btree* root, int data);

        //splits nodes if too big
        void split_child(Btree* root, int data);

        public:
        //constructor of the B tree class takes in degree
        Btree(int degree);

        //Public method to call private insert method
        void insert(int data);

        //Public method to call private search method
        void search(int data);

        //Public method to call private traverse method
        void traverse();
};
