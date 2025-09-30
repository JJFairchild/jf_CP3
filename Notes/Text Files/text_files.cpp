// Jonas Fairchild, Text Files

#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Movie{
    int id;
    string title;
    int year;
};

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

    cout << "You entered " << first << " and " << second << endl;

    /*
    ifstream > input files stream
    ofstream < output file stream
    fstream >< combines the functionality
    */

    ofstream ofile;
    ofile.open("data.txt");
    if(ofile.is_open()){
        ofile << setw(20) << "Hello " << setw(20) << "World";
        ofile.close();
    }
    
    ifstream ifile;
    ifile.open("data.txt");
    if(ifile.is_open()){
        string str;
        getline(ifile, str);
        cout << str << endl;
        ifile.close();
    }
    

    ofile.open("data.csv");
    if(ofile.is_open()){
        ofile <<
        "id, title, year\n" <<
        "1, Terminator, 1984\n" <<
        "2, Terminator 2, 1991\n";
        ofile.close();
    }
    ifile.open("data.csv");
    if(ifile.is_open()){
        vector <Movie> movies;
        string str;

        getline(ifile, str);

        while(!ifile.eof()){
            getline(ifile, str, ',');
            if(str.empty()) continue;
            Movie movie;
            movie.id = stoi(str);

            getline(ifile, str, ',');
            movie.title = str;

            getline(ifile, str);
            movie.year = stoi(str);

            movies.push_back(movie);
        }
        
        for(auto& movie : movies){
            cout << movie.id << ", " << movie.title << ", " << movie.year << endl;
        }

        ifile.close();
    }
    
    return 0;
}