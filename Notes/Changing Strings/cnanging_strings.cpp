// Jonas Fairchild, Changing Strings

#include <iostream>
using namespace std;

string name = "jonas fairchild";
string sentence = "The quick brown fox jumps over the lazy dog!";

int main(){
    auto index = name.find(" ");

    string firstname = name.substr(0, index); // Starting index, # of characters
    string lastname = name.substr(index+1);

    cout << "First name: " << firstname << endl;
    cout << "Last name: " << lastname << endl;

    firstname[0] = toupper(firstname[0]);
    // tolower()

    for(int i=0; i<size(sentence); i++){
        if(isspace(sentence[i])){
            sentence[i] = '_';
        } else if(islower(sentence[i])){
            sentence[i] = toupper(sentence[i]);
        } else{
            sentence[i] = char((int(sentence[i]) + 4) % 27 + 97);
        }
    }
    cout << sentence << endl;

    cout << R"(This is a \"Question\"\n\t. . . I think)";

    return 0;
}