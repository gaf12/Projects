/**------------------------------------------
  Program 1: Layered Pine Tree
  Prompt for the number of tree layers and display
  ASCII layered pine tree
  Course: CS 141, Fall 2022.
  System: MacOS and G++
  Author: Dr. Sara Riazi
---------------------------------------------**/
#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.
using namespace std; // so that we don't need to preface every cin and cout with std::
int main() {
    // Display the menu and get the user choice
    int menu_option = 0;
    cout << "Program 1: The Pine Tree            \n"
         << "Choose from the following options:  \n"
         << "   1. Display the HELLO graphic  \n"
         << "   2. Display The Pine Tree        \n"
         << "   3. Exit the program          \n"
         << "Your choice -> ";
    cin >> menu_option;
    if (menu_option == 3) { // Handle menu option of 3 to exit
        exit(0); // The call to exit the code successfully (0 means the runs didn't encounter any problem).
    }
    else if (menu_option == 1) { // Handle menu option of 1 to display custom ASCII graphics
        // Display ASCII graphics for "HELLO".
        // The main purpose of this part is to give you hints about usnig setw and setfill and their behaviors.
        //the character for the frame of our display.
        char frame = '-';
        cout << "Enter your frame character: ";
        cin >> frame;
        cout << endl;
        // The goal of next three lines is to print a line with 77 dashes differently.
        cout << setfill(frame); //change the default character for filling the fields defined using setw. You can change it fill to different characte to see the difference.
        cout << setw(78) << "\n"; // \n counts in 78 so you will get 77 dashes plus one \n
        cout << setw(78) << endl; ///after setfill you need to pass a string or character to push setfil to fill the field, otherwise you will see an empty line for this instruction. See the differnce in output from this line and the above line.
        cout << setw(77) << frame << endl; //I use 77 with setfill and one extra at the end to get the same result
        cout << setw(8) << " " << "   **    **    ********    **         **         ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    **         **         ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    **          **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   ********    ********    **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   ********    ********    **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    **          **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    ********   ********   ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    ********   ********   ********    " << setw(9) << "\n";
        cout << setw(77) << frame << endl; //the extra character is - so in total we will
        cout << setw(77) << frame << endl; //the extra character is - so in total we will have 77 dashes.
        cout << setw(78) << "\n"; //again, the extra character is \n so you have set the width to 78
        //you can do it this way using a for-loop too
         for (int i = 0; i < 77; i++) {
            cout << frame;
        }
        cout << endl;
    }
    else if (menu_option == 2) {
        // Prompt for and get the number of layers for the tree.
        int number_of_tree_layers = 0;
        cout << "Number of tree layers -> ";
        cin >> number_of_tree_layers;
        cout << endl; //do not remove this line. It is essential for the autograder!
        
   {
        int row2;

        // The code from line 66 is the main for loops which takes input from a user and controls the number of layers to be printed.
        for(int numOfLayers = 1; numOfLayers <= number_of_tree_layers; numOfLayers++)
            {
                // The code on line 69 is for out putting spaces before the first line of every tree layer. And the for loop is to print out the number of "*" in the first line of every layer.
                cout << setfill(' ') << setw(number_of_tree_layers + 2 - numOfLayers) << "";
                for (int row1 = 1; row1 <= numOfLayers * 2 - 1; row1++)
                {
                    cout << "*";
                }
                cout << endl;

                // The code on line 76 is for out putting soaces before the second line of every tree layer. And the for loop from line 78 to 82 is to print out the number of "*" in the second line of every layer.
                cout << setfill(' ') << setw(number_of_tree_layers + 2 - numOfLayers - 1) << "";
                row2 = numOfLayers * 2 - 1;
                for (int secondLine = 1; secondLine <= row2 + 2 ; secondLine++)
                {
                    cout << "*";
                }
                cout << endl;

                // The code on line 85 is for out putting spaces before the third line of every tree layer. And the for loop from line "87 to 91" is to print out the number of "*" in the third line of every layer.
                cout << setfill(' ') << setw(number_of_tree_layers + 2 - numOfLayers - 2) << "";
                int row3 = row2 + 2;
                for (int thirdLine = 1; thirdLine <= row3 + 2; thirdLine++)
                {
                    cout << "*";
                }
                cout << endl;
            }

        // This for loop is to create the height of the trunk as well as the spacing.
        for (int trunkHeight = 1; trunkHeight <= number_of_tree_layers * 2; trunkHeight++)
            {
                cout << setfill(' ') << setw(number_of_tree_layers) << "";
                cout << "|||" << endl;
            }

        }

    } //end if( menu_option == 2)
    cout << endl; //DO NOT CHANGE THIS LINE
    return 0;
}
    
