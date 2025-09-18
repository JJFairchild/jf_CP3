// Jonas Fairchild, User Structure

/*
Lesson 1: Structures
LESSON I CAN: I CAN build custom structures in C++

By the end of this lesson you will be able to:
- Define structures
- Create structures
- Use pointers to access structures
- Add information to a structure
- Overload an operator

State Standards: ***This is a UVU CS1410 requirement***

INSTRUCTIONS:
- Write a program that takes in a username, password, and admin status (you can do more but that is the minimum). The program then uses that information to create a user object from a structure. 
- It then needs to compare that user with a list of already existing users (10 users minimum) to see if the user already exists.

OUTPUT EXAMPLE: 
- User: Alex LaRose
- Already exists. 

OR
- Welcome
- User: Alex LaRose

KEY REMINDERS:
- Remember you have to set your variable types
- You will need to over write an operator so that you can compare two of the user objects. 
- You have to get the standard library to create your inputs and outputs
- Make sure your arrows are pointing the right way for the input/output stream.

HOW TO SUBMIT:
- Submit the link to your project on Github
*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct User{
    string name;
    string pass;
    string admin; // string so that there can be an undecided state "" for the logIn() function
};

vector<User> users = {
    {"Alice", "alice123!", "Y"},
    {"Bob", "b0bSecure$", "N"},
    {"Charlie", "charlieP@ss", "N"},
    {"Dana", "D@n@2025", "Y"},
    {"Eli", "eli_pass!", "N"},
    {"Fiona", "Fi0na#Rulez", "Y"},
    {"George", "Gpass_99", "N"},
    {"Hannah", "H@nnah$ecure", "N"},
    {"Ian", "ian!123", "N"},
    {"Jade", "J@d3_Admin", "Y"}
};

string user = "";
void logIn(string name = "", string pass = "", string admin = ""){

    bool user_exists;
    for (int i = 0; i < size(users); i++){
        if (users[i].name == name && users[i].pass == pass && users[i].admin == admin){
            user_exists = true;
            break;
        }
        user_exists = false;
    }

    if (user_exists){
        
    }
}

void createUser(){
    string name = "";
    string pass = "";
    string admin = "";

    while(name == ""){
        cout << "What do you want your username to be?" << endl;
        cin >> name;
        for (int i = 0; i < size(users); i++){
            if (users[i].name == name){
                ;
            }
        }
    }

    cout << "What do you want your password to be?" << endl;
    cin >> pass;

    while (true) {
        cout << "Are you an admin? (Y/N)";
        cin >> admin;
        if (admin == "Y" or admin == "N"){
            break;
        }
        cout << "That's not a valid input. Type 'Y' or 'N'." << endl;
    }
}

int main(){
    while(true){
        cout << "What do you want to do?\nLog in: 1\nCreate an account: 2\nExit: 3" << endl;
        int choice;
        cin >> choice;

        if (cin.fail() or choice <= 0 or choice >= 4) {
            cout << "That's not a valid input. Type the integer that corresponds to the action you would like to select." << endl;
        } else if (choice == 1){
            
        } else if (choice == 2){

        } else if (choice == 3){
            break;
        }

        cout << "Done reading?: ";
        string dummy;
        cin >> dummy;
        cout << endl;
    }

    return 0;
}