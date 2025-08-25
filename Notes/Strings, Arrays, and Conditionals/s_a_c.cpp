// Jonas Fairchild, Strings, Arrays, and Conditionals

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    long long_num = 108'135'701; // Narrowing
    short short_num = long_num;
    cout << short_num;

    int seconds = time(nullptr); // Randomness
    srand(seconds);
    int my_num = rand() % 11;
    cout << my_num;

    return 0;
}