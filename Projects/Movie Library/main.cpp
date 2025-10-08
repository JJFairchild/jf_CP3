// Jonas Fairchild

/*
INSTRUCTIONS:
- Create an application that manages your Movie Library using structures to store movie details and enumerations for menu options. Your program should persist movie data by reading from and writing to an external file in CSV format.
- Main menu needs to allow our user to load the library from a file (I will use a different one than the example one I have given you), view all movies, add a movie, delete a movie, and search movies.
- The search menu should allow the user to select what they would like to search by, then the specific value they would like to search. 

NOTE: You need to build a sequential search algorithm for this project (it is a state standard) 

EXAMPLE:
- Rating (e.g., G, PG, PG-13, R)
- Director (e.g., Christopher Nolan)
- Release Year (e.g., 1987)
- Genre (e.g., Action, Comedy)

KEY REMINDERS:
- Use structures to organize movie data.
- Use enumerations for the menu.
- Incorporate input validation and error handling.
- Make sure the program is user-friendly and clear.

HOW TO SUBMIT:
- Submit the link to your project on GitHub.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

struct Movie{
    string title;
    string dir;
    int year;
    string genre;
    string rating;
};

string getLib(){

    string filename;
    cout << "Input your library's file name: ";
    getline(cin, filename);
    ifstream file(filename);

    if (file) {
        cout << "Successfully added library." << endl;
        return filename;
    } else {
        cout << "Sorry, couldn't find that file.\n";
        return "";
    }
}

vector<Movie> readLib(string filename){
    vector <Movie> movies;

    try{
        ifstream file(filename);

        string line;

        if (file.is_open()){

            getline(file, line);

            while (getline(file, line)){
                istringstream iss(line);
                string item;
                Movie mov;

                getline(iss, item, ',');
                mov.title = item;
                getline(iss, item, ',');
                mov.dir = item;
                getline(iss, item, ',');
                mov.year = stoi(item);
                getline(iss, item, ',');
                mov.genre = item;
                getline(iss, item, ',');
                mov.rating = item;

                movies.push_back(mov);
            }

            file.close();
        }
    } catch (...){
        cout << "Unable to read the given library. Ensure it is a csv and follows the proper format (title, director, year, genre, rating).\n";
    }
    return movies;
}

void displayMov(vector<Movie> movies){
    for(auto& movie : movies){
        cout << 
        "- " << movie.title <<
        "\n\t- " << ;
    }
}

vector<string> seqSearch(vector<string> movies, string search){

}

enum MainMenu{
    SelectLib = 1,
    ViewMov,
    DelMov,
    SearchMov,
    Exit
};

int main(){

    string library;
    vector<Movie> movies;

    while(true){
        string line;
        cout <<
        "\nWhat do you want to do?\n" <<
        "1: Select a movie library\n" <<
        "2: View the movie list\n" <<
        "3: Delete a movie\n" <<
        "4: Search the movie list\n" <<
        "5: Save and exit\n";
        getline(cin, line);

        try{
            int choice = stoi(line);

            if (choice = MainMenu::SelectLib){
                string lib = getLib();
                if (!lib.empty()){
                    library = lib;

                    movies = readLib(library);
                }
            } else if (choice = MainMenu::ViewMov){

            } else if (choice = MainMenu::DelMov){

            } else if (choice = MainMenu::SearchMov){

            } else if (choice = MainMenu::Exit){
                break;
            } else {
                cout << "That's not an option. Try again.\n";
            }
        } catch(...){
            cout << "Invalid input. Try again.\n";
        }
    }

    return 0;
}