// Jonas Fairchild, Strings, Arrays, and Conditionals

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int seconds = time(nullptr);
    srand(seconds);
    int my_num = rand() % 11;
    cout << my_num;
    return 0;
}