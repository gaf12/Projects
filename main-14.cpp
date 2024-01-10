/****************************
 * HEADER
 *  Yahtzee
 * Starter code provided by: Dr. Sara Riazi
 * Student Author : Abdul Gaffir Zambi
 * ***************************/


#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;



//#################################################################################################


class Dice{
private:
    int value;
    // this bool value checks if a dice is kept or not..
    bool keep;

public:
    // if a dice is kept keepSel is set to true..
    void keepSel(){
        keep = true;
    }
    // if a dice is not kept unkeepsel is set to false..
    void unKeepSel(){
        keep = false;
    }
    // this reti
    bool getKeep(){
        return keep;
    }
    
  
//Randomly assigns a value between from 1 to 6 to the dice.
void roll(){
          // this creates a random number foor the dice..
          value = rand() % 6 + 1;
       }
   
    int reveal() {return value;}
     
    //The autograder will set the values directly instead of calling roll() to avoid randomness!
    void setValue(int value) {this->value = value;}

};


//#################################################################################################

const int HAND_SIZE = 5;

class Hand {
    public:

        //Display the value of the five dice
        void show();
        void play();
    Dice* getDice(int diceNum){
        // getDice returns the value of the dice at the position of dicenum..
        return &arrayDice[diceNum];
        
    }
        
        //selection is the string of dice numbers that the player wants to keep.
        //For example, "125" means that player wants to keep the first, second, and fifth dice, and roll the rest.
        void setSelection(string selection){
           // int arrayDice2[selection.size()];
            for(int i = 0; i < selection.size();i++){
                // selection is converted to int..
                temp = selection[i] - '0' - 1;
                // the code below checks if the dice has to be kept or not..
                if(temp < HAND_SIZE){
                    arrayDice[temp].keepSel();
                }
            }
           
        }
        //  go through thhe array of dice and send true or false if selected.. not play again..
    Hand(){
        for (int i = 0; i < 5; i++){
                arrayDice[i].roll();
        }
    }
    
    private:
    int temp;
    // declaring a dice array of type Dice..
    Dice arrayDice[HAND_SIZE];
};

void Hand::play(){
    // this code checks if a hand is kept or not.. if its not kept its rolled..
    for (int i = 0 ; i < 5; i++){
        for (int i = 0; i < HAND_SIZE; i++){
            // if getkeep is false the dice roll..
            if(arrayDice[i].getKeep() == false){
                arrayDice[i].roll();
            }
        }
        }
}

void Hand::show(){
    // printing out the dice array..
    cout << "Hand: ";
  for (int i = 0; i < 5; i++){
      cout << arrayDice[i].reveal() << " ";
  }
    cout << endl;
}


//######################################################################


const int ONES = 0;
const int TWOS = 1;
const int THREES = 2;
const int FOURS = 3;
const int FIVES = 4;
const int SIXES = 5;
const int THREE_OF_KIND = 6;
const int FOUR_OF_KIND = 7;
const int FULL_HOUSE = 8;
const int SMALL_STRAIGHT = 9;
const int LARGE_STRAIGHT = 10;
const int CHANCE = 11;
const int YAHTZEE = 12;

const int BOARD_SIZE = 13;

class Game {

    public:
        //calcScore returns a score of a hand (5 dice) for given row in the board.
        //Note the rows are indexed from zero.
        //For example if the hand is 2 1 1 5 1 then calcScore(hand, ONES) returns 3 and  calcScore(hand, TWOS) returns 2.
    int calcScore(Hand* hand, int row);
        
        
        //Display the board
        void show();
        

        //Returns the score of the upper part of the board
    int getUpperScore(){
        return this->upperScore;
    }
        
        //Returns the score of the lower part of the board
    int getLowerScore(){
        return this->lowerScore;
    }
    

        //Returns the bonus points
        int getBonusScore(){
            int bonusScore = 0;
            // checks if the upper part of the board is above 63..
            // bonusScore is then set to 35..
            if(upperScore >= 63){
                bonusScore = 35;
            }
        // bonusScore is then return..
         return bonusScore;
        }

        //Returns the total score
        int getTotalScore(){
            return totalScore;
        }

