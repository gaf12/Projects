/****************************
 *
 * HEADER
 *
 * ABDUL GAFFIR ZAMBI
 * *** **********************/



#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


const string rule_msg_1 = "The selected password must be at least eight characters long.";
const string rule_msg_2 = "The selected password must have at least one uppercase letter.";
const string rule_msg_3 = "The selected password must have at least one lowercase letter.";
const string rule_msg_4 = "The selected password must have at least one digit.";
const string rule_msg_5 = "The selected password must have at least one of special characters: [@,!,#,^,&,*,$]";
const string rule_msg_6 = "The selected password has been leaked.";
const string rule_msg_7 = "The selected password cannot contain a dictionary word.";

    
/****
 * Runs the main part of the program
 ****/
// The function deletingSymbols delets symbols from a string and then save it into
// a new variable.. The new string created does ot have any special character.
void deletingSymbols(string password, string& newPassword){
  for (int i = 0; i < password.size(); i++){
      // if there is a special character in password the loop skips it..
      // and saved a new string  newPassword..
    if (ispunct(password[i]) != 0){
        continue;
    }
    else
    {
        newPassword = newPassword + password[i];
    }
  }
}


// The function convertToLowerCase converts all uppercases in a string to lower case..
// and stores it in a new string..
void convertToLowerCase(string& newPassword){
    for (int i = 0; i < newPassword.size(); i++){
        newPassword[i] = tolower(newPassword[i]);
    }
}


// The function deletingDigitsFromString delets all numbers from a string
// and saves the new string into another variable..
void deletingDigitsFromString (string noSymbPass, string& noDigitPass){
    for (int i = 0; i < noSymbPass.size(); i++){
        if(isdigit(noSymbPass[i]) != 0){
            continue;
        }
        else
        {
            noDigitPass = noDigitPass + noSymbPass[i];
        }
    }
}


//The function passwordChecker accpets the user input and check  the first 5 conditions of the
// string..
int passwordChecker(string password){
    //The code below checks the length of the user cin...
    // Only Inputs with length 8 and above are allowed..
    int lengthChecker = 0;
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSymbol = 0;
    int fiveCaseValid = 0;
    
    // This for loop goes through the user input and checks if the first 5 cases
    // or conditions are met..
    // This first if condition checks the length of the user input..
    if (password.size() < 8)
    {
        cout << rule_msg_1 << endl;
        lengthChecker++;
    }
    // The for loop below goes through the user Input and checks the remaining 4 conditons..
    for (int i = 0; i < password.size(); i++)
    {
        // isupper checks to see if the user input has an upper case..
        // and returns 1 if true...
        if (isupper(password[i])){
            hasUpper = 1;
        }
        // islower checks if the user input has a lower case...
        // and returns 1 if true...
        if (islower(password[i])){
            hasLower = 1;
        }
        // isdigit checks if the user input has a digit..
        // and returns 1 if true...
        if (isdigit(password[i]))
        {
            hasDigit = 1;
        }
        // ispunct checks if the user input has a special character...
        // and returns 1 if true...
        if (ispunct(password[i]))
        {
            hasSymbol = 1;
        }
    }
    // if any of the conditions above is met the conditions below will check to see which
    // condition above was failed.. and print out a rule based on the conditiion above..
    if (hasUpper == 0)
    {
        cout << rule_msg_2 << endl;
    }
    // if hasLower is 0 it means the user input has no lowerCase so
    // the conditions fails...
    if (hasLower == 0)
    {
        cout << rule_msg_3 << endl;
    }
    // if hasDigit is 0 it means the user input has no digit so
    // the conditions fails...
    if (hasDigit == 0)
    {
        cout << rule_msg_4 << endl;
    }
    // if hasSymbol is 0 it means the user input has no special Cases char so
    // the conditions fails...
    if (hasSymbol == 0)
    {
        cout << rule_msg_5 << endl;
    }
    
    // if all five cases are met this condition checks that and set fiveCaseValid to 1;
    if ((hasUpper >= 1) && (hasLower >= 1) && (hasDigit >= 1) && (hasSymbol >= 1) && (lengthChecker == 0)){
        fiveCaseValid = 1;
    }
    // if any of the conditions fails fiveCases is set to 0;
    else
    {
        fiveCaseValid = 0;
    }
    
    return fiveCaseValid;
}
// the function lookngForBinaryMatch contains the binary search..
// this function returns an integer..
int lookingForBinaryMatch(vector<string>allegedPassword,string newPassword){
    int long long  fileSizeHigh = allegedPassword.size() - 1;
    int long beginAllegedPass = 0;
    int long long middle = 0;
    int checkLeak = 0;
    
    // the while loop keeps looping till the mid is equal to itself..
    while(beginAllegedPass <= fileSizeHigh){
        middle = (beginAllegedPass + fileSizeHigh) / 2 ;
        // if the middle is greater than the password the highest point is assigned
        // with middle - 1...
        if (allegedPassword.at(middle) > newPassword){
            fileSizeHigh = middle - 1;
        }
        // is the middle is less tha the password the lowest point is assigned with
        // middle - 1..
        else if (allegedPassword.at(middle) < newPassword){
            beginAllegedPass = middle + 1;
        }
        else {
            checkLeak = 1;
            return middle;
        }
    }
    // this is the value returned...ret
    return checkLeak;
}

