// Jonas Fairchild, Arrays Notes

#include <iostream>
#include <limits>
using namespace std;

string fam[6] = {"Kenneth", "Annette", "Jonas", "Landon", "William", "Spencer"};
string childs[4] = {"Jonas", "Landon", "William", "Spencer"};

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
        search(childs, size(childs), fam[i]);
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

    // Sorting arrays
    int list[19] = {5, 3, 8, 12, 16, 1, 1, 3, 5, 7, 2, 9, 64, 31, 86, 23, 98, 23, 54};
    for (int i=0; i<size(list); i++){
        for (int j=1; j<size(list); j++){
            if(list[j] < list [j-1]){
                int swap = list[j];
                list[j] = list[j-1];
                list[j-1] = swap;
            }
        }
    }
    for (int i=0; i<size(list); i++){
        cout << list[i] << ", ";
    }

    // Multi-dimensional arrays
    int matrix[3][3][3] = {
        {
            {1, 2, 3}, {1, 2, 3}, {1, 2, 3}
        },
        {
            {1, 2, 3}, {1, 2, 3}, {1, 2, 3}
        },
        {
            {1, 2, 3}, {1, 2, 3}, {1, 2, 3}
        }
    };

    return 0;
}