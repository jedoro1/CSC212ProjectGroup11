#include <ctime>
#include <cstring>
#include "Btree.h"
#include "bst.h"
#include "llrbtree.h"
#include <iostream>

//Function to calculate complexity for Btree
float time_func_Btree(Btree t, const char *name, int key) {
    unsigned long c_start, c_end;

    if (! strcmp(name, "insert")) {
        c_start = std::clock();
        t.insert(key);
        c_end = std::clock();
    }
    else if (! strcmp(name, "search")) {
        c_start = std::clock();
        t.search(key);
        c_end = std::clock();
    }
    else if (! strcmp(name, "traverse")) {
        c_start = std::clock();
        t.traverse();
        c_end = std::clock();
    }
    else{
        std::cout << "Invalid method call" << std::endl;
        return 0;
    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    return output;
}

//Function to calculate time complexities for LLRBTrees
float time_func_LLRB(LLRBTree t, const char *name, int key) {
    unsigned long c_start, c_end;

    if (! strcmp(name, "insert")) {
        c_start = std::clock();
        t.insert(key);
        c_end = std::clock();
    }
    else if (! strcmp(name, "search")) {
        c_start = std::clock();
        t.search(key);
        c_end = std::clock();
    }
    else if (! strcmp(name, "inorder")) {
        c_start = std::clock();
        t.inorder();
        c_end = std::clock();
    }
    else if (! strcmp(name, "preorder")) {
        c_start = std::clock();
        t.preorder();
        c_end = std::clock();
    }
    else if (! strcmp(name, "postorder")) {
        c_start = std::clock();
        t.postorder();
        c_end = std::clock();
    }
    else{
        std::cout << "Invalid method call" << std::endl;
        return 0;
    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    return output;
}

float time_func_BST(BSTree t, const char *name, int key, BSTNode* root) {
    unsigned long c_start, c_end;

    if (! strcmp(name, "insert")) {
        c_start = std::clock();
        t.insert(key);
        c_end = std::clock();
    }
    else if (! strcmp(name, "search")) {
        c_start = std::clock();
        t.search(root, key);
        c_end = std::clock();
    }
    else if (! strcmp(name, "inorder")) {
        c_start = std::clock();
        t.inorder();
        c_end = std::clock();
    }
    else if (! strcmp(name, "preorder")) {
        c_start = std::clock();
        t.preorder();
        c_end = std::clock();
    }
    else if (! strcmp(name, "postorder")) {
        c_start = std::clock();
        t.postorder();
        c_end = std::clock();
    }
    else{
        std::cout << "Invalid method call" << std::endl;
        return 0;
    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    return output;
}

