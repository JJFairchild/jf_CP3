// Jonas Fairchild, Calculator Menu Options

/*
Lesson 2: Enumeration
LESSON I CAN: I CAN build custom structures in C++

By the end of this lesson you will be able to:
- Define enumeration
- Build enumeration
- What data type does enumeration automatically convert to?
- How do you make a strongly typed enumerator

State Standards:

INSTRUCTIONS:
- Write a program that creates a user menu for a basic calculator using enumeration in C++. The calculator should be able to perform addition, subtraction, multiplication, and division. The program should display a menu of options, allow the user to select an operation, input two numbers, perform the calculation, and display the result. The program must continue to run till the user chooses to exit and have proper input handling. 

OUTPUT EXAMPLE: 
    Calculator Menu:
    1: Addition
    2: Subtraction
    3: Multiplication
    4: Division
    5: Exit
    Enter your choice (1-5): 1

    Enter first number: 10
    Enter second number: 5
    Result: 10 + 5 = 15

KEY REMINDERS:
- Set appropriate variable types (e.g., double for temperatures).
- Use at least one decimal number in your conversion calculations to ensure accurate results.
- You have to get the standard library to create your inputs and outputs
- Make sure your arrows are pointing the right way for the input/output stream. 
- Implement error handling for invalid menu choices.

HOW TO SUBMIT:
- Submit the link to your project on Github
*/

#include <iostream>
#include <limits>
using namespace std;

enum MainMenu{
    Addition = 1,
    Subtraction,
    Multiplication,
    Division,
    Exit
};

double getNum(string messageMod){ // messageMod is to tell you what the number will be used for; eg. if it outputs "Enter your first number" then "first" is the messageMod.
    while (true){
        double num;
        cout << "Enter your " << messageMod << " number: ";
        cin >> num;

        if (cin.fail()){
            cout << "That isn't a valid input. Enter any number." << endl;
            continue;
        } else {
            return num;
        }
    }
}

int main(){

    while (true){
        int input;

        cout << endl <<
        "1: Addition" << endl <<
        "2: Subtraction" << endl <<
        "3: Multiplication" << endl <<
        "4: Division" << endl <<
        "5: Exit" << endl <<
        "Select an action (1-5): ";
        cin >> input;

        while (cin.fail()){
            cout << "That isn't a valid input. Enter the number from 1-5 that corresponds with your intended action." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        

        if (input == MainMenu::Exit){
            break;
        } else if (input != MainMenu::Addition && input != MainMenu::Subtraction && input != MainMenu::Multiplication && input != MainMenu::Division){
            cout << "That isn't an option. Try again." << endl;
            continue;
        }

        double first = getNum("first");
        double second = getNum("second");
        
        if (input == MainMenu::Addition){
            cout << first << " + " << second << " = " << (first + second) << endl;
        } else if (input == MainMenu::Subtraction){
            cout << first << " - " << second << " = " << (first - second) << endl;
        } else if (input == MainMenu::Multiplication){
            cout << first << " * " << second << " = " << (first * second) << endl;
        } else if (input == MainMenu::Division){
            cout << first << " / " << second << " = " << (first / second) << endl;
        }
    }

    return 0;
}