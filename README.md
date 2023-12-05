# CSC212ProjectGroup11
B-Tree

**_How to compile the code_**

**_YOU NEED TERMINAL INPUT IN YOUR IDE TO RUN THIS PROGRAM_**

**_VSCODE AND CLION SHOULD WORK FINE IF YOU ARE RUNNING THE C++ VERSION WE'VE BEEN USING IN CLASS ALL SEMESTER, THANK YOU_**

Our program requires the user to use a txt file as a command line argument. 

The txt file needs to have spaced out words on the first line of the file to insert them into the B-Tree.

Example:

TXT FILE
______________________________________________________
1. hello bye fish cat code tree fun eat shampoo      
2.                                                   
3.                                                   
______________________________________________________

The rest of the program is inserting through terminal or inputting a file into the website that we used to visualize in lab 12 (link provided in the program).

This is the what your command line should look like:
./<"compiled file name"> <"txt file">

The txt file in the command line is the only main dependancy for this code to run. As long as you have access to terminal in your IDE and an internet connection to use the visualization website, you should be all set. The program itself is entirely user input, so the program instructs the user how to use every method.

- `Insert` - Requires a key (Integer or string) 
- `Search` - Requires a key (Integer or string) 
- `Traverse` - Technically requires a key because we used traverse in our search method to find the repeats of a specific key, but you can insert 0 here and it works perfectly fine as a traverse method 
- `WriteDotFile` - Requires an output file name and the mode we are currently in (Integers - 0, Strings - 1). 



////////////////////////////////////////////////////////////////

**_Implement the Data Structure (using classes)_**

- ensure at least `insert` & `search` methods are correct
  - `search` must also return/print the count

- generate a DOT file for visualization

**_Store the words of an input text file_**

- for the word ($node$) in the tree, a count with the number of repeats must also be stored

**Insertion**
- `insert(key, value)`: Inserts a new key-value pair into the B-tree while maintaining the B-tree properties (such as balanced nodes and  sorted keys).

**Search**
- `search(key)`: Searches for a key in the B-tree and returns the associated value, or indicates if the key is not present.

**Traversal**
- `inOrderTraversal()`: Traverses the B-tree in ascending order, visiting all nodes.


