// Jonas Fairchild, Binary and Searching

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

/* Convert other data types to strings
istringstream => reading a string
ostringstream => writing a string
stringstream => both
*/

string toString(double number, int precision){

    stringstream stream;
    stream << fixed << setprecision(precision) << number << endl;
    return stream.str();
}

struct Movie{
    string title;
    int year;
};

Movie parseMovie(string str){
    stringstream stream;
    stream.str(str);

    Movie movie;
    getline(stream, movie.title, ',');
    int year;
    stream >> movie.year;
    return movie;
}

int main(){

    cout << toString(3.1415926535, 10);

    // parsing
    string users = "10 20";
    stringstream fix;
    fix.str(users);

    int first;
    fix >> first;
    int second;
    fix >> second;

    cout << "First: " << first << ", Second: " << second << endl;

    auto movie = parseMovie("Terminator 1,1984");
    cout << 
    movie.title << endl <<
    movie.year << endl;

    fstream file;
    file.open("file.txt", ios::in | ios::out | ios::app | ios::binary);
    if(file.is_open()){

    }

    return 0;
}