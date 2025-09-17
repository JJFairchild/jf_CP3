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
using namespace std;

struct User{
    string name;
    string pass;
    bool admin;
};

int main(){
    vector<User> users = {};


    return 0;
}