/*
Lesson 1: Streams and Txt
LESSON I CAN: I CAN use read and write to TXT and CSV files

By the end of this lesson you will be able to:
- Explain how streams work
- Read and write to a txt file
- Read and write to a csv file

State Standards: ***This is a UVU CS1410 requirement***

INSTRUCTIONS:
- Write a program that manages a high score leaderboard for a game using file I/O in C++. The program should allow the user to add new high scores, view the existing leaderboard, and save the data to a text file. It should also read data from the file when the program starts. The user menu should include options to add a new score, display the high scores, and exit. The program must handle invalid inputs gracefully and continue running until the user chooses to exit.

OUTPUT EXAMPLE: 

    High Score Leaderboard:

    1. Player: Alice | Score: 1200 | Date: 09/26/2025
    2. Player: Bob   | Score: 950  | Date: 09/25/2025
    3. Player: Carol | Score: 880  | Date: 09/24/2025

    Menu:
    1. Add a new high score
    2. Display high scores
    3. Exit
    Enter your choice (1-3): 1

    Enter player's name: Alice
    Enter score: 1300
    Enter date (MM/DD/YYYY): 09/26/2025

    High score added successfully.

    Menu:
    1. Add a new high score
    2. Display high scores
    3. Exit
    Enter your choice (1-3): 2

    --- High Scores ---
    1. Player: Alice | Score: 1300 | Date: 09/26/2025
    2. Player: Alice | Score: 1200 | Date: 09/26/2025
    3. Player: Bob   | Score: 950  | Date: 09/25/2025
    4. Player: Carol | Score: 880  | Date: 09/24/2025

    Menu:
    1. Add a new high score
    2. Display high scores
    3. Exit
    Enter your choice (1-3): 3

    Goodbye!

KEY REMINDERS:
- Use appropriate data structures, such as struct or class, to store the high score data.
- When adding a new score, insert it into the list, and sort based on scores if necessary.
 -When the program starts, read existing high scores from a text file (e.g., highscores.txt) and load them into memory.
- When the program exits, save the current high scores back to the file, overwriting previous data if needed.
- Use fstream for file input/output, and ensure proper opening, reading, writing, and closing files.
- Implement input validation for menu choices, scores, and date formats.
- Make sure your program continues to run until the user chooses to exit.

HOW TO SUBMIT:
- Submit the link to your project on Github
*/

#include <iostream>
#include <limits>
using namespace std;

enum MainMenu{
    Add = 1,
    Display,
    Exit
};

struct Date{
    int month;
    int day;
    int year;
};

struct HighScore{
    string player;
    int score;
    Date date;
};

int getNum(const string& prompt, const string& error, int max, int min){
    int num;
    while (true){
        cout << prompt;
        getline(cin, num);
        if (cin.fail()){
            cout << "That's not a valid input. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (num > max || num < min){
            cout << error << endl;
        } else return num;
    }
}

string getStr(const string& prompt){
    string str;
    while (true){
        cout << prompt;
        cin >> str;
        if(str.empty()) cout << "You have to type something. Try again.\n";
        else return str;
    }
}

HighScore getHS(){
    string player = getStr("What is the name of your player?: ");
}

int main(){

    while (true){
        int choice;
        cout <<
        "\nWhat do you want to do?\n" <<
        "1: Add a new high score\n" <<
        "2: View high scores\n" <<
        "3: Save and exit\n";
        getline(cin, choice);

        if(cin.fail()){
            cout << "That's not a valid input. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (choice == MainMenu::Add){
            // Run add function
        } else if (choice == MainMenu::Display){
            // Run display function
        } else if (choice == MainMenu::Exit){
            // Save data
            break;
        } else {
            cout << "That's not an option. Try again.\n";
        }
    }

    return 0;
}