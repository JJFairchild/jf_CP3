// Jonas Fairchild, User Login

/*

Lesson 3: Strings, Arrays, Conditionals
LESSON I CAN: I CAN use strings arrays and conditionals in C++

By the end of this lesson you will be able to:
- Describe the basics of how strings are made in C++
- Create an array
- Build a conditional to check an array

State Standards:
***This is a UVU CS1410 requirement***

INSTRUCTIONS:
- Write a program that takes in a user name and checks to see if that user is an admin, returning user, or a new user and then says hello to them accordingly. 

EXAMPLE:
- Hello Admin Ms.LaRose
- Welcome back Andrew
- Lets get you signed up Katie

KEY REMINDERS:
- Remember you have to set your variable types
- You have to get the standard library to create your inputs and outputs
- Make sure your arrows are pointing the right way for the input/output stream. 
- You have to set the length of the array when you create it

HOW TO SUBMIT:
Submit the link to your project on Github

*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    string names[7] = {"Jake", "Matthew", "Caleb", "Patrick", "Sofia", "Rachel", "Zack"};
    int admins[7] = {1, 1, 0, 0, 0, 0, 0};

    cout << "Enter your username: ";
    string name;
    cin >> name;

    for(int i; i<size(names); i++){
        if (name == names[i]){
            cout << "Hello Admin " << name;
            return 0;
        }
    }

    return 0;
}