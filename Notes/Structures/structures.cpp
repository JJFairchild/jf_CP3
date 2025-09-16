// Jonas Fairchild, Structures

#include <iostream>
#include <vector>
using namespace std;

struct Date{
    short year = 1900;
    short month = 1;
    short day = 1;
};

struct Movie{
    string title;
    Date releaseDate;
    bool isPopular = true;

    bool == (Movie movie){
        if (title == movie.title &&
            releaseDate.year == movie.releaseDate.year &&
            releaseDate.month == movie.releaseDate.month &&
            releaseDate.day == movie.releaseDate.day &&
            isPopular == movie.isPopular
        ){
            return true;
        } else {
            return false;
        }
    }
};

struct Customer{
    int id;
    string name;
    string email;
};

int main(){
    vector<Movie> movies;

    // Movie terminator = {"Terminator", 1984};
    /*
    Movie terminator;
    terminator.title = "Terminator";
    terminator.releaseYear = 1984;
    */

    movies.push_back({"Terminator", {1984, 6, 1}});
    movies.push_back({"Terminator 2", 1987});

    Movie movie1 = {"Terminator", {1984, 6, 1}};
    Movie movie2 = {"Terminator 2", 1987};

    // auto [title, releaseYear, isPopular] {terminator};
    // cout << "Movie Title: " << terminator.title << endl;

    for(auto movie: movies){
        auto [title, releaseDate, isPopular] {movie};
        cout << "Movie title: " << movie.title << endl;
        cout << "Movie year: " << movie.releaseDate.year << endl;
        cout << "Movie month: " << movie.releaseDate.month << endl;
        cout << "Movie day: " << movie.releaseDate.day << endl;
        cout << "Movie popularity: " << movie.isPopular << endl;
    }
    cout << movie1 == movie2 << endl;

    Customer john = {23998754, "John Clarke", "johnclarke@gmail.com"};

    return 0;
}