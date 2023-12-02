#include <fstream>
#include <sstream>
#include <iostream>

class BSTNode{
private:
    int data;
    BSTNode* left;
    BSTNode* right;

    friend class BSTree;
public:
    BSTNode(int data);
    ~BSTNode();
};

class BSTree{

private:
    void destroy(BSTNode *p);
    BSTNode* insert(BSTNode* node, int data);
    BSTNode* remove(BSTNode* node, int data);
    int height(BSTNode* root);
    void preorder(BSTNode* node, std::ostream& os);
    void inorder(BSTNode* node, std::ostream& os);
    void postorder(BSTNode* node, std::ostream& os);

public:
    BSTNode* root;
    BSTree();
    ~BSTree();
    void insert(int data);
    int height();
    void remove(int d);
    void preorder(std::ostream& os = std::cout);
    void inorder(std::ostream& os = std::cout);
    void postorder(std::ostream& os = std::cout);
    bool search(BSTNode* node, int data);

};
