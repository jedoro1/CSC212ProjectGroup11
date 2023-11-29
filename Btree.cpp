//
// Created by ryanj on 11/29/2023.
//

//For this commit I just cleaned up the cpp file and labeled the methods I'm working on.
//I decided printing out the repeatednum inside the method is the best approach

#include "Btree.h"
#include <iostream>


//constructor that takes in minimum number of keys and isLeaf
Node::Node(int min_key, bool leaf){
    //we can start with min key 2 for simplicity
    //initializing minimum number of keys and if it is a leaf
    this->min_key = min_key;
    this->isLeaf = leaf;
    //resizing keys and child vectors
    this->keys.resize(2 * min_key - 1);
    this->child.resize(2 * min_key);
    //no keys have been inserted so num keys is 0
    this->num_keys = 0;
}


///
////PRIVATE SECTION
///

//traverse all nodes in a subtree rooted with node
void traverse(Node* node){
    // Implement your insertion logic here
    //I would leave this until last since we may or
    //may not need it for the ouput
}
//insert helper - Ryan Jensen
void insert_non_full(Btree* root, int data){
    // Implement your insertion logic here
}
//insert helper
void split_child(Btree* root, int data){
    // Implement your insertion logic here
}
//main insert
Node* Btree::insert(int data, Node* root) {
    // Implement your insertion logic here
    return nullptr;
}
//search for data in subtree of node given - Ryan Jensen
Node* Btree::search(int data, Node* root) {

    return nullptr;
}

////
////PUBLIC SECTION
///


//Btree constructor
Btree::Btree(int degree) {
    //we set the minimum degree to 0 and root as nullptr as there is
    //nothing in the Btree. It will be filled in the insert.
    this->min=degree;
    this->root=nullptr;
}

//Public insert called by user
void Btree::insert(int data) {
    //setting current root to inserted data
    this->root = insert(data, this->root);
}

//Public search called by user
void Btree::search(int data) {
    //search returns count of data in Btree
    search(data, this->root);
}
