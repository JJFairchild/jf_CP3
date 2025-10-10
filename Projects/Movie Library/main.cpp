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
#include <algorithm>
#include <cctype>
using namespace std;

enum MainMenu{
    SelectLib = 1,
    ViewMov,
    SearchMov,
    AddMov,
    DelMov,
    Exit
};

enum SearchMenu{
    Title = 1,
    Dir,
    Year,
    Genre,
    Rating
};

struct Movie{
    string title;
    string dir;
    string year;
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

string toLower(string str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
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
                Movie movie;

                getline(iss, item, ',');
                movie.title = item;
                getline(iss, item, ',');
                movie.dir = item;
                getline(iss, item, ',');
                movie.year = item;
                getline(iss, item, ',');
                movie.genre = item;
                getline(iss, item, ',');
                movie.rating = item;

                movies.push_back(movie);
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

void display(vector<Movie> movies){
    if(!movies.empty()){
        for(auto& movie : movies){
            cout << 
            "- " << movie.title <<
            "\n\tDirector: " << movie.dir <<
            "\n\tRelease year: " << movie.year <<
            "\n\tGenre: " << movie.genre <<
            "\n\tRating: " << movie.rating << "\n\n";
        }
    } else cout << "The movies list is empty, or you haven't assigned a library.\n";
}

vector<Movie> search(vector<Movie> movies){

    vector<Movie> results;

    if(!movies.empty()){
        int field = getInt(R"(
Select a field:
1: Title
2: Director
3: Year
4: Genre
5: Rating
)", 1, 5);

        string search = toLower(getString("What do you want to search for?: "));
        
        for(auto& movie : movies){
            string field_val;
            
            if(field == SearchMenu::Title) field_val = toLower(movie.title);
            else if(field == SearchMenu::Dir) field_val = toLower(movie.dir);
            else if(field == SearchMenu::Year) field_val = toLower(movie.year);
            else if(field == SearchMenu::Genre) field_val = toLower(movie.genre);
            else if(field == SearchMenu::Rating) field_val = toLower(movie.rating);
            
            if(field_val.find(search) != string::npos) {
                results.push_back(movie);
            }
        }
    } else cout << "The movies list is empty, or you haven't assigned a library.\n";

    return results;
}

Movie createMov(){
    Movie movie;
    movie.title = getString("What is the title of the movie?: ");
    movie.dir = getString("Who was the director of the movie?: ");
    movie.year = to_string(getInt("What year was it published?: ", 1888, 2025));
    movie.genre = getString("What genre is the movie?: ");
    movie.rating = getString("What is the movie's rating?: ");
    return movie;
}

vector<Movie> delMov(vector<Movie> movies){

    if (!movies.empty()){
        cout << "Search for a movie to delete:\n";
        vector<Movie> movs_d = search(movies);

        if (movs_d.empty()) {
            cout << "No matching movies found.\n";
            return movies;
        }

        while(true){
            cout << "Search results:\n";
            display(movs_d);

            string del = toLower(getString("What movie do you want to delete? (type 'cancel' to exit): "));

            if (del == "cancel") {
                cout << "Deletion cancelled.\n";
                break;
            }

            // Check if a matching movie exists in movs_d
            bool found = false;
            for (auto& m : movs_d) {
                if (toLower(m.title) == del) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No movie with that title found in search results. Try again.\n";
                continue;
            }

            // Remove the movie from the original list
            movies.erase(
                remove_if(movies.begin(), movies.end(),
                    [del](const Movie& m) {
                        return toLower(m.title) == del;
                    }),
                movies.end()
            );

            cout << "Movie deleted successfully.\n";
            break;
        }
    } else cout << "The movies list is empty, or you haven't assigned a library.\n";

    return movies;
}

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
            if (!movies.empty()) cout << "Movie list:\n";
            display(movies);
        } else if (choice == MainMenu::SearchMov){
            vector<Movie> movs_s = search(movies);
            if (!movs_s.empty()){
                cout << "Search results:\n";
                display(movs_s);
            }
        } else if (choice == MainMenu::AddMov){
            if(!library.empty()) movies.push_back(createMov());
            else cout << "You need to assign a library before you can make any movies.\n";
        } else if (choice == MainMenu::DelMov){
            movies = delMov(movies);
        } else if (choice == MainMenu::Exit) {
            if (!library.empty()) writeLib(movies, library);
            break;
        }

    }

    return 0;
}