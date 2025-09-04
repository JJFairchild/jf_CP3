// Jonas Fairchild, Tic Tac Toe

/*

Lesson 1: Arrays
LESSON I CAN: I CAN use strings arrays and conditionals in C++

By the end of this lesson you will be able to:
- Iterate over an array
- Compare items in arrays
- Pass an array into a function
- Understand type_t
- Unpack an array
- Search and sort arrays
- Create multi dimensional arrays

State Standards:
STRAND 3: Students will utilize multidimensional arrays

    STANDARD 1: Utilize multidimensional arrays

        - Initialize multidimensional arrays

        - Input and output data into and from multidimensional arrays

        - Preform Operations on multidimensional Arrays

        - Preform searches on multidimensional arrays

INSTRUCTIONS:
- Create a tic tac toe game where the user plays against a random number generator. Save the locations on the board as a multidimensional array.

KEY REMINDERS:
- Remember you have to set your variable types
- You have to get the standard library to create your inputs and outputs
- Make sure your arrows are pointing the right way for the input/output stream. 
- You have to set the length of the array when you create it
- Use functions to reduce repetitive code

HOW TO SUBMIT:
- Submit the link to your project on Github

*/

/*

TODO:
- Function to randomly select a spot for O to play
- 
- Main loop (wait for user to select a spot to play, have the bot play, display the board, check if someone won)
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string board[3][3] = { // The board. Modified by several other functions.
    {" ", " ", " "},
    {" ", " ", " "},
    {" ", " ", " "}
};

int win_combos[8][3][2] = { // All possible win combinations.
    {{0, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}},
    {{2, 0}, {1, 1}, {0, 2}}
};

string check_win(){ // Function to check the win state of the board (win for X or O, tie, or nothing)
    // Check all possible win combos
    for(int i=0; i<8; i++){
        string potential_winner = board[win_combos[i][0][0]][win_combos[i][0][1]]; // Assign a potential winner to the first tile in the combo

        for(int j=0; j<3; j++){
            if(board[win_combos[i][j][0]][win_combos[i][j][1]] != potential_winner){
                potential_winner = " "; // Don't assign a winner if the combination isn't the same throughout.
            }
        }

        if(potential_winner == "X" or potential_winner == "O"){ // If a winner is found to exist, return that.
            return potential_winner;
        }
        
    }

    // Check for a tie
    int tie_count = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == "X" or board[i][j] == "O"){ // Count how many spaces are full
                tie_count++;
            }
        }
    }

    if(tie_count == 9){ // If all spaces are full, return that it is a tie.
        return "T";
    }

    return " ";
}

void o_play(){ // Determines a spot for O to play.
    if(check_win() == " "){
        while(true){
            // Randomly selects a spot to play
            int row = rand() % 3;
            int col = rand() % 3;

            if(board[row][col] == " "){ // Makes sure the spot is open and sets it to O before leaving.
                board[row][col] = "O";
                break;
            }
        }
    }
}

void display(){
    for(int i=0; i<3; i++){
        cout << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
    }
}

int main(){
    srand(time(nullptr));
    
    cout << "Tic Tac Toe is a game that takes place on a 3x3 board. The two players place Xs and Os in spots of their choosing (X plays first), and the first player to place 3 in a row (in any direction) of their tile wins.\nReady to begin?: ";
    int empty_input;
    cin >> empty_input;
    
    while(true){
        display();

        while(true){
            int row;
            int col;
            
            while(true){
                cout << "Select the row you want to play on (1, 2, 3): ";
                cin >> row;
                row -= 1;
                if(not (0 <= row and row <= 2)){
                    cout << "That's not in the range. Try again.";
                    continue;
                }
                break;
            }
            
            while(true){;
                cout << "Select the column you want to play on (1, 2, 3): ";
                cin >> col;
                col -= 1;
                if(not (0 <= col and col <= 2)){
                    cout << "That's not in the range. Try again.";
                    continue;
                }
                break;
            }
            
            if(board[row][col] != " "){
                cout << "That space isn't available. Try again.";
                continue;
            }

            board[row][col] = "X";
            break;
        }
        
        o_play();
        string win = check_win();
        if(win == "X"){
            cout << "Congratulations! You win!";
            return 0;
        } else if(win == "O"){
            cout << "Looks like you lost to a robot. Better luck next time!";
            return 0;
        } else if(win == "T"){
            cout << "That's a tie! Better luck next time!";
            return 0;
        }

    }
}
