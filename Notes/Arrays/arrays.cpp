// Jonas Fairchild, Arrays Notes

#include <iostream>
#include <limits>
using namespace std;

string fam[6] = {"Kenneth", "Annette", "Jonas", "Landon", "William", "Spencer"};
string sibs[4] = {"Jonas", "Landon", "William", "Spencer"};

int search(string list[], int len, string item){
    for (int i=0; i<len; i++){

        if (list[i] == item){
            cout << " (child)";
            return 1;
        }
    }
    cout << " (parent)";
    return 0;
}

int main(){
    for(int i=0; i<size(fam); i++){
        cout << fam[i] << " Fairchild";
        search(sibs, size(sibs), fam[i]);
        cout << endl;
    }

    // SIZE OF T
    cout << numeric_limits <long long> ::min() << endl;
    cout << numeric_limits <long long> ::max() << endl;
    cout << numeric_limits <size_t> ::min() << endl;
    cout << numeric_limits <size_t> ::max() << endl;

    // Structured binding
    auto [a, b, c, d, e, f] = fam;
    cout << e << endl;

    // Multi dimensional
    int matrix[3][3] = {
        (1, 2, 3),
        (1, 2, 3),
        (1, 2, 3)
    };

    return 0;
}