        //Play a hand based on the selected row
        void play(Hand* hand, int row){
            // return the calcScore..
            calcScore(hand, row);
        }
        
        string checkingBoard(int c);
        
        //Check to see if a row has been played or not (returns true if a row has been played)
        bool isPlayed(int row){
            // checks to see if a given row is  -1 then it means the row hasnt been played
            // therefore true is returned.. same from row 1 to 13...
            if (row == 1){
                if(numb1 == -1){
                    return true;
                }
            }
            if (row == 2){
                if(numb2 == -1){
                    return true;
                }
            }
            if (row == 3){
                if(numb3 == -1){
                    return true;
                }
            }
            if (row == 4){
                if(numb4 == -1){
                    return true;
                }
            }
            if (row == 5){
                if(numb5 == -1){
                    return true;
                }
            }
            if (row == 6){
                if(numb6 == -1){
                    return true;
                }
            }
            if (row == 7){
                if(numb7 == -1){
                    return true;
                }
            }
            if (row == 8){
                if(numb8 == -1){
                    return true;
                }
            }
            if (row == 9){
                if(numb9 == -1){
                    return true;
                }
            }
            if (row == 10){
                if(numb10 == -1){
                    return true;
                }
            }
            if (row == 11){
                if(numb11 == -1){
                    return true;
                }
            }
            if (row == 12){
                if(numb1 == -1){
                    return true;
                }
            }
            if (row == 1){
                if(numb12 == -1){
                    return true;
                }
            }
            if (row == 13){
                if(numb13 == -1){
                    return true;
                }
            }
         return false;
        }

        //Check to see if all rows haven been played or not (returns true if all rows have been played)
        bool isFinished(){
            // this goes through all the scores on the board and checks if it has been played or not.. if all has been played
            // the isFinished return false....
            if (numb1 != -1 && numb2 != -1 && numb3 != -1 && numb4 != -1 && numb5 != -1 && numb6 != -1
                && numb7 != -1 && numb8 != -1 && numb9 != -1 && numb10 != -1 && numb11 != -1 && numb12 != -1 && numb13 != -1){
                return true;
            }
            return false;
        }

private:
    int score = 0;
    int upperScore = 0;
    int lowerScore = 0;
    int sum = 0;
    int numb1 = -1;
    int numb2 = -1;
    int numb3 = -1;
    int numb4 = -1;
    int numb5 = -1;
    int numb6 = -1;
    int numb7 = -1;
    int numb8 = -1;
    int numb9 = -1;
    int numb10 = -1;
    int numb11 = -1;
    int numb12 = -1;
    int numb13 = -1;
    int totalScore = 0;
 };

