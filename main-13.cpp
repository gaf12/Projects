
/**------------------------------------------

    Program 4: IMDB
    Course: CS 141, Fall 2022.
    System: MacOS using Clion
    Author: Dr. Sara Riazi
    Student Author : Abdul Gaffir Zambi
-------------------------------------------*/


#include <iostream>
#include <cctype>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
/*********************************************** Helper functions ***************************************/

//The splitString function takes a line and split it on the delimiter and push the parts into items

/**********************************************************************************************************/
void splitString(string line, char delimiter, vector<string>& items ) {
    stringstream s_stream(line);
    while (s_stream.good()) {
        string item;
        getline(s_stream, item, delimiter);
        items.push_back(item);
    }
}


// loLowerCase takes a string and converts all the upper cases in the string to lower cases..
void toLowerCase(string& words){
    for (int i = 0; i < words.size(); i++){
        words[i] = tolower(words[i]);
    }
}

// this function is used to delete commas in a given string..
// a string is passed into it and all the commas in the string is replaced with a space..
void deletingComas(string& newPhrase){
   
    for (int i = 0; i < newPhrase.size();i++){
        if (newPhrase.at(i) == ','){
            newPhrase[i] = ' ';
        }
    }
}

// Defining the struct TitleRecords
// and assigning it to its respective objects..
struct TitleRecord {
    string Tconst;
    string PrimaryTitle;
    string StartYear;
    string Genres;
};

// Defining the struct Namerecord
// and assigning it to its respective objects..
struct NameRecord {
    string nameId;
    string primaryName;
    string birthYear;
    string deathYear;
    string primaryProfession;
};

//Defining the struct PrincipalRecord..
// and assigning it to its respective objects..
struct PrincipalRecord {
    string titleIdTwo;
    string secondNameId;
    string category;
    string job;
    string character;
};


