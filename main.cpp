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

    std::cout << "Inserting " << random_num << " random numbers into the B-Tree..." << std::endl;
    int number;
    for(int i = 1; i <= random_num; i++){
        number = distribution(gen);
        btree.insert(number);
    }

    std::cout << "V YOUR B-TREE V" << std::endl;
    btree.traverse(0);
    std::cout << std::endl;

    ////USER INPUT SECTION
    std::string method;
    while(method != "done") {

        std::cout << "Which method do you want to use?" << std::endl;
        std::cout << std::endl;
        std::cout << "Your options are:" << std::endl;
        std::cout << "insert (Inputs an integer into the B-Tree)" << std::endl;
        std::cout << "search (searches for an integer into the B-Tree)" << std::endl;
        std::cout << "traverse (Prints out all the numbers in your current B-Tree)" << std::endl;
        std::cout << "quiz (Test your knowledge on a B-Tree topic!)" << std::endl;
        std::cout << "done (Ends the program)" << std::endl;
        std::cin >> method;

        ////USER INPUTS INSERT
        if(method == "insert"){
            int key;
            std::cout << std::endl;
            std::cout << "What integer do you want to insert into the B-Tree?" << std::endl;
            std::cin >> key;
            std::cout << "Inserted number into tree below..."<<std::endl;
            float BTinsertT = time_func_Btree(btree, "insert", key);
            float BTtraverseT = time_func_Btree(btree, "traverse", 0);
            std::cout << std::endl;
            std::cout << "Insertion time for B-Tree --> " << BTinsertT << " seconds" << std::endl;
            std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;
            std::cout << std::endl;
            std::cout << "Type continue in all lowercase to continue..." << std::endl;

            std::string con;
            while(con != "continue"){
                std::cin>>con;
                if(con == "continue"){
                    break;
                }
                else{
                    std::cout << "Try again" << std::endl;
                }

            }
        }

        ////USER INPUTS SEARCH

        else if(method == "search"){
            int key;
            std::cout<<std::endl;
            std::cout << "What integer do you want to search for in the B-Tree?" << std::endl;
            std::cin>>key;
            float BTsearchT = time_func_Btree(btree, "search", key);
            std::cout<<std::endl;
            std::cout << "Search time for B-Tree --> " << BTsearchT << " seconds" << std::endl;

            std::cout << "Type continue in all lowercase to continue..." << std::endl;
            std::string con;
            while(con != "continue"){
                std::cin>>con;
                if(con == "continue"){
                    break;
                }
                else{
                    std::cout << "Try again" << std::endl;
                }
            }
        }

        ////USER INPUTS TRAVERSE
        else if(method == "traverse"){
            float BTtraverseT = time_func_Btree(btree, "traverse", 0);
            std::cout << std::endl;
            std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;

            std::cout << "Type continue in all lowercase to continue..." << std::endl;
            std::string con;
            while(con != "continue"){
                std::cin>>con;
                if(con == "continue"){
                    break;
                }
                else{
                    std::cout << "Try again" << std::endl;
                }
            }
        }

        ////USER INPUTS QUIZ
        else if(method == "quiz"){
            // Mersenne Twister random number engine
            std::mt19937 gen(rd());
            // Define the range for random numbers (1 to userAmount)
            std::uniform_int_distribution<int> distribution(1, 4);

            int random_q = distribution(gen);

            std::cout<<std::endl;

            std::string answer = "";
            std::cout<<"QUESTION:"<<std::endl;
            if(random_q == 1){
                std::cout<<"What is the time complexity for insert method?"<<std::endl;
                std::cout<<"A. O(log(N)) | B. O(N) | C. O(1) | D. None of the Above"<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Please input answer as a capital letter."<<std::endl;
                //User inputs answer here

                //Makes user repeats until they get the right answer.
                while(answer != "A"){
                    std::cin>>answer;
                    if(answer == "A"){
                        std::cout<<std::endl;
                        std::cout<<"Correct! Since trees typically split in half, insert methods don't need to traverse the entire tree! Therefore, the time complexity is O(log(n))"<<std::endl;
                        std::cout<<std::endl;
                        break;
                    }
                    else{
                        std::cout << "Try again" << std::endl;
                    }
                }
            }
            if(random_q == 2){
                std::cout<<"What is the time complexity for search method?"<<std::endl;
                std::cout<<"A. O(log(N)) | B. O(N) | C. O(1) | D. None of the Above"<<std::endl;

                std::cout<<"Please input answer as a capital letter."<<std::endl;
                //User inputs answer here

                //Makes user repeats until they get the right answer.
                while(answer != "A"){
                    std::cin>>answer;
                    if(answer == "A"){
                        std::cout<<std::endl;
                        std::cout<<"Correct! Since trees typically split in half, search methods don't need to traverse the entire tree! Therefore, the time complexity is O(log(n))"<<std::endl;
                        std::cout<<std::endl;
                        break;
                    }
                    else{
                        std::cout << "Try again" << std::endl;
                    }
                }
            }
            if(random_q == 3){
                std::cout<<"Which real world scenario/application would you think is the most similar to a B-Tree?"<<std::endl;
                std::cout<<std::endl;
                std::cout<<"Options: "<<std::endl;
                std::cout<<"A. Waiting in line at the bank"<<std::endl;
                std::cout<<"B. A computer file system"<<std::endl;
                std::cout<<"C. NFL Playoff bracket"<<std::endl;
                std::cout<<"D. A google search"<<std::endl;
                std::cout<<std::endl;


                std::cout<<"Please input answer as a capital letter."<<std::endl;
                //User inputs answer here

                //Makes user repeats until they get the right answer.
                while(answer != "B"){
                    std::cin>>answer;
                    if(answer == "B"){
                        std::cout<<std::endl;
                        std::cout<<"Correct! Putting a file inside of another file in your filing system is a perfect example of B-Tree functionality!"<<std::endl;
                        std::cout<<std::endl;
                        break;
                    }
                    else{
                        std::cout << "Try again" << std::endl;
                    }
                }
            }
            if(random_q == 4){
                std::cout<<"Why should we use a B-Tree?"<<std::endl;
                std::cout<<std::endl;
                std::cout<<"Options:"<<std::endl;
                std::cout<<"A. You are able to store multiple instances of data in one node"<<std::endl;
                std::cout<<"B. The height of the tree is shorter, making some methods slightly more efficient than other trees"<<std::endl;
                std::cout<<"C. The tree is self balancing"<<std::endl;
                std::cout<<"D. All of the above"<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Please input answer as a capital letter."<<std::endl;
                //User inputs answer here

                //Makes user repeats until they get the right answer.
                while(answer != "B"){
                    std::cin>>answer;
                    if(answer == "B"){
                        std::cout<<std::endl;
                        std::cout<<"Correct! These are all main reasons as to why people should use a B-Tree!"<<std::endl;
                        std::cout<<std::endl;
                        break;
                    }
                    else{
                        std::cout << "Try again" << std::endl;
                    }
                }

            }


            std::string con;
            std::cout << "Type continue in all lowercase to continue..." << std::endl;
            while(con != "continue"){
                std::cin>>con;
                if(con == "continue"){
                    break;
                }
                else{
                    std::cout << "Try again" << std::endl;
                }
            }


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