int Game::calcScore(Hand *hand, int row)
{
    int count = 0;
    // if the row enter is ONES.. 1 is added to it to make it one.. and then 1 is searched for in the dice array..
    // if one is found the number of ones is then added to gether and reutnr to numb1.....
    if ((row + 1 == 1) && (numb1 == -1)){
        numb1 = 0;
        for (int i = 0; i < HAND_SIZE;i++){
            if (hand->getDice(i)->reveal() == (row + 1)){
                numb1 = numb1 + row + 1;
                count++;
            }
            
        }
        upperScore += numb1;
        return  numb1;
    }
    
    // if the row enter is TWOS.. 1 is added to it to make it TWO.. and then 2 is searched for in the dice array..
    // if one is found the number of two is then added to gether and return to numb2.....
    if ((row  + 1) == 2 && (numb2 == -1)){
        numb2 = 0;
        for (int i = 0; i < HAND_SIZE;i++){
            if (hand->getDice(i)->reveal() == row + 1){
                numb2 = numb2 + row + 1;
            }
        }
        upperScore += numb2;
        return  numb2;
        
    }
    
    // if the row enter is 0.. 1 is added to it to make it one.. and then 1 is searched for in the dice array..
    // if one is found the number of ones is then added to gether and reutnr to numb1.....
    if ((row +1) == 3 && (numb3 == -1)){
        numb3 = 0;
        for (int i = 0; i < HAND_SIZE;i++){
            if (hand->getDice(i)->reveal() == row + 1){
                numb3 = numb3 + row + 1;
            }
        }
        upperScore += numb3;
        return  numb3;
        
    }
    
    // if the row enter is 0.. 1 is added to it to make it one.. and then 1 is searched for in the dice array..
    // if one is found the number of ones is then added to gether and reutnr to numb1.....
    if (row + 1 == 4 && (numb4 == -1)){
        numb4 = 0;
        for (int i = 0; i < HAND_SIZE;i++){
            if (hand->getDice(i)->reveal() == row + 1){
                numb4 = numb4 + row + 1;
            }
        }
        upperScore += numb4;
        return  numb4;
        
    }
    
    // if the row enter is 0.. 1 is added to it to make it one.. and then 1 is searched for in the dice array..
    // if one is found the number of ones is then added to gether and reutnr to numb1.....
    if (row + 1 == 5 && (numb5 == -1)){
        numb5 = 0;
        for (int i = 0; i < HAND_SIZE;i++){
            if (hand->getDice(i)->reveal() == row + 1){
                numb5 = numb5 + row + 1;
            }
        }
        upperScore += numb5;
        return  numb5;
    }
    
    // if the row enter is 0.. 1 is added to it to make it one.. and then 1 is searched for in the dice array..
    // if one is found the number of ones is then added to gether and reutnr to numb1.....
    if (row + 1 == 6 && (numb6 == -1)){
        numb6 = 0;
        for (int i = 0; i < HAND_SIZE;i++){
            if (hand->getDice(i)->reveal() == row + 1){
                numb6 = numb6 + row + 1;
            }
        }
        upperScore += numb6;
        return  numb6;
        
    }
    
    
    int store[6] = {0,0,0,0,0,0};
    
    for (int i = 0; i < HAND_SIZE;i++){
        
        if (hand->getDice(i)->reveal() == 1){
            store[0]++;
        }
        
       else if (hand->getDice(i)->reveal() == 2){
            store[1]++;
        }
       else if (hand->getDice(i)->reveal() == 3){
            store[2]++;
         }
        else if (hand->getDice(i)->reveal() == 4){
            store[3]++;
        }
       else if (hand->getDice(i)->reveal() == 5){
            store[4]++;
        }
       else if (hand->getDice(i)->reveal() == 6){
            store[5]++;
        }
    }
    
    int safeDice[5];
    
    int lengthOfarray = sizeof(store)/sizeof(store[0]);

    
    
    for (int i = 0; i < 5; i++){
        safeDice[i] = hand->getDice(i)->reveal();
    }
    
    
    sort(safeDice, safeDice+5);
    
    if (row + 1 == 7){
        numb7 = 0;
       
        if(safeDice[0] == safeDice[1]){
            if(safeDice[1] == safeDice[2]){
                numb7 += safeDice[0] + safeDice[1] + safeDice[2] + safeDice[3] + safeDice[4];
            }
            else if(safeDice[2] == safeDice[3]){
                if(safeDice[3] == safeDice[4]){
                    numb7 += safeDice[0] + safeDice[1] + safeDice[2] + safeDice[3] + safeDice[4];
                }
            }
            else
                numb7 = 0;
        }
        else if(safeDice[1] == safeDice[2] && safeDice[2] == safeDice[3]){
            {
                numb7 += safeDice[0] + safeDice[1] + safeDice[2] + safeDice[3] + safeDice[4];
            }
        }
        else if(safeDice[2] == safeDice[3]){
            if(safeDice[3] == safeDice[4]){
                numb7 += safeDice[0] + safeDice[1] + safeDice[2] + safeDice[3] + safeDice[4];
            }
        }
        return numb7;
    }
    if (row + 1 == 8){
        numb8 = 0;
        if(safeDice[0] == safeDice[1]){
            if(safeDice[1] == safeDice[2]){
                if(safeDice[2] == safeDice[3]){
                    if(safeDice[3] == safeDice[4]){
                        numb8 += safeDice[0] + safeDice[1] + safeDice[2] + safeDice[3] + safeDice[4];
                    }
                    else
                        numb8 += safeDice[0] + safeDice[1] + safeDice[2] + safeDice[3] + safeDice[4];
                }
            }
        }
        return  numb8;
    }
    
    
    if (row + 1 == 9){
        numb9 = 0;
        if(safeDice[0] == safeDice[1]){
            if(safeDice[1] == safeDice[2]){
                if(safeDice[3] == safeDice[4])
                    numb9 = 25;
                else
                    numb9 = 0;
            }
            else if(safeDice[2] == safeDice[3] && safeDice[3] == safeDice[4])
                numb9 = 25;
        }
        return numb9;
    }
    
    if (row + 1 == 10){
        numb10 = 0;
        if(store[0] >= 1){
            if(store[1] >= 1 && store[2] >= 1 && store[3] >= 1)
                numb10 = 30;
        }
        if(store[1] >= 1){
            if(store[2] >= 1 && store[3] >= 1 && store[4] >= 1)
                numb10 = 30;
        }
        if(store[2] >= 1){
            if(store[3] >= 1 && store[4] >= 1 && store[5] >= 1)
                numb10 = 30;
        }
        return numb10;
        
    }
    
    
    if (row + 1 == 11){
        numb11 = 0;
        
        if(store[0] == 1){
            if(store[1] == 1 && store[2] == 1 && store[3] == 1 && store[4] == 1)
                numb11 = 40;
        }
        if(store[1] == 1){
            if(store[2] == 1 && store[3] == 1 && store[4] == 1 && store[5] == 1)
                numb11 = 40;
        }
       
        return numb11;
    }
    
    if (row + 1  == 12){
        numb12 = 0;

        for (int i = 0; i < HAND_SIZE; i++){
            numb12 += hand->getDice(i)->reveal();
        }
        return numb12;
    }
    
    if (row + 1 == 13){
        numb13 = 0;
        
        if (hand->getDice(0)->reveal() == hand->getDice(1)->reveal() && hand->getDice(1)->reveal() == hand->getDice(2)->reveal() && hand->getDice(2)->reveal() ==  hand->getDice(3)->reveal() &&
            hand->getDice(3)->reveal() == hand->getDice(4)->reveal()){
            numb13 = 50;
        }
        
        return  numb13;
    }
    return 0;
}

