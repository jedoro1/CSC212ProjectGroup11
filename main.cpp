int main(int argc, char* argv[]) {
    //This variable controls whether you use integers or strings (0 or 1 respectively).
    int mode;

    //input txt file with words
    std::string fname = argv[1];

    //Creating btree
    Btree btree(3);

    //This block of code takes in the mode with error handling
    std::cout<<"Are you using integers or strings? (enter 0 for integers, 1 for strings)" << std::endl;
    while (!(std::cin >> mode)) {
        std::cout << "Please input either 0 or 1." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Seed for the random number generator
    std::random_device rd;

    //Integer b-tree is selected
    if (mode == 0) {
        int random_num = 0;
        std::cout << "Please choose the amount of random numbers to insert into B-Tree" << std::endl;
        std::cin >> random_num;

        //Code from <random> library to get random numbers from 1 to whatever the user inputs

        // Mersenne Twister random number engine
        std::mt19937 gen(rd());
        // Define the range for random numbers (1 to userAmount)
        std::uniform_int_distribution<int> distribution(1, random_num);

        //For loop that inserts random numbers into our B-tree
        std::cout << "Inserting " << random_num << " random numbers into the B-Tree..." << std::endl;
        int number;
        for (int i = 1; i <= random_num; i++) {
            number = distribution(gen);
            btree.insert(number);
        }
    }

    //Words are selected (mode 1);
    else if(mode == 1){

        //Reading from a file and inserting into b-tree
        std::cout<<fname<<std::endl;
        std::ifstream inputF(fname);

        std::string line;

        std::getline(inputF, line);
        std::stringstream ss(line);

        std::string s;

        //While loop that takes every word and uses
        while(ss >> s){
            btree.insert(s);
        }

        inputF.close();
    }

    //Showing your current B-Tree
    std::cout << "V YOUR B-TREE V" << std::endl;
    if(mode == 0){
        btree.traverse(0);
    }
    if(mode == 1){
        std::string s;
        btree.traverse(s);
    }
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
        std::cout << "traverse (Prints out all the numbers in your current B-Tree in order)" << std::endl;
        std::cout << "show (Creates a dot file visualization of your B-Tree)" << std::endl;
        std::cout << "quiz (Test your knowledge on a B-Tree topic!)" << std::endl;
        std::cout << "done (Ends the program)" << std::endl;

        //User chooses a method
        std::cin >> method;

        ////USER INPUTS INSERT
        if(method == "insert"){
            int key;
            std::string s_key;

            std::cout << std::endl;

            //User chooses the key they want to insert with error handling
            if(mode == 0) {
                std::cout << "What integer do you want to insert into the B-Tree?" << std::endl;
                while (!(std::cin >> key)) {
                    std::cout << "Please input a valid integer." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Inserted number into tree below..."<<std::endl;
            }
            if(mode == 1) {
                std::cout << "What string do you want to insert into the B-Tree?" << std::endl;
                while (!(std::cin >> s_key)) {
                    std::cout << "Please input a valid string." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Inserted string into tree below..."<<std::endl;
            }

            //These lines calls insert and traverse while recording the time it takes to do each method

            if(mode == 0) {
                float BTinsertT = time_func_Btree(btree, "insert", key);
                float BTtraverseT = time_func_Btree(btree, "traverse", 0);

                std::cout << std::endl;

                //These lines print out the times for each method
                std::cout << "Insertion time for B-Tree --> " << BTinsertT << " seconds" << std::endl;
                std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;
            }

            if(mode == 1) {
                float BTinsertT = time_func_Btree(btree, "insert", s_key);
                float BTtraverseT = time_func_Btree(btree, "traverse", s_key);

                std::cout << std::endl;

                //These lines print out the times for each method
                std::cout << "Insertion time for B-Tree --> " << BTinsertT << " seconds" << std::endl;
                std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;
            }

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
            std::string s_key;
            std::cout<<std::endl;

            //String search
            if(mode == 0){
                std::cout << "What integer do you want to search for in the B-Tree?" << std::endl;

                //User inputs key with error handling
                while (!(std::cin >> key)) {
                    std::cout << "Please input a valid integer." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                //This line calls the search method while recording the time
                float BTsearchT = time_func_Btree(btree, "search", key);

                //This line prints out the search time
                std::cout << "Search time for B-Tree --> " << BTsearchT << " seconds" << std::endl;

            }

            //String
            if (mode == 1){
                std::cout << "What string do you want to search for in the B-Tree?" << std::endl;

                //User inputs string with error handling
                while (!(std::cin >> s_key)) {
                    std::cout << "Please input a valid string." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                //This line calls the search method while recording the time
                float BTsearchT = time_func_Btree(btree, "search", s_key);

                //This line prints out the search time
                std::cout << "Search time for B-Tree --> " << BTsearchT << " seconds" << std::endl;
            }


            std::cout<<std::endl;

            //Stop in code
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
            if(mode == 0) {
                float BTtraverseT = time_func_Btree(btree, "traverse", 0);
                std::cout << std::endl;

                //This line prints out the traversal time
                std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;

            }
            //String
            if(mode == 1) {
                float BTtraverseT = time_func_Btree(btree, "traverse", "woohoo!");
                std::cout << std::endl;

                //This line prints out the traversal time
                std::cout << "Traverse time for B-Tree --> " << BTtraverseT << " seconds" << std::endl;

            }

            //Stop in code
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
        //4 randomly chosen questions to ask the user with 4 multiple choice options
        else if(method == "quiz"){
            // Mersenne Twister random number engine
            std::mt19937 gen(rd());
            // Define the range for random numbers (1 to userAmount)
            std::uniform_int_distribution<int> distribution(1, 4);

            //This picks the random question
            int random_q = distribution(gen);

            std::cout<<std::endl;

            //Variable to hold the user's answer
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

            //Stop in code
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
        ////USER INPUTS SHOW
        else if(method == "show"){
            std::cout<<std::endl;
            //Method call for writing the dot file.
            if(mode == 0) {
                btree.writeDotFile("dot.txt", mode);
            }
            if(mode == 1) {
                btree.writeDotFile("dot_string.txt", mode);
            }

            std::cout << "A file for your visualization of your B-Tree has been made."<<std::endl;
            std::cout << std::endl;
        }
        ////USER INPUTS DONE
        //User inputs done and ends the program
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
