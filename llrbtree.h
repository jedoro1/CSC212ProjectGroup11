#pragma once

#include <iostream>
#include <ostream>

// Defines MAX
// When used, MAX(a,b) will be replaced with ((a > b) ? a : b)
#ifndef MAX
#define MAX(a,b) ((a > b) ? a : b)
#endif

// Underlying class which will be used to implement the BSTree class.
// I.E. BSTree is made up of BSTNode
class LLRBNode
{
private:
    int data;
    LLRBNode* left;
    LLRBNode* right;
    bool red;

public:
    LLRBNode();
    LLRBNode(int data);
    ~LLRBNode();

    friend class LLRBTree;
};

// Public versions: accept a single parameter so the usage of the class is neat.
// Private version: implement the functions recursively
class LLRBTree
{
private:
    LLRBNode* _root;
    bool isRed(LLRBNode* root);

    LLRBNode* insert(int data, LLRBNode* root);
    LLRBNode* remove(int data, LLRBNode* root);
    LLRBNode* find_ios(LLRBNode* root, bool& disconnect);
    int height(LLRBNode* root);

    void preorder(LLRBNode* root, std::ostream& os);
    void inorder(LLRBNode* root, std::ostream& os);
    void postorder(LLRBNode* root, std::ostream& os);

    void destroy(LLRBNode* root);
    bool search(int data, LLRBNode* root);

public:
    LLRBTree();
    ~LLRBTree();

    void insert(int data);
    void remove(int data);
    int height();

    LLRBNode* rotateLeft(LLRBNode* root);
    LLRBNode* rotateRight(LLRBNode* root);
    LLRBNode* flipColors(LLRBNode* root);
    //void flipRoot();


    void preorder(std::ostream& os = std::cout);
    void inorder(std::ostream& os = std::cout);
    void postorder(std::ostream& os = std::cout);

    bool search(int data);

};