int run(string leaked_password_file, string english_word_file){
    cout << "Enter password: ";
    string password;
    getline(cin,password);
    int dictionaryWordLeak = 0;
    vector<string> allegedPassword;
    string new12Password;
    int countingLeakMatch = 0;
    string noSymbPassFile;
    string noDigitPass;
    string newPassword;
    
    
    // checkedPassword recieves the value returned from the functions passwordChecker..
    int checkedPassword = passwordChecker(password);
    
    // if the value of checkedPassword is equal to 1.. it means all first five conditions were met
    // the userInput has all five conditions..
    //The if condtion below then goes on to read the file alleged-gmail-password..
    //And do a binary search to see if there is a match or not.. a found match indicates a
    // password leak...
    if (checkedPassword == 1){
        //the deletingSymbols function is called to delete the special cases from the user input
        //and store it in a new variable called newPassword....
        deletingSymbols(password,newPassword);
        
        //convertToLowerCase converts newPassword to lower case to match that of the file..
        convertToLowerCase(newPassword);
        
        // declare a variable myfile of type ifstream..
        ifstream myFile;
        // alleged-gmail-password is then assigned to myFile;
        myFile.open("alleged-gmail-passwords.txt");
        //from the if statement below if the file doesnt open correctly the app close..
        if(!myFile.is_open()){
            cout << "not open" << endl;
        }
        
        //Else if the file opens..
        else if(myFile.is_open()){
            string checkingLeakPass;
            
            // this while loop read every line of code into the string checkingLeakpass
            while (!myFile.eof()){
                myFile >> checkingLeakPass;
                // All symbols in checkingPass is deleted..
                deletingSymbols(checkingLeakPass, noSymbPassFile);
                
                // the strings without symbols is then saved in to the vector allegedPassword..
                allegedPassword.push_back(noSymbPassFile);
                
                noSymbPassFile = "";
            }
            
            // A binary search is then done on th allegedPassword to find newPassword
            // if there is a match the function return a value greater than or equal to 1..
            // and if a match is found it means there is a password leak..
            // if there is a password leak countingLeakMatch is increased.
            if(lookingForBinaryMatch(allegedPassword,newPassword) >= 1){
                cout << rule_msg_6 << endl;
                countingLeakMatch++;
            }
            
        }
        
        // if countingLeakMatch
        if (countingLeakMatch == 0){
            // The function deletingDigitsFromString deletes all the numbers in the user input
            // and assign it to a new string noDigitPass..
            deletingDigitsFromString(newPassword, noDigitPass);
            
            // A new variable mySecondfile is declare and initialized with word_5.txt
            ifstream mySecondFile;
            mySecondFile.open("words_5.txt");
            
            // if the file doesnot open the app closes
            if(!mySecondFile.is_open()){
                exit (-1);
            }
            // else if it opens each line of the file is read in to the string second input
            else if (myFile.is_open()){
                string secondInputPass;
                // the file is read until the end of the file
                while (!mySecondFile.eof()){
                    mySecondFile >> secondInputPass;
                    // after the file is read in to the string the string is then compared to the user
                    //input with no digits and if there is a match the 7th condition fails ..
                    // And the value of dictionarWordleak is incresed....
                    if (noDigitPass == secondInputPass){
                        cout << rule_msg_7 << endl;
                        dictionaryWordLeak++;
                    }
                }
            }
        }
    } // End of checkedPassword == 1 condition
    
    //if the any of the five conditions fail of condition 6 fails or condition 7 fails..
    // the password is rejected..printing poword rejected...
    if ((checkedPassword == 0) || (countingLeakMatch >= 1) || (dictionaryWordLeak  >= 1))
    {
        cout << "Password rejected!" << endl;
    }
    //if all the conditions from 1 to 7 is met, the password is accepted....
    else
    {
        cout << "Password accepted!" << endl;
    }
        
    return -1;
    
}
    
int main() {
    /** Change the address of the files appropriatly based on your local machine.
     * This main function will be replaced during testing. Do not add any line of code to the main function
     **/
    string leaked_password_file = "alleged-gmail-passwords"; //change this based on the location of the file on your machine
    string english_word_file = "words_5.txt"; //change this based on the location of the file on your machine
    run(leaked_password_file, english_word_file);
    return 0;
}
