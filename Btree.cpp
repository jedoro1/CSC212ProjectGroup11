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
    
    //if tree is empty
   if(root==nullptr){
       //set root from null to new node
       root=new Node(t,true);
       //put in key
       root->keys.push_back(data);
       //change the number of keys
       root->num_keys+=1;
   }
   else{
       //if tree has values, and the number of keys are full in a node
       if(root->num_keys== 2*this->min_keys-1){
           //create new node
            Node* n= new Node(t, false);
            //make the new node have current root as child
            n->child.push_back(root);
            //splits old root into 2 nodes
            n->split_child(n,0);
            //set new node as current root
            this->root=n;
            //this method is called since the root is now not full
            this->root.insert_non_full(this->root,data);

       }
       else{
           //the tree is not full so we can insert normally
           this->root.insert_non_full(this->root,data);
       }
   }
    return root;
}
//search for data in subtree of node given - Ryan Jensen
Node* Btree::search(int data, Node* root) {
    int i = 0;

    //Loop that finds the specific index
    while (i < root->num_keys && root->keys[i] < data) {
        i++;
    }

    //Checks if we've reached the key
    if (data == root->keys[i] && i < root->num_keys){
        return root;
    }

    //Check if the node is a leaf
    if (root->isLeaf){
        return nullptr;
    }

    //Recursively move to the child node.
    return search(data, root->child[i]);
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
