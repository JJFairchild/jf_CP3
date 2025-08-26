// Jonas Fairchild, Strings, Arrays, and Conditionals

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    long long_num = 108'135'701; // Narrowing
    short short_num = long_num;
    cout << short_num << endl;


    int seconds = time(nullptr); // Randomness
    srand(seconds);
    int my_num = rand() % 11;
    cout << my_num << endl;


    int grades[5] = {96, 75, 89, 90, 98}; // Arrays
    cout << grades[2] << endl;


    string name = "Trust in Clang"; // Strings
    cout << name << endl;

    // .substr() makes a substring
    // .length() returns the length of the string

    // .starts_with("x"), ends_with("x") returns 1 or 0 depending if it starts or ends with x.
    // .front() returns first character
    // .back() returns last character

    // .append() adds things to the end
    // .insert() inserts things at an index
    // .erase()
    // .clear() makes the string empty
    // .replace() replaces a section

    
    if (name > "o"){ // Conditionals
        cout << "Trust in Clang even more. Now. Or else." << endl;
    }else if (0){
        cout << "Trust in Clang slightly less. :(" << endl;
    }else{
        cout << "be happers pls" << endl;
    }

    return 0;
}