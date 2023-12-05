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
        t.traverse(key);
        c_end = std::clock();
    }
    else{
        std::cout << "Invalid method call" << std::endl;
        return 0;
    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    return output;
}

//Function to find time for string B-Tree.
float time_func_Btree(Btree t, const char *name, std::string key) {
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
        t.traverse(key);
        c_end = std::clock();
    }
    else{
        std::cout << "Invalid method call" << std::endl;
        return 0;
    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    return output;
}




