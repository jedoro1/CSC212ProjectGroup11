#include <iostream>
#include <random>
#include "Btree.h"
#include "time_functions.h"


int main(int argc, char* argv[]) {
    Btree btree(3);

    int random_num = std::stoi(argv[1]);

    //Code from <random> library to get random numbers from 1 to whatever the user inputs
    // Seed for the random number generator
    std::random_device rd;
    // Mersenne Twister random number engine
    std::mt19937 gen(rd());
    // Define the range for random numbers (1 to userAmount)
    std::uniform_int_distribution<int> distribution(1, random_num);

    std::cout << "Inserting " << random_num <<" random numbers into the B-Tree..." << std::endl;
    int number;
    for(int i = 1; i <= random_num; i++){
        number = distribution(gen);
        btree.insert(number);
        //llrbtree.insert(randomNum);
        //bstree.insert(randomNum);

    }

    std::cout << "V YOUR B-TREE V" << std::endl;
    btree.traverse();
    std::cout << std::endl;

    ////USER INPUT SECTION
    std::string method = "";
    while(method != "done") {

        std::cout << "Which method do you want to use?" << std::endl;
        std::cout<<std::endl;
        std::cout << "Your options are:" << std::endl;
        std::cout << "insert (Inputs a number into the B-Tree)" << std::endl;
        std::cout << "search (searches for a number into the B-Tree)" << std::endl;
        std::cout << "traverse (Inputs a number into the B-Tree)" << std::endl;
        std::cout << "done (Ends the program)" << std::endl;
        std::cin >> method;

        ////USER INPUTS INSERT
        if(method == "insert"){
            int key;
            std::cout << "What number do you want to insert into the B-Tree?" << std::endl;

            std::cout << std::endl;

            std::cin>>key;
            std::cout << "Inserted number into tree below..."<<std::endl;
            float BTinsertT = time_func_Btree(btree, "insert", key);
            float BTtraverseT = time_func_Btree(btree, "traverse", 0);
            std::cout << std::endl;
            std::cout << "Insertion time for B-Tree --> " << BTinsertT << " seconds" << std::endl;
            std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;
        }

        ////USER INPUTS SEARCH
        else if(method == "search"){
            int key;
            std::cout << "What number do you want to search for in the B-Tree?" << std::endl;
            std::cin>>key;
            float BTsearchT = time_func_Btree(btree, "search", key);
            std::cout<<std::endl;
            std::cout << "Search time for B-Tree --> " << BTsearchT << " seconds" << std::endl;
        }

        ////USER INPUTS TRAVERSE
        else if(method == "traverse"){
            float BTtraverseT = time_func_Btree(btree, "traverse", 0);
            std::cout << std::endl;
            std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;

        }

        ////USER INPUTS DONE
        else if(method == "done"){
            std::cout << "Thanks for using our program to learn more about B-Trees!" << std::endl;
            return 0;
        }
        else{
            std::cout << "Please try again... type the method you want exactly as it's shown in the menu." << std::endl;
        }
    }


    return 0;
}

    
