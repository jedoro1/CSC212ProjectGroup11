#include <iostream>
#include <random>
#include "Btree.h"
#include "time_functions.h"


int main(int argc, char* argv[]) {
    Btree btree(3);
    LLRBTree llrbtree;
    BSTree bstree;

    std::cout << "V To show the B-Tree class works V" << std::endl;

    std::cout << "Inserting 5 numbers into B-Tree..." << std::endl;
    btree.insert(5);
    btree.insert(9);
    btree.insert(12);
    btree.insert(15);
    btree.insert(4);

    std::cout<<std::endl;
    std::cout<<"Showcasing traverse method"<<std::endl;
    btree.traverse();

    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Inserting 7 into tree..."<<std::endl;

    btree.insert(7);

    std::cout<<std::endl;
    std::cout<<"Showing new btree..."<<std::endl;
    btree.traverse();

    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Searching for 7 in btree..."<<std::endl;
    btree.search(7);

    std::cout<<std::endl;
    std::cout<<"Searching for 8 in btree.."<<std::endl;
    btree.search(8);



    //Code from <random> library to get random numbers from 1 to whatever the user inputs
    // Seed for the random number generator
    std::random_device rd;
    // Mersenne Twister random number engine
    std::mt19937 gen(rd());
    // Define the range for random numbers (1 to userAmount)
    std::uniform_int_distribution<int> distribution(1, 10000);

    int randomNum;
    for(int i = 0; i < 100; i++){
        randomNum = distribution(gen);
        btree.insert(randomNum);
        //llrbtree.insert(randomNum);
        //bstree.insert(randomNum);

    }

    //CODE FOR B-TREE TIME COMPLEXITY

    float BTinsertT = time_func_Btree(btree, "insert", 101);
    float BTsearchT = time_func_Btree(btree, "search", 55);
    float BTtraverseT = time_func_Btree(btree, "traverse", 0);

    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "** BTree TIME COMPLEXITY **" << '\n';
    std::cout << '\n';
    std::cout << "Insertion time for B-Tree --> " << BTinsertT << " seconds" << std::endl;
    std::cout << "Search time for B-Tree --> " << BTsearchT << " seconds" << std::endl;
    std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;
    std::cout << std::endl;
    
    //CODE FOR BST TIME COMPLEXITY
   
    std::cout << "** BST TIME COMPLEXITY **" << '\n';
    std::cout << '\n';
   
   float BSTinsertT = time_func_BST(bstree, "insert", 101, bstree.root);
   float BSTsearchT = time_func_BST(bstree, "search", 55, bstree.root);
    float BSTinorderT = time_func_BST(bstree, "inorder", 0, bstree.root);
   float BSTpreorderT = time_func_BST(bstree, "preorder", 0, bstree.root);
   float BSTpostorderT = time_func_BST(bstree, "postorder", 0, bstree.root);

    std::cout << "Insertion time for BSTree --> " << BSTinsertT << " seconds" << std::endl;
    std::cout << "Search time for BSTree --> " << BSTsearchT << " seconds" << std::endl;
   std::cout << "Inorder time for BSTree --> " << BSTinorderT << " seconds" << std::endl;
   std::cout << "Preorder time for BSTree --> " << BSTpreorderT << " seconds" << std::endl;
   std::cout << "Postorder time for BSTree --> " << BSTpostorderT << " seconds" << std::endl;

   std::cout << std::endl;


    //CODE FOR LLBR TIME COMPLEXITY

    std::cout << "** LLRBTree TIME COMPLEXITY **" << '\n';
    std::cout << '\n';

   float LLRBinsertT = time_func_LLRB(llrbtree, "insert", 101);
   float LLRBsearchT = time_func_LLRB(llrbtree, "search", 55);
   float LLRBinorderT = time_func_LLRB(llrbtree, "inorder", 0);
   float LLRBpreorderT = time_func_LLRB(llrbtree, "preorder", 0);
   float LLRBpostorderT = time_func_LLRB(llrbtree, "postorder", 0);

   std::cout << "Insertion time for BSTree --> " << LLRBinsertT << " seconds" << std::endl;
   std::cout << "Search time for BSTree --> " << LLRBsearchT << " seconds" << std::endl;
   std::cout << "Inorder time for BSTree --> " << LLRBinorderT << " seconds" << std::endl;
   std::cout << "Preorder time for BSTree --> " << LLRBpreorderT << " seconds" << std::endl;
   std::cout << "Postorder time for BSTree --> " << LLRBpostorderT  << " seconds" << std::endl;

   std::cout << std::endl;


    return 0;
}

    
