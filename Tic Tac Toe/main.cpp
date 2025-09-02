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
- Function to determine if position has a winner or tie or neither
- Function to randomly select a spot for O to play
- 
- Main loop (wait for user to select a spot to play, have the bot play, display the board, check if someone won)
*/


#include <iostream>
using namespace std;

string board[3][3] = {
    {" ", " ", " "},
    {" ", " ", " "},
    {" ", " ", " "}
};

string check_win(){
    // Check all possible win combos
    for(int i=0; i<8; i++){
        int win_combos[8][3][2] = {
            {{{}, {}}, {{}, {}}, {{}, {}}},
            {{{}, {}}, {{}, {}}, {{}, {}}},
            {{{}, {}}, {{}, {}}, {{}, {}}},
            {{{}, {}}, {{}, {}}, {{}, {}}},
            {{{}, {}}, {{}, {}}, {{}, {}}},
            {{{}, {}}, {{}, {}}, {{}, {}}},
            {{{}, {}}, {{}, {}}, {{}, {}}},
            {{{}, {}}, {{}, {}}, {{}, {}}}
        };
    }

    // Check for a tie
    int tie_count = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == "X" or board[i][j] == "O"){
                tie_count++;
            }
        }
    }  
    if(tie_count == 9){
        return "T";
    }
}

int main(){
    cout << "Tic Tac Toe is a game that takes place on a 3x3 board. The two players place Xs and Os in spots of their choosing (X plays first), and the first player to place 3 in a row (in any direction) of their tile wins.\nReady to begin?: ";
    int empty_input;
    cin >> empty_input;

    return 0;
}