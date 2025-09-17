// Jonas Fairchild, Fahrenheit to Celsius

/*

Lesson 2: Variables, Inputs and Outputs
LESSON I CAN: I CAN create a simple program in C++

By the end of this lesson you will be able to:
- Describe how to write statically typed variables
- Access the C++ standard library to create inputs and outputs
- Describe the stream
- Know when to create constant variables

State Standards: ***This is a UVU CS1410 requirement***

INSTRUCTIONS:
Write a program that takes in a temperature in Fahrenheit, converts it to Celcius and then prints for your user that the given temperature in Fahrenheit is the new amount in Celsius.

OUTPUT EXAMPLE: 
50 degrees Fahrenheit is 10 degrees Celsius

KEY REMINDERS:
- Remember you have to set your variable types
- Division will not give you a decimal unless at least 1 of your input numbers is a decimal type
- You have to get the standard library to create your inputs and outputs
- Make sure your arrows are pointing the right way for the input/output stream. 

HOW TO SUBMIT:
Submit the link to your project on Github

*/

#include <iostream>
using namespace std;

int main(){
    cout << "Enter a value in Fahrenheit: ";
    float far;
    cin >> far;
    cout << far << " degrees Fahrenheit is " << (far-32)*(5.0/9) << " degrees Celsius.";
    return 0;
}