int c1 = ONES;
int c2 = TWOS;
int c3 = THREES;
int c4 = FOURS;
int c5 = FIVES;
int c6 = SIXES;
int c7 = THREE_OF_KIND;
int c8 = FOUR_OF_KIND;
int c9 = FULL_HOUSE;
int c10 = SMALL_STRAIGHT;
int c11 = LARGE_STRAIGHT;
int c12 = CHANCE;
int c13 = YAHTZEE;

string Game::checkingBoard(int c){
    // building my board...
    // if the board is at -1 the tag is printed out..
    // else if it changes to any number the number is printed out..
    string tag;
    switch (c) {
    case ONES:
        if (numb1 == -1)
            tag = "-";
        else{
            cout << numb1;
         }
        break;

    case TWOS:
        if (numb2 == -1)
            tag = "-";
        else{
            cout << numb2;
         }
        break;

    case THREES:
        if (numb3 == -1)
            tag = "-";
        else{
            cout << numb3;
         }
        break;
        
       
    case FOURS:
        if (numb4 == -1)
            tag = "-";
        else{
            cout << numb4;
         }
        break;
        
    case FIVES:
        if (numb5 == -1)
            tag = "-";
        else{
            cout << numb5;
         }
        break;
            
    case SIXES:
        if (numb6 == -1)
            tag = "-";
        else{

            cout << numb6;
         }
        break;
        
    case THREE_OF_KIND:
        if (numb7 == -1)
            tag = "-";
        else{
            cout << numb7;
         }
        break;
            
    case FOUR_OF_KIND:
        if (numb8 == -1)
            tag = "-";
        else{
            cout << numb8;
         }
        break;
            
    case FULL_HOUSE:
        if (numb9 == -1)
            tag = "-";
        else{
            cout << numb9;
         }
        break;
        
    case SMALL_STRAIGHT:
        if (numb10 == -1)
            tag = "-";
        else{
            cout << numb10;
         }
        break;
        
    case LARGE_STRAIGHT:
        if (numb11 == -1)
            tag = "-";
        else{
            cout << numb11;
         }
        break;
    case CHANCE:
        if (numb12 == -1)
            tag = "-";
        else{
            cout << numb12;
         }
            break;
    case YAHTZEE:
        if (numb13 == -1)
            tag = "-";
        else{
            cout << numb13;
         }
        break;
    
        
        default:
            break;
    }
    
    return  tag;
}

 void Game::show(){
     cout << "1. Ones:                   "  << checkingBoard(c1) << endl;
     cout << "2. Twos:                   "  << checkingBoard(c2) << endl;
     cout << "3. Threes:                 " << checkingBoard(c3) << endl;
     cout << "4. Fours:                  "  <<checkingBoard(c4) << endl;
     cout << "5. Fives:                  "  << checkingBoard(c5) << endl;;
     cout << "6. Sixes:                  "  << checkingBoard(c6) << endl;
     cout << "   Sum                     " << upperScore << endl;
     cout << "   Bonus                   " <<  getBonusScore() << endl;
     cout << "7. Three of a kind:        " << checkingBoard(c7) << endl;
     cout << "8. Four of a kind:         " << checkingBoard(c8) << endl;
     cout << "9. Full house              " << checkingBoard(c9) << endl;
     cout << "10.Small straight:         " << checkingBoard(c10) << endl;
     cout << "11.Large straight:         " << checkingBoard(c11) << endl;
     cout << "12.Chance:                 " << checkingBoard(c12) << endl;
     cout << "13.Yahtzee:                " << checkingBoard(c13) << endl;
     cout << "Total:                     " << upperScore + lowerScore << endl;
 }


