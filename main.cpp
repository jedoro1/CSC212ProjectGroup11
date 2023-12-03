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

    //For loop that inserts random numbers into our B-tree
    std::cout << "Inserting " << random_num << " random numbers into the B-Tree..." << std::endl;
    int number;
    for(int i = 1; i <= random_num; i++){
        number = distribution(gen);
        btree.insert(number);
    }

    //Showing your current B-Tree
    std::cout << "V YOUR B-TREE V" << std::endl;
    btree.traverse(0);
    std::cout << std::endl;

    ////USER INPUT SECTION

    std::string method;

    //Program continuously runs until user types "done"
    while(method != "done") {

        //Start up menu that showcases all the options for the user
        std::cout << "Which method do you want to use?" << std::endl;
        std::cout << std::endl;
        std::cout << "Your options are:" << std::endl;
        std::cout << "insert (Inputs an integer into the B-Tree)" << std::endl;
        std::cout << "search (searches for an integer into the B-Tree)" << std::endl;
        std::cout << "traverse (Prints out all the numbers in your current B-Tree)" << std::endl;
        std::cout << "quiz (Test your knowledge on a B-Tree topic!)" << std::endl;
        std::cout << "done (Ends the program)" << std::endl;

        //User chooses a method
        std::cin >> method;

        ////USER INPUTS INSERT
        if(method == "insert"){
            int key;
            std::cout << std::endl;
            std::cout << "What integer do you want to insert into the B-Tree?" << std::endl;

            //User chooses the key they want to insert with error handling
            while (!(std::cin >> key)) {
                std::cout << "Please input a valid integer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cout << "Inserted number into tree below..."<<std::endl;

            //These two lines calls insert and traverse while recording the time it takes to do each method
            float BTinsertT = time_func_Btree(btree, "insert", key);
            float BTtraverseT = time_func_Btree(btree, "traverse", 0);

            std::cout << std::endl;

            //These lines print out the times for each method
            std::cout << "Insertion time for B-Tree --> " << BTinsertT << " seconds" << std::endl;
            std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;

            std::cout << std::endl;

            std::cout << "Type continue in all lowercase to continue..." << std::endl;

            //This while loop is just so the code doesn't print everything out at once, I want it to look smooth.
            //This is repeated throughout every method
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

            //User inputs key they want to search for with error handling
            while (!(std::cin >> key)) {
                std::cout << "Please input a valid integer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            //This line calls the search method while recording the time 
            float BTsearchT = time_func_Btree(btree, "search", key);
            
            std::cout<<std::endl;
            
            //This line prints out the search time
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
            //This line calls the traverse method and records the time it takes to traverse the whole tree.
            float BTtraverseT = time_func_Btree(btree, "traverse", 0);
            
            std::cout << std::endl;
            
            //This line prints out the traversal time
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

            //This picks the random question
            int random_q = distribution(gen);

            std::cout<<std::endl;

            std::string answer = "";
            std::cout<<"QUESTION:"<<std::endl;
            
            //First question was randomly chosen
            if(random_q == 1){
                std::cout<<"What is the time complexity for insert method?"<<std::endl;
                std::cout<<"A. O(log(N)) | B. O(N) | C. O(1) | D. None of the Above"<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Please input answer as a capital letter."<<std::endl;
                

                //Makes user repeats until they get the right answer.
                while(answer != "A"){
                    //User inputs answer here
                    std::cin>>answer;
                    
                    //Answer is correct, breaks loop
                    if(answer == "A"){
                        std::cout<<std::endl;
                        std::cout<<"Correct! Since trees typically split in half, insert methods don't need to traverse the entire tree! Therefore, the time complexity is O(log(n))"<<std::endl;
                        std::cout<<std::endl;
                        break;
                    }
                    else{
                        //Incorrect choice, resets loop
                        std::cout << "Incorrect. Try again" << std::endl;
                    }
                }
            }
            
            //Second question is randomly chosen
            if(random_q == 2){
                std::cout<<"What is the time complexity for search method?"<<std::endl;
                std::cout<<"A. O(log(N)) | B. O(N) | C. O(1) | D. None of the Above"<<std::endl;

                std::cout<<"Please input answer as a capital letter."<<std::endl;

                //Makes user repeats until they get the right answer.
                while(answer != "A"){
                    //User inputs answer here
                    std::cin>>answer;
                    
                    //Answer is correct, breaks loop
                    if(answer == "A"){
                        std::cout<<std::endl;
                        std::cout<<"Correct! Since trees typically split in half, search methods don't need to traverse the entire tree! Therefore, the time complexity is O(log(n))"<<std::endl;
                        std::cout<<std::endl;
                        break;
                    }
                    //Answer is incorrect, resets loop
                    else{
                        std::cout << "Try again" << std::endl;
                    }
                }
            }
            
            //Third question is randomly chosen
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

                //Makes user repeats until they get the right answer.
                while(answer != "B"){
                    //User inputs answer here
                    std::cin>>answer;
                    
                    //Answer is correct, breaks loop
                    if(answer == "B"){
                        std::cout<<std::endl;
                        std::cout<<"Correct! Putting a file inside of another file in your filing system is a perfect example of B-Tree functionality!"<<std::endl;
                        std::cout<<std::endl;
                        break;
                    }
                    
                    //Answer is incorrect, resets loop
                    else{
                        std::cout << "Try again" << std::endl;
                    }
                }
            }
            
            //Fourth question is randomly chosen
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

                //Makes user repeats until they get the right answer.
                while(answer != "D"){
                    //User inputs answer here
                    std::cin>>answer;
                    
                    //Answer is correct, break loop
                    if(answer == "D"){
                        std::cout<<std::endl;
                        std::cout<<"Correct! These are all main reasons as to why people should use a B-Tree!"<<std::endl;
                        std::cout<<std::endl;
                        break;
                    }
                    //Answer is incorrect, reset loop
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
            //Ends the program
            return 0;
        }
        
        //If the user inputs something that isn't one of the methods, ask them again with an error message.
        else{
            std::cout << "Please try again... type the method you want exactly as it's shown in the menu." << std::endl;
        }
    }
}
    
