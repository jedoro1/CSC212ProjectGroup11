#pragma once
#include <vector>
#include <sstream>
#include <fstream>


class Node{
private:
    // Keys stored in a vector as integers
    int* keys;

    std::string* s_keys;

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

    void split_child_string(int index, Node*child);

    //preorder, post order, in order (probably needed so we generate dot file)
    int traverse(int key, int repeated_nums);

    //Same code but for strings
    int traverse(std::string key, int repeated_nums);

    //inserts into a non full node
    void insert_non_full(int key);

    void insert_non_full(std::string key);

public:
    //constructor that takes in minimum number of keys and isLeaf
    Node(int min_key, bool isLeaf);

    //searches the tree finding repeats, returns count(see above guidelines)
    Node* search(int key);

    Node* search(std::string key);

    friend class Btree;

};

class Btree{

private:
    Node* root;

    //Minimum degree of Btree
    int min_key;


public:
    //constructor of the B tree class takes in degree
    Btree(int min_key);

    //Public method to call private insert method
    void insert(int key);

    void insert(std::string key);

    //Public method to call private search method
    Node* search(int key);

    Node* search(std::string key);

    //Public method to call private traverse method
    void traverse(int key);

    void traverse(std::string key);

