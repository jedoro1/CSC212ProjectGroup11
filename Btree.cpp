//
// Created by ryanj on 11/29/2023.
//

//For this commit I just cleaned up the cpp file and labeled the methods I'm working on.
//I decided printing out the repeatednum inside the method is the best approach

#include "Btree.h"
#include <iostream>


//constructor that takes in minimum number of keys and isLeaf
// Constructor for Node
Node::Node(int min_key, bool isLeaf)
    : min_key(min_key), isLeaf(isLeaf), num_keys(0) {
    keys = new int[2 * min_key - 1];
    children.resize(2 * min_key);
}


///
////PRIVATE SECTION
///

//Jaiden Diaz
//traverse all nodes in a subtree rooted with node
void Node::traverse() {
    int i;
    for (i = 0; i < num_keys; i++) {
        if (!isLeaf) {
            children[i]->traverse();
        }
        std::cout << " " << keys[i];
    }

    if (!isLeaf) {
        children[i]->traverse();
    }
}

//insert helper - Ryan Jensen
//edited -Jaiden Diaz
void Node::insert_non_full(int key) {
    int i = num_keys - 1;

    if (isLeaf) {
        // If the node is a leaf, insert the key into the correct position
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = key;
        num_keys++;
    } else {
        // If the node is not a leaf, recursively insert into the appropriate child
        while (i >= 0 && keys[i] > key) {
            i--;
        }

        if (children[i + 1]->num_keys == 2 * min_key - 1) {
            // If the child is full, split the child before insertion
            split_child(i + 1, children[i + 1]);

            if (keys[i + 1] < key) {
                i++;
            }
        }
        children[i + 1]->insert_non_full(key);
    }
}

//split child method -Jaiden Diaz
void Node::split_child(int index, Node* child) {
    Node* z = new Node(child->min_key, child->isLeaf);
    z->num_keys = min_key - 1;

    // Copy the last (min_key-1) keys of the full child to the new node
    for (int j = 0; j < min_key - 1; j++) {
        z->keys[j] = child->keys[j + min_key];
    }

    if (!child->isLeaf) {
        // Copy the last min_key children of the full child to the new node
        for (int j = 0; j < min_key; j++) {
            z->children[j] = child->children[j + min_key];
        }
    }

    // Update the number of keys in the full child
    child->num_keys = min_key - 1;

    // Move the pointer to the new node into the parent node
    for (int j = num_keys; j >= index + 1; j--) {
        children[j + 1] = children[j];
    }
    children[index + 1] = z;

    // Move the key from the full child to the parent node
    for (int j = num_keys - 1; j >= index; j--) {
        keys[j + 1] = keys[j];
    }
    keys[index] = child->keys[min_key - 1];
    num_keys++;
}

//main insert -Jaiden Diaz
void Btree::insert(int key) {
  //if tree is empty
   if (root == nullptr) {
        // If the tree is empty, create a new root node
        root = new Node(min_key, true);
        root->keys[0] = key;
        root->num_keys = 1;
    } else {
        if (root->num_keys == 2 * min_key - 1) {
            // If the root is full, create a new root and split the old root
            Node* s = new Node(min_key, false);
            s->children[0] = root;
            s->split_child(0, root);

            int i = 0;
            if (s->keys[0] < key) {
                i++;
            }
            s->children[i]->insert_non_full(key);

            root = s;
        } else {
            // If the root is not full, insert into the root directly
            root->insert_non_full(key);
        }
    }
}

//search for data in subtree of node given - Ryan Jensen
Node* Node::search(int key) {
       int i = 0;
    while (i < num_keys && key > keys[i]) {
        i++;
    }

    if (keys[i] == key) {
        return this;
    }

    if (isLeaf) {
        return nullptr;
    }

    return children[i]->search(key);
}

////
////PUBLIC SECTION
///


//Btree constructor
// Constructor for BTree
Btree::Btree(int min_key) : root(nullptr), min_key(min_key) {}

// Public method to traverse the entire B-tree
void Btree::traverse() {
    if (root != nullptr) {
        root->traverse();
    }
}

// Public method to search for a key in the B-tree
Node* Btree::search(int key) {
    return (root == nullptr) ? nullptr : root->search(key);
}
