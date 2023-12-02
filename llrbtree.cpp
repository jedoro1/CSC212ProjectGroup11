#include "llrbtree.h"

/*
 * Node Class Functions
*/

LLRBNode::LLRBNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->red = true;
}

LLRBNode::~LLRBNode(){

}

/*
 * Tree Class Functions
*/

/*
 * Private Functions
*/

LLRBNode* LLRBTree::insert(int data, LLRBNode* root){
    if(!root){
        return new LLRBNode(data);
    }
    // Go left if data < data at this Node
    if(data < root->data){
        root->left = insert(data, root->left);
        // Go right otherwise
    }else{
        root->right = insert(data, root->right);
    }

    if(isRed(root->right) && !isRed(root->left)){
        root = rotateLeft(root);
    }
    if(isRed(root->left) && isRed(root->left->left)){
        root = rotateRight(root);
    }
    if(isRed(root->left) && isRed(root->right)){
        flipColors(root);
    }

    return root;
}

LLRBNode* LLRBTree::remove(int data, LLRBNode* root){
    if(!root){
        return nullptr;
    }

    // We found what we're looking for, delete it.
    if(data == root->data){
        LLRBNode* temp;
        // This is a leaf node
        if(root->left == root->right){
            delete root;
            return nullptr;
        }

        // This node has 1 child
        if(!root->left != !root->right){
            // Set temp to whichever child exists
            root->left ? temp = root->left : temp = root->right;

            delete root;
            return temp;
        }

        // This node has 2 children
        // Find the in-order successor
        temp = root->right;

        while(temp->left){
            temp = temp->left;
        }

        // Copy the data to this node and delete the original
        root->data = temp->data;
        root->right = remove(temp->data, root->right);
        return root;
    }

    // This is not the Node we're looking for, recursively find the data we want to delete
    if(data < root->data){
        root->left = remove(data, root->left);
    }else{
        root->right = remove(data, root->right);
    }

    return root;
}

LLRBNode* LLRBTree::find_ios(LLRBNode* root, bool& disconnect){
    if(!root->left){
        disconnect = true;
        return root;
    }
    LLRBNode* temp = find_ios(root->left, disconnect);

    if(disconnect){
        root->left = nullptr;
        disconnect = false;
    }

    return temp;
}

int LLRBTree::height(LLRBNode* root){
    if(!root){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left + 1 : right + 1);
}

void LLRBTree::preorder(LLRBNode* root, std::ostream& os){
    if(!root){
        return;
    }

    os << root->data << ":" << root->red << " ";
    this->preorder(root->left, os);
    this->preorder(root->right, os);

    return;
}

void LLRBTree::inorder(LLRBNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->inorder(root->left, os);
    os << root->data << ":" << root->red << " ";
    this->inorder(root->right, os);

    return;
}

void LLRBTree::postorder(LLRBNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->postorder(root->left, os);
    this->postorder(root->right, os);
    os << root->data << ":" << root->red << " ";

    return;
}

void LLRBTree::destroy(LLRBNode* root){
    if(!root){
        return;
    }

    this->destroy(root->left);
    this->destroy(root->right);
    delete root->left;
    delete root->right;
}

bool LLRBTree::search(int data, LLRBNode* root){
    if(!root){
        return false;
    }

    if(data == root->data){
        return true;
    }

    if(data < root->data){
        return this->search(data, root->left);
    }else{
        return this->search(data, root->right);
    }
}

bool LLRBTree::isRed(LLRBNode* root){
    if(root == nullptr){
        return false;
    }

    return root->red;
}

//void LLRBTree::flipRoot(){
//    if(isRed(_root)){
//        this->_root->red = false;
//    }
//}

LLRBNode* LLRBTree::rotateLeft(LLRBNode* root){
    LLRBNode* p = root->right;
    root->right = p->left;
    p->left = root;
    p->red = root->red;
    root->red = true;
    return p;
}

LLRBNode* LLRBTree::rotateRight(LLRBNode* root){
    LLRBNode* p = root->left;
    root->left = p->right;
    p->right = root;
    p->red = root->red;
    root->red = true;
    return p;
}

LLRBNode* LLRBTree::flipColors(LLRBNode *root) {
    root->red = true;
    root->left->red = false;
    root->right->red = false;
}
/*
 * Public Functions
*/

LLRBTree::LLRBTree(){
    this->_root = nullptr;
    std::cout<<"Tree was made woohoo"<<std::endl;
}

LLRBTree::~LLRBTree(){
    delete this->_root;
}

void LLRBTree::insert(int data){
    this->_root = this->insert(data, this->_root);
    _root->red = false;
}

void LLRBTree::remove(int data){
    this->_root = this->remove(data, this->_root);
}

int LLRBTree::height(){
    return this->height(this->_root);
}

void LLRBTree::preorder(std::ostream& os){
    this->preorder(this->_root, os);
    os << "\n";
}

void LLRBTree::inorder(std::ostream& os){
    this->inorder(this->_root, os);
    os << "\n";
}

void LLRBTree::postorder(std::ostream& os){
    this->postorder(this->_root, os);
    os << "\n";
}

bool LLRBTree::search(int data){
    return this->search(data, this->_root);
}