// This is the function which does all the operations in this code
// this functions contains the game stages 1 and 2..
void allOperations(string searchPhrase,int menuOption){
    // if the Userinput is one the code below takes place.
    // the user Input is taken from the user as he selects either to
    // search for a movie, or actress.. if the the user inputs 1,
    // a movie search is done...
if (menuOption == 1){
    vector <string> phraseHolderOne;
    // the string or users searchPhrase is been passed into the file
    // as searchPhrase and searchPhrase is converted to lower cases
    toLowerCase(searchPhrase);
    // searchPhrase is split into two and then each half is stored inside the
    // vectore of type string called phraseHolderOne.. using the helper function
    //splitstring....
    splitString(searchPhrase, '+', phraseHolderOne);
    
    // first the file movie.title.tsv is read and store into the struct TitleRecord.
    string phraseWord;
    string eachWord;
    // Declaring a vector of type TitleRecord to hold the informtion stored
    // inside the file..
    vector <TitleRecord> titleRecordLowerCase;
    vector <TitleRecord>titleRecord;
    vector<TitleRecord> matchedStore;
    int matchChecker = 0;
    ifstream titleRecordFile;
    
    // reading movie.titles.tsv into the decleared variable
    // to open the file....
    titleRecordFile.open("movie.titles.tsv");
    
    // if the file does not open for any reason the program shuts down..
    if (!titleRecordFile.is_open()){
        exit (-1);
    }
    // If the file opens the reading of the information foes on...
    else {
            // The first line is read into phraseWord and then cleared..
            // this is done to get rid of the first line...
            getline(titleRecordFile,phraseWord);
            phraseWord = "";
            
        // After the fiirst line has been deleted the other lines of the file are
        // read into pharaseWord and then assigned to the objects in the struct..
            while (getline(titleRecordFile,phraseWord)){
                // Declaring a struct of type TitleRecords to hold the lines
                // in the file..
                TitleRecord Records;
                vector <string> titleRecordFileHolder;
                // Firstly all the comma in the file is taken out..
                deletingComas(phraseWord);
                // After that using the split function the line is split into many parts..
                splitString(phraseWord,'\t' ,titleRecordFileHolder);
                
                // The order of lines are then passed into the struct titleRecord..
                // based on the order in the file.....
                Records.Tconst = titleRecordFileHolder[0];
                Records.PrimaryTitle = titleRecordFileHolder[2];
                Records.StartYear = titleRecordFileHolder[5];
                Records.Genres = titleRecordFileHolder[8];
                
                //the struct Records is pushed into the vector titleRecord
                // vector titleRecords is a vector of type TitleRecords
                titleRecord.push_back(Records);
                // this version of titleRecords is to be lowered...
                titleRecordLowerCase.push_back(Records);
            }
            // closing the file
            titleRecordFile.close();
        
            // this for loops goes through titleRecords and see if there is matches with
            // the user input after the user input has been split into two...
            for (int i = 0; i < titleRecordLowerCase.size(); i++){
                int phraseMatch = 0;
                for (int j = 0; j < phraseHolderOne.size();j++){
                    // first the titleRecord is set to all lowerCases..
                    toLowerCase(titleRecordLowerCase[i].PrimaryTitle);
                    // if there is a match in a string the variable phraseMatch is increased....
                    if (titleRecordLowerCase[i].PrimaryTitle.find(phraseHolderOne[j]) != string::npos){
                        phraseMatch++;
                    }
                }
                // if the phraseMatch is the same as the size of the userInput vector
                // this means there is a total match found in one line...
                if(phraseMatch == phraseHolderOne.size()){
                    // if there is a total match firstly,
                    // the match is pushed into the vector matchedStore..
                    matchedStore.push_back(titleRecord[i]);
                    matchChecker = 1;
                    // After that their respective information is printed out..
                    cout << matchedStore.size() - 1 << ": " << endl;
                    cout << "Title: "  << titleRecord[i].PrimaryTitle << endl;
                    cout << "Year: " << titleRecord[i].StartYear << endl;
                    cout << "Genre: " << titleRecord[i].Genres << endl;
                    cout << "---------------" << endl;
                }
            }
     // this is a counter to check if there is a full match or not..
    if (matchChecker == 0){
        cout << "No match found! " << endl;
    }
    // if there is a match the following then happens...
    else {
            // dispalying a statement to the user to decide what to do..
            cout << "Select a movie to see its actors/actresses (-1 to go back to the previous menu): " ;
        
            // declaring a variable of type ifstream..
            ifstream principalRecordFile;
            
            // opening the file movie.principals.tsv..
            principalRecordFile.open("movie.principals.tsv");
            string principalLine;
            // reading the first line of the file and then clearing it ...
            getline(principalRecordFile,principalLine);
            principalLine = "";
            
            vector <PrincipalRecord> principalNames;
            
            // The file reading continues..
            while(getline(principalRecordFile, principalLine)){
                
                vector<string>princiPalBin;
                PrincipalRecord principalRecord;
                // After that using the split function the line is split into many parts..
                splitString(principalLine, '\t', princiPalBin);
                
                // The order of lines are then passed into the struct principalRecord..
                // based on the order in the file.....
                principalRecord.titleIdTwo = princiPalBin[0];
                principalRecord.secondNameId = princiPalBin[2];
                principalRecord.category = princiPalBin[3];
                principalRecord.job = princiPalBin[4];
                principalRecord.character = princiPalBin[5];
                
                //the struct Records is pushed into the vector principalRecord
                // vector titleRecords is a vector of type PrincipalRecords
                principalNames.push_back(principalRecord);
            }
            // clsing the file..
            principalRecordFile.close();
            
            // the code below opens the NamerecordFile and assigns the elements in the file to the
            // objects of a declared vector of type NameRecord.. which is a struct..
            ifstream NameRecordFile;
            string NameFileHolder;
            
            // Opening the file movie.names.tsv
            NameRecordFile.open("movie.names.tsv");
            
            // if the file fails to open the app closes..
            if (!NameRecordFile.is_open()){
                exit (-1);
            }
            
            else{
                    //else i go on to declare a vector of type Name record strut and push
                    // all the elemnts contained in the file to the strut...
                    vector<NameRecord> RecordNames;
                    
                    // reading the file to a line and clearing it to get rid of the first line of the file..
                    getline(NameRecordFile,NameFileHolder);
                    // clearing the line..
                    NameFileHolder = "";
                    
                    // contibuereading the lines after clearing the line..
                    while (getline(NameRecordFile,NameFileHolder)){
                        
                        vector <string> recordLine;
                        NameRecord nameRecords;
                        
                        // the lines of the read files is split until it gets to a tab..
                        splitString(NameFileHolder, '\t', recordLine);
                        
                        // these strings are then assigned to the vector ...
                        // based on the order on the file...
                        nameRecords.nameId = recordLine[0];
                        nameRecords.primaryName = recordLine[1];
                        nameRecords.birthYear = recordLine[2];
                        nameRecords.deathYear = recordLine[3];
                        nameRecords.primaryProfession = recordLine[4];
                        
                        //the struct nameRecords is pushed into the vector RecordNames
                        // vector RecordNames is a vector of type NameRecord
                        RecordNames.push_back(nameRecords);
                    }
                // the file is then closed..
                    NameRecordFile.close();
                    // user input is taken to decide the game status...
                    int UserInput;
                    cin >> UserInput;
                
                    // if the userinput is - 1, the user is taken back to the first screen..
                    if (UserInput == - 1){
                    int menuOption;
                    string searchPhrase;
                    vector <string> phraseHolderOne;
                    cout << "Select a menu option: " << endl;
                    cout << "    1. Search for a movie" << endl;
                    cout << "    2. Search for actor/actresses" << endl;
                    cout << "    3. Exit" << endl;
                    cout << "Your choice --> ";
                    cin >> menuOption;
                    if (menuOption == 1 || menuOption == 2){
                        cout << "Enter search phrase: ";
                        cin >> searchPhrase;
                        cout << endl;
                        // the the function allOperations is called and the searchPhrase
                        // and menuOption is passed into the function..
                        allOperations(searchPhrase,menuOption);
                    }
                }

            else {
                    // If a user selects a movie the tconst of the movie is taken.
                    vector<PrincipalRecord> namedMatch;
                    // then the principalNames is searched to find a matching tconst
                    // which has a category of an actor or actress..
                    for (int i = 0; i < principalNames.size(); i++){
                        if ((principalNames[i].titleIdTwo == matchedStore[UserInput].Tconst)
                            &&  (principalNames[i].category == "actor" ||
                                 principalNames[i].category == "actress"))
                        {
                            // this match is then pushed into nameMatched..
                            namedMatch.push_back(principalNames[i]);
                        }
                    }
                    // at the location where the tconst matched in the principal,
                    // the nconst is grabbed and this ncost is then match with
                    // namerecords .. and if there is a match the names and characters
                    // of the actors are printed out ..
                    for (int i = 0; i < RecordNames.size(); i++){
                        for (int j = 0; j < namedMatch.size(); j++){
                            if(RecordNames[i].nameId == namedMatch[j].secondNameId){
                                cout << RecordNames[i].primaryName << " " << namedMatch[j].character<< endl;
                            }
                        }
                    }

                    cout << "Enter search phrase (type done to go back to the previous menu): " ;
                    cin >> searchPhrase;
                    cout << "_______________" << endl;
                    //  if the user inputs done the user is taken to the main menu
                    if(searchPhrase == "done"){
                        int menuOption;
                        string searchPhrase;
                        vector <string> phraseHolderOne;
                         cout << "Select a menu option: " << endl;
                         cout << "    1. Search for a movie" << endl;
                         cout << "    2. Search for actor/actresses" << endl;
                         cout << "    3. Exit" << endl;
                         cout << "Your choice --> ";
                        cin >> menuOption;
                        if (menuOption == 1 || menuOption == 2){
                            cout << "Enter search phrase: ";
                            cin >> searchPhrase;
                            cout << endl;
                            // the the function allOperations is called and the searchPhrase
                            // and menuOption is passed into the function..
                            allOperations(searchPhrase,menuOption);
                        }
                    }
                }
            }
        }
    }
}

//If the userInputs 2.. the following code
// proceeds..
if (menuOption == 2){
    
    // the string or users searchPhrase is been passed into the file
    // as searchPhrase and searchPhrase is converted to lower cases
    toLowerCase(searchPhrase);
    vector <string> secUserHolder;
    
    // searchPhrase is split into two and then each half is stored inside the
    // vectore of type string called secUserHolder.. using the helper function
    //splitstring....
    splitString(searchPhrase, '+', secUserHolder);
    
    // defining a variable of type NameRecordfile
    ifstream NameRecordFile;
    string NameFileHolder;
    int gameChoice = 0;
    
    // NameRecordFile is assigned with movie.names.tsv
    NameRecordFile.open("movie.names.tsv");
    
    // If the file does not open the program shuts down..
    if (!NameRecordFile.is_open()){
        exit(0);
    }

    else{
        // opening the file
        vector<NameRecord> recordNames;
        vector <NameRecord> recordNamesLow;
        // the first line of the file is read into
        // NameFileHolder and then cleared..
        getline(NameRecordFile,NameFileHolder);
        NameFileHolder = "";

        // after that the file reading goes on...
        while (getline(NameRecordFile,NameFileHolder)){
            
            vector <string> recordLine;
            NameRecord nameRecords;
        
            // the lines of the read files is split until it gets to a tab.
            splitString(NameFileHolder, '\t', recordLine);
            // these strings are then assigned to the vector ...
            // based on the order on the file...
            nameRecords.nameId = recordLine[0];
            nameRecords.primaryName = recordLine[1];
            nameRecords.birthYear = recordLine[2];
            nameRecords.deathYear = recordLine[3];
            nameRecords.primaryProfession = recordLine[4];
            // the struct nameRecord is now pushed into
            // another vector of type NameRecord
            recordNames.push_back(nameRecords);
            
            recordNamesLow.push_back(nameRecords);
        }
        // the file is closed..\
        NameRecordFile.close();

        vector <NameRecord> recordStore;
        string phraseWord;
        vector <TitleRecord> titleRecordLowerCase;
        vector <TitleRecord>titleRecord;
        vector<TitleRecord> matchedStore;

        ifstream titleRecordFile;
        titleRecordFile.open("movie.titles.tsv");

        if (!titleRecordFile.is_open()){
            exit (-1);
        }
        else {
                getline(titleRecordFile,phraseWord);
                phraseWord = "";
                
                while (getline(titleRecordFile,phraseWord)){
                    getline(titleRecordFile,phraseWord);
                    TitleRecord Records;
                    vector <string> titleRecordFileHolder;
                    
                    // the lines of the read files is split until it gets to a tab.
                    splitString(phraseWord,'\t' ,titleRecordFileHolder);
                    
                    // these strings are then assigned to the vector ...
                    // based on the order on the file...
                    Records.Tconst = titleRecordFileHolder[0];
                    Records.PrimaryTitle = titleRecordFileHolder[2];
                    Records.StartYear = titleRecordFileHolder[5];
                    Records.Genres = titleRecordFileHolder[8];
                    
                    // the struct Record is now pushed into
                    // another vector of type TitleRecord
                    titleRecord.push_back(Records);
                }
                
                // closing the file...
                titleRecordFile.close();
                
                // declearing a variable of type istream..
                ifstream principalRecordFile;
                
                // the variable is assigned to movie.principal.tsv.
                principalRecordFile.open("movie.principals.tsv");
                string principalLine;
                // the first line of the file is read and cleared to get rid of it..
                getline(principalRecordFile,principalLine);
                principalLine = "";
                
                vector <PrincipalRecord> principalNames;
                // the reading of line goes on every line of the file
                // is read into principalLine..
                while(getline(principalRecordFile, principalLine)){
                    
                    vector<string>princiPalBin;
                    PrincipalRecord principalRecord;
                    
                    //The read line is slip into multiple parts
                    // till it gets to a tab.. using the splitString..
                    splitString(principalLine, '\t', princiPalBin);
                    
                    principalRecord.titleIdTwo = princiPalBin[0];
                    principalRecord.secondNameId = princiPalBin[2];
                    principalRecord.category = princiPalBin[3];
                    principalRecord.job = princiPalBin[4];
                    principalRecord.character = princiPalBin[5];
                    
                    principalNames.push_back(principalRecord);
                }
                
                //  closing the file..
                principalRecordFile.close();
                
                int firstNameCheck = 0;
                
                vector<PrincipalRecord> namedMatch;
                
                // this for loop loops through recordNamesLow which is record names that have lowercases
                // and the nested for loop also loops through user input which has been splitted into two
                // and saved into a vector string... the loops seeks out a match between theses two vectors..
                // if a match of the elements in secUserHolder is found.. nameMtach is increased.
                for (int i = 0; i < recordNamesLow.size();i++){
                    int nameMatch = 0;
                    for (int j = 0; j < secUserHolder.size(); j++){
                        toLowerCase(recordNamesLow[i].primaryName);
                        if (recordNamesLow[i].primaryName.find(secUserHolder[j]) != string::npos){
                            nameMatch++;
                        }
                    }
                    // if a complete match is found it means all the elements in secuser
                    // was found in one line of recordNames.. and also a check is done to make sure
                    // the found item is an actor or actress..
                    // after this all matches the persons info is printed out ..
                    if (nameMatch == secUserHolder.size() && recordNames[i].primaryProfession.find("act") != string::npos){
                        recordStore.push_back(recordNames[i]);
                        firstNameCheck = 1;
                        cout << endl;
                        cout << recordStore.size() - 1 << ":" << endl;
                        cout << recordNames[i].primaryName << endl;
                        cout << recordNames[i].primaryProfession << endl;
                        cout << "(" << recordNames[i].birthYear << "-";
                        cout << recordNames[i].deathYear << ")" << endl;
                        cout << "______________" << endl;
                    }
                }
                // this code below checks
                if (firstNameCheck == 0){
                    cout << "No match found! " << endl;
                    cout << endl;
                }
                
                // this cout statement ask the user what he or she intends to do in the game
                //  the user decides whether to go back to the main menu of continue with the game..
                cout << "Select an actor/actress to see movies (-1 to go back to the previous menu): ";
                cin >> gameChoice;
                
                // if the user inputs -1 the user is taken to the main menu...
                if (gameChoice == - 1){
                    int menuOption;
                    string searchPhrase;
                    vector <string> phraseHolderOne;
                    cout << "Select a menu option: " << endl;
                    cout << "    1. Search for a movie" << endl;
                    cout << "    2. Search for actor/actresses" << endl;
                    cout << "    3. Exit" << endl;
                    cout << "Your choice --> ";
                    cin >> menuOption;
                    if (menuOption == 1 || menuOption == 2){
                        cout << "Enter search phrase: ";
                        cin >> searchPhrase;
                        cout << endl;
                        // searchPhrase is then passed back into the function
                        // allOperations..
                        allOperations(searchPhrase,menuOption);
                    }
                }
                
                else{
                    vector <PrincipalRecord> tempRecHolder;
                    // The for loop goes through principalNames and match the nameid with
                    // the nameid of the selected user inpuy..
                    for (int i = 0; i < principalNames.size();i++){
                            if (principalNames[i].secondNameId == recordStore[gameChoice].nameId){
                                tempRecHolder.push_back(principalNames[i]);
                            }
                    }
                    int matchedName = 0;
                    // the tcont of the ovie is then grabbed and the list that holds the
                    // old movie is looped through to see if there is a matach ..
                    // if a match is found between the both tconst the actors
                    // and character they played is dispalyed..
                    for (int i = 0; i < titleRecord.size(); i++){
                        for (int j =0; j < tempRecHolder.size(); j++){
                            if (titleRecord[i].Tconst == tempRecHolder[j].titleIdTwo){
                                cout << titleRecord[i].PrimaryTitle;
                                cout << " " << titleRecord[i].StartYear;
                                cout << " " << tempRecHolder[j].character << endl;
                                matchedName = 1;
                            }
                        }
                    }
                    // if no match is found..
                    if (matchedName == 0){
                        cout << "No match found!" << endl;
                        
                        cout << endl;
                    }
                    
                    string secPhrase;
                    vector <string> secPhraseHolder;
                    // Then the user is prompted to either look for a phrase or go back to the
                    // previous menu..
                    cout << "Enter search phrase (type done to go back to the previous menu): " ;
                    cin >> secPhrase;
                    cout << "_______________" << endl;
                    toLowerCase(secPhrase);
                    // if the user inputs done .. the user is sent back to the home screen..
                    if (secPhrase == "done"){
                        int menuOption;
                        string searchPhrase;
                        vector <string> phraseHolderOne;
                        cout << "Select a menu option: " << endl;
                        cout << "    1. Search for a movie" << endl;
                        cout << "    2. Search for actor/actresses" << endl;
                        cout << "    3. Exit" << endl;
                        cout << "Your choice --> ";
                        cin >> menuOption;
                        if (menuOption == 1 || menuOption == 2){
                            cout << "Enter search phrase: ";
                            cin >> searchPhrase;
                            cout << endl;
                            // the searchPhrase and menuOption are
                            // assigned to the function allOperations..
                            allOperations(searchPhrase,menuOption);
                        }
                    }
                }
            }
        }
    }
}


