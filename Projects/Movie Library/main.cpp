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

string getString(string message){

    string str;

    while(true){
        cout << message;
        getline(cin, str);
        if(!str.empty()) return str;
        else cout << "You have to type something. Try again.\n";
    }
}

int getInt(string message, int min, int max){

    string line;
    int num;

    while(true){
        cout << message;
        getline(cin, line);
        try{
            num = stoi(line);
            if(num <= max && num >= min) return num;
            else cout << "That's not in the valid range (min: " << min << ", max: " << max << "). Try again.\n";
        } catch (...){
            cout << "That's not a valid input. Try again.\n";
        }
    }
}

string getLib(){

    string filename = getString("Input your library's file name: ");
    ifstream file(filename);

    if (file) {
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
            cout << "Successfully added library." << endl;
        }
    } catch (...){
        cout << "Unable to read the given library. Ensure it is a csv and follows the proper format (title, director, year, genre, rating).\n";
    }
    return movies;
}

void writeLib(vector<Movie> movies, string filename){

    ofstream file(filename);
    if(file.is_open()){
        file << "title,director,year,genre,rating\n";

        for(auto& movie : movies){
            file << movie.title << "," << movie.dir << "," << movie.year << "," << movie.genre << "," << movie.rating << endl;
        }
    }
}

void displayMov(vector<Movie> movies, string message){
    if(!movies.empty()){
        cout << message << endl;
        for(auto& movie : movies){
            cout << 
            "- " << movie.title <<
            "\n\tDirector: " << movie.dir <<
            "\n\tRelease year: " << movie.year <<
            "\n\tGenre: " << movie.genre <<
            "\n\tRating: " << movie.rating << endl;
        }
    } else cout << "You haven't assigned a library or the movies list is empty.\n";
}

vector<Movie> seqSearch(vector<Movie> movies, string search){
    int field = getInt(R"(
Select a field:
1: Title
2: Director
3: Year
4: Genre
5: Rating
)", 1, 5);
    
    
}

Movie createMov(){
    Movie movie;
    
}

enum MainMenu{
    SelectLib = 1,
    ViewMov,
    SearchMov,
    AddMov,
    DelMov,
    Exit
};

int main(){

    string library;
    vector<Movie> movies;

    while(true){
        
        int choice = getInt(R"(
What do you want to do?
1: Select a movie library
2: View the movie list
3: Search the movie list
4: Add a movie
5: Remove a movie
6: Save and exit
)", 1, 6);        

        if (choice == MainMenu::SelectLib){
            string lib = getLib();
            if (!lib.empty()){
                library = lib;
                movies = readLib(library);
            }
        } else if (choice == MainMenu::ViewMov){
            displayMov(movies, "Movie list:");
        } else if (choice == MainMenu::SearchMov){

        } else if (choice == MainMenu::AddMov){

        } else if (choice == MainMenu::DelMov){

        } else if (choice == MainMenu::Exit){
            writeLib(movies, library);
            break;
        }

    }

    return 0;
}