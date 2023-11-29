//
// Created by Jacqueline Edoro on 11/24/23.
//
#include "Btree.h"
#include <iostream>


//constructor that takes in minimum number of keys and isLeaf
Node::Node(int min_key, bool leaf){
    //we can start with min key 2 for simplicity
    //initializing minimum number of keys and if it is a leaf
    this->min=min_key;
    this->isLeaf=false;
    //resizing keys and child vectors
    this->keys.resize(2*t-1);
    this->child.resize(2*t);
    //no keys have been inserted so num keys is 0
    this->num_keys=0;
}


///
////PRIVATE SECTION
///

//traverse all nodes in a subtree rooted with node
void traverse(BTreeNode* node){
    // Implement your insertion logic here
    //I would leave this until last since we may or
    //may not need it for the ouput
}
//insert helper
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
//search for data in subtree of node given
int Btree::search(int data, Node* root) {
    // Implement your search logic here
    return nullptr;
}

////
////PUBLIC SECTION
///


//Btree constructor
Btree::Btree(int degree) {
    //we set the minimum degree and root as nullptr as there is
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
   this->repeated_num=search(int data, this->root);
}

