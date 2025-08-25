// JF Variables, Data types, Inputs, and Outputs

#include <iostream> // c++ standard library, stands for input/output stream, handles info going in and out of your program.
using namespace std;

int main(){
    short days = 5; // Variable Types
    int students = 11;
    long years = 25541;
    const float pi = 3.1415926535f; //float will automatically compile to double if f is not included
    bool on = true;
    char name = 'Clang';

    cout << "Tell me your age: "; // Inputs and outputs
    int age;
    cin >> age;
    cout << "Your age is: " << age << endl;
    return 0;
}

//variable types

//short         2b  -32,768 - 32768
//int           4b  -2 billion - 2 billion
//long          4b  -2 billion - 2 billion
//longlong      8b  REALLY BIG #s
//float         4b  -3.4e38 - 3.4e38
//double        8b  -1.7e308 - 1.7e308
//longdouble    8b  -3.4e932 - 3.4e932
//bool          1b  True/False
//single        1b  Single Character
//char          ?b  Multiple Characters

//use snake_case