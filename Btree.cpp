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

//Jaiden Diaz
//traverse all nodes in a subtree rooted with node
void traverse(){
    // Implement your insertion logic here
    //I would leave this until last since we may or
    //may not need it for the ouput
    int i;
    for (i = 0; i < numKeys; i++) {
        if (!isLeaf)
            children[i]->traverse();
        std::cout << " " << keys[i];
    }

    if (!isLeaf)
        children[i]->traverse();
}

//insert helper - Ryan Jensen
void insert_non_full(Btree* root, int data){
    void Btree::insert_non_full(Node* root, int data){
    int i = root->num_keys - 1;

    //Checks if root is a leaf
    if (root->isLeaf){

        //Finds location of new key by moving
        //all the keys forward by one.
        while(i >= 0 && root->keys[i] > data){
            root->keys[i+1] = root->keys[i];
            i--;
        }

        //Insert new key at location found in while loop
        root->keys[i+1] = data;
        root->num_keys++;
    }
    //If root is not a leaf
    else{

        //Finding child node index
        while(i >= 0 && root->keys[i] > data){
            i--;
        }

        //If it's full, split it
        if(root->child[i+1]->num_keys == 2 * root->min_key - 1) {
            split_child(root->child[i + 1], i + 1);

            //Checking which of the two sides has the key
            if (root->keys[i + 1] < data) {
                i++;
            }

            //Inserting key
            insert_non_full(root->child[i + 1], data);
        }
    }
}

}
//insert helper
void split_child(Node* root, int index){

    Node* fullChild = root->children[index];
    Node* newChild = new Node(fullChild->isLeaf);

    // Move the middle key to the parent
    int middleKey = fullChild->keys[min_key - 1];
    root->keys.insert(root->keys.begin() + index, middleKey);

    // Move the keys to the new node
    newChild->keys.assign(fullChild->keys.begin() + min_key, fullChild->keys.end());
    fullChild->keys.resize(min_key - 1);

    // If the nodes are not leaf nodes, move the children as well
    if (!fullChild->isLeaf) {
        newChild->children.assign(fullChild->children.begin() + min_key, fullChild->children.end());
        fullChild->children.resize(min_key);
    }

    // Insert the new node as a child to the parent
     root->children.insert(root->children.begin() + index + 1, newChild);
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

//Jaiden Diaz
// Public method to traverse the entire B-tree
void BTree::traverse() {
    if (root != nullptr)
        root->traverse();
}
