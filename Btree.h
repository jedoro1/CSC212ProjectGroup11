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

        // //Removes a key from the B-tree while preserving the B-tree properties.
        // void deleteKey(int data);

        // // Merges two nodes when deleting a key
        // void mergeNodes(Node* node1, Node* node2);

        // // Splits a node into two nodes when it becomes full
        // void split(Node* node);

        // // Merges a node with its sibling when it becomes underflowed
        // void merge(Node* node);

        // // Finds the successor key in the B-tree
        // int findSuccessor(int data);

        // // Finds the predecessor key in the B-tree
        // int findPredecessor(int data);

        // // Retrieves all key-value pairs within the given range
        // void rangeQuery(int start, int end);

        // // Adjusts the B-tree structure after a deletion operation
        // void adjustAfterDelete(Node* node);

        // // Adjusts the B-tree structure after an insertion operation
        // void adjustAfterInsert(Node* node);

        // Calculates and returns the height of the B-tree
        int getHeight();

        // Prints the structure of the B-tree for visualization and debugging purposes
        void printTree();


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
