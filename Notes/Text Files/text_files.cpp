// Jonas Fairchild, Text Files

#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
using namespace std;

int getNumber(const string& prompt){
    int num;
    while(true){
        cout << prompt;
        cin >> num;
        if(cin.fail()){
            cout << "That's not a valid number. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    return num;
}

int main(){

    /*
    terminal - cout, cin (user-given)
    file - txt, csv, binary
    network - internet, other computers

    STREAMS: Data source/destination
    */

    int first = getNumber("Tell me a number: ");
    int second = getNumber("Tell me another number: ");

    cout << "You entered " << first << " and " << second;

    /*
    ifstream > input files stream
    ofstream < output file stream
    fstream >< combines the functionality
    */

    ofstream file;
    file.open("data.txt");
    if(file.is_open()){
        file << setw(20) << "Hello " << setw(20) << "World";
        file.close();
    }

    file.open("data.csv");
    if(file.is_open()){
        file << "id, title, year\n" <<
        "1, Terminator, 1984\n" <<
        "2, Terminator 2, 1991\n";
        file.close();
    }
    

    return 0;
}