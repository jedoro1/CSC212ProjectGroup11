#include "bst.h"

BSTNode::BSTNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}


BSTNode::~BSTNode(){

}

//Constructor
BSTree::BSTree(){
    this->root = nullptr;
}
//Destructor
BSTree::~BSTree(){
    destroy(root);
}
//Private destroy method
void BSTree::destroy(BSTNode* node){
    if (node != nullptr){
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}
//Private Insert

BSTNode * BSTree::insert(BSTNode* node, int data){
    if(node == nullptr){
        return new BSTNode(data);
    }
    if(node->data < data){
        node->right = insert(node->right, data);
    }
    if(node->data > data){
        node->left = insert(node->left, data);
    }
    return node;
}


//Public Insert
void BSTree::insert(int data){
    root = insert(root, data);
}

//Private remove
BSTNode* BSTree::remove(BSTNode* node, int data){

    if(node == nullptr){
        return nullptr;
    }
    if(node->data < data){
        node->right = remove(node->right, data);
    }
    else if(node->data > data){
        node->left = remove(node->left, data);
    }
    else{
        if(node->left == nullptr){
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right == nullptr){
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }

        BSTNode* temp = node->right;
        while(temp->left != nullptr){
            temp = temp->left;
        }
        node->data = temp->data;

        node->right = remove(node->right, temp->data);
    }
    return node;
}
//Public remove

void BSTree::remove(int data){
    root = remove(root, data);
}

//Private Height

int BSTree::height(BSTNode* node){
    if(root == nullptr){
        return -1;
    }

    int leftH = 0;
    int rightH = 0;

    if(node->left != nullptr){
        leftH = 1 + height(node->left);
    }
    if(node->right != nullptr){
        rightH = 1 + height(node->right);
    }

    if(leftH < rightH){
        return rightH;
    }
    if(rightH < leftH){
        return leftH;
    }
}

//Public Height

int BSTree::height(){
    return height(root);
}

//Private preorder
void BSTree::preorder(BSTNode* node, std::ostream& os){
    if (node != nullptr){
        os<<node->data << " ";
        preorder(node->left, os);
        preorder(node->right, os);
    }
}
//Public preorder
void BSTree::preorder(std::ostream& os){
    preorder(root, os);
}

//Private inorder
void BSTree::inorder(BSTNode* node, std::ostream& os){
    if (node != nullptr){
        inorder(node->left, os);
        os<<node->data << " ";
        inorder(node->right, os);
    }
}

//Public inorder
void BSTree::inorder(std::ostream& os){
    inorder(root, os);
}

//Private postorder
void BSTree::postorder(BSTNode* node, std::ostream& os){
    if (node != nullptr){
        postorder(node->left, os);
        postorder(node->right, os);
        os<<node->data << " ";
    }

}
//Public postorder
void BSTree::postorder(std::ostream& os){
    postorder(root, os);
}

//Public search
bool BSTree::search(BSTNode* node, int data){
    if(root == nullptr){
        return false;
    }

    if(node->data == data){
        return true;
    }

    if(node->data < data){
        return search(node->right, data);
    }

    if(node->data > data){
        return search(node->left, data);
    }
}