int run(string titlesFile, string namesFile, string principalsFile) {
    // this is the begining of the program.. this output
    // is the first to pop up when the program starts running
    int menuOption;
    string searchPhrase;
    vector <string> phraseHolderOne;
    // the display menu ....
    cout << "Select a menu option: " << endl;
    cout << "    1. Search for a movie" << endl;
    cout << "    2. Search for actor/actresses" << endl;
    cout << "    3. Exit" << endl;
    cout << "Your choice --> ";
    cin >> menuOption;
    // first the user is prompted to make  a selection
    // then the user is asked to enter a phrase..
    // this selection and phrase is then passed into the function
    // allOperations..if the users selection is either one or two..
    if (menuOption == 1 || menuOption == 2){
    cout << "Enter search phrase: ";
    cin >> searchPhrase;
    cout << endl;
    // the searchPharse and menuOption is then assinged back into allOperation.
    allOperations(searchPhrase,menuOption);
    }
    
    // if user input is - 3 the program quits...
    if(menuOption == 3){
        exit(0);
    }
        
    return 0;
}

int main() {
    //Change these addresses according to your local machine
    string titlesFile =    "movie.titles.tsv";
    string namesFile = "movie.names.tsv";
    string principalsFile = "movie.principals.tsv";

    //DO NOT change the main function. The main function will be removed by the autograder
    run(titlesFile, namesFile, principalsFile);
    return 0;
}
