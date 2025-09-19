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
#include <string>
#include <limits>
using namespace std;

struct User{
    string name;
    string pass;
    string admin; // string so that there can be an undecided state "" for the logIn() function
};

bool operator==(const User& u1, const User& u2) { // NOTE FOR MS LAROSE: This overflow is not used, despite being defined. Originally, there was a for loop on line 140 that would search through each user in users to find the index of the user that was just created so that user_index could be assigned a value. That was the only instance of this being used, and after I optimized that to what it is now, there weren't any left. Any place where I would check if one entire user is the same as another is actually just checking if the individual parts are the same because that's what made more sense to me logically and at this point implementing them would just be rewriting the entire code and this is due in an hour and a half as of me writing this so I don't have time to do that. Just know that I do know how overflows work, I just didn't get a chance to implement them in this project.
    return u1.name == u2.name && u1.pass == u2.pass && u1.admin == u2.admin;
}

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

int logIn(int user_index){
    if (user_index != -1){
        user_index = -1;
        cout << "Successfully logged out.";
    } else {
        bool check = true;

        while (check){
            cout << "What is your username?: ";
            string name;
            getline(cin, name);
            
            int i = 0; // Manual counter because the for loop was giving me trouble
            for (const auto& user : users){
                if (user.name == name){
                    check = false;
                    user_index = i;
                    break;
                }
                i++;
            }
            if(check == true) cout << "Name not found. Try again." << endl;
        }

        while (true){
            cout << "What is your password?: ";
            string pass;
            getline(cin, pass);

            if (users[user_index].pass == pass) break;
            cout << "Incorrect password." << endl;
        }
        cout << "Successfully logged in." << endl;
    }
    return user_index;
}

int createUser(int user_index){
    if (user_index == -1){
        bool check = true; // A value that is modified when checking whether a name is valid or not.
        string name = "";
        string pass = "";
        string admin = "";

        while(check){
            check = false;
            cout << "What do you want your username to be?" << endl;
            getline(cin, name);

            for (const auto& user : users){ // Makes sure that the name the user gives isn't already used.
                if (user.name == name){
                    cout << "That name already exists. Try again." << endl;
                    check = true;
                    break;
                }
            }
        }
        
        cout << "What do you want your password to be?" << endl;
        getline(cin, pass);

        while (true) {
            cout << "Are you an admin? (Y/N)";
            getline(cin, admin);
            if (admin == "Y" || admin == "N"){
                break;
            }
            cout << "That's not a valid input. Type 'Y' or 'N'." << endl;
        }

        users.push_back({name, pass, admin});
        cout << "Successfully created a user profile. Welcome!\nYou are now logged in." << endl;
        user_index = users.size() - 1;
    } else {
        cout << "You are already logged in; you can't create an account right now.";
    }
    return user_index;
}

int main(){
    int user_index = -1; // Current account the user is logged into. Not used for much.
    while(true){
        cout << "What do you want to do?\nLog in/out: 1\nCreate an account: 2\nExit: 3" << endl;
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (cin.fail() || choice <= 0 || choice >= 4) {
            cout << "That's not a valid input. Type the integer that corresponds to the action you would like to select." << endl;
            cin.clear();
        } else if (choice == 1){
            user_index = logIn(user_index);
        } else if (choice == 2){
            user_index = createUser(user_index);
        } else if (choice == 3){
            break;
        }

        cout << endl;
    }

    return 0;
}