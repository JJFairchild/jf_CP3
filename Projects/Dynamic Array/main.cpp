// Jonas Fairchild, Dynamic Array

/*

Lesson 6: Pointers
LESSON I CAN: I CAN use pointers in C++

By the end of this lesson you will be able to:
- Define pointers
- Use pointers in a program
- Describe the benefits of pointers

State Standards:
***This is a UVU CS1410 requirement***

INSTRUCTIONS:
- Write a program that asks the user to enter books, movies, shows, colors, comics, etc. until they can't think of anymore. 
- Start your array with only 5 spaces. Continue to increase the size of the array as your user hits the array cap. 
- THEN, print out each of the inputs they gave you!

KEY REMINDERS:
- Remember you have to set your variable types
- You have to get the standard library to create your inputs and outputs
- Make sure your arrows are pointing the right way for the input/output stream. 
- You have to set the length of the array when you create it

HOW TO SUBMIT:
- Submit the link to your project on Github

*/

#include <iostream>
#include <memory>
#include <cctype>
using namespace std;

int capacity = 5;
unique_ptr<string[]> stuff(new string[capacity]);
int entries = 0;

void check_size(){ // Function to check if the list is full and adds space if necessary.
    if (entries == capacity) {
        capacity += 5;
        unique_ptr<string[]> temp(new string[capacity]); // Creates a new array and moves the contents of "stuff."
        for (int i=0; i<entries; i++) {
            temp[i] = stuff[i];
        }
        stuff = move(temp);
    }
}

int main(){

    while (true) { // Main loop, adds things to the list of stuff.
        string thing;
        cout << "What media (book, comic, show, movie, etc.) do you want to add to your list? (type 'done' to quit): ";
        getline(cin, thing);
        if (thing == "done") break; // exit mechanism
        stuff[entries] = thing;
        entries++;
        check_size();
    }

    cout << "\nYour List:\n";
    for (int i=0; i<entries; i++) {
        cout << "- " << stuff[i] << endl;
    }

    return 0;
}