//#######################################################################################

//The run function is the main loop of your program
void run() {
    Game game1;
    
    while(!game1.isFinished()){
        string choice;
        game1.show();
        Hand hand1;
        hand1.show();
        Hand *hand = &hand1;
        int row = 0;
        int counter = 0;
        while(counter < 2){
            cout << "keep Dice (s to stop playing): " ;
            cin >> choice;
            if (choice == "s" || choice == "S"){
                break;
            }
            hand1.setSelection(choice);
            hand1.play();
            hand1.show();
            counter++;
        }
        cout << "Slect a combination to play: ";
        cin >> row;
        game1.calcScore(hand, row);
        game1.show();
    }
}

void test_case()
{
    Game game;
    auto hand = new Hand();
    hand->getDice(0)->setValue(1);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(3);
    hand->getDice(3)->setValue(4);
    hand->getDice(4)->setValue(5);

    bool check1 = true;
    if (game.calcScore(hand, LARGE_STRAIGHT) != 40)
    {
        check1 = false;
    }
    if (check1)
    {
        cout << "check 1 passed\n";
    }

    hand->getDice(0)->setValue(2);
    hand->getDice(1)->setValue(6);
    hand->getDice(2)->setValue(4);
    hand->getDice(3)->setValue(3);
    hand->getDice(4)->setValue(5);

    bool check2 = true;
    if (game.calcScore(hand, LARGE_STRAIGHT) != 40)
    {
        check2 = false;
    }

    if (check2)
    {
        cout << "check 2 passed\n";
    }

    hand->getDice(0)->setValue(3);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(5);
    hand->getDice(3)->setValue(6);
    hand->getDice(4)->setValue(3);

    bool check3 = true;
    if (game.calcScore(hand, LARGE_STRAIGHT) != 0)
    {
        check3 = false;
    }

    if (check3)
    {
        cout << "check 3 passed\n";
    }

    hand->getDice(0)->setValue(1);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(3);
    hand->getDice(3)->setValue(4);
    hand->getDice(4)->setValue(6);

    bool check4 = true;
    if (game.calcScore(hand, LARGE_STRAIGHT) != 0)
    {
        check4 = false;
    }

    if (check4)
    {
        cout << "check 4 passed\n";
    }
}


//For these types of programs there exists many combinations that you might have missed.
//The best way to check them all is to write test cases for your program.
//Here I give you an example of checking large straight. You can design your own test cases for different parts.



// THE AUTOGRADER WILL REPLACE THE MAIN FUNCTION.
// DO NOT ADD ANY LOGIC OF YOUR PROGRAM HERE.
int main() {
    
    srand(time(0));
    run();
    test_case();
    return 0;
}
