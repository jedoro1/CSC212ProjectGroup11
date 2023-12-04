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
    s_keys = new std::string[2 * min_key - 1];
    children.resize(2 * min_key);
}


///
////PRIVATE SECTION
///

//Jaiden Diaz
//traverse all nodes in a subtree rooted with node
int Node::traverse(int key, int repeated_nums) {
    int i;

    //Counts repeated key in the B-Tree
    for (i = 0; i < num_keys; i++) {
        if(key == keys[i]){
            repeated_nums++;
        }
    }

    // Traverse child nodes
    for (i = 0; i < num_keys; i++) {
        if (!isLeaf) {
            repeated_nums += children[i]->traverse(key, 0);
        }
        std::cout << " " << keys[i];
    }

    if (!isLeaf){
        repeated_nums += children[i]->traverse(key, 0);
    }

    return repeated_nums;
}

//String edition
int Node::traverse(std::string key, int repeated_nums) {
    int i;

    //Counts repeated keys in B-Tree
    for (i = 0; i < num_keys; i++) {
        if(key == s_keys[i]){
            repeated_nums++;
        }
    }

    //Traverse child nodes
    for (i = 0; i < num_keys; i++) {
        if (!isLeaf) {
            repeated_nums += children[i]->traverse(key, 0);
        }
        std::cout << " " << s_keys[i];
    }

    if (!isLeaf){
        repeated_nums += children[i]->traverse(key, 0);
    }

    return repeated_nums;
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

//String edition
void Node::insert_non_full(std::string key) {
    int i = num_keys - 1;

    if (isLeaf) {
        // If the node is a leaf, insert the key into the correct position
        while (i >= 0 && s_keys[i].compare(key) > 0) {
            s_keys[i + 1] = s_keys[i];
            i--;
        }

        s_keys[i + 1] = key;
        num_keys++;
    } else {
        // If the node is not a leaf, recursively insert into the appropriate child
        while (i >= 0 && s_keys[i].compare(key) > 0) {
            i--;
        }

        if (children[i + 1]->num_keys == 2 * min_key - 1) {
            // If the child is full, split the child before insertion
            split_child_string(i + 1, children[i + 1]);

            if (i < num_keys && s_keys[i].compare(key) < 0) {
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

//String edition
void Node::split_child_string(int index, Node* child) {
    Node* z = new Node(child->min_key, child->isLeaf);
    z->num_keys = min_key - 1;

    // Copy the last (min_key-1) keys of the full child to the new node
    for (int j = 0; j < min_key - 1; j++) {
        z->s_keys[j] = child->s_keys[j + min_key];
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
        s_keys[j + 1] = s_keys[j];
    }
    s_keys[index] = child->s_keys[min_key - 1];
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

//main insert -Jaiden Diaz
void Btree::insert(std::string key) {
    // if the tree is empty
    if (root == nullptr) {
        // If the tree is empty, create a new root node
        root = new Node(min_key, true);
        root->s_keys[0] = key;
        root->num_keys = 1;
    } else {
        if (root->num_keys == 2 * min_key - 1) {
            // If the root is full, create a new root and split the old root
            Node* s = new Node(min_key, false);
            s->children[0] = root;
            s->split_child_string(0, root);

            int i = 0;
            if (s->s_keys[0].compare(key) < 0) {
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
    int repeated_nums = 0;

    //Finds spot in keys
    while (i < num_keys && key > keys[i]) {
        i++;
    }

    //If it found the key, print out key was found with repeated_nums
    if (keys[i] == key) {
        repeated_nums = traverse(key, repeated_nums);
        std::cout<<std::endl;
        std::cout<<"Key was found!"<<std::endl;

        if(repeated_nums == 1){
            std::cout<<"The key was repeated "<< repeated_nums << " time." << std::endl;
        }
        else {
            std::cout << "The key was repeated " << repeated_nums << " times." << std::endl;
        }
        return this;
    }

    //Reached the end of the subtree, didn't find the key
    if (isLeaf) {
        std::cout<<"Key not found :(."<<std::endl;
        return nullptr;
    }

    return children[i]->search(key);
}

Node* Node::search(std::string key) {
    int i = 0;
    int repeated_nums = 0;

    //Finds spot in keys
    while (i < num_keys && key > s_keys[i]) {
        i++;
    }

    //If it found the key, print out key was found with repeated_nums
    if (s_keys[i] == key) {
        repeated_nums = traverse(key, repeated_nums);
        std::cout<<std::endl;
        std::cout<<"Key was found!"<<std::endl;
        std::cout<<"The key was repeated "<< repeated_nums << " times." << std::endl;
        return this;
    }

    //Reached the end of the subtree, didn't find the key
    if (isLeaf) {
        std::cout<<"Key not found :(."<<std::endl;
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
void Btree::traverse(int key) {
    int repeated_nums = 0;
    if (root != nullptr) {
        root->traverse(key, repeated_nums);
    }
}

void Btree::traverse(std::string key) {
    int repeated_nums = 0;
    if (root != nullptr) {
        root->traverse(key, repeated_nums);
    }
}

// Public method to search for a key in the B-tree
Node* Btree::search(int key) {
    return (root == nullptr) ? nullptr : root->search(key);
}

Node* Btree::search(std::string key) {
    return (root == nullptr) ? nullptr : root->search(key);
}

//Method to write dotfile
void Btree::writeNodeDot(Node* node, std::ostream& dotfile, int& nodeId, int mode) {

    //Integer
    if(mode == 0){

        int currentId = nodeId++;
        dotfile << "  node" << currentId << " [label=\"{";
        if (node->keys) {
            //Iterates through keys and inserts into dot file
            for (int i = 0; i < node->num_keys ; ++i) {  // Assuming -1 marks the end of keys
                dotfile << " <data" << i << "> " << node-> keys[i];
                //Adds | between each word
                if ( i != node->num_keys-1 ) {
                    dotfile << " | ";
                }
            }
        }
        dotfile << "}\"];\n";

        //If the node has children, does the same thing but for children
        if (!node->children.empty()) {
            for (int i = 0; node->children[i] != nullptr; ++i) {  // Assuming nullptr marks the end of children
                writeNodeDot(node->children[i], dotfile, nodeId, mode);
                int childId = nodeId - 1;
                dotfile << "  node" << currentId << ":data" << i << " -> node" << childId << ";\n";
            }
        }
    }


    //Same thing for strings instead
    if(mode == 1){

        int currentId = nodeId++;
        dotfile << "  node" << currentId << " [label=\"{";
        if (node->s_keys) {
            for (int i = 0; i < node->num_keys; ++i) {  // Assuming -1 marks the end of keys
                dotfile << " <data" << i << "> " << node->s_keys[i];
                if (i != node->num_keys-1) {
                    dotfile << " | ";
                }
            }
        }
        dotfile << "}\"];\n";

        if (!node->children.empty()) {
            for (int i = 0; node->children[i] != nullptr; ++i) {  // Assuming nullptr marks the end of children
                writeNodeDot(node->children[i], dotfile, nodeId, mode);
                int childId = nodeId - 1;
                dotfile << "  node" << currentId << ":data" << i << " -> node" << childId << ";\n";
            }
        }
    }
}

//Helper method that calls the dot file writer and opens the file
void Btree::writeDotFile(Node* root, const std::string& filename, int mode ) {
    std::ofstream dotfile(filename);
    if (!dotfile.is_open()) {
        std::cerr << "Error: Unable to open Dot file for writing.\n";
        return;
    }

    dotfile << "digraph BTree {\n";
    dotfile << "  node [shape=record];\n";
    int nodeId = 0;
    writeNodeDot(root, dotfile, nodeId, mode);
    dotfile << "}\n";
}

//Helper dot file method
void Btree::writeDotFile(const std::string& filename, int mode){
    return this->writeDotFile(this->root, filename, mode);
}
