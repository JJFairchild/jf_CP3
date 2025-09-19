// Jonas Fairchild, Enumeration

#include <iostream>
using namespace std;

enum Menu{
    List = 1,
    Add,
    Update
};

enum class Operation{
    List = 1,
    Add,
    Update
};

int main(){

    int input;

    cout << 
    "1: List invoices" << endl <<
    "2: Add invoices" << endl <<
    "3: Update invoices" << endl <<
    "Select: ";
    cin >> input;

    if (input == static_cast<int>(Operation::List)){
        cout << "List invloices: ";
    } else if (input == Menu::Add){
        cout << "Haven't built this yet" << endl;
    } else if (input == Menu::Update){
        cout << "Haven't built this yet either :/" << endl;
    } else {
        cout << "Womp womp. Not an option." << endl;
    }

    return 0;
}