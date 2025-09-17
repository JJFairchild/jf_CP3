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
};

struct Customer{
    int id;
    string name;
    string email;
};

bool operator==(const Movie& first, const Movie& second){
        return (first.title == second.title &&
            first.releaseDate.year == second.releaseDate.year &&
            first.releaseDate.month == second.releaseDate.month &&
            first.releaseDate.day == second.releaseDate.day &&
            first.isPopular == second.isPopular
        );
    }

ostream& operator<<(ostream& stream, Movie& movie){
    stream << movie.title;
    return stream;
}

ostream& operator<<(ostream& stream, Customer& customer){
    stream << customer.name;
    return stream;
} 

void showMovie(Movie* movie){
    cout << movie -> title << endl;
}

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
    showMovie(&movie1);

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
    if (movie1 == movie2){
        cout << movie1 << " is equal" << endl;
    } else {
        cout << movie1 << " is not " << movie2 << endl;
    }
    cout << (movie1 == movie1) << endl;

    Customer john = {23998754, "John Clarke", "johnclarke@gmail.com"};

    return 0;
}