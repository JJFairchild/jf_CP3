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
string user = ""; // Current account the user is logged into. Not used for much.

void logIn(){
    if (user != ""){
        user = "";
        cout << "Successfully logged out.";
    } else {
        bool check = true;

        while (check){
            cout << "What is your username?: ";
            string name;
            cin >> name;

            for (int i = 0; i < size(users); i++){
                if (users[i].name == name){
                    check = false;
                    user = i;
                    break;
                }
            }
            if(check == true) cout << "Name not found. Try again." << endl;
        }

        check = true;

        while (check){
            cout << "What is your password?: ";
            string pass;
            cin >> pass;

            if (users[user].pass != pass)
        }
        cout << "Successfully logged in." << endl;
    }
}

void createUser(){
    if (user == ""){
        bool check = false; // A value that is modified when checking whether a name is valid or not.
        string name = "";
        string pass = "";
        string admin = "";

        while(check){
            check = false;
            cout << "What do you want your username to be?" << endl;
            cin >> name;

            for (int i = 0; i < size(users); i++){ // Makes sure that the name the user gives isn't already used.
                if (users[i].name == name){
                    cout << "That name already exists. Try again." << endl;
                    check = true;
                }
            }
        }

        while(check){
            check = false;
            cout << "What do you want your password to be?" << endl;
            cin >> name;

            for (int i = 0; i < size(users); i++){
                if (users[i].pass == pass){
                    cout << "That password already exists. Try again." << endl;
                    check = true;
                }
            }
        }

        while (true) {
            cout << "Are you an admin? (Y/N)";
            cin >> admin;
            if (admin == "Y" or admin == "N"){
                break;
            }
            cout << "That's not a valid input. Type 'Y' or 'N'." << endl;
        }

        users.push_back({name, pass, admin});
        user = name;
    } else {
        cout << "You are already logged in; you can't create an account right now.";
    }
}

int main(){
    while(true){
        cout << "What do you want to do?\nLog in/out: 1\nCreate an account: 2\nExit: 3" << endl